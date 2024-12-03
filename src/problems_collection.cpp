#include "problems_collection.hpp"

//lib
#include "util.hpp"

//problems
#include "p1.hpp"
#include "p9.hpp"
#include "p14.hpp"

void init_solutions() {
	ISolution::make_solution<p1::Solution>([](const p1::Solution& s) {
		using input_t = std::tuple<std::vector<int>, int>;
		using output_t = std::vector<int>;

		util::tests_t<input_t, output_t> tests;
		util::read_tests(1, [&](std::istream& is) {
			auto nums = util::read_vector<int>(is);
			auto target = util::read_value<int>(is);
			auto result = util::read_vector<int>(is);
			tests.emplace_back(std::make_tuple(nums, target), result);
		});
		util::exec_tests<input_t, output_t>(tests, [&](const input_t& input) {
			const auto& [nums, target] = input;
			auto result = s.twoSum(nums, target);
			return result;
		}, [&](const input_t& args, const output_t& output, const output_t& result) {
			return output == result;
		});
	});
	ISolution::make_solution<p9::Solution>([](const p9::Solution& s) {
		using input_t = int;
		using output_t = bool;

		util::tests_t<input_t, output_t> tests;
		util::read_tests(9, [&](std::istream& is) {
			auto x = util::read_value<int>(is);
			auto result = util::read_value<bool>(is);
			tests.emplace_back(x, result);
		});
		util::exec_tests<input_t, output_t>(tests, [&](const input_t& x) {
			auto result = s.isPalindrome(x);
			return result;
		}, [&](const input_t& args, const output_t& output, const output_t& result) {
			return output == result;
		});
	});
	ISolution::make_solution<p14::Solution>([](const p14::Solution& s) {
		using input_t = std::vector<std::string>;
		using output_t = std::string;

		util::tests_t<input_t, output_t> tests;
		util::read_tests(14, [&](std::istream& is) {
			auto lines = util::read_vector<std::string>(is, &util::read_string);
			auto result = util::read_string(is);
			tests.emplace_back(lines, result);
		});
		util::exec_tests<input_t, output_t>(tests, [&](const input_t& lines) {
			auto result = s.longestCommonPrefix(lines);
			return result;
		}, [&](const input_t& args, const output_t& output, const output_t& result) {
			return output == result;
		});
	});

	ISolution::set_active(0);
}
