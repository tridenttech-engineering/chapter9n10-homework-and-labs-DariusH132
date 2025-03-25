//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Darius Haywood> on <3/25/25>

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// Function prototypes
double getPayment(int, double, int);
double getTotal(double, int);

int main()
{
    // Declare variables
    int carPrice = 0, rebate = 0, term = 0;
    double creditRate = 0.0, dealerRate = 0.0;
    double creditPayment = 0.0, dealerPayment = 0.0;
    double totalCreditCost = 0.0, totalDealerCost = 0.0;

    // Get user input
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

    // Call function to calculate payments
    creditPayment = getPayment(carPrice - rebate, creditMonthlyRate, months);
    dealerPayment = getPayment(carPrice, dealerMonthlyRate, months);

    // Calculate total payments
    totalCreditCost = getTotal(creditPayment, months);
    totalDealerCost = getTotal(dealerPayment, months);

    // Display payments
    cout << fixed << setprecision(2) << endl;
    cout << "Credit union payment: $" << creditPayment << endl;
    cout << "Total cost via credit union: $" << totalCreditCost << endl;
    cout << "Dealer payment: $" << dealerPayment << endl;
    cout << "Total cost via dealer: $" << totalDealerCost << endl;

    return 0;
}

// Function to calculate monthly loan payment
double getPayment(int principal, double monthRate, int months)
{
    if (months <= 0 || (1 - pow(1 + monthRate, -months)) == 0) {
        return -1; // Return -1 if division by zero occurs
    }

    return principal * (monthRate / (1 - pow(1 + monthRate, -months)));
}

// Function to calculate total amount paid over the loan term
double getTotal(double monthPay, int months)
{
    double total = 0.0;
    double roundedPay = 0.0;

    roundedPay = static_cast<int>((monthPay + .005) * 100) / 100.0;
    total = roundedPay * months;
    return total;
} 