/*
 * Class: CMSC140 CRN
 * Instructor:
 * Project<number>
 * Description: (Give a brief description for Project)
 * Due Date:
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Khalid abdullahi
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int AGE_G = 0, AGE_PG = 7, AGE_PG13 = 13, AGE_R = 17, AGE_NC17 = 18;
    const double ADULT_TICKET = 12.00, CHILD_TICKET = 8.00;
    
    cout << "********** Movie Ticket Booking **********\n";
    cout << "Today's Movies:\n";
    cout << "1. The Matrix - Rated R\n";
    cout << "2. Star Wars: Episode V - Rated PG\n";
    cout << "3. Inception - Rated PG-13\n";
    cout << "4. Toy Story - Rated G\n";
    cout << "5. Crash - Rated NC-17\n";
    
    int movieChoice, age;
    cout << "Please select a movie by entering its number: ";
    cin >> movieChoice;
    
    if (movieChoice < 1 || movieChoice > 5) { cout << "Invalid selection."; 
        return 0; }
    
    string movieName;
    int requiredAge;
    
    switch (movieChoice) {
        case 1: movieName = "The Matrix"; 
        requiredAge = AGE_R; 
        break;
        case 2: movieName = "Star Wars: Episode V"; 
        requiredAge = AGE_PG; 
        break;
        case 3: movieName = "Inception"; 
        requiredAge = AGE_PG13; break;
        case 4: movieName = "Toy Story"; 
        requiredAge = AGE_G; 
        break;
        case 5: movieName = "Crash"; 
        requiredAge = AGE_NC17; 
        break;
    }
    
    cout << "\"" << movieName << "\" is selected. Please enter your age: ";
    cin >> age;
    
    if (age < 0) { cout << "Invalid age."; 
        return 0; }
    
    if (age < requiredAge) { cout << "Sorry, you must be at least " << requiredAge << " to watch \"" << movieName << "\"."; 
        return 0; }
    
    int adultTickets, childTickets;
    cout << "How many adult tickets? ";
    cin >> adultTickets;
    cout << "How many child tickets? ";
    cin >> childTickets;
    
    if (adultTickets < 0 || childTickets < 0) { cout << "Invalid ticket number."; 
        return 0; }
    
    double totalCost = (adultTickets * ADULT_TICKET) + (childTickets * CHILD_TICKET);
    cout << "Total cost: $" << totalCost << endl;
    
    double amountPaid;
    cout << "Enter payment amount: ";
    cin >> amountPaid;
    
    if (amountPaid < totalCost) { cout << "Error: Amount is less than total cost. Transaction Cancelled."; 
        return 0; }
    
    cout << "Payment successful! Change returned: $" << (amountPaid - totalCost) << endl;
    
    return 0;
}
