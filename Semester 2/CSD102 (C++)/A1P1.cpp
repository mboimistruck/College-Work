//Program Name: A1P1.cpp
//Programmer: Michael Boimistruck
//Overview: The prorgam will take in user data and compute the total rainfall, average rainfall, and lowest/highest rainfall months
//Date Written: 12/01/2016
//Date Modified: 13/01/2016

#include <iostream>
#include <string>

using namespace std;

//Declarations
string months[] = { "January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November", "December" };
double lowest = 9999999, highest = 0;
double temps[12], total, average;

//method to determine which months matched up with the lowest temperature element position and then prints the months.
void detLowest() {
	for (int i = 0; i < 12; i++) {

		if (temps[i] == lowest) {
			cout << "\t\t" << months[i] << endl;

		}
	}
}

//method to determine which months matched up with the highest temperature element position and then prints the months.
void detHighest() {
	for (int i = 0; i < 12; i++) {

		if (temps[i] == highest) {
			cout << "\t\t" << months[i] << endl;

		}
	}
}

//method to gather data from user and determine the lowest/highest temperatures.
void gatherInput() {
	for (int i = 0; i < 12; i++) {
		cout << "\tEnter the amount of rainfall (millimetres) for the month of " << months[i] << ": ";
		cin >> temps[i];
		cin.ignore();

		if (temps[i] < lowest) {
			lowest = temps[i];

		}
		if (temps[i] > highest) {
			highest = temps[i];

		}
	}
}

//method to calculate the total rainfall
void calculateTotal() {
	for (int i = 0; i < 12; i++) {
		total = total + temps[i];

	}
}

//method to calculate the average rainfall
void calculateAverage() {
	for (int i = 0; i < 12; i++) {
		average = total / 12;

	}
}

//method to output all the data
void outputResults() {
	cout << "\n\t\tTotal rainfall for the year: " << total << "mm" << endl;
	cout << "\t\tAverage monthly rainfall: " << average << "mm" << endl;
	cout << "\n\t\tThe lowest rainfall (" << lowest << " mm) occurred during: " << endl;
	detLowest();
	cout << "\n\t\tThe highest rainfall (" << highest << " mm) occurred during: " << endl;
	detHighest();

}

int main() {
	
	char check = 'y';
	do {
		gatherInput();
		calculateTotal();
		calculateAverage();
		outputResults();
		cout << "\n\tWould you like to run the program again? y/n." << endl;
		cin >> check;

	} while(check == 'y');
	
	system("pause");
	return 0;

}
