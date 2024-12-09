#include "lib.hpp"

//std
#include <queue>
#include <stack>

bool is_in_range(int val, int lower_bound, int upper_bound)  {
	return val >= lower_bound && val <= upper_bound;
}

TreeNode* create_tree(const std::vector<int>& input) {
	TreeNode* root = nullptr;

	if (!input.empty()) {
		std::queue<TreeNode*> queue;

		root = new TreeNode(input.front());
		queue.push(root);

		int i = 1;
		while(i < input.size()) {
			TreeNode* curr = queue.front();
			queue.pop();

			if (i < input.size() && is_in_range(input[i], -100, 100)) {
				curr->left = new TreeNode(input[i]);
				queue.push(curr->left);
			}
			i++;

			if (i < input.size() && is_in_range(input[i], -100, 100)) {
				curr->right = new TreeNode(input[i]);
				queue.push(curr->right);
			}
			i++;
		}
	}

	return root;
}
void delete_tree(TreeNode* tree) {
	TreeNode* curr = tree;
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

ListNode* create_list(const std::vector<int>& input) {
	ListNode* result = nullptr;

	if (!input.empty()) {
		ListNode* curr;
		auto it = input.begin();

		result = new ListNode(*it);
		curr = result;
		it++;
		for (size_t i = 1; i < input.size(); i++, it++) {
			curr->next = new ListNode(*it);
			curr = curr->next;
		}
	}

	return result;
}
void delete_list(ListNode* list) {
	for (auto it = list; it != nullptr;) {
		auto prev = it;
		it = it->next;
		delete prev;
	}
}


