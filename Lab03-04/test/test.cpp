#include "../dep/igloo/igloo.h"
#include "../inc/Arrays.h"
#include "../inc/LinkedList.h"

using namespace igloo;

Context(DefaultConstructorTest){
	Spec(InitialSizeAndCounterTest){
		ResizableArray arr;

		Assert::That(arr.size, Equals(1));
		Assert::That(arr.counter, Equals(0));
	}
};

Context(CopyConstructorTest){
	Spec(EmptyArraysMatch){
		ResizableArray one;
		ResizableArray two;

		Assert::That(one == two, IsTrue());
	}
};

Context(AppendFunctionTest){
	Spec(AppendFiveToEmpty){
		// Hardcode expected value
		ResizableArray expected;
		expected.size = 2;
		expected.counter = 1;
		delete[] expected.data;
		expected.data = new int[2];
		expected.data[0] = 5;

		// Use append function to produce actual value
		ResizableArray actual;
		actual.append(5);

		// Actual should be the same as expected
		Assert::That(actual, Equals(expected));
	}

	Spec(AppendFiveAndSevenToEmpty){
		// Hardcode expected value
		ResizableArray expected;
		expected.size = 4;
		expected.counter = 2;
		delete[] expected.data;
		expected.data = new int[4];
		expected.data[0] = 5;
		expected.data[1] = 7;

		// Use append function to produce actual value
		ResizableArray actual;
		actual.append(5);
		actual.append(7);

		// Actual should be the same as expected
		Assert::That(actual, Equals(expected));
	}

	Spec(AppendFiveSevenAndOneToEmpty){
		// Hardcode expected value
		ResizableArray expected;
		expected.size = 4;
		expected.counter = 3;
		delete[] expected.data;
		expected.data = new int[4];
		expected.data[0] = 5;
		expected.data[1] = 7;
		expected.data[2] = 1;

		// Use append function to produce actual value
		ResizableArray actual;
		actual.append(5);
		actual.append(7);
		actual.append(1);

		// Actual should be the same as expected
		Assert::That(actual, Equals(expected));
	}
	Spec(AppendFiveSevenOneAndSixToEmpty){
		// Hardcode expected value
		ResizableArray expected;
		expected.size = 8;
		expected.counter = 4;
		delete[] expected.data;
		expected.data = new int[8];
		expected.data[0] = 5;
		expected.data[1] = 7;
		expected.data[2] = 1;
		expected.data[3] = 6;

		// Use append function to produce actual value
		ResizableArray actual;
		actual.append(5);
		actual.append(7);
		actual.append(1);
		actual.append(6);

		// Actual should be the same as expected
		Assert::That(actual, Equals(expected));
	}
};

Context(InsertFunctionTest){
	Spec(InsertFiveIntoEmptyAtPositionZero){
		ResizableArray expected;
		expected.append(5);

		ResizableArray actual;
		actual.insert(0, 5);

		Assert::That(actual, Equals(expected));
	}
	// Write some more tests here to convince us that your implementation is correct

	Spec (InsertFourIntoPosOne) {
		ResizableArray expected;
		expected.append (3);
		expected.append (4);
		expected.append (5);

		ResizableArray actual;
		actual.append (3);
		actual.append (5);
		actual.insert (1, 4);

		Assert::That(actual, Equals(expected));
	}


	Spec (InsertOneHundredIntoPosSeven) {
		ResizableArray expected;
		expected.append (21);
		expected.append (533);
		expected.append (0);
		expected.append (68);
		expected.append (3);
		expected.append (9347);
		expected.append (234);
		expected.append (100);
		expected.append (4);
		expected.append (86);
		expected.append (2);

		ResizableArray actual;
		actual.append (21);
		actual.append (533);
		actual.append (0);
		actual.append (68);
		actual.append (3);
		actual.append (9347);
		actual.append (234);
		actual.append (4);
		actual.append (86);
		actual.append (2);
		actual.insert (7, 100);

	}

};

Context(LinkedListInsertFunctionTest) {
    Spec(InsertTwentysevenIntoListAtPositionTen) {
        LinkedList expected;
        expected.append(0);
        expected.append(1);
        expected.append(2);
        expected.append(3);
        expected.append(4);
        expected.append(5);
        expected.append(0);
        expected.append(0);
        expected.append(0);
        expected.append(0);
        expected.append(27);
 
        LinkedList actual;
        actual.append(0);
        actual.append(1);
        actual.append(2);
        actual.append(3);
        actual.append(4);
        actual.append(5);
        actual.insert(10, 27);
    }
	Spec(InsertOneHundredIntoListAtPositionFour) {
        LinkedList expected;
        expected.append(0);
        expected.append(1);
        expected.append(2);
        expected.append(3);
        expected.append(100);
 
        LinkedList actual;
        actual.append(0);
        actual.append(1);
        actual.append(2);
        actual.append(3);
        actual.insert(4, 27);
	}
	Spec(InsertTwoIntoListAtPositionZero) {
        LinkedList expected;
        expected.append(2);
        expected.append(40);
        expected.append(5);
        expected.append(3);
        expected.append(100);
 
        LinkedList actual;
        actual.append(40);
        actual.append(5);
        actual.append(3);
        actual.append(100);
        actual.insert(0, 2);
	}
};

int main() {
	// Run all the tests defined above
	return TestRunner::RunAllTests();
}
