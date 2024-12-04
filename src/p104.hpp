#pragma once

//std
#include <stack>

//src
#include "lib.hpp"
#include "util.hpp"

namespace p104 {
	class Solution {
		enum checked_t : char { nc, lc, rc };

		struct iterator_t {
			TreeNode* ptr;
			checked_t status;
		};
	public:
		int maxDepth(TreeNode* root) const {
			int result = 0;

			if (root) {
				std::stack<iterator_t> stack;

				stack.emplace(root, nc);
				while (!stack.empty()) {
					if (stack.top().status < lc && stack.top().ptr->left) {
						stack.top().status = lc;
						stack.emplace(stack.top().ptr->left, nc);
					} else if (stack.top().status < rc && stack.top().ptr->right) {
						stack.top().status = rc;
						stack.emplace(stack.top().ptr->right, nc);
					} else {
						if (stack.size() > result)
							result = stack.size();
						stack.pop();
					}
				}
			}

			return result;
		}
	};

	using input_t = TreeNode*;
	using output_t = int;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto input = make_tree(util::read_vector<int>(is));
		auto result = util::read_value<int>(is);
		tests.emplace_back(input, result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		return s.maxDepth(input);
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {
		delete_tree(input);
	}
}
