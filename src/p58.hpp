#pragma once

//std
#include <string>

//lib
#include "util.hpp"

namespace p58 {
	class Solution {
	public:
		int lengthOfLastWord(const std::string& str) const {
			size_t result = 0, pos = str.size() - 1;

			while (str[pos] == ' ')
				--pos;
			while (pos != 0 && str[pos] != ' ') {
				--pos;
				++result;
			}
			result += pos == 0 && str.front() != ' ';

			return result;
		}
	};

	using input_t = std::string;
	using output_t = int;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto input = util::read_string(is);
		auto result = util::read_value<int>(is);
		tests.emplace_back(std::move(input), result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		return s.lengthOfLastWord(input);
	}
}
