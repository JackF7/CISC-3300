/* CISC 1611 - Computer Science I Lab
 * Lab 3A - Season If
 *
 * This program outputs the season associated with a month number inputted by 
 * the user. Lab 3A is part one of a double lab, wherein this lab will perform
 * the function using if-else statements, while Lab 3B will do the same with
 * switch statements.
 *
 * Jack Forester 
 * Last Edited: September 19, 2023
 */

#include <iostream>
using namespace std;

int main()
{
	int month;

	cout << "Enter a month number between 1 and 12. ";
	cin  >> month;
	
	if (month == 12 || month == 1 || month == 2)
	{	
		cout << "It is winter.\n";
	}
	else if (month == 3 || month == 4 || month == 5)
	{ 
		cout << "It is spring.\n";
	}
	else if (month == 6 || month == 7 || month == 8)
	{
		cout << "It is summer.\n";
	}
	else if (month == 9 || month == 10 || month == 11)
	{
		cout << "It is fall.\n";
	}
	else
	{
		cout << "Invalid month. Please enter a number 1-12.\n";
	}
	return 0;
}
