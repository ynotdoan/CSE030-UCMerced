#include <igloo/igloo.h>
#include <../inc/MemoryStuff.h>

using namespace igloo;

Context(DecimalToHexTest){
	Spec(Seven_07){
		// Check to see if we actually add a 0 in front of a single digit result
		Assert::That(decToHex(7), Equals("07"));
	}

	Spec(Fifteen_0F){
		// Check to see if hex symbols A-F are in upper case
		Assert::That(decToHex(15), Equals("0F"));
	}
	Spec (OneThousandThirtyFour_40A) {
		Assert :: That (decToHex (1034), Equals ("40A")); //added for task1
	}
	Spec (FortyThousandTwoHundredTwentyOne_9D1D) {
		Assert :: That (decToHex (40221), Equals ("9D1D")); //added for task1
	}
};

Context(MemoryContentFunctionTest){
	Spec(ThreeHundredFourteen_00_00_01_3A){
		Assert::That(memoryContents(314), Equals("3A:01:00:00")); 
	}
	// Your code here
	Spec(TwoThousandTwenty_7E4){
		Assert::That(memoryContents(2020), Equals("E4:07:00:00")); //task2
		// Put in the 4 correct values above in place of the xx
	}
	Spec (TenThousandFiftyOne_2743) {
		Assert::That (memoryContents (10051), Equals ("43:27:00:00"));
	}
	Spec (TwoMillionFourHundred_1E8610) {
		Assert::That (memoryContents (2000400), Equals ("10:86:1E:00"));
	}
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
