#pragma once

//std
#include <unordered_map>
#include <vector>

//lib
#include "util.hpp"

namespace p1 {
	class Solution {
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

	using input_t = std::tuple<std::vector<int>, int>;
	using output_t = std::vector<int>;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto nums = util::read_vector<int>(is);
		auto target = util::read_value<int>(is);
		auto result = util::read_vector<int>(is);
		tests.emplace_back(std::make_tuple(std::move(nums), target), std::move(result));
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		const auto& [nums, target] = input;
		return s.twoSum(nums, target);
	}
}
