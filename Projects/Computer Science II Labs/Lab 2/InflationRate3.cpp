/* CISC 2010 - Computer Science II Lab
 * Lab 1 - Inflation Rate Part 3
 *
 * This program calculates the median and average inflation rates and more comparing consumer prices, an extension of Inflation Rate Part 2.
 *
 * Jack Forester 
 * Last Edited: January 26, 2024
 */

#include <iostream>
#include <fstream>
using namespace std;

void getCPIValues (float& old_CPI, float& new_CPI);
// Pre-Condition: user has not input CPIs
// Post-Condition: takes input for new and old CPI

double calcInflationRate (float old_CPI, float new_CPI, float& total);
// Pre-Condition: the inflation rate of user-input consumer price indices is unknown
// Post-Condition: returns the inflation rate comparing the old and new consumer price indices

void selectionSort (double array[], int numRates);
// Pre-Condition: values of the inflation rate array are unsorted
// Post-Condition: the values are sorted in ascending order.

void swapValues (double& num1, double& num2);
// Pre-Condition: arguments have their original values.
// Post-Condition: values are swapped

double findMedianRate (double array[], int numRates);
// Pre-Condition: inflation rate array is unsorted.
// Post-Condition: array is sorted and median value is found.

void newLine (istream& inStream);
// Pre-Condition: Extra spaces or characters remain
// Post-Condition: Clears any extra spaces or characters input by the user

int main() {

    float oldCPI, newCPI, totalRates = 0;
    int numRates = 0;
    const int MAX_RATES = 20;
    char tryAgain;
    double inflationRates[MAX_RATES];

    do {
        getCPIValues (oldCPI, newCPI);

        float rate = calcInflationRate (oldCPI, newCPI, totalRates);
        numRates++;
        inflationRates[numRates - 1] = rate;
        
        cout << "Inflation rate is " << rate << endl; 
        cout << "Try again? (y or Y): ";
        cin >> tryAgain;

    } 
    while (tryAgain == 'y' || tryAgain == 'Y');

    double median = findMedianRate (inflationRates, numRates);

    cout << "Average rate is " << (totalRates / numRates) << endl
         << "Median rate is " << median << endl;

    return 0;
}

void getCPIValues (float& old_CPI, float& new_CPI) {

    do {

        cout << "Enter the old and new consumer price indices: ";
        cin >> old_CPI >> new_CPI;

        if (old_CPI <= 0 || new_CPI <= 0) {
        cout << "Error: CPI values must be greater than 0" << endl;
        }
    } while (old_CPI <= 0 || new_CPI <= 0);
        
}

double calcInflationRate (float old_CPI, float new_CPI, float& total) {

    double inflationRate = (((new_CPI - old_CPI) / old_CPI) * 100); 

    total += inflationRate;

    return inflationRate;
}

void selectionSort (double array[], int numRates) {

    int minIndex;

    for (int i = 0; i < numRates - 1; i++) {

        minIndex = i;

        for (int j = i + 1; j < numRates; j++) {

            if (array[j] < array[minIndex])
                minIndex = j;
        }
        swapValues (array[minIndex], array[i]);
    }
}

void swapValues (double& num1, double& num2) {

        double temp;
        temp = num1;
        num1 = num2;
        num2 = temp;
}

double findMedianRate ( double array[], int numRates) {

    double medianRate;
    int middleNum1, middleNum2;

    selectionSort (array, numRates);

    middleNum1 = numRates/2;

    if (numRates % 2 != 0) {
        medianRate = array[middleNum1];   
    }
    else if (numRates % 2 == 0) {
        middleNum2 = middleNum1 - 1;
        medianRate = ((array[middleNum1]) + (array[middleNum2]))/2;
    }

    return medianRate;
}

void newLine (istream& inStream) {
     char symbol;
     do {
         inStream.get(symbol);
     }  while (symbol != '\n');
} 
