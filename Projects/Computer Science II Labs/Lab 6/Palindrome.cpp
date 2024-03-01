/* CISC 2010 - Computer Science II Lab
 * Lab 6 - Palindrome
 *
 * This program determines if a string is a palindrome.
 *
 * Jack Forester 
 * Last Edited: February 23, 2024
 */

 /*First, create a clean version of the string. 
 *  	- convert all characters to lower case.
 *  	- remove all punctuation.
 * 
 *  Second, create a reverse version of the string.
 *   - use reverse and swap from our lab assignment
 *   so first make a copy of the string and pass in
 *   the copy to reverse.
 *   
 *  Third
 *  	- compare the two strings 
 *  		if they are the same, palindrome.
 *  		else, not palindrome.
 */

#include <iostream>
#include <vector>
#include <cctype>
#include <string>
using namespace std;

string removePunct(string str);
// Precondition: a string that may or may not have punctuation.
// Postcondition: returns a (possibly shorter) string with punctuaton
// removed.

string convertToLower(string str);
// Precondition: a string that may have mixed case in it.
// Postcondition: returns a lowercase string

string reverse(string str);
// Precondition: a string to be reversed
// Postcondition: returns a string that is the
// reverse of the input string.

void display(vector<string> vstrings);
// Precondition: a vector of strings to print
// Postcondition: strings are printed one per line.

bool isPalindrome(string str);
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome
// returns false otherwise.

int main() {

    vector<string> palindromes, notPalindromes;
    string keepGoing;

    do {
        cout << "Enter your palindrome or type quit:" << endl;
        getline (cin, keepGoing);

        if (isPalindrome(keepGoing)) {
            palindromes.push_back(keepGoing);
        }
        else if (keepGoing == "quit" || keepGoing == "Quit"){
            break;
        }
        else {
            notPalindromes.push_back(keepGoing);
        }
   } while (keepGoing != "quit" && keepGoing != "Quit");




   // ToDo: After exiting the loop, print the list of palindromes under a Palindrome
   // heading and the list that are not palindromes under a Not Palindrome heading.
   // The display function should print a tab character before printing the string.

    cout << "Palindromes:" << endl;
    display(palindromes);

    cout << "NOT Palindromes:" << endl;
    display(notPalindromes);

	return 0;
}

string removePunct(string str) {
    
    string noPunct;

    for (int i = 0; i < str.length(); i++) {
        if (!ispunct(str[i]) && !isspace(str[i])) {
            noPunct += str[i];
        }
    }

    return noPunct;
}

string convertToLower(string str) {
   
    string lowercase;

    for (int i = 0; i < str.length(); i++) {
        lowercase += tolower(str[i]);
    }

    return lowercase;

}

string reverse(string str)
// Precondition: a string to be reversed
// Postcondition: returns a string that is the
// reverse of the input string.
{
    string reverse;

    for (int i = str.length() - 1; i >= 0; i--) {
        reverse += str[i];
    }

    return reverse;
}

void display(vector<string> vstrings)
// Precondition: a vector of strings to print
// Postcondition: strings are printed one per line.
{
    for (int i = 0; i < vstrings.size(); i++) {
        cout << "\t" << vstrings[i] << endl;
    }
}

bool isPalindrome(string str)
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome
// returns false otherwise.
{
    string lower = convertToLower(str);
    string noPunct = removePunct(lower);
    string reversed = reverse(noPunct);
   
    return (reversed == noPunct);
}
