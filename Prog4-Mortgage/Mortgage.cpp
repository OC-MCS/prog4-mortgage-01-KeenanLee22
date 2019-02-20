#include "Mortgage.h"
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

//============================================
//calculatePayment: Calculates the monthly payment for the loan
// parameters: none
// return type: float
// ============================================
float Mortgage::calculatePayment()
{
	float term = pow((1 + rate / 12), 12 * years);
	float payment = (loan*rate / 12 * term) / (term - 1);
	return payment;
}


//============================================
//calculateTotal: Calculates the total payment for the loan
// parameters: none
// return type: float
// ============================================
float Mortgage::calculateTotal()
{
	float payment;
	payment = calculatePayment();
	float total = payment * 12 * years;
	return total;
}

// default constructor for Mortgage
Mortgage::Mortgage()
{
	loan = 0;
	rate = 0;
	years = 0;
}

// sets constructor of Mortgage from input received
Mortgage::Mortgage(float l, float r, int y)
{
	loan = l;
	rate = r;
	years = y;
}
