
/* CISC 1610 - Lab 11
 *
 * This program creates a shopping list using parallel arrays. 
 *
 * Jack Forester
 * Last Edited: November 28, 2023
 */

 #include <iostream>
 #include <string>
 using namespace std;

 void inputInfo (string s[], double d[], int q[], const int size);
// Precondition: three arrays for the number, price, and quantity of items are not filled.
// Postcondition: arrays are filled with values input by user.

double totalCost (const double d[], const int q[], const int size);
// Precondition: total cost of shopping list has no value.
// Postcondition: calculated total cost of shopping list

void shoppingList (const string s[], const double d[], const int q[], const int size);
// Precondition: shopping list not shown.
// Postcondition: outputs shopping list.

int main () {

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    const int numItems = 5;
    string name[numItems];
    double price[numItems];
    int itemQuantity[numItems];
    double itemPrice[numItems];

    inputInfo (name, price, itemQuantity, numItems);
    shoppingList (name, price, itemQuantity, numItems);

    return 0;
 }

void inputInfo (string s[], double d[], int q[], const int size) {

    for (int i = 0; i < size; i++) {
    cout << "Enter information for item #" << i + 1 << ": " << endl
         << "Name: ";
    cin >> s[i];

    cout << "How much of that item?: ";
    cin >> q[i];

    cout << "Price per item: $";
    cin >> d[i];
    }
}

double totalCost (const double d[], const int q[], const int size) {

    double total = 0;
    double itemPrice[size];
    for (int i = 0; i < size; i++) {

        itemPrice[i] = d[i] * q[i];
        total += itemPrice[i];
    }

    return (total);
}

void shoppingList (const string s[], const double d[], const int q[], const int size) {

    cout << "This week's shopping list: \n";
    for (int i = 0; i < size; i++) {

        cout << s[i] << endl
             << "Quantity: " << q[i] << endl
             << "Price: $" << d[i] * q[i] << endl;
    }
    double total = totalCost (d, q, size);
    cout << "Total Cost: $" << total << endl;
}
