
/* CISC 1610: - Computer Science I Lab
 * 
 * Lab 7 - Swap and Mult
 *
 * This program takes user input of two numbers, swaps them, multiplies them by a user-inputted multiplier, and swaps them again.
 *
 * Jack Forester 
 * Last Edited: October 24, 2023
 */

#include <iostream>
using namespace std;

void gets2Ints (int& num1, int& num2);
// Reads in two integers from the user.

void swap (int& num1, int& num2);
// Swap the values of variable1 and variable 2.

void swapAndMult (int& num1, int& num2, int multiplier);
// Multiplies the swapped integers and swaps them again.

int main() {

        int userInt1, userInt2, mult;
        gets2Ints (userInt1, userInt2);
        cout << userInt1 << ' ' << userInt2 << endl;

        swap (userInt1, userInt2);
        cout << "After swap: " << endl
             << userInt1 << ' ' << userInt2 << endl;

        cout << "Enter the multiplier: ";
        cin >> mult;
        cout << mult << endl;

        swapAndMult (userInt1, userInt2, mult);
        cout << "After swap and mult: " << endl
             << userInt1 << ' ' << userInt2 << endl;

        return 0;
}

void gets2Ints (int& num1, int& num2) {

        cout << "Input two numbers: ";
        cin >> num1 >> num2;
}

void swap (int& num1, int& num2) {

        int temp;
        temp = num1;
        num1 = num2;
        num2 = temp;
}

void swapAndMult (int& num1, int& num2, int multiplier) {
        
        num1 *= multiplier;
        num2 *= multiplier;

        swap (num1, num2);
}
