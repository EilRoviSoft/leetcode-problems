#pragma once

//lib
#include "lib.hpp"
#include "util.hpp"

namespace p21 {
	class Solution {
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

	using input_t = std::tuple<ListNode*, ListNode*>;
	using output_t = ListNode*;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, output_t>& tests) {
		auto list1 = create_list_node(util::read_vector<int>(is));
		auto list2 = create_list_node(util::read_vector<int>(is));
		auto result = create_list_node(util::read_vector<int>(is));
		tests.emplace_back(std::make_tuple(list1, list2), result);
	}
	inline output_t test_executor(const Solution& s, input_t& input) {
		auto [list1, list2] = input;
		return s.mergeTwoLists(list1, list2);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		bool ret = true;
		for (auto it1 = output, it2 = result; it1 && it2; it1 = it1->next, it2 = it2->next)
			if (it1->val != it2->val)
				ret = false;
		return ret;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {
		auto [list1, list2] = input;
		delete_list_node(list1);
		delete_list_node(list2);
		delete_list_node(output);
		delete_list_node(result);
	}
}
