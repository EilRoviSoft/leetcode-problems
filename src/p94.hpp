#pragma once

//std
#include <stack>

//src
#include "lib.hpp"
#include "util.hpp"

namespace p94 {
	class Solution {
		enum Status : char { nc = 'u', lc = 'l', rc = 'r' };
		struct iterator {
			TreeNode* ptr;
			Status status;
		};

	public:
		std::vector<int> inorderTraversal(TreeNode* root) const {
			std::vector<int> result;
			if (root) {
				std::stack<iterator> stack;
				stack.emplace(root, nc);
				while (!stack.empty()) {
					if (stack.top().ptr->left && stack.top().status == nc) {
						stack.top().status = lc;
						stack.emplace(stack.top().ptr->left, nc);
					} else if (stack.top().ptr->right && stack.top().status != rc) {
						if (stack.top().status != rc)
							result.push_back(stack.top().ptr->val);
						stack.top().status = rc;
						stack.emplace(stack.top().ptr->right, nc);
					} else {
						if (stack.top().status != rc)
							result.push_back(stack.top().ptr->val);
						stack.pop();
					}
				}
			}

			return result;
		}
	};

	using input_t = TreeNode*;
	using output_t = std::vector<int>;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto input = make_tree(util::read_vector<int>(is));
		auto result = util::read_vector<int>(is);
		tests.emplace_back(input, result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		return s.inorderTraversal(input);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		return output == result;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {
		delete_tree(input);
	}
}
