#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>


using namespace std;

//Declarations
string months[] = { "January", "February", "March", "April", "May", "June",
"July", "August", "September", "October", "November", "December" };
double lowest = 9999999, highest = 0;
double temps[12], total, average;


//Function to determine which months matched up with the lowest temperature element position and then prints the months.
void determine_min_rainfall() {
	for (int i = 0; i < 12; i++) {

		if (temps[i] == lowest) {
			cout << "\t" << months[i] << endl;

		}
	}
}
//Function to determine which months matched up with the highest temperature element position and then prints the months.
void determine_max_rainfall() {
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
void input_rainfall_data() {

	for (int i = 0; i < 12; i++) {
		cout << "\tPlease enter the amount of rainfall (mm) for the month of " << months[i] << ": " << endl;

	}
	for (int i = 0; i < 12; i++) {
		gotoxy(76, i);
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
void calculate_total_and_average_rainfall() {
	for (int i = 0; i < 12; i++) {
		total = total + temps[i];
		average = total / 12;

	}
}

//Function to output all the data
void output_rainfall_report() {
	cout << "\n\tTotal rainfall for the year: " << total << endl;
	cout << "\tAverage monthly rainfall: " << average << endl;
	cout << "\n\tThe lowest rainfall (" << lowest << " mm) occured during: " << endl;
	determine_min_rainfall();
	cout << "\n\tThe highest rainfall (" << highest << " mm) occured during: " << endl;
	determine_max_rainfall();

}

int main() {

	char check = 'y';
	do {
		input_rainfall_data();
		calculate_total_and_average_rainfall();
		output_rainfall_report();
		cout << "\n\tWould you like to run the program again? y/n." << endl;
		cin >> check;

	} while (check == 'y');

	system("pause");
	return 0;

}
