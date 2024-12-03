#pragma once
//std
#include <map>
#include <string>
#include <vector>

//src
#include "solution.hpp"

namespace p20 {
	class Solution : public ISolution {
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
				switch(c) {
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
}
