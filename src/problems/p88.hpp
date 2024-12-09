#pragma once

//std
#include <iostream>
#include <vector>

//lib
#include "util.hpp"

namespace p88 {
	class Solution {
	public:
		void merge(std::vector<int>& v1, int s1, const std::vector<int>& v2, int s2) const {
			auto copy = std::vector(v1.begin(), v1.begin() + s1);
			size_t i = 0, j = 0;

			while (i < s1 && j < s2) {
				if (copy[i] >= v2[j]) {
					v1[i + j] = v2[j];
					++j;
				} else {
					v1[i + j] = copy[i];
					++i;
				}
			}
			while (i < s1) {
				v1[i + j] = copy[i];
				++i;
			}
			while (j < s2) {
				v1[i + j] = v2[j];
				++j;
			}
		}
	};

	using input_t = std::tuple<std::vector<int>, int, std::vector<int>, int>;
	using output_t = util::none_t;
	using result_t = std::vector<int>;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto v1 = util::read_vector<int>(is);
		auto s1 = util::read_value<int>(is);
		auto v2 = util::read_vector<int>(is);
		auto s2 = util::read_value<int>(is);
		auto result = util::read_vector<int>(is);
		tests.emplace_back(std::make_tuple(std::move(v1), s1, std::move(v2), s2), std::move(result));
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		auto& [v1, s1, v2, s2] = input;
		s.merge(v1, s1, v2, s2);
		return {};
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		auto& [v1, s1, v2, s2] = input;
		return v1 == result;
	}
}
