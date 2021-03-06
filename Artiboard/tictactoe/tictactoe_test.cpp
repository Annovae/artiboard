#include <tut/tut.hpp>
#include <exception>
#include <memory>
#include <test_util.h>
#include "tictactoe.h"

#define UTEST template<> template<> void test_group<tictacTestData>::object::test

namespace tut {
	using namespace std;
	using namespace arti;

	struct tictacTestData {
	};

	test_group<tictacTestData> tictactoeTests("016 Tictactoe Tests");


	UTEST <1>() {
		set_test_name("TictacToe Play");
		TicTacToeSpecification spec;
		PickFirst picker;
		Match match(spec,picker);
		match.play();
		std::cout << match;
		ensure("not enough moves made",match.line().sequence().size() > 1);
		ensure_equals(match.outcome(), MatchOutcome::SouthPlayerWins);
	}}
