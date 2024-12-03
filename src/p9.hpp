#pragma once
//std
#include <cstdint>

//src
#include "solution.hpp"

namespace p9 {
	class Solution : public ISolution {
	public:
		bool isPalindrome(int x) const {
			bool result = true;

			if (x < 0) {
				result = false;
			} else if (x < 10) {
				result = true;
			} else {
				size_t cpy = x, i0 = 1, i1 = 1, m1 = 1;
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
}
