#pragma once

//std
#include <stack>

//src
#include "lib.hpp"
#include "util.hpp"

namespace p100 {
	class Solution {
		enum status_t : char { nc = 0, sc, lc, rc };
		struct iterator_t {
			TreeNode* p1, * p2;
			status_t status;
		};
	public:
		bool isSameTree(TreeNode* n1, TreeNode* n2) const {
			bool result = !n1 && !n2;

			if (n1 && n2) {
				std::stack<iterator_t> stack;

				result = true;
				stack.emplace(n1, n2, nc);
				while (result && !stack.empty()) {
					if (stack.top().status < sc) {
						if (stack.top().p1->val != stack.top().p2->val ||
							(bool) stack.top().p1->left != (bool) stack.top().p2->left ||
							(bool) stack.top().p1->right != (bool) stack.top().p2->right) {
							result = false;
							continue;
							}
						stack.top().status = sc;
					}

					if (stack.top().status < lc && stack.top().p1->left && stack.top().p2->left) {
						stack.top().status = lc;
						stack.emplace(stack.top().p1->left, stack.top().p2->left, nc);
					} else if (stack.top().status < rc && stack.top().p1->right && stack.top().p2->right) {
						stack.top().status = rc;
						stack.emplace(stack.top().p1->right, stack.top().p2->right, nc);
					} else
						stack.pop();
				}
			}

			return result;
		}
	};

	using input_t = std::tuple<TreeNode*, TreeNode*>;
	using output_t = bool;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto n1 = make_tree(util::read_vector<int>(is));
		auto n2 = make_tree(util::read_vector<int>(is));
		auto result = util::read_value<bool>(is);
		tests.emplace_back(std::make_tuple(n1, n2), result);
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		const auto& [n1, n2] = input;
		return s.isSameTree(n1, n2);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		return output == result;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {
		const auto& [n1, n2] = input;
		delete_tree(n1);
		delete_tree(n2);
	}
}
