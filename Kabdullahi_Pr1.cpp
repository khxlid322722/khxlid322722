/*
 * Class: CMSC140 CRN
 * Instructor:
 * Project<number>
 * Description: (Give a brief description for Project)
 * Due Date:
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here:  Khalid Abdullahi
*/


#include <iostream>
using namespace std;

int main()
{
    cout << "********** Welcome to Stock Transaction Program **********" << endl;
    string name, stockName, choice; 
    int shareAmount, sellAmount;
    double buyCommisionRate, sellCommisionRate, stockPrice, newPrice;
    cout << "Hello! What is your name? ";
    cin >> name;
    cout << "Nice to meet you, " + name + ". How can I help?" << endl;
    cout << "Can you calculate the profit from my transactions?" << endl;
    cout << "Sure! Which stock did you buy? ";
    cin >> stockName;
    cout << "The NASDAQ symbol is AAPL. Is that correct? ";
    cin >> choice;
    cout << "How many shares did you purchase? ";
    cin >> shareAmount;
    cout << "What was the price per share? ";
    cin >> stockPrice;
    cout << "What is the brokerage commission rate? ";
    cin >> buyCommisionRate;
    cout << "Suppose that two weeks later, I sell my stock. How much profit will I make? "<< endl;
    cout << "How many shares did you sell? ";
    cin >> sellAmount;
    cout << "What was the stock price when you sold? ";
    cin >> newPrice;
    cout << "What is the brokerage commission rate for selling? ";
    cin >> sellCommisionRate;
    double purchasePrice = shareAmount * stockPrice;
    double salePrice = sellAmount * newPrice;
    double purchaseCommission = purchasePrice * buyCommisionRate;
    double saleCommission = salePrice * sellCommisionRate;
    double profit = salePrice - purchasePrice - saleCommission - purchaseCommission;
    cout << "Here are the details of the transactions:" << endl;
    cout << "Purchase Price: $" << purchasePrice << endl;
    cout << "Purchase Commission: $" << purchaseCommission << endl;
    cout << "Sale Price: $" << salePrice << endl;
    cout << "Sale Commission: $" << saleCommission << endl;
    cout << "Profit: $" << profit << endl;
    cout << "Thank you for participating, " << name << "!" << endl;
    cout << "PROGRAMMER: Khalid Abdullahi" << endl;
    cout << "Course: CMSC140" << endl;
    cout << "Semester: Spring 2025" << endl;
    cout << "Due Date: 2/23/25" << endl;

    return 0;
}

