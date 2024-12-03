#pragma once

//lib
#include "util.hpp"

//std
#include <vector>

namespace p35 {
	class Solution {
	public:
		int searchInsert(const std::vector<int>& nums, int target) const {
			int64_t a = 0, b = nums.size() - 1, result = -1;
			while (a <= b) {
				int64_t i = (a + b) / 2;
				if (nums[i] < target)
					a = i + 1;
				else if (nums[i] > target)
					b = i - 1;
				else {
					result = i;
					break;
				}
			}
			if (result == -1)
				result = a;
			return result;
		}
	};

	using input_t = std::tuple<std::vector<int>, int>;
	using output_t = int;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto nums = util::read_vector<int>(is);
		auto target = util::read_value<int>(is);
		auto result = util::read_value<int>(is);
		tests.emplace_back(std::make_tuple(nums, target), result);
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		const auto& [nums, target] = input;
		return s.searchInsert(nums, target);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		return output == result;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {}
}
