#pragma once

//std
#include <string>

//lib
#include "util.hpp"

namespace p67 {
	class Solution {
	public:
		std::string addBinary(const std::string& a, const std::string& b) const {
			std::string result;
			size_t carry = 0, min_size, max_size, diff_size;
			const std::string* max, * min;
			bool new_digit_flag;
			auto f = [](const std::string& s, size_t i) { return s[i] - '0'; };

			if (a.size() > b.size()) {
				max = &a;
				min = &b;
			} else {
				max = &b;
				min = &a;
			}
			max_size = max->size();
			min_size = min->size();
			diff_size = max_size - min_size;
			result.resize(max_size, '0');
			for (int64_t i = max_size - 1; i >= int64_t(max_size - min_size); --i) {
				const size_t sum = f(*max, i) + f(*min, i - diff_size) + carry;
				result[i] = sum % 2 + '0';
				carry = sum / 2;
			}
			for (int64_t i = max_size - min_size - 1; i >= 0; --i) {
				const size_t sum = f(*max, i) + carry;
				result[i] = sum % 2 + '0';
				carry = sum / 2;
			}
			if (carry)
				result.insert(result.begin(), '1');

			return result;
		}
	};

	using input_t = std::tuple<std::string, std::string>;
	using output_t = std::string;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto a = util::read_string(is);
		auto b = util::read_string(is);
		auto result = util::read_string(is);
		tests.emplace_back(std::make_tuple(a, b), result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		const auto& [a, b] = input;
		return s.addBinary(a, b);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		return output == result;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {}
}
