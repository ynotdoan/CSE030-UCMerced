#ifndef Arrays_h
#define Arrays_h

#include <iostream>
#include <ostream>

struct ResizableArray {
    // This is the poiner to the start of our array
    int* data;
    
    // Keep track of how much memory we have allocated
    int size;
    
    // Keep track of how much memory we have used
    int counter;
    
    // A default constructor
    ResizableArray(){
        // Start off by allocating memory for 1 int
        data = new int[1];
        
        // This means we have allocated for 1
        size = 1;
        
        // And we are currently using 0
        counter = 0;
    }

	// This is a copy constructor. It specifies what happens when
	// the array needs to be copied. In this case it performs
	// a deep copy, which is what we need
	ResizableArray(const ResizableArray& other){
		size = other.size;
		counter = other.counter;
		data = new int[other.size];

		for (int i = 0; i < other.size; i++){
			data[i] = other.data[i];
		}
	}

	// Overloading the == operator. Now we can compare 
	// two ResizableArrays with the == operator
	bool operator==(const ResizableArray rhs) const {
		// If the sizes or counters are different, it's not a match
		if (size != rhs.size){
			return false;
		}
		if (counter != rhs.counter){
			return false;
		}

		// Assume the arrays match
		bool same = true;

		// And try to find a contradiction
		for (int i = 0; i < counter; i++){
			if (data[i] != rhs.data[i]){
				return false;
			}
		}
		
		// Colud not get a contradiction
		return true;
	}
    
    // Print the contents we have
    void print(){
        for (int i = 0; i < counter; i++){
            std::cout << data[i] << std::endl;
        }
    }
    
	// Get the value at a specified position
    int get(int index){
        // Your code here...

        return data[index]; // This is not the actual return value, it's just a placeholder
    }
    
	// Set the value at a specified position with a given integer
    void set(int index, int value){
        // Your code here...
		data[index] = value;
    }

	void insert(int index, int value){
        // Your code here...
		// increase counter
		// counter++;
		// if (counter == size) {
		// 		int notsize = size;
		// 		size = size * 2;
		// 		int* newarr = new int [size];
		// 		for (int i = 0; i < notsize; i++) {
		// 			newarr [i] = data[i];
		// 		}
		// 		delete [] data;
		// 		data = newarr;
		// 	}
		
		if (index > size) {
			int newsize = size;
			// doubles size
			while (index + 1 > newsize) {
				newsize = newsize * 2;
			}
			// points to newsize
			int* newdata = new int [newsize];
			// copy data
			for (int i = 0; i < size; i++) {
				newdata [i] = data [i];
			}
			// reset
			for (int i = index - 1; i > counter - 1; i--) {
				newdata [i] = 0;
			}

			counter = index;
			size = newsize;
			// delete
			delete [] data;
			data = newdata;
			
			data [index] = value;
		}
		else {
			for (int i = counter - 1; i > 0; i--) {
				if (i != index - 1) {
					int temp = data[i];
					data [i + 1] = temp;
				}
			}
		//puts value in index position	
		data [index] = value;

		counter++;
		if (counter == size) {
				int notsize = size;
				size = size * 2;
				int* newdata = new int [size];
				for (int i = 0; i < notsize; i++) {
					newdata [i] = data[i];
				}
				delete [] data;
				data = newdata;
			}
		}
    }
    
    
    // Store a new value in the array
    void append(int value){
        // The very first time this is called
        // we know we have enough storage allocated
        // because we allocated space for 1 int
        // so we store it
        data[counter] = value;
        // and increase the counter
        counter++;
        
        // If we are out of space, i.e. we have
        // stored as much as we have allocated
        // then we need to increase our storage space
        if (counter == size){
            // Just for convenience, store the old size
            int oldSize = size;
            
            // Let's double the amount of storage we have
            size = size * 2;
            
            // Allocate another chunk of memory
            // twice as big as the first
            int* newArr = new int[size];
            
            // Copy all elements from the old location
            // to the new location
            for (int i = 0; i < oldSize; i++) {
                newArr[i] = data[i];
            }
            
            // Release the old location
            delete[] data;
            
            // Make our data pointer point to the new location
            data = newArr;
            
        }
    }
	
	// This is called a destructor. It simply releases the 
	// memory we have been using.
	~ResizableArray(){
		delete[] data;
	}
};

// This is an overload of the << operator, which allows us
// to print out the ResizableArray with cout <<
std::ostream& operator<<(std::ostream& os, const ResizableArray& arr) {
    for (int i = 0; i < arr.counter; i++){
		os << arr.data[i] << " ";
	}
	os << " - counter: " << arr.counter << ", size: " << arr.size << std::endl;

    return os;
}

#endif
