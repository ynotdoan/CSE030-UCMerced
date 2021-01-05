#ifndef MemoryStuff_h
#define MemoryStuff_h

#include <string>
#include <sstream>

// A helper function to convert an integer (decimal value)
// to a hexadecimal representaion saved as a string
std::string decToHex(int x){
	std::stringstream ss;
	ss << std::hex << x;
	std::string res ( ss.str() );

	// Convert the result to upper case so hex values look better
	for (int i = 0; i< res.length(); ++i){
		res[i] = std::toupper(res[i]);
	}
    	
	// If the result is only one digit, add a zero to the front
	// Example: the number 10 in hexadecimal is A
	// so this function will return 0A, which is the same thing
    if (res.size() == 1){
        res = "0" + res;
    }

	return res;
}

std::string memoryContents(int x){
	// Your code here
	std::string fin;

	int* p = &x;
	unsigned char* a = (unsigned char*) p;
	unsigned char* b = (unsigned char*) p + 1;
	unsigned char* c = (unsigned char*) p + 2;
	unsigned char* d = (unsigned char*) p + 3;

	fin = decToHex (*a) + ":" + decToHex (*b) + ":" + decToHex (*c) + ":" + decToHex (*d);

    return fin;
	// The return value above is just a placeholder.
	// Make the function return the appropriate string value.
}

#endif
