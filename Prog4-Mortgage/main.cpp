//=====================================================
// Keenan Lee
// 2/20/19
// Programming Assignment #4
// Description: Mortgage
//=====================================================

#include "Mortgage.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
bool parseInt(string, int&);
bool parseFloat(string, float&);
int main()
{
	cout << setprecision(2) << fixed << showpoint;
	int yearsInt; // Years loan will take
	float rateFloat, loanFloat, payment, total; // annual rate, loan amount, monthly payment, and total payment
	string loan, rate, years; // strings to use for parse int/float to test for bad input
	cout << "Enter loan amount: $";
	//cin >> loanFloat
	getline(cin, loan);
	while (!parseFloat(loan, loanFloat) || loanFloat < 0)
	{
		cout << "Invalid input, please try again: ";
		//cin >> loanFloat
		getline(cin, loan);
	}
	cout << "Enter interest rate: %";
	//cin >> rateFloat;
	getline(cin, rate);
	while (!parseFloat(rate, rateFloat) || rateFloat < 0)
	{
		cout << "Invalid input, please try again: ";
		//cin >> rateFloat
		getline(cin, rate);
	}
	rateFloat = rateFloat / 100;
	cout << "Enter time in years of the loan: ";
	//cin >> yearsInt;
	getline(cin, years);
	while (!parseInt(years, yearsInt) || yearsInt < 0)
	{
		cout << "Invalid input, please try again: ";
		//cin >> yearsInt
		getline(cin, years);
	}
	Mortgage info(loanFloat, rateFloat, yearsInt); //Constructor for calculations
	payment = info.calculatePayment();
	total = info.calculateTotal();
	cout << "Monthly payment: $" << payment << endl;
	cout << "Total payment: $" << total;




}

//============================================
//parseInt: tests input of an int for validation, returns true if valid
// parameters: 
//	sval: string version of input
//  val: int version of input
// return type: bool
// ============================================
bool parseInt(string sval, int& val)
{
	int num;
	bool success = true;
	try
	{
		num = stoi(sval);
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;

}


//============================================
//parseFloat: tests input of a float for validation, returns true if valid
// parameters: 
//	sval: string version of input
//  val: float version of input
// return type: bool
// ============================================
bool parseFloat(string sval, float& val)
{
	float num;
	bool success = true;
	try
	{
		num = stof(sval);
		val = num;
	}
	catch (const std::exception&)
	{
		success = false;
	}
	return success;

}
