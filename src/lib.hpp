#pragma once

//std
#include <vector>

bool is_in_range(int val, int lower_bound, int upper_bound);

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* create_tree(const std::vector<int>& input);
void delete_tree(TreeNode* tree);

struct ListNode {
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}

	int val;
	ListNode* next;
};

ListNode* create_list(const std::vector<int>& input);
void delete_list(ListNode* list);
