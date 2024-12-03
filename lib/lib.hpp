#pragma once

//std
#include <vector>
#include <queue>
#include <stack>

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

bool is_in_range(int val, int lower_bound, int upper_bound) {
	return val >= lower_bound && val <= upper_bound;
}

TreeNode* make_tree(const std::vector<int>& nums) {
	TreeNode* root = nullptr;

	if (!nums.empty()) {
		std::queue<TreeNode*> queue;

		root = new TreeNode(nums.front());
		queue.push(root);

		int i = 1;
		while(i < nums.size()) {
			TreeNode* curr = queue.front();
			queue.pop();

			if (i < nums.size() && is_in_range(nums[i], -100, 100)) {
				curr->left = new TreeNode(nums[i]);
				queue.push(curr->left);
			}
			i++;

			if (i < nums.size() && is_in_range(nums[i], -100, 100)) {
				curr->right = new TreeNode(nums[i]);
				queue.push(curr->right);
			}
			i++;
		}
	}

	return root;
}

void delete_tree(TreeNode* root) {
	TreeNode* curr = root;
	std::stack<TreeNode*> parents_stack;

	while (curr) {
		if (curr->left) {
			parents_stack.push(curr);
			curr = curr->left;
			parents_stack.top()->left = nullptr;
		} else if (curr->right) {
			parents_stack.push(curr);
			curr = curr->right;
			parents_stack.top()->right = nullptr;
		} else {
			delete curr;
			if (!parents_stack.empty()) {
				curr = parents_stack.top();
				parents_stack.pop();
			} else
				curr = nullptr;
		}
	}
}
