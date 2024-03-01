/* CISC 2010 - Computer Science II Lab
 * Lab 0 - Inflation Rate Part 1
 *
 * This program calculates and prints out the inflation rate comparing two consumer prices.
 *
 * Jack Forester 
 * Last Edited: January 19, 2024
 */

#include <iostream>
#include <fstream>
using namespace std;

double calcInflationRate (float old_CPI, float new_CPI);
// Pre-Condition: the inflation rate of user-input consumer price indices is unknown.
// Post-Condition: returns the inflation rate comparing the old and new consumer price indices.

void newLine (istream& inStream);
// Pre-Condition: Extra spaces or characters remain
// Post-Condition: Clears any extra spaces or characters input by the user

int main() {

    float oldCPI, newCPI; 

    cout << "Enter the old and new consumer price indices: ";
    cin >> oldCPI >> newCPI;

    float rate = calcInflationRate (oldCPI, newCPI);
    cout << "Inflation rate is " << rate;

    return 0;
}

double calcInflationRate (float old_CPI, float new_CPI) {

    double inflationRate = (((new_CPI - old_CPI) / old_CPI) * 100); 

    if (new_CPI < 0 || old_CPI < 0 || new_CPI == 0 || old_CPI == 0) {

        inflationRate = 0;
    }

    return inflationRate;
}

void newLine (istream& inStream) {
     char symbol;
     do {
         inStream.get(symbol);
     }  while (symbol != '\n');
} 
