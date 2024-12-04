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

template<typename _InputType, typename _OutputType, typename _ResultType>
bool standard_checker(const _InputType& input, const _OutputType& output, const _ResultType& result) {
	return output == result;
}
template<typename _InputType, typename _OutputType, typename _ResultType>
void standard_destroyer(const _InputType& input, const _OutputType& output, const _ResultType& result) {}

#define STANDARD_CHECKER(PRID) standard_checker<p##PRID::input_t, p##PRID::output_t, p##PRID::result_t>
#define STANDARD_DESTROYER(PRID) standard_destroyer<p##PRID::input_t, p##PRID::output_t, p##PRID::result_t>

#define ADD_CUSTOM_TESTER(PRID, CLASS_NAME, TEST_MAKER, TEST_EXECUTOR, TEST_CHECKER, DATA_DESTROYER) util::add_solution<p##PRID::##CLASS_NAME, p##PRID::input_t, p##PRID::output_t, p##PRID::result_t>(PRID, TEST_MAKER, TEST_EXECUTOR, TEST_CHECKER, DATA_DESTROYER)

#define ADD_CUSTOM_MECD(PRID, CLASS_NAME) ADD_CUSTOM_TESTER(PRID, CLASS_NAME, p##PRID::test_maker, p##PRID::test_executor, p##PRID::test_checker, p##PRID::data_destroyer)
#define ADD_SOLUTION_MECD(PRID) ADD_CUSTOM_MECD(PRID, Solution)

#define ADD_CUSTOM_MEC(PRID, CLASS_NAME) ADD_CUSTOM_TESTER(PRID, CLASS_NAME, p##PRID::test_maker, p##PRID::test_executor, p##PRID::test_checker, STANDARD_DESTROYER(PRID))
#define ADD_SOLUTION_MEC(PRID) ADD_CUSTOM_MEC(PRID, Solution)

#define ADD_CUSTOM_MED(PRID, CLASS_NAME) ADD_CUSTOM_TESTER(PRID, CLASS_NAME, p##PRID::test_maker, p##PRID::test_executor, STANDARD_CHECKER(PRID), p##PRID::data_destroyer)
#define ADD_SOLUTION_MED(PRID) ADD_CUSTOM_MED(PRID, Solution)

#define ADD_CUSTOM_ME(PRID, CLASS_NAME) ADD_CUSTOM_TESTER(PRID, CLASS_NAME, p##PRID::test_maker, p##PRID::test_executor, STANDARD_CHECKER(PRID), STANDARD_DESTROYER(PRID))
#define ADD_SOLUTION_ME(PRID) ADD_CUSTOM_ME(PRID, Solution)

void init_solutions() {
	ADD_SOLUTION_ME(1);
	ADD_SOLUTION_ME(9);
	ADD_SOLUTION_ME(14);
	ADD_SOLUTION_ME(20);
	ADD_SOLUTION_MECD(21);
	ADD_SOLUTION_MEC(26);
	ADD_SOLUTION_MEC(27);
	ADD_SOLUTION_ME(28);
	ADD_SOLUTION_ME(35);
	ADD_SOLUTION_ME(58);
	ADD_SOLUTION_ME(66);
	ADD_SOLUTION_ME(67);
	ADD_SOLUTION_ME(69);
	ADD_SOLUTION_ME(70);
	ADD_SOLUTION_MECD(83);
	ADD_SOLUTION_MEC(88);
	ADD_SOLUTION_MED(94);
	ADD_SOLUTION_MED(100);
	ADD_SOLUTION_MED(101);
	ADD_SOLUTION_MED(104);
	ADD_SOLUTION_MED(111);
	ADD_SOLUTION_MED(112);
}
