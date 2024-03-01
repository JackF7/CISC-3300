/* CISC 1610 - Lab 9
 *
 * This program demonstrates the process of performing file input. The program
 will open a file chosen by the user, call a function, print, and close the 
 file.
 *
 * Jack Forester
 * Last Edited: November 7, 2023
 */
 
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void openInputFile (ifstream& inStream);
//Precondition: instream is not currently associated with a file.
//Asks the user for a file name, then attempts to open the file oninstream with the provided name.
//Exits the program if the file does not exist.

void multAndSum (ifstream& inStream);
//Precondition: instream is associated with a file.
//For each line of numbers in your file, it reads the three numbersin, multiplies them by each other, i.e. 1*2*3 = 6.
//The resulting number is printed out, then it is added to a runningtotal, which is returned after all lines have been processed.

int main () {
    
    ifstream ins; 
    
    openInputFile(ins);
    
    multAndSum (ins); 
    
    ins.close();
    
    return 0;
 }
 
 void openInputFile (ifstream& inStream) {
     
    string fileName;
     
    cout << "Enter a file name: ";
    cin >> fileName;
    inStream.open(fileName);
     
    if (inStream.fail()) {
        cout << "File not found! Exiting program." << endl;
	exit(1);
    }
 }
 
 void multAndSum (ifstream& inStream) {
     
    int num1, num2, num3, product, sum = 0;
    
    while (inStream >> num1 >> num2 >> num3) {
         
        product = num1 * num2 * num3;
        cout << "Current row: " << setw(10) << product << endl;
        sum += product;
    }
     
    cout << "Final result: " << setw(9) << sum << endl;
 }
 
