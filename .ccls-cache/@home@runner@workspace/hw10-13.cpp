//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototype
void getPayment(int, double, int, double &);

int main()
{
    // Declare variables
    int carPrice = 0, rebate = 0, term = 0;
    double creditRate = 0.0, dealerRate = 0.0;
    double creditPayment = 0.0, dealerPayment = 0.0;

    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate (in %): ";
    cin >> creditRate;
    cout << "Dealer rate (in %): ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    // Convert interest rates from % to decimal and divide by 12 for monthly rate
    double creditMonthlyRate = creditRate / 12;
    double dealerMonthlyRate = dealerRate / 12;
    int months = term * 12;

    // Call function to calculate payments (pass by reference)
    getPayment(carPrice - rebate, creditMonthlyRate, months, creditPayment);
    getPayment(carPrice, dealerMonthlyRate, months, dealerPayment);

    // Display payments
    cout << fixed << setprecision(2) << endl; 
    cout << "Credit union payment: $" << creditPayment << endl;
    cout << "Dealer payment: $" << dealerPayment << endl;
    return 0;
}

// Function to calculate monthly loan payment (pass result by reference)
void getPayment(int prin, double monthRate, int months, double &payment)
{
    if (months <= 0 || (1 - pow(1 + monthRate, -months)) == 0) {
        payment = -1; // Handle potential division by zero
    } 
    else {
        payment = prin * (monthRate / (1 - pow(1 + monthRate, -months)));
    }
}