#pragma once

//std
#include <map>
#include <string>
#include <vector>

//lib
#include "util.hpp"

namespace p20 {
	class Solution {
	public:
		bool isValid(const std::string& str) const {
			bool result = true;
			std::vector <int> stack;
			const std::map<char, char> inverse = {
				{ ')', '(' },
				{ ']', '[' },
				{ '}', '{' }
			};

			for (auto c : str) {
				switch (c) {
				case '(':
				case '[':
				case '{':
					stack.push_back(c);
					break;
				case ')':
				case ']':
				case '}':
					if (stack.empty() || stack.back() != inverse.at(c))
						result = false;
					else
						stack.pop_back();
					break;
				}
			}

			return result && stack.empty();
		}
	};

	using input_t = std::string;
	using output_t = bool;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto input = util::read_value<std::string>(is);
		auto result = util::read_value<bool>(is);
		tests.emplace_back(std::move(input), result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		return s.isValid(input);
	}
}
