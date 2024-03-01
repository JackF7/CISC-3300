/* CISC 1611 - Computer Science I Lab
 * Lab 2 - Coffee Shop
 *
 * This program takes an order from a customer, computers the total charge, 
 calculates their change, and prints a receipt.
 * 
 *
 * Jack Forester 
 * Last Edited: September 18, 2023
 */

#include <iostream>
using namespace std;

int main()
{
 	cout.setf(ios::fixed);
        cout.setf(ios::showpoint);
        cout.precision(2);

// Welcoming The Customer
	
	string firstName;
	
	cout << "Welcome to Jack's Coffee Shop!\n"
		"What is your first name? ";
	cin >> firstName;
	cout << "Welcome, " + firstName + "!\n";

// Order Information - Questions and Inputs
	
	int numCoffees, numBagels, numDonuts;
	
	cout << "How many coffees would you like, " + firstName + "? ";
	cin >> numCoffees;
	cout << "How many bagels would you like? ";
	cin >> numBagels;
	cout << "How many donuts would you like? ";
	cin >> numDonuts;	

// Calculating Customer's Total and Change
	
	double amtPaid;
	double total = (1.085 * (numCoffees * 2.5 + numBagels * 1.75 + numDonuts));
	
	cout << "Your total is $" << total << ".\n";
	cout << "How much will you pay? $";
	cin >>  amtPaid;
	
	double change = amtPaid - total;

// Receipt - Items, Total, and Change

	cout << "Receipt for " << firstName << ":\n"
	     << "Coffees: " << numCoffees << "\n"
	     << "Bagels: " << numBagels << "\n"
	     << "Donuts: " << numDonuts << "\n"
	     << "Your total is $" << total << ".\n"
	     << "Your change is $" << change << ".\n";

	return 0;
}
