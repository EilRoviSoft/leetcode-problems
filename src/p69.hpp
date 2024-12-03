#pragma once

//std
#include <istream>

//lib
#include "util.hpp"

namespace p69 {
	class Solution {
	public:
		int mySqrt(int x) const {
			int result = -1;
			int64_t a = 2, b = x;
			auto f = [](int64_t a, int64_t b) { return (a + b) / 2; };

			if (x > 1) {
				for (int64_t i = f(a, b); a <= b; i = f(a, b)) {
					int64_t diff = i * i - x;
					if (diff > 0)
						b = i - 1;
					else if (diff < 0)
						a = i + 1;
					else {
						result = i;
						break;
					}
				}
				if (result == -1)
					result = b;
			} else
				result = x;
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
		return s.mySqrt(input);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		return output == result;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {}
}
