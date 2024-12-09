#pragma once

//std
#include <iostream>
#include <stack>

//lib
#include "lib.hpp"
#include "util.hpp"

namespace p112 {
	class Solution {
		enum Status : char { nc = 'u', lc = 'l', rc = 'r' };
		struct iterator {
			const TreeNode* ptr;
			Status status;
			int sum = 0;
		};

	public:
		bool hasPathSum(const TreeNode* root, int target_sum) const {
			bool result = false;

			if (root) {
				std::stack<iterator> stack;
				stack.emplace(root, nc, root->val);
				while (!stack.empty()) {
					if (stack.top().ptr->left && stack.top().status == nc) {
						stack.top().status = lc;
						stack.emplace(stack.top().ptr->left, nc, stack.top().sum + stack.top().ptr->left->val);
					} else if (stack.top().ptr->right && stack.top().status != rc) {
						stack.top().status = rc;
						stack.emplace(stack.top().ptr->right, nc, stack.top().sum + stack.top().ptr->right->val);
					} else {
						if (!stack.top().ptr->left && !stack.top().ptr->right && stack.top().sum == target_sum) {
							result = true;
							break;
						}
						stack.pop();
					}
				}
			}

			return result;
		}
	};

	using input_t = std::tuple<TreeNode*, int>;
	using output_t = bool;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto root = create_tree(util::read_vector<int>(is));
		auto target_sum = util::read_value<int>(is);
		auto result = util::read_value<int>(is);
		tests.emplace_back(std::make_tuple(root, target_sum), result);
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		const auto& [root, target_sum] = input;
		return s.hasPathSum(root, target_sum);
	}
	inline void data_destroyer(input_t& input, output_t& output, result_t& result) {
		const auto& [root, target_sum] = input;
		delete_tree(root);
	}
}
