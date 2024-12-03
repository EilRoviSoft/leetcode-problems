#pragma once

//std
#include <vector>

//src
#include "solution.hpp"

namespace p26 {
	class Solution : public ISolution {
	public:
		int removeDuplicates(std::vector<int>& nums) const {
			std::vector<int> uniques;
			uniques.reserve(nums.size());
			uniques.push_back(nums.front());
			for (size_t i = 1; i != nums.size(); ++i) {
				if (uniques.back() != nums[i])
					uniques.push_back(nums[i]);
			}
			uniques.shrink_to_fit();
			nums = std::move(uniques);
			return nums.size();
		}
	};
}
