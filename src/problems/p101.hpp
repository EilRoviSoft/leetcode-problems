#pragma once

//std
#include <iostream>
#include <stack>

//lib
#include "lib.hpp"
#include "util.hpp"

namespace p101 {
	class Solution {
		enum status_t : char { nc, sc, lc, rc };

		struct iterator_t {
			TreeNode* p1, * p2;
			status_t status;
		};
	public:
		bool isSymmetric(TreeNode* root) const {
			bool result = (bool) root->left == (bool) root->right;

			if (result && root->left && root->right) {
				std::stack<iterator_t> stack;

				stack.emplace(root->left, root->right, nc);
				while (result && !stack.empty()) {
					if (stack.top().status < sc) {
						if (stack.top().p1->val != stack.top().p2->val ||
							(bool) stack.top().p1->left != (bool) stack.top().p2->right ||
							(bool) stack.top().p1->right != (bool) stack.top().p2->left) {
							result = false;
							continue;
							}
						stack.top().status = sc;
					}

					if (stack.top().status < lc && stack.top().p1->left && stack.top().p2->right) {
						stack.top().status = lc;
						stack.emplace(stack.top().p1->left, stack.top().p2->right, nc);
					} else if (stack.top().status < rc && stack.top().p1->right && stack.top().p2->left) {
						stack.top().status = rc;
						stack.emplace(stack.top().p1->right, stack.top().p2->left, nc);
					} else
						stack.pop();
				}
			}

			return result;
		}
	};

	using input_t = TreeNode*;
	using output_t = bool;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto input = create_tree(util::read_vector<int>(is));
		auto result = util::read_value<bool>(is);
		tests.emplace_back(input, result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		return s.isSymmetric(input);
	}
	inline void data_destroyer(input_t& input, output_t& output, result_t& result) {
		delete_tree(input);
	}
}
