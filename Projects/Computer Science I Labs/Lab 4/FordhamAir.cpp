/* CISC 1610: - Computer Science I Lab
 * 
 * Lab 4 - Fordham Air
 *
 * This program allows a customer to purchase flights from Fordham Airlines, calculates how much the customer owes, takes 
 * payment, and calculates change. The code is practice for conditional statements, utilizing boolean logic and if-else 
 * statements.
 *
 * Jack Forester 
 * Last Edited: September 26, 2023
 */

#include <iostream>
using namespace std;

int main() {

// Welcome - Destination, Flight Time, and Day

	char destination;
	cout << "Welcome to Fordham Airlines!\n" << "What is your destination? ([C]hicago, [M]iami, [P]ortland) ";
	cin >> destination;

	double flightTime;
	cout << "What time will you travel? (Enter time between 0-2359) ";
	cin >> flightTime;
	
	bool isDayflight;
	if (flightTime >= 500 && flightTime <= 1900) {
		isDayflight = true;
	}
	else {
	      	isDayflight = false;
	}

	char weekEndOrWeekDayLetter;
	cout << "What type of day are you traveling? (week[E]nd or week[D]ay) ";
	cin >> weekEndOrWeekDayLetter;

	bool isWeekend;
	if (weekEndOrWeekDayLetter == 'E') {
		isWeekend = true;
	}
	else {
		isWeekend = false;
	}

// Calculation of Ticket Price

	double ticketPrice;

	// Chicago Flights
	if (destination == 'C' && isDayflight && isWeekend) {
		ticketPrice = 90;
	}
	else if (destination == 'C' && isDayflight && !isWeekend) {   
                ticketPrice = 75;
        }
	else if (destination == 'C' && !isDayflight && isWeekend) {
                ticketPrice = 60;
        }
	else if (destination == 'C' && !isDayflight && !isWeekend) {  
                ticketPrice = 50;
        }
       	// Portland Flights	 
	else if (destination == 'P' && isDayflight && isWeekend) {  
                ticketPrice = 360;
        }
	else if (destination == 'P' && isDayflight && !isWeekend) {  
                ticketPrice = 300;
        }
	else if (destination == 'P' && !isDayflight && isWeekend) {  
                ticketPrice = 240;
        }
	else if (destination == 'P' && !isDayflight && !isWeekend) {  
                ticketPrice = 200;
        }
	// Miami Flights
         else if (destination == 'M' && isDayflight && isWeekend) {
                ticketPrice = 180;
        }
        else if (destination == 'M' && isDayflight && !isWeekend) {
                ticketPrice = 150;
        }
        else if (destination == 'M' && !isDayflight && isWeekend) {
                ticketPrice = 120;
        }
        else if (destination == 'M' && !isDayflight && !isWeekend) {
                ticketPrice = 100;
        }

// Ticket Information
	
	cout.setf(ios::fixed);
        cout.setf(ios::showpoint); // Show Decimals
        cout.precision(2); // Two Values to the Right of the Decimal

        cout << "Each ticket will cost: $" << ticketPrice << endl;
	
	int numTickets;
	double totalCost;

	cout << "How many tickets do you want? ";
	cin >> numTickets;
	if (numTickets < 0) {
		cout << "The number of tickets ordered is invalid and the order has been cancelled.";
	}
	else {
		totalCost = numTickets * ticketPrice;
		cout << "You owe: $" << totalCost << endl; 	
	}
	
	double userPayment;
	double change;

	cout << "Amount paid? $";
	cin >> userPayment;
	
	if (userPayment < totalCost) {
		cout << "That is too little! No tickets ordered.";
		return 0;
	}
	else {
		change = userPayment - totalCost;
		cout << "You will get $" << change << " in change.\n" << "Your tickets have been ordered!\n";
	}

return 0;

}

