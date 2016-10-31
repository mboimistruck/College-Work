//Program Name: A1P2.cpp
//Programmer: Michael Boimistruck
//Overview: The program will take in user data and compute the gross and net box office profits for the night
//Date Written: 13/01/2016
//Date Modified: 13/01/2016

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


string movieName;
int chdTkts, adtTkts;
double gross, net, distDiff;


//method to gather data from user and determine the movie name and tickets sold.
void gatherInput() {
	cout << "\n\tMovie name: ";
	cin >> movieName;
	cin.ignore();

	cout << "\n\tNumber of adult tickets: ";
	cin >> adtTkts;
	cin.ignore();


	cout << "\n\tNumber of child tickets: ";
	cin >> chdTkts;
	cin.ignore();

}

void computeProfits() {
	gross = ((adtTkts * 22) + (chdTkts * 15));
	net = (gross * 0.45);
	distDiff = gross - net;

}

void outputResults() {
	cout << "\n\n\t\tMovie Name: " << movieName << endl;
	cout << "\n\t\tAdult Tickets Sold: " << adtTkts << endl;
	cout << "\n\t\tChild Tickets Sold: " << chdTkts << endl;
	cout << "\n\t\tGross Box Office Profit: $" << setprecision(2) << fixed << gross << endl;
	cout << "\n\t\tNet Box Office Profit: $" << setprecision(2) << fixed << net << endl;
	cout << "\n\t\tAmount Paid to Distributor: $" << setprecision(2) << fixed << distDiff << endl;

}

int main() {
	gatherInput();
	computeProfits();
	outputResults();
	system("pause");

	return 0;

}