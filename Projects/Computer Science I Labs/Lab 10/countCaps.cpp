/* CISC 1610: - Computer Science I Lab
* 
* Lab 10 - Count Caps
*
* This program demonstrates code using character input, both with file input and user input.
*
* Jack Forester 
* Last Edited: November 14, 2023
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void openFile (ifstream& inStream);
//Precondition: instream is not currently associated with a file.
//Asks the user for a file name, then attempts to open the file oninstream with the provided name.
//Exits the program if the file does not exist.

int countCapitals (istream& inStream);
//Precondition: Total number of capitals = 0.
//Takes in input (from the keyboard or a file) until it reaches a newline character. For each capital letter found in the string, add one to a total number of capitals. 
//Postcondition: Return total number of capitals.

int countCapitals ();
//Precondition: Total number of capitals = 0.
//Takes in string input until it reaches a newline character. For each capital letter found in the string, add one to a total number of capitals. 
//Postcondition: Return total number of capitals.

void newLine (istream& inStream);
//Precondition: There is an extra space ('/n') hanging around.
//Postcondition: The extra space is "eaten."

int main() {
   
   char usingFile;
   ifstream ins;
   int totalCapitals;
   
   cout << "Are you using a file for input? (Y/N): ";
   cin >> usingFile;
  
   while (usingFile != 'Y' && usingFile != 'y' && usingFile != 'N' && usingFile != 'n') {
       cout << "Invalid input - try again.\n"
	    << "Are you using a file for input? (Y/N): ";
       cin >> usingFile;
   }
   
   if (usingFile == 'Y' || usingFile == 'y') {
       
       openFile (ins);
       totalCapitals = countCapitals (ins);
       cout << "The number of capitals in your string is: " << totalCapitals << endl;
   }
   else if (usingFile == 'N' || usingFile == 'n') {
       
       newLine(cin);
       string userString;
       cout << "Enter your string. Press Enter/Return to end: ";
       totalCapitals = countCapitals ();
       cout << "The number of capitals in your string is: " << totalCapitals << endl;
   }
   
   return 0;
}

void openFile (ifstream& inStream) {
     
    string fileName;
    
    cout << "Enter the file name: ";
    cin >> fileName;
    inStream.open(fileName);
     
    if (inStream.fail()) {
        cout << "Error! File not found. Exiting..." << endl;
	exit(1);
    }
 }
 
 int countCapitals (istream& inStream) {
  
    char text;
    int totalCapitals = 0;
    
    while (text != '\n') {
        
        inStream.get(text);
        
        if (isupper(text)) {
            totalCapitals++;
        }        
    }
  
    return (totalCapitals);
 }
 
 int countCapitals () {
  
    char text;
    int totalCapitals = 0;
    while (text != '\n') {
        
        cin.get(text);
        
        if (isupper(text)) {
            totalCapitals++;
        }
    }
    
    return (totalCapitals);
 }
 
 
 void newLine (istream& inStream) {
     char symbol;
     do {
         inStream.get(symbol);
     }  while (symbol != '\n');
} 
