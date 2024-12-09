#pragma once

//std
#include <iostream>
#include <queue>

//lib
#include "lib.hpp"
#include "util.hpp"

namespace p111 {
	class Solution {
		enum checked_t : char { nc, lc, rc };

		struct iterator_t {
			TreeNode* ptr;
			checked_t status;
		};
	public:
		int minDepth(TreeNode* root) const {
			int result = 0;

			if (root) {
				std::queue<TreeNode*> queue;
				int height = 0;

				queue.push(root);
				while (!queue.empty() && !result) {
					size_t size = queue.size();
					height++;
					for (size_t i = 0; i < size; i++) {
						TreeNode* curr = queue.front();
						queue.pop();
						if (!curr->left && !curr->right) {
							result = height;
							break;
						}
						if (curr->left)
							queue.push(curr->left);
						if (curr->right)
							queue.push(curr->right);
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
		auto input = create_tree(util::read_vector<int>(is));
		auto result = util::read_value<int>(is);
		tests.emplace_back(input, result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		return s.minDepth(input);
	}
	inline void data_destroyer(input_t& input, output_t& output, result_t& result) {
		delete_tree(input);
	}
}
