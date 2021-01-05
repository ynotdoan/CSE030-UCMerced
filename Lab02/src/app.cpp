#include <iostream>
#include "../inc/MemoryStuff.h"

using namespace std;

int main (int num){
    // Your code here
	//task 5

	cout << "Please enter an int: ";
	cin >> num;

	cout << "Here are the memory contents for the int " << num << ": " << memoryContents (num) << endl;
    
    return 0;
}
