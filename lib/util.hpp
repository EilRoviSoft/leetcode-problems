#pragma once

//std
#include <chrono>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <optional>
#include <set>
#include <string>
#include <vector>

//winapi
#include "Windows.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using ms_duration_t = std::chrono::duration<double, std::milli>;
extern std::unordered_map<size_t, std::function<ms_duration_t()>> solutions;

namespace util {
	template<typename InputT, typename ResultT>
	using tests_t = std::vector<std::pair<InputT, ResultT>>;

	struct none_t {};

	static const std::set whitespace = { ' ', '\t', '\n' };

	inline void skip_until(std::istream& is, const std::function<bool(const char&)>& condition) {
		while (condition(is.get()));
	}

	inline void ignore_until(std::istream& is, const std::function<bool(const char&)>& condition) {
		while (condition(is.peek()))
			is.ignore();
	}

	template<typename T>
	T read_value(std::istream& is) {
		T result;
		is >> result;
		return result;
	}
	inline std::string read_string(std::istream& is) {
		std::string result;

		ignore_until(is, [&](const char& c) { return whitespace.contains(c); });

		if (is.get() != '\"')
			throw std::runtime_error("util.hpp, read_string: string doesn't have \" at start");

		char c = is.get();
		if (c != '\"') {
			do {
				result += c;
				c = is.get();
			} while (c != '\"');
		}
		is.get();

		//std::cout << result << ' ';
		return result;
	}

	template<typename T>
	std::vector<T> read_vector(std::istream& is, const std::function<T(std::istream& is)>& value_reader = read_value<T>) {
		std::vector<T> result;
		result.resize(read_value<size_t>(is));
		for (size_t i = 0; i < result.size(); i++)
			result[i] = value_reader(is);
		return result;
	}

	template<typename SolutionT, typename InputT, typename OutputT, typename ResultT>
	void add_solution(size_t problem_id,
					  std::function<void(std::istream& is, tests_t<InputT, ResultT>&)> test_maker,
					  std::function<OutputT(SolutionT&, InputT&)> test_executor,
					  std::function<bool(const InputT&, const OutputT&, const ResultT&)> test_checker,
					  std::optional<std::function<void(InputT, OutputT, ResultT)>> output_destroyer = {}) {
		solutions.emplace(problem_id, [problem_id, test_maker, test_executor, test_checker, output_destroyer]() {
			//to check memory leaks and calc execution time
			std::chrono::duration<double, std::milli> result;
			_CrtMemState _old, _new, _dif;
			_CrtMemCheckpoint(&_old);

			{
				SolutionT s;
				tests_t<InputT, ResultT> tests;

				std::string filename = "tests/p" + std::to_string(problem_id) + ".txt";
				std::fstream file(filename);
				if (!file.is_open())
					throw std::runtime_error("util.hpp, init_solution: test is not found\n");
				while (!file.eof())
					test_maker(file, tests);
				file.close();

				auto start_time = std::chrono::high_resolution_clock::now();
				for (size_t i = 0; i < tests.size(); i++) {
					auto output = test_executor(s, tests[i].first);
					if (!test_checker(tests[i].first, output, tests[i].second))
						std::cerr << "Error on test: " << i + 1 << "\n";
					if (output_destroyer)
						(*output_destroyer)(tests[i].first, output, tests[i].second);
				}
				auto end_time = std::chrono::high_resolution_clock::now();

				//calc execution time
				result = end_time - start_time;
			}

			//check memory leaks
			_CrtMemCheckpoint(&_new);
			if (_CrtMemDifference(&_dif, &_old, &_new)) {
				auto message = L"Problem ID: " + std::to_wstring(problem_id) + L"\n\n";
				OutputDebugString(message.c_str());
				OutputDebugString(L"_CrtMemDumpStatistics:");
				_CrtMemDumpStatistics(&_dif);
				OutputDebugString(L"_CrtMemDumpAllObjectsSince:");
				_CrtMemDumpAllObjectsSince(&_old);
				OutputDebugString(L"_CrtDumpMemoryLeaks:");
				_CrtDumpMemoryLeaks();
			}

			return result;
		});
	}

	template<typename T>
	std::map<T, size_t> count_values(const std::vector<T>& values) {
		std::map<T, size_t> result;
		for (const auto& it : values) {
			if (result.contains(it))
				result[it]++;
			else
				result[it] = 1;
		}
		return result;
	}

	template<class T>
	std::vector<T> get_combination(const std::vector<T>& v1, const std::vector<T>& v2) {
		std::set<T> result;
		for (const auto& it : v1) {
			if (!result.contains(it))
				result.insert(it);
		}
		for (const auto& it : v2) {
			if (!result.contains(it))
				result.insert(it);
		}
		return std::vector<T>(result.begin(), result.end());
	}

	template<typename T>
	bool has_same_values(const std::vector<T>& v1, const std::vector<T>& v2) {
		bool result = true;
		std::map<T, size_t> s1 = count_values(v1), s2 = count_values(v2);
		for (const auto& it : get_combination(v1, v2))
			if (s1[it] != s2[it]) {
				result = false;
				break;
			}
		return result;
	}
}
