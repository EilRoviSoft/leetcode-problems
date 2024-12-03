#include "problems_collection.hpp"

//lib
#include "util.hpp"

//problems
#include "p1.hpp"
#include "p9.hpp"
#include "p14.hpp"
#include "p20.hpp"
#include "p21.hpp"
#include "p26.hpp"

/*
ISolution::make_solution<p::Solution>(, [](const p::Solution& s) {
	using input_t = ;
	using output_t = ;

	util::tests_t<input_t, output_t> tests;
	util::read_tests(20, [&](std::istream& is) {
		auto input = ;
		auto result = ;
		tests.emplace_back(input, result);
	});
	util::exec_tests<input_t, output_t>(tests, [&](const input_t& input) {
		auto result = ;
		return result;
	}, [&](const input_t& args, const output_t& output, const output_t& result) {
		return output == result;
	});
});
*/

void init_solutions() {
	ISolution::make_solution<p1::Solution>(1, [](const p1::Solution& s) {
		using input_t = std::tuple<std::vector<int>, int>;
		using output_t = std::vector<int>;
		using result_t = output_t;

		util::tests_t<input_t, output_t> tests;
		util::read_tests(1, [&](std::istream& is) {
			auto nums = util::read_vector<int>(is);
			auto target = util::read_value<int>(is);
			auto result = util::read_vector<int>(is);
			tests.emplace_back(std::make_tuple(nums, target), result);
		});
		util::exec_tests<input_t, output_t, result_t>(tests, [&](const input_t& input) {
			const auto& [nums, target] = input;
			auto result = s.twoSum(nums, target);
			return result;
		}, [&](const input_t& args, const output_t& output, const result_t& result) {
			return output == result;
		});
	});
	ISolution::make_solution<p9::Solution>(9, [](const p9::Solution& s) {
		using input_t = int;
		using output_t = bool;
		using result_t = output_t;

		util::tests_t<input_t, output_t> tests;
		util::read_tests(9, [&](std::istream& is) {
			auto input = util::read_value<int>(is);
			auto result = util::read_value<bool>(is);
			tests.emplace_back(input, result);
		});
		util::exec_tests<input_t, output_t, result_t>(tests, [&](const input_t& input) {
			auto result = s.isPalindrome(input);
			return result;
		}, [&](const input_t& args, const output_t& output, const result_t& result) {
			return output == result;
		});
	});
	ISolution::make_solution<p14::Solution>(14, [](const p14::Solution& s) {
		using input_t = std::vector<std::string>;
		using output_t = std::string;
		using result_t = output_t;

		util::tests_t<input_t, output_t> tests;
		util::read_tests(14, [&](std::istream& is) {
			auto input = util::read_vector<std::string>(is, &util::read_string);
			auto result = util::read_string(is);
			tests.emplace_back(input, result);
		});
		util::exec_tests<input_t, output_t, result_t>(tests, [&](const input_t& input) {
			auto result = s.longestCommonPrefix(input);
			return result;
		}, [&](const input_t& args, const output_t& output, const result_t& result) {
			return output == result;
		});
	});
	ISolution::make_solution<p20::Solution>(20, [](const p20::Solution& s) {
		using input_t = std::string;
		using output_t = bool;
		using result_t = output_t;

		util::tests_t<input_t, output_t> tests;
		util::read_tests(20, [&](std::istream& is) {
			auto input = util::read_value<std::string>(is);
			auto result = util::read_value<bool>(is);
			tests.emplace_back(input, result);
		});
		util::exec_tests<input_t, output_t, result_t>(tests, [&](const input_t& input) {
			auto result = s.isValid(input);
			return result;
		}, [&](const input_t& args, const output_t& output, const result_t& result) {
			return output == result;
		});
	});
	ISolution::make_solution<p21::Solution>(21, [](const p21::Solution& s) {
		using input_t = std::tuple<ListNode*, ListNode*>;
		using output_t = ListNode*;
		using result_t = output_t;

		util::tests_t<input_t, output_t> tests;
		util::read_tests(21, [&](std::istream& is) {
			auto list1 = create_list_node(util::read_vector<int>(is));
			auto list2 = create_list_node(util::read_vector<int>(is));
			auto result = create_list_node(util::read_vector<int>(is));
			tests.emplace_back(std::make_tuple(list1, list2), result);
		});
		util::exec_tests<input_t, output_t, result_t>(tests, [&](const input_t& input) {
			auto [list1, list2] = input;
			auto result = s.mergeTwoLists(list1, list2);
			return result;
		}, [&](const input_t& args, const output_t& output, const result_t& result) {
			bool ret = true;
			for (auto it1 = output, it2 = result; it1 && it2; it1 = it1->next, it2 = it2->next)
				if (it1->val != it2->val)
					ret = false;
			return ret;
		}, [&](const ListNode* output) {
			delete_list_node(output);
		});

		for (auto& [input, result] : tests) {
			auto [list1, list2] = input;
			delete_list_node(list1);
			delete_list_node(list2);
			delete_list_node(result);
		}
	});
	ISolution::make_solution<p26::Solution>(26, [](const p26::Solution& s) {
		using input_t = std::vector<int>;
		using output_t = int;
		using result_t = std::tuple<int, std::vector<int>>;

		util::tests_t<input_t, result_t> tests;
		util::read_tests(26, [&](std::istream& is) {
			auto input = util::read_vector<int>(is);
			auto size = util::read_value<int>(is);
			auto vec = util::read_vector<int>(is);
			tests.emplace_back(input, std::make_tuple(size, vec));
		});
		util::exec_tests<input_t, output_t, result_t>(tests, [&](input_t& input) {
			auto result = s.removeDuplicates(input);
			return result;
		}, [&](const input_t& args, const output_t& output, const result_t& result) {
			const auto& [size, vec] = result;
			return output == size && args == vec;
		});
	});
}
