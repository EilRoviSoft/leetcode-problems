#pragma once

//std
#include <string>
#include <vector>

//lib
#include "util.hpp"

namespace p14 {
	class Solution {
	public:
		std::string longestCommonPrefix(const std::vector<std::string>& lines) const {
			size_t result = 0;
			size_t min_length = lines[0].size();
			for (const auto& line : lines) {
				if (min_length > line.size())
					min_length = line.size();
			}

			for (size_t i = 0; i != min_length; ++i) {
				bool flag = false;
				for (size_t j = 1; j != lines.size(); ++j) {
					if (lines[0][i] != lines[j][i]) {
						flag = true;
						break;
					}
				}

				if (flag)
					break;
				++result;
			}

			return lines[0].substr(0, result);
		}
	};

	using input_t = std::vector<std::string>;
	using output_t = std::string;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto input = util::read_vector<std::string>(is, &util::read_string);
		auto result = util::read_string(is);
		tests.emplace_back(input, result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		return s.longestCommonPrefix(input);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		return output == result;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {}
}
