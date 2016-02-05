//Program Name: A1P3.cpp
//Programmer: Michael Boimistruck
//Overview: The prorgam will take in user data and compute the interest earned
//Date Written: 13/01/2016
//Date Modified: 13/02/2016

#include <iostream>
#include <string>
#include <math.h>
using namespace std;


double principle, interestRate, interestEarned, total;
int compounded;


void gatherInput() {
	cout << "\tPrinciple amount: ";
	cin >> principle;
	cin.ignore();

	cout << "\n\tInterest rate: ";
	cin >> interestRate;
	cin.ignore();


	cout << "\n\tNumber of times compounded: ";
	cin >> compounded;
	cin.ignore();

}

void computeAmount() {
	total = pow(principle*((1 + interestRate) / compounded), compounded);

}

void outputResults() {
	cout << "\n\n\t\tInterest Rate: " << interestRate << "%" << endl;
	cout << "\n\t\tTimes Compounded: " << compounded << endl;
	cout << "\n\t\tPrinciple: $" << principle << endl;
	cout << "\n\t\tInterest: $" << interestEarned << endl;
	cout << "\n\t\tAmount in Savings: $" << total << endl;

}

int main() {
	gatherInput();
	computeAmount();
	outputResults();
	system("pause");

	return 0;

}