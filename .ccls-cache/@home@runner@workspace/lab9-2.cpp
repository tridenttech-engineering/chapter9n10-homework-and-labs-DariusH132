//Lab 9-2.cpp - displays two monthly car payments
//Created/revised by <Darius Haywood> on <3/25/25>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double getPayment(double, double, int);
int main()
{
    int carPrice = 0;
    int rebate = 0;
    double creditRate = 0.0;
    double dealerRate = 0.0;
    int term = 0;
    double creditPayment = 0.0;
    double dealerPayment = 0.0;
    
    cout << "Car price (after any trade-in): ";
    cin >> carPrice;
    cout << "Rebate: ";
    cin >> rebate;
    cout << "Credit union rate: ";
    cin >> creditRate;
    cout << "Dealer rate: ";
    cin >> dealerRate;
    cout << "Term in years: ";
    cin >> term;

    double creditMonthlyRate = creditRate / 12.0;
    double dealerMonthlyRate = dealerRate / 12.0;
    int months = term * 12;

    creditPayment = getPayment(carPrice - rebate, creditMonthlyRate, months);
    dealerPayment = getPayment(carPrice, dealerMonthlyRate, months);
    
    cout << fixed << setprecision(2) << endl;
    cout << "Credit union payment: $ " << creditPayment << endl;
    cout << "Dealer payment: $ " << dealerPayment << endl;
    
    return 0;
}//end of main function    
double getPayment(double principle, double monthlyRate, int months)
{
    if (months <= 0)
        return 0;
    if (monthlyRate == 0.0)
        return principle / months;
    else
        return principle * (monthlyRate / (1 - pow(monthlyRate + 1, -months)));
}