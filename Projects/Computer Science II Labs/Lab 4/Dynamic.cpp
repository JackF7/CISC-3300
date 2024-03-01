/* CISC 2010 - Computer Science II Lab
 * Lab 4B - Dynamic Array Mini Lab
 *
 * This program tests knowledge of dynamic arrays.
 *
 * Jack Forester 
 * Last Edited: February 9, 2024
 */

#include <iostream>
using namespace std;

/* A function that reads a sequence of integers from input to fill a dynamically allocated array. For example, if the length is 3, and the numbers are 123 345 99 then the array returned will be of size 3, and stores values 123, 345 and 99.
@param size: upon return, stores the size of the array
@return the pointer pointing to the array
*/

int *ReadNumberSequence (int &size) {
    
	int *array = NULL; // initialize the pointer to NULL
	do {
		cout << "Enter the length of the number sequence: ";
		cin >> size;
	} while (size <= 0);
	
	array = new int[size];
	
	cout << "Enter " << size << " number of elements to store in the array: ";
	for (int i = 0; i < size; i++) {
	    cin >> array[i];
	}
	
	return array;
}

int main() {
    
    int arraySize;
    int *filledArray = NULL;
    
    filledArray = ReadNumberSequence(arraySize);
    
    for (int i = 0; i < arraySize; i++) {
        cout << filledArray[i] << endl;
    }

    delete[] filledArray;
    
    return 0;
}