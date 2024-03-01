/* CISC 1610: - Computer Science I Lab
 * 
 * Lab 5 - Campus Travel Game
 *
 * This program is a short computer game wherein the player's goal is to reach
 * Fordham's campus. The code will utilize loops and the program will involve using either a subway, bus, or jetpack to reach campus.
 *
 * Jack Forester 
 * Last Edited: October 3, 2023
 */

#include <iostream>
using namespace std;

int main() {

// Variable Declarations

        int turns = 4;
        int miles = 14;
        int travel;

// Game
	cout << "You are 14 mile(s) from campus!\n";

        while (turns > 0) {   
            if (miles > 0) {
		if (travel == 1 || travel == 2 || travel == 3) {
			cout << "You are " << miles << " mile(s) from campus!\n";
		}
		else {
		}

		cout << "How do you wish to travel? " 
                 << "(1 bus, 2 subway, 3 jetpack) ";
            	cin >> travel;
            
             switch (travel)
                {
                 case 1:
                     miles -= 2;
                     turns--;
		     break;
                  
		 case 2:
		     miles -= 5;
		     turns--;
		     break;
                    
		 case 3:
		     miles -= 10;
		     turns--;
		     break;
                    
		 default:
		     cout << "Invalid choice, try again!\n";
                    }            
              }
              else if (miles <= 0) {
                  turns = 0;
              }
           }

// Game Results

           if (miles == 0) {
                cout << "You are 0 mile(s) from campus!\n"
		     <<	"You have won!\n";
            }
            else if (miles >= 0)
            {   cout << "You are " << miles << " mile(s) from campus!\n"
		     << "You haven't reached your target!\n"
                     << "You lose!\n";
            }
            else if (miles <= 0)
            {   cout << "You have over-shot your target!\n"
                     << "You lose!\n";
            }
return 0;

}
