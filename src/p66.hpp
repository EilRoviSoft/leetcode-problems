#pragma once

//std
#include <vector>

//lib
#include "util.hpp"

namespace p66 {
	class Solution {
	public:
		std::vector<int> plusOne(const std::vector<int>& number) const {
			std::vector<int> result;
			int64_t i, digits, carry_pos = number.size() - 1;
			bool new_digit_flag, carry_flag = number.back() == 9;

			for (i = number.size() - 1, digits = 0; i != -1 && number[i] == 9; --i, ++digits);
			new_digit_flag = i == -1;
			result.resize(number.size() + new_digit_flag);
			if (new_digit_flag)
				result.front() = 1;
			for (i = number.size() - 1; i != -1; --i) {
				if (carry_flag && number[i] == 9) {
					carry_pos = i - 1;
					result[new_digit_flag + i] = 0;
				} else {
					result[new_digit_flag + i] = number[i];
					carry_flag = false;
				}
			}
			if (!new_digit_flag)
				++result[carry_pos];

			return result;
		}
	};
	using input_t = std::vector<int>;
	using output_t = std::vector<int>;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto input = util::read_vector<int>(is);
		auto output = util::read_vector<int>(is);
		tests.emplace_back(input, output);
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		return s.plusOne(input);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		return output == result;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {}
}
