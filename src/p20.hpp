#pragma once

//std
#include <map>
#include <string>
#include <vector>

namespace p20 {
	class Solution {
	public:
		bool isValid(const std::string& s) const {
			bool result = true;
			std::vector <int> stack;
			const std::map<char, char> inverse = {
				{ ')', '(' },
				{ ']', '[' },
				{ '}', '{' }
			};

			for (auto c : s) {
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
		tests.emplace_back(input, result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		auto result = s.isValid(input);
		return result;
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		return output == result;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {}
}
