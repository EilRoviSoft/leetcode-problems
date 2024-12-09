#pragma once

//std
#include <iostream>
#include <vector>

//lib
#include "util.hpp"

namespace p27 {
	class Solution {
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

	using input_t = std::tuple<std::vector<int>, int>;
	using output_t = int;
	using result_t = std::tuple<int, std::vector<int>>;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto nums = util::read_vector<int>(is);
		auto val = util::read_value<int>(is);
		auto size = util::read_value<int>(is);
		auto vec = util::read_vector<int>(is);
		tests.emplace_back(std::make_tuple(std::move(nums), val), std::make_tuple(size, std::move(vec)));
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		auto& [nums, val] = input;
		return s.removeElement(nums, val);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		const auto& [nums, val] = input;
		const auto& [size, vec] = result;
		return output == size && util::has_same_values(nums, vec);
	}
}
