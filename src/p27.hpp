#pragma once

//std
#include <vector>

//src
#include "solution.hpp"

namespace p27 {
	class Solution : public ISolution {
	public:
		int removeElement(std::vector<int>& nums, int val) const {
			std::vector<int> result;
			size_t size = 0;

			for (const auto& it : nums) {
				if (it != val)
					++size;
			}
			result.reserve(size);
			for (const auto& it : nums) {
				if (it != val)
					result.push_back(it);
			}

			nums = result;
			return nums.size();
		}
	};
}
