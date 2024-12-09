//std
#include <algorithm>
#include <chrono>
#include <functional>
#include <iostream>
#include <ranges>
#include <unordered_map>

//leetcode files
#include "problems.hpp"
#include "util.hpp"

std::unordered_map<size_t, std::function<ms_duration_t()>> solutions;

int main() {
	init_solutions();

	std::string command;
	std::cout << "write problem id: ";
	std::cin >> command;

	if (command == "all") {
		std::vector<std::pair<size_t, std::function<ms_duration_t()>>> sorted_solutions(solutions.begin(), solutions.end());
		std::ranges::sort(sorted_solutions, [](const auto& lhs, const auto& rhs) {
			return lhs.first < rhs.first;
		});

		for (const auto& [problem_id, func] : sorted_solutions) {
			auto duration = func();
			std::cout << "problem: " << problem_id << "\tis done in " << duration.count() << "\tms\n";
		}
	} else if (auto id = std::stoull(command); solutions.contains(id)) {
		auto duration = solutions[id]();
		std::cout << "problem: " << id << "\tis done in " << duration.count() << "\tms\n";
	} else
		std::cout << "this problem deosn't exist\n";
}
