#pragma once

//std
#include <unordered_map>
#include <vector>

//src
#include "solution.hpp"

namespace p1 {
	class Solution : public ISolution {
	public:
		std::vector<int> twoSum(const std::vector<int>& nums, int target) const {
			std::vector <int> result(2);
			std::unordered_map<int, int> c;

			for (size_t i = 0; i != nums.size(); ++i) {
				auto it = c.find(target - nums[i]);
				if (it != c.end() && it->second != i) {
					result[0] = it->second < i ? it->second : i;
					result[1] = it->second > i ? it->second : i;
					break;
				}
				c[nums[i]] = i;
			}

			return result;
		}
	};
}
