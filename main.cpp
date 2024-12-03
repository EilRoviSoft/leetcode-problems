//std
#include <iostream>

//winapi
#include "Windows.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

//lib files
#include "util.hpp"

//problems
#include "problems_collection.hpp"

std::unordered_map<size_t, std::function<void()>> solutions;

int main() {
	init_solutions();

	std::string command;
	std::cout << "write problem id: ";
	std::cin >> command;

	/*_CrtMemState _old, _new, _dif;
	_CrtMemCheckpoint(&_old);*/

	if (command == "all") {
		for (const auto& [problem_id, func] : solutions) {
			func();
			std::cout << "problem: " << problem_id << " is done\n";
		}
	} else if (auto id = std::stoull(command); solutions.contains(id))
		solutions[id]();

	solutions.clear();

	/*_CrtMemCheckpoint(&_new);
	if (_CrtMemDifference(&_dif, &_old, &_new)) {
		OutputDebugString(L"_CrtMemDumpStatistics:");
		_CrtMemDumpStatistics(&_dif);
		OutputDebugString(L"_CrtMemDumpAllObjectsSince:");
		_CrtMemDumpAllObjectsSince(&_old);
		OutputDebugString(L"_CrtDumpMemoryLeaks:");
		_CrtDumpMemoryLeaks();
	}*/
}
