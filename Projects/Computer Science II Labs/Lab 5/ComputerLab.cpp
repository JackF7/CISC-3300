/* CISC 2010 - Computer Science II Lab
 * Lab 5 - Computer Lab
 *
 * This program 
 *
 * Jack Forester 
 * Last Edited: February 16, 2024
 */

#include <iostream>
using namespace std;

// Type definition
typedef int* IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes

void createArrays(IntPtr labs[], int labSizes[]);
/* Creates the dynamic arrays for the labs.
@param labs: the array of labs,
@param labsizes: contains the size (or number of computers) of each lab
This dictates the size of the dynamic array.

Pre-Condition: labsize[0] is the # of computers in lab1,
               labsize[1] is the # of computers in lab2, ...
Post-condition: labs[0] points to lab1's array (of size given by labsize[0])
      labs[1] points to lab2's array (of size given by labsize[1])
        ...
*/

void freeArrays(IntPtr labs[]);
// Pre-Condition: memory still allocated from "new" function in createArrays.
// Post-Condition: releases allocated memory.

void showLabs(IntPtr labs[], int labSizes[]);
// Pre-Condition: lab status not displayed.
// Post-Condition: displays the status of all labs (who is logged into which computer).

void login(IntPtr labs[], int labSizes[]);
// Simulates a user login by asking for the login info from
// the console.

void logout(IntPtr labs[], int labSizes[]);
// Searches through the arrays for the input user ID and if found
// logs that user out.

void search(IntPtr labs[], int labSizes[]);
// Searches through the arrays for the input user ID and if found
// outputs the station number.

int main()
{
	IntPtr labs[NUMLABS]; 	// store the pointers to the dynamic array for each lab
	int labsizes[NUMLABS];	// Number of computers in each lab
	int choice = -1;
	
	cout <<"Welcome to the LabMonitorProgram!\n";

	// Prompt the user to enter labsizes 
	cout <<"Please enter the number of computer stations in each lab:\n"; 
	for (int i=0; i< NUMLABS; i++)
	{
		do
		{
			cout <<"How many computers in Lab "<< i+1<<"?";
			cin >> labsizes[i]; 
		} while (labsizes[i]<0); 
	}

	// Create ragged array structure
	createArrays(labs, labsizes);

	// Main Menu
	while (choice != 0)
	{
		cout << endl;
		cout << "MAIN MENU" << endl;
		cout << "0) Quit" << endl;
		cout << "1) Simulate login" << endl;
		cout << "2) Simulate logout" << endl;
		cout << "3) Search" << endl;
		cin >> choice;
		if (choice == 1)
		{
			login(labs, labsizes);
			showLabs(labs, labsizes);
		}
		else if (choice == 2)
		{
			logout(labs, labsizes);
			showLabs(labs, labsizes);
		}
		else if (choice == 3)
		{
			search(labs, labsizes);

		}
	}
	freeArrays(labs); // Free memory before exiting
	cout << "Bye!\n";
	return 0;
}

void createArrays(IntPtr labs[], int labSizes[])
{

	for (int i = 0; i < NUMLABS; i++) {
        
		labs[i] = new int[labSizes[i]];

		//An empty lab is indicated by -1
        for (int j = 0; j < labSizes[i]; ++j) 
		{
            labs[i][j] = -1;
        }
	}
}

void freeArrays(IntPtr labs[])
{
	for (int i = 0; i < NUMLABS; i++) 
	{
        delete[] labs[i];
    }
}

/* showLabs:
   Displays the status of all labs (who is logged into which computer).
   Precondition: labs[] is a multidimension array of labs with computers
                 labsizes[i] contains the size of the array in labs[i]
 
 */
void showLabs(IntPtr labs[], int labSizes[])
{

	int i;
	int j;

	cout << "LAB STATUS" << endl;
	cout << "Lab #     Computer Stations" << endl;
	for (i = 0; i < NUMLABS; i++)
	{
		cout << i + 1 << "         ";
		for (j = 0; j < labSizes[i]; j++)
		{
			cout << (j+1) << ": ";
			if (labs[i][j] == -1)
			{
				cout << "empty ";
			}
			else
			{
				cout << labs[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}

void login(IntPtr labs[], int labSizes[])
{
	int userID, labNumber, numComputerStation;

	cout << "Enter the 5 digit ID number of the user logging in:" << endl;
	cin >> userID;
	cout << "Enter the lab number the user is logging in from (1-" << NUMLABS << "):" << endl;
	cin >> labNumber;
	cout << "Enter computer station number the user is logging in to (1-" << labSizes[labNumber - 1] << ") :" << endl;
	cin >> numComputerStation;

	labs[labNumber - 1][numComputerStation - 1] = userID;
}

void logout(IntPtr labs[], int labSizes[])
{
	int userID;

    cout << "Enter the 5 digit ID number of the user logging out: " << endl;
    cin >> userID;
	bool userFound = false;

    // Search for user
    for (int i = 0; i < NUMLABS; i++)
    {
        for (int j = 0; j < labSizes[i]; ++j)
        {
            if (labs[i][j] == userID)
            {
                cout << "Logout user " << userID << " in Lab " << i + 1 << " at computer " << j + 1 << endl;
                labs[i][j] = -1;  // Mark the station as empty after logout
                userFound = true;
            }
        }
    }

	if (!userFound) 
    { cout << "User not logged in." << endl;
	}
}

void search(IntPtr labs[], int labSizes[])
{
	int userID;

    cout << "Enter the 5 digit ID number of the user logging in: " << endl;
    cin >> userID;
	bool userFound = false;

    // Search for user
    for (int i = 0; i < NUMLABS; i++)
    {
        for (int j = 0; j < labSizes[i]; j++)
        {
            if (labs[i][j] == userID)
            {
                cout << "User " << userID << " logged in Lab " << i + 1 << " at computer " << j + 1 << endl;
				userFound = true;
            }
        }
    }

	if (!userFound)
    {
        cout << "User not logged in." << endl;
    }
}

	
