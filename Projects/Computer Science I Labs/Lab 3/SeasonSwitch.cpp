/* CISC 1611 - Computer Science I Lab
 * Lab 3B - Season Switch
 *
 * This program outputs the season associated with a month number inputted by 
 * the user. Lab 3B is part one of a double lab, wherein this lab will perform
 * the function using switch statements, while Lab 3A will do the same with
 * if-else statements.
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
	
	switch (month)
	{	case 12:
		case 1:
		case 2:
			cout << "It is winter.\n";
			break;
		case 3:
		case 4:
		case 5:
			cout << "It is spring.\n";
			break;
		case 6:
		case 7:
		case 8:
			cout << "It is summer.\n";
			break;
		case 9:
		case 10:
		case 11:
			cout << "It is fall.\n";
			break;
		default:
		cout << "Invalid month. Please enter a number 1-12.\n";
	}
	return 0;
}
