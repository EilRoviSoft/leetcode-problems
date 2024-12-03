#pragma once
//std
#include <string>
#include <vector>

//src
#include "solution.hpp"

namespace p14 {
	class Solution : public ISolution {
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
}
