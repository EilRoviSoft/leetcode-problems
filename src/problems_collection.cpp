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
#include "p88.hpp"
#include "p94.hpp"
#include "p100.hpp"
#include "p101.hpp"
#include "p104.hpp"
#include "p111.hpp"
#include "p112.hpp"

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

#define ADD_CUSTOM_TESTER(PRID, CLASS_NAME) util::add_solution<p##PRID::##CLASS_NAME, p##PRID::input_t, p##PRID::output_t, p##PRID::result_t>(PRID, p##PRID::test_maker, p##PRID::test_executor, p##PRID::test_checker, p##PRID::data_destroyer)
#define ADD_SOLUTION_TESTER(PRID) ADD_CUSTOM_TESTER(PRID, Solution)

void init_solutions() {
	ADD_SOLUTION_TESTER(1);
	ADD_SOLUTION_TESTER(9);
	ADD_SOLUTION_TESTER(14);
	ADD_SOLUTION_TESTER(20);
	ADD_SOLUTION_TESTER(21);
	ADD_SOLUTION_TESTER(26);
	ADD_SOLUTION_TESTER(27);
	ADD_SOLUTION_TESTER(28);
	ADD_SOLUTION_TESTER(35);
	ADD_SOLUTION_TESTER(58);
	ADD_SOLUTION_TESTER(66);
	ADD_SOLUTION_TESTER(67);
	ADD_SOLUTION_TESTER(69);
	ADD_SOLUTION_TESTER(70);
	ADD_SOLUTION_TESTER(83);
	ADD_SOLUTION_TESTER(88);
	ADD_SOLUTION_TESTER(94);
	ADD_SOLUTION_TESTER(100);
	ADD_SOLUTION_TESTER(101);
	ADD_SOLUTION_TESTER(104);
	ADD_SOLUTION_TESTER(111);
	ADD_SOLUTION_TESTER(112);
}
