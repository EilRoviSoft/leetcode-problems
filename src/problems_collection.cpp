#include "problems_collection.hpp"

//lib
#include "util.hpp"

//src
#include "p1.hpp"
#include "p9.hpp"
#include "p14.hpp"
#include "p20.hpp"
#include "p21.hpp"
#include "p26.hpp"
#include "p27.hpp"
#include "p28.hpp"
#include "p35.hpp"
#include "p58.hpp"
#include "p66.hpp"
#include "p67.hpp"
#include "p69.hpp"
#include "p70.hpp"
#include "p83.hpp"

/*
//lib
#include "util.hpp"

using input_t = ;
using output_t = ;
using result_t = output_t;

inline void test_maker(std::istream& is, util::tests_t<input_t, result_t>& tests) {}
inline output_t test_executor(const Solution& s, input_t& input) {}
inline bool test_checker(const input_t& input, const output_t& output, const result_t& result) {}
inline void data_destroyer(const input_t& input, const output_t& output, const result_t& result) {}
*/

#define EXECUTE_SOLUTION_TESTER(PRID) util::exec_solution<p##PRID::Solution, p##PRID::input_t, p##PRID::output_t, p##PRID::result_t>(PRID, p##PRID::test_maker, p##PRID::test_executor, p##PRID::test_checker, p##PRID::data_destroyer)

void init_solutions() {
	EXECUTE_SOLUTION_TESTER(1);
	EXECUTE_SOLUTION_TESTER(9);
	EXECUTE_SOLUTION_TESTER(14);
	EXECUTE_SOLUTION_TESTER(20);
	EXECUTE_SOLUTION_TESTER(21);
	EXECUTE_SOLUTION_TESTER(26);
	EXECUTE_SOLUTION_TESTER(27);
	EXECUTE_SOLUTION_TESTER(28);
	EXECUTE_SOLUTION_TESTER(35);
	EXECUTE_SOLUTION_TESTER(58);
	EXECUTE_SOLUTION_TESTER(66);
	EXECUTE_SOLUTION_TESTER(67);
	EXECUTE_SOLUTION_TESTER(69);
	EXECUTE_SOLUTION_TESTER(70);
	EXECUTE_SOLUTION_TESTER(83);
}
