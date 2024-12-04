#pragma once

//src
#include "lib.hpp"
#include "util.hpp"

namespace p112 {
	class Solution {
	public:
		bool hasPathSum(TreeNode* root, int target_sum) const {
			return false;
		}
	};

	using input_t = std::tuple<TreeNode*, int>;
	using output_t = bool;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto root = make_tree(util::read_vector<int>(is));
		auto target_sum = util::read_value<int>(is);
		auto result = util::read_value<int>(is);
		tests.emplace_back(std::make_tuple(root, target_sum), result);
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		const auto& [root, target_sum] = input;
		return s.hasPathSum(root, target_sum);
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {
		const auto& [root, target_sum] = input;
		delete_tree(root);
	}
}
