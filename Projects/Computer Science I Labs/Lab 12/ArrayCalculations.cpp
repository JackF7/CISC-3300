/* CISC 1610: - Computer Science I Lab
* 
* Lab 12 - Array Calculatios
*
* This program practices using partially filled arrays and calculates the minimum, maximum, sum, and average of a user-input array.
*
* Jack Forester 
* Last Edited: November 28, 2023
*/
#include <iostream>
using namespace std;

void initializeArray (int a[], int size, int& numberUsed);
// Pre-Condition: array a of maximum size 50 is empty.
// Post-Condition: array is partially filled (can be completely filled) with user input. 

void display (const int a[], int numberUsed);
// Pre-Condition: array a is not shown.
// Post-Condition: all numbers in array a are printed.

void calculations (const int a[], int numberUsed, int& min, int& max, int& sum, double& avg);
// Pre-Condition: minimum, maximum, sum, and average of array a are unknown.
// Pre-Condition: minimum, maximum, sum, and average are printed.

bool search (const int a[], int numberUsed, int& numLookingFor);
// Pre-Condition: bool found is false.
// Post-Condition: returns bool found based on whether the user's inputted number is in the array a.

int numFrequency (const int a[], int numberUsed, int& numWondering);
// Pre-Condition: frequency of user's inputted number in array a is unknown.
// Post-Condition: returns frequency

int main() {
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    const int size = 50;
    int a[size];
    int numberUsed, numLookingFor, numWondering, minimum, maximum, numSum;
    double average;
    
// Input Integers for Array

    initializeArray(a, size, numberUsed);
    
// Display Array    

    display (a, numberUsed);
    
// Calculations
    
    calculations (a, numberUsed, minimum, maximum, numSum, average);
    cout << "The minimum value in the array is " << minimum << endl
         << "The maximum value in the array is " << maximum << endl
         << "The sum of all the elements in the array is " << numSum << endl
         << "The average of all the elements in the array is " << average << endl;
    
// Search for Number

    cout << "Please enter the value you want to search in the array: ";
    cin >> numLookingFor;
    
    bool found = search (a, numberUsed, numLookingFor);
    if (found == true) {
        cout << "Find your target " << numLookingFor << endl;
    }
    else if (found == false) {
        cout << "Could not find " << numLookingFor << endl;
    }
    
// Frequency of Number

    cout << "Please enter the value you want to know the frequency of: ";
    cin >> numWondering;
    
    int frequency = numFrequency (a, numberUsed, numWondering);
    cout << "The number " << numWondering << " has occured " << frequency << " time(s) in the array\n"; 
    
    return 0;
}

void initializeArray (int a[], int size, int& numberUsed) {
    
    cout << "Please enter up to " << size << " non-negative whole numbers separated by space.\n"
         << "Mark the end of the input list with a negative number:\n";
    int next, index = 0;
    cin >> next;
    while (next >= 0 && index < size) {
        
        a[index] = next;
        index++;
        cin >> next;
    }
    numberUsed = index;
}

void display (const int a[], int numberUsed) {
    
    for (int i = 0; i < numberUsed; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void calculations (const int a[], int numberUsed, int& min, int& max, int& sum, double& avg) {
    
// Minimum Calculation    
    min = a[0];
    
    for (int i = 0; i < numberUsed; i++) {
        if (a[i] < min) {
            min = a[i];
        }
    }
    
// Maximum Calculation
    
    max = a[0];
    
    for (int i = 0; i < numberUsed; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

// Sum Calculation
    
    sum = a[0];
    
    for (int i = 1; i < numberUsed; i++) {
        sum += a[i];
    }
    
// Average Calculation

    avg = (1.0 *sum)/numberUsed;
}

bool search (const int a[], int numberUsed, int& numLookingFor) {
    
    bool found = false;
    for (int i = 0; i < numberUsed; i++) {
        if (a[i] == numLookingFor) {
            found = true;
            break;
        }
    }
    return found;
}

int numFrequency (const int a[], int numberUsed, int& numWondering) {
    
    int freq = 0;
    for (int i = 0; i < numberUsed; i++) {
        if (a[i] == numWondering) {
            freq++;
        }
    }
    return freq;
}
