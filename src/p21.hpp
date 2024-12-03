#pragma once

//lib
#include "lib.hpp"

//src
#include "solution.hpp"

namespace p21 {
	class Solution : public ISolution {
	public:
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) const {
			ListNode* result = nullptr;
			if (list1 || list2) {
				ListNode* curr;
				auto it1 = list1;
				auto it2 = list2;
				auto insert_value = [&it1, &it2]() {
					ListNode* result;
					if (it1 && it2 && it1->val < it2->val || it1 && !it2) {
						result = new ListNode(it1->val);
						it1 = it1->next;
					} else {
						result = new ListNode(it2->val);
						it2 = it2->next;
					}
					return result;
				};

				result = insert_value();
				curr = result;
				while (it1 || it2) {
					curr->next = insert_value();
					curr = curr->next;
				}
			}

			return result;
		}
	};
}
