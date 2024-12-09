#pragma once

//std
#include <cstdint>
#include <iostream>

//lib
#include "util.hpp"

 namespace p9 {
	class Solution {
	public:
		bool isPalindrome(int x) const {
			bool result = true;

			if (x < 0) {
				result = false;
			} else if (x < 10) {
				result = true;
			} else {
				int cpy = x, i0 = 1, i1 = 1, m1 = 1;
				while (cpy >= 10) {
					cpy /= 10;
					++i1;
					m1 *= 10;
				}

				while (i1 >= i0) {
					int a0 = x % 10,
						a1 = x / m1;
					if (a0 != a1) {
						result = false;
						break;
					}
					++i0;
					--i1;
					x = (x - (x / m1) * m1) / 10;
					m1 /= 100;
				}
			}

			return result;
		}
	};

	using input_t = int;
	using output_t = bool;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto input = util::read_value<int>(is);
		auto result = util::read_value<bool>(is);
		tests.emplace_back(input, result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		return s.isPalindrome(input);
	}
}
