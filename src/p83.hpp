#pragma once

//lib
#include "lib.hpp"
#include "util.hpp"

namespace p83 {
	class Solution {
	public:
		ListNode* deleteDuplicates(const ListNode* head) const {
			ListNode* result = nullptr;

			if (head) {
				int val = head->val;
				const ListNode* it1 = head;
				ListNode* it2;

				result = new ListNode(head->val);
				it2 = result;
				while (it1->next) {
					it1 = it1->next;
					if (val == it1->val)
						continue;
					val = it1->val;
					it2->next = new ListNode(val);
					it2 = it2->next;
				}
			}

			return result;
		}
	};

	using input_t = ListNode*;
	using output_t = ListNode*;
	using result_t = output_t;

	inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {
		auto input = create_list_node(util::read_vector<int>(is));
		auto result = create_list_node(util::read_vector<int>(is));
		tests.emplace_back(input, result);
	}
	inline output_t test_executor(const Solution& s, const input_t& input) {
		return s.deleteDuplicates(input);
	}
	inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {
		bool ret = true;
		for (auto it1 = output, it2 = result; it1 && it2; it1 = it1->next, it2 = it2->next)
			if (it1->val != it2->val)
				ret = false;
		return ret;
	}
	inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {
		delete_list_node(input);
		delete_list_node(output);
		delete_list_node(result);
	}
}
