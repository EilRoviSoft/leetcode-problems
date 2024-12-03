//std
#include <iostream>

//winapi
#include "Windows.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

//lib files
#include "util.hpp"
#include "lib.hpp"
#include "solution.hpp"

size_t ISolution::active_id = 0;
std::vector<std::tuple<solution_ptr, std::function<void()>>> ISolution::solutions = {};

//problems
#include "problems_collection.hpp"

int main() {
	init_solutions();

	_CrtMemState _old, _new, _dif;
	_CrtMemCheckpoint(&_old);

	ISolution::exec();

	_CrtMemCheckpoint(&_new);
	if (_CrtMemDifference(&_dif, &_old, &_new)) {
		OutputDebugString(L"_CrtMemDumpStatistics:");
		_CrtMemDumpStatistics(&_dif);
		OutputDebugString(L"_CrtMemDumpAllObjectsSince:");
		_CrtMemDumpAllObjectsSince(&_old);
		OutputDebugString(L"_CrtDumpMemoryLeaks:");
		_CrtDumpMemoryLeaks();
	}
}
