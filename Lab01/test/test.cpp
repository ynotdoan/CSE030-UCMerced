#include <igloo/igloo.h>
#include <Functions.h>

using namespace igloo;

Context (MaxFunctionsTest) {
	Spec (OneGreaterThanZero) {
		Assert :: That (max (1,0), Equals (1));
	}
	Spec (ZeroLessThanOne) {
		Assert :: That (max (0,1), Equals (1));
	}
	Spec (FiveGreaterThanTwo) {
		Assert :: That (max (5,2), Equals (5));
	}
	Spec (SevenLessThanNine) {
		Assert :: That (max (7,9), Equals (9));
	}
};

Context (EvenFunctionsTest) {
	Spec (TwoIsTrue) {
		Assert :: That (even (2), Equals (true));
	}
	Spec (FourIsTrue) {
		Assert :: That (even (4), Equals (true));
	}
	Spec (SevenIsFalse) {
		Assert :: That (even (7), Equals (false));
	}
	Spec (EighteenIsTrue) {
		Assert :: That (even (18), Equals (true));
	}
	Spec (TwentySevenIsFalse) {
		Assert :: That (even (27), Equals (false));
	}
	Spec (OneHundredSixtyThreeIsFalse) {
		Assert :: That (even (163), Equals (false));
	}
	Spec (NegEightySixIsTrue) {
		Assert :: That (even (-86), Equals (true));
	}
};

Context (SumFunctionsTest) {
	Spec (SumThreeIsSix) {
		Assert :: That (sum (3), Equals (6));
	}
	Spec (SumTenIsFiftyFive) {
		Assert :: That (sum (10) , Equals (55));
	}
	Spec (SumOneHundredIsFiveThousandFifty) {
		Assert :: That (sum (100), Equals (5050));
	}
	Spec (NegNineIsNotValid) {
		Assert :: That (sum (-9), Equals (0));
	}
	Spec (ZeroIsZero) {
		Assert :: That (sum (0), Equals (0));
	}
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
