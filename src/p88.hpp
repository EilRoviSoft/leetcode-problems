#pragma once

//lib
#include "util.hpp"

namespace p88 {
	class Solution {
	public:
		void merge(std::vector<int>& result, int s1, std::vector<int>& v2, int s2) const {
			auto v1 = std::vector(result.begin(), result.begin() + s1);
			size_t i = 0, j = 0;

			while (i < s1 && j < s2) {
				if (v1[i] >= v2[j]) {
					result[i + j] = v2[j];
					++j;
				} else {
					result[i + j] = v1[i];
					++i;
				}
			}
			while (i < s1) {
				result[i + j] = v1[i];
				++i;
			}
			while (j < s2) {
				result[i + j] = v2[j];
				++j;
			}
		}
	};

	using input_t = std::tuple<std::vector<int>, int, std::vector<int>, int>;
	using output_t = util::none_t;
	using result_t = std::vector<int>;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto v1 = util::read_vector<int>(is);
		auto s1 = util::read_value<int>(is);
		auto v2 = util::read_vector<int>(is);
		auto s2 = util::read_value<int>(is);
		auto result = util::read_vector<int>(is);
		tests.emplace_back(std::make_tuple(v1, s1, v2, s2), result);
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		auto& [v1, s1, v2, s2] = input;
		s.merge(v1, s1, v2, s2);
		return {};
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		auto& [v1, s1, v2, s2] = input;
		return v1 == result;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {}
}