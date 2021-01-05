#include <iostream>

using namespace std;

int main(){

	//cout << "Hello World" << endl;

	int x;
	int sum = 0;

	cout << "Pls enter a positive number: " << endl;
	cin >> x;

	for (int i = 0; i <= x; i++) {
		sum += i;
	}

	cout << sum << endl;
	
	return 0;
}
