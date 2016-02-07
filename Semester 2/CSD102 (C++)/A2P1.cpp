//Program Name: A2P1.cpp
//Prorgammer Name: Michael Boimistruck
//Date Last Compiled: Feb 07, 2016. 2:42 AM
//Program Description: Manipulates user inputted data regarding monthly rainfall (mm) and determines the total, average,
//						highest, and lowest rainfall over the year

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

//Declarations
double lowest = 9999999, highest = 0;
double total, average = 0;


//Function to determine which months matched up with the lowest temperature element position and then prints the months.
void determine_min_rainfall(string months[], double temps[]) {
	for (int i = 0; i < 12; i++) {

		if (temps[i] == lowest) {
			cout << "\t" << months[i] << endl;

		}
	}
}
//Function to determine which months matched up with the highest temperature element position and then prints the months.
void determine_max_rainfall(string months[], double temps[]) {
	for (int i = 0; i < 12; i++) {

		if (temps[i] == highest) {
			cout << "\t" << months[i] << endl;

		}
	}
}

void gotoxy(int x, int y) {
	COORD coords;
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);

}

//Function to gather data from user and determine the lowest/highest temperatures.
void input_rainfall_data(string months[], double temps[]) {

	for (int i = 0; i < 12; i++) {
		gotoxy(4, i + 1);
		cout << "Please enter the amount of rainfall (mm) for the month of " << months[i] << ": ";

	}
	for (int i = 0; i < 12; i++) {
		gotoxy(73, i + 1);
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

//Function to calculate the total rainfall
void calculate_total_and_average_rainfall(double temps[]) {
	for (int i = 0; i < 12; i++) {
		total = total + temps[i];
		average = total / 12;

	}
}

//Function to output all the data
void output_rainfall_report(string months[], double temps[]) {
	cout << "\n\tTotal rainfall for the year: " << total << endl;
	cout << "\tAverage monthly rainfall: " << average << endl;
	cout << "\n\tThe lowest rainfall (" << lowest << " mm) occured during: " << endl;
	determine_min_rainfall(months, temps);
	cout << "\n\tThe highest rainfall (" << highest << " mm) occured during: " << endl;
	determine_max_rainfall(months, temps);

}

int main() {
	string months[] = { "January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December" };

	char check = 'y';
	do {
		double temps[12];
		total = 0;
		average = 0;
		highest = 0;
		lowest = 9999999;

		system("cls");

		input_rainfall_data(months, temps);
		calculate_total_and_average_rainfall(temps);
		output_rainfall_report(months, temps);
		
		cout << "\n\tWould you like to run the program again? y/n." << endl;
		cin >> check;

	} while (check == 'y');

	system("pause");
	return 0;

}
