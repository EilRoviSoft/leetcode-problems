#pragma once

//std
#include <vector>

//lib
#include "util.hpp"

namespace p26 {
	class Solution {
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

	using input_t = std::vector<int>;
	using output_t = int;
	using result_t = std::tuple<int, std::vector<int>>;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto input = util::read_vector<int>(is);
		auto size = util::read_value<int>(is);
		auto vec = util::read_vector<int>(is);
		tests.emplace_back(input, std::make_tuple(size, vec));
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		return s.removeDuplicates(input);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		const auto& [size, vec] = result;
		return output == size && input == vec;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {}
}
