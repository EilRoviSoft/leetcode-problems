#pragma once

//std
#include <string>
#include <vector>

//lib
#include "util.hpp"

namespace p28 {
	class Solution {
	public:
		int strStr(const std::string& haystack, const std::string& needle) const {
			int64_t result = -1;
			std::vector<size_t> flags, on_remove;

			for (size_t i = 0; i < haystack.size(); ++i) {
				if (haystack[i] == needle.front())
					flags.push_back(i);
				for (size_t j = 0; j != flags.size(); ++j) {
					if (haystack[i] != needle[i - flags[j]])
						on_remove.push_back(j);
					else if (i - flags[j] + 1 == needle.size()) {
						result = flags[j];
						break;
					}
				}
				if (result != -1)
					break;
				for (auto it = on_remove.rbegin(); it != on_remove.rend(); ++it)
					flags.erase(flags.begin() + *it);
				on_remove.clear();
			}

			return result;
		}
	};

	using input_t = std::tuple<std::string, std::string>;
	using output_t = int;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto haystack = util::read_string(is);
		auto needle = util::read_string(is);
		auto result = util::read_value<int>(is);
		tests.emplace_back(std::make_tuple(std::move(haystack), std::move(needle)), result);
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		const auto& [haystack, needle] = input;
		return s.strStr(haystack, needle);
	}
}
