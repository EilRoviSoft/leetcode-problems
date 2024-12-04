#pragma once

//lib
#include "util.hpp"

namespace p70 {
	class Solution {
	public:
		int climbStairs(int n) const {
			int result = 0;

			if (n == 1 || n == 2) {
				result = n;
			} else {
				int n0 = 1, n1 = 2;
				for (int i = 3; i <= n; ++i) {
					auto t = n1;
					n1 += n0;
					n0 = t;
				}
				result = n1;
			}

			return result;
		}
	};

	using input_t = int;
	using output_t = int;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto input = util::read_value<int>(is);
		auto result = util::read_value<int>(is);
		tests.emplace_back(input, result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		return s.climbStairs(input);
	}
}
