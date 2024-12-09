#pragma once

//std
#include <climits>
#include <iostream>
#include <stack>
#include <unordered_map>

//lib
#include "lib.hpp"
#include "util.hpp"

namespace p110 {
	class Solution {
		struct iterator_t {
			const TreeNode* ptr;
			int state;
		};
	public:
		bool isBalanced(const TreeNode* root) const {
			bool result = true;

			if (root) {
				std::stack<iterator_t> stack;
				std::unordered_map<TreeNode*, int> heights;

				stack.emplace(root, 0);
				while(!stack.empty()) {
					
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
		return s.isBalanced(input);
	}
	inline void data_destroyer(input_t& input, output_t& output, result_t& result) {
		delete_tree(input);
	}
}
