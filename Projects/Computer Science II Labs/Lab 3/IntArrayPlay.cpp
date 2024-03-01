/* CISC 2010 - Computer Science II Lab
 * Lab 1 - Int Array Play
 *
 * This program will utilize many abilities of an array, including searching for, removing, and inserting a value.
 *
 * Jack Forester 
 * Last Edited: February 2, 2024
 */

#include <iostream>
#include <fstream>
using namespace std;

void displayArray (const int array[], int numElements);
// Pre-Condition: array not shown.
// Post-Condition: prints array to the screen.

void fillArray (int array[], int& numElements);
// Pre-Condition: array is empty.
// Post-Condition: array contains values input by user.

bool isArraySorted (const int array[], int& numElements);
// Pre-Condition: unknown if array is sorted.
// Post-Condition: determines if an array is sorted in ascending order, returning true if so and false if not.

int findInsertPosition (const int array[], int numElements, int valueToInsert);
// Pre-Condition: array does not contain user's number.
// Post-Condition: returns index of position to insert user's number. Array still does not contain user's number.

int searchElement (const int array[], int numElements, int numLookingFor);
// Pre-Condition: unknown if user's desired element is in the array.
// Post-Condition: returns the position of the desired element or -1 if not found.

bool removeElement (int array[], int& numElements, int positionToDelete);
// Pre-Condition: array is unchanged.
// Post-Condition: deletes user's desired element if in the array. Returns error message otherwise.

bool insertElement (int array[], int& numElements, int valueToInsert, int positionToInsert);
// Pre-Condition: array is unchanged.
// Post-Condition: removes chosen element and replaces it with user-input number.

const int CAPACITY = 20;

int main () {

    int mainArray[CAPACITY];
    int numElements = 0, insertValue, removeValue;;

    fillArray (mainArray, numElements);
    displayArray (mainArray, numElements);

    cout << "Enter a value to insert: ";
    cin >> insertValue;
    int position = findInsertPosition (mainArray, numElements, insertValue);
    insertElement (mainArray, numElements, insertValue, position);
    displayArray (mainArray, numElements);

    if (bool sorted = isArraySorted (mainArray, numElements)) {
        cout << "Array is sorted" << endl;
    }
    else {
        cout << "Array is not sorted" << endl;
    }
    
    cout << "Enter a value to remove: ";
    cin >> removeValue;
    int positionToRemove = searchElement (mainArray, numElements, removeValue);
    removeElement (mainArray, numElements, positionToRemove);
        
    displayArray (mainArray, numElements);     

    return 0;
}

void displayArray (const int array[], int numElements) {

    for (int i = 0; i < numElements; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void fillArray (int array[], int& numElements) {

    int arrayInput;
    cout << "Enter a list of up to 20 integers or -1 to end the list" << endl;

    for (int i = 0; i < CAPACITY; i++) {

        cin >> arrayInput;
        if (arrayInput == -1) {
            break;
        }

        numElements++;
        array[i] = arrayInput;
    }
}

bool isArraySorted (const int array[], int& numElements) {

    for (int i = 1; i < numElements; i++) {
        if (array[i] < array[i - 1]) {
            return false;
        }
    }
    return true;
}

int findInsertPosition (const int array[], int numElements, int valueToInsert) {
    
    for (int i = 0; i < numElements; i++) {
        if (array[i] > valueToInsert) {
            return (i);
        }
    }

    return (numElements);
}

int searchElement (const int array[], int numElements, int numLookingFor) {
    

    for (int i = 0; i < numElements; i++) {
        if (array[i] == numLookingFor) {
            return (i);
        }
    }

    return (-1);
}

bool removeElement (int array[], int& numElements, int positionToDelete) {

    for (int i = 0; i < numElements; i++) {
        if (i == positionToDelete) {
            break;
        }
    }

    if (positionToDelete == -1) {
        cout << "Error: position out of range: -1" << endl;
        return false;
    }

    for (int i = positionToDelete; i < numElements; i++) {

        array[i] = array[i + 1];
    }
    
    numElements--;
    return true;
} 

bool insertElement (int array[], int& numElements, int valueToInsert, int positionToInsert) {

    if (numElements == CAPACITY) {
        cout << "Error: array is full" << endl;
        return false;
    }

    numElements++;
    for (int i = numElements - 1; i > positionToInsert; i--) {

        array[i] = array[i - 1];
    }

    array[positionToInsert] = valueToInsert;

    return true;
}

