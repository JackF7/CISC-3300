/* CISC 2010 - Computer Science II Lab
 * Lab 1 - Inflation Rate Part 2
 *
 * This program calculates and prints out the inflation rate comparing two consumer prices, an extension of Inflation Rate Part 1.
 *
 * Jack Forester 
 * Last Edited: January 19, 2024
 */

#include <iostream>
#include <fstream>
using namespace std;

double calcInflationRate (float old_CPI, float new_CPI, float& total, int& numRates);
// Pre-Condition: the inflation rate of user-input consumer price indices is unknown.
// Post-Condition: returns the inflation rate comparing the old and new consumer price indices.

void newLine (istream& inStream);
// Pre-Condition: Extra spaces or characters remain
// Post-Condition: Clears any extra spaces or characters input by the user

int main() {

    float oldCPI, newCPI, totalRates = 0;
    int numRates = 0;
    char tryAgain;

    do {
        cout << "Enter the old and new consumer price indices: ";
        cin >> oldCPI >> newCPI;

        float rate = calcInflationRate (oldCPI, newCPI, totalRates, numRates);
        cout << "Inflation rate is " << rate << endl; 

        cout << "Try again? (y or Y): ";
        cin >> tryAgain;

    } 
    while (tryAgain == 'y' || tryAgain == 'Y');

    cout << "Average rate is " << (totalRates / numRates);

    return 0;
}

double calcInflationRate (float old_CPI, float new_CPI, float& total, int& numRates) {

    double inflationRate = (((new_CPI - old_CPI) / old_CPI) * 100); 

    if (new_CPI < 0 || old_CPI < 0 || new_CPI == 0 || old_CPI == 0) {

        inflationRate = 0;
    }

    if (inflationRate != 0) {

        total += inflationRate;
        numRates++;
    }
    return inflationRate;
}

void newLine (istream& inStream) {
     char symbol;
     do {
         inStream.get(symbol);
     }  while (symbol != '\n');
} 
