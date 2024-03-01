/* CISC 1610: - Computer Science I Lab
* 
* Lab 8 - Sin Print or Graph
*
* This program prints and graphs the sin function.
*
* Jack Forester 
* Last Edited: October 31, 2023
*/

#include <iostream>
#include <cmath>
using namespace std;
const double pi = 3.14159265358979323846;

double Degrees2Radians (int maxAngle);
// Converts a number (angle) from degrees to radians.
void Drawline (char characterPrint, int numRepitions);
// Prints a line of characters a specific number of times. Both the character and number of repetitions are input by the user.
void doPrinting (int maxAngle, int angleIncrement, char characterPrint, int numChars);
// Prints the values of sine from 0 to an angle input by the user. The range from 0 to the maximum includes several more angles, increased by a user-input increment. For every angle divisible by 90 degrees, a line of characters is printed using the Drawline function.
void doGraphing (int maxAngle, int angleIncrement);
// Prints a sinusoidal graph with the domain [0, angle input by user], using the character 'X.''
int main () {
    
        cout.setf(ios::fixed);
        cout.setf(ios::showpoint); 
        cout.precision(5); // Values of sin are five decimal places.
        
        int highestAngle;
        int angleIncrement;
        char graphQuestion;
        
        cout << "Perform calculations from angle=0 to what value (in degrees)? ";
        cin >> highestAngle;
        
        cout << "How often should the angle be incremented? ";
        cin >> angleIncrement;

        cout << "Graph it? ";
        cin >> graphQuestion;
        if (graphQuestion == 'N' || graphQuestion == 'n') {
            
            char characterToPrint;
            cout << "Make the line from what character? ";
            cin >> characterToPrint;
            
            int numberOfCharsToPrint;
            cout << "How many characters form a line? ";
            cin >> numberOfCharsToPrint;
            
            doPrinting (highestAngle, angleIncrement, characterToPrint, numberOfCharsToPrint);
        }
        else if (graphQuestion == 'Y' || graphQuestion == 'y') {
            
            doGraphing (highestAngle, angleIncrement);
        }
        
    return 0;
}

double Degrees2Radians (int maxAngle) {
        
    double radians = (maxAngle * pi)/180;
    return (radians);
}       

void Drawline (char characterPrint, int numRepetions) {
    
        for (int i = numRepetions; i > 0; i--) {
                cout << characterPrint;
            }
            cout << endl;
        }
        
void doPrinting (int maxAngle, int angleIncrement, char characterPrint, int numChars) {
    
    int angleInDegrees = 0;
    double angleInRadians = 0;
    double incrementInRadians = Degrees2Radians(angleIncrement);
    
    for (angleInDegrees; angleInDegrees <= maxAngle; angleInDegrees += angleIncrement) // Prints values of sine.
        {
        
        cout << "sin(" << angleInDegrees << ") = " << sin(angleInRadians) << endl;
        if (angleInDegrees % 90 == 0) {
            Drawline (characterPrint, numChars);
        }
        angleInRadians += incrementInRadians;
    }
}
void doGraphing (int maxAngle, int angleIncrement) {
    
    int angleInDegrees = 0;
    double angleInRadians = 0;
    double incrementInRadians = Degrees2Radians(angleIncrement); 
    // Converts the increment to radians.
    double maxAngleInRadians = Degrees2Radians(maxAngle); 
    // Converts the user-input angle to radians.
    
    while (angleInDegrees < maxAngle) {
        
        int spaces = sin(angleInRadians) * 20 + 20;
        for (int i = 0; i<= spaces; i++) {
            cout << ' ';
        }
        cout << 'X' << endl;
        angleInDegrees += angleIncrement;
        angleInRadians += incrementInRadians;
    }
}
 
