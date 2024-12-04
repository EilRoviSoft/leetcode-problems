#pragma once

//std
#include <queue>

//src
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
				bool is_done = false;
				std::queue<TreeNode*> queue;

				queue.push(root);
				while (!queue.empty() && !is_done) {
					size_t size = queue.size();
					result++;
					for (size_t i = 0; i < size; i++) {
						TreeNode* curr = queue.front();
						queue.pop();
						if (!curr->left && !curr->right) {
							is_done = true;
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
		auto input = make_tree(util::read_vector<int>(is));
		auto result = util::read_value<int>(is);
		tests.emplace_back(input, result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		return s.minDepth(input);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		return output == result;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {
		delete_tree(input);
	}
}
