#pragma once

//std
#include <functional>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

namespace util {
	template<typename _InputType, typename _ResultType>
	using tests_t = std::vector<std::pair<_InputType, _ResultType>>;

	template<typename T>
	T read_value(std::istream& is) {
		T result;
		is >> result;
		return result;
	}
	std::string read_string(std::istream& is);

	template<typename T>
	std::vector<T> read_vector(std::istream& is, const std::function<T(std::istream& is)>& value_reader = read_value<T>) {
		std::vector<T> result;
		result.resize(read_value<size_t>(is));
		for (size_t i = 0; i < result.size(); i++)
			result[i] = value_reader(is);
		return result;
	}

	void read_tests(size_t test_id, const std::function<void(std::istream& is)>& test_maker);

	template<typename _InputType, typename _OutputType, typename _ResultType>
	void exec_tests(tests_t<_InputType, _ResultType>& tests, 
					const std::function<_OutputType(_InputType&)> test_executor,
					const std::function<bool(const _InputType&, const _OutputType&, const _ResultType&)> test_checker,
					const std::optional<std::function<void(_OutputType)>> output_destroyer = {}){
		for (size_t i = 0; i < tests.size(); i++) {
			auto output = test_executor(tests[i].first);
			if (!test_checker(tests[i].first, output, tests[i].second))
				std::cout << "Error on test: " << i + 1 << "\n";
			if (output_destroyer)
				(*output_destroyer)(output);
		}
	}
}
