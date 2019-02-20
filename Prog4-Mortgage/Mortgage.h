#pragma once

using namespace std;

class Mortgage
{
private:
	float loan;
	float rate;
	int years;
public:
	float calculatePayment();
	float calculateTotal();
	Mortgage();
	Mortgage(float, float, int);
};

