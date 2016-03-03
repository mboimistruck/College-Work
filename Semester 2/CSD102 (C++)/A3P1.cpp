//Program Name: A3P1
//Programmer Name: Michael Boimistruck
//Date Last Compiled: February 20th, 2016
//Program Summary: Book Store

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iomanip>

using namespace std;

//Declarations
float total = 0.0;

void gotoxy(int x, int y) {
	COORD coords;
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);

}
void method(int isbn[], string book_title[], float retail[], int storedISBN[]) {

	char totalClose;
	int userInput;
	int added = 0;
	int purchaseAmount = 0;
	float stored = 0;
	bool flagged = false;

	while (added <= 4) {
		flagged = false;
		gotoxy(2, added + 2);
		cin >> userInput;

		for (int i = 0; i < 13; i++) { // clears the "Invalid text"
			gotoxy(i + 11, 10);
			cout << ' ';
		}

		for (int i = 0; i <= 5; i++) {
			if (i == 5) {
				gotoxy(11, 10);
				cout << "Invalid input";

				for (int i = 0; i < 13; i++) {
					gotoxy(i + 2, added + 2);
					cout << ' ';
				}
				break;

			}
			if (userInput == isbn[i]) {
				flagged = true;

				gotoxy(11, added + 2);
				cout << book_title[i];

				gotoxy(38, added + 2);
				cout << "$" << retail[i];
				stored = retail[i];

				break;

			}
			else {
				continue;
			}
		}

		if (flagged == true) {

			for (int i = 0; i < 5; i++) {

				if (userInput == storedISBN[i]) {
					gotoxy(11, 10);
					cout << "Invalid input";
					for (int i = 0; i < 43; i++) { // clears the line if repeated
						gotoxy(i + 2, added + 2);
						cout << ' ';
					}
					break;

				}
				else  if (storedISBN[i] == 0 && userInput != storedISBN[i]) {
					storedISBN[i] = userInput;
					added++;

					gotoxy(48, added + 1);
					cin >> purchaseAmount;
					total = total + (purchaseAmount * retail[i]);

					gotoxy(53, added + 1);
					cout << "$" << setprecision(2) << fixed << (stored * purchaseAmount);

					totalClose = _getch();
					if (totalClose == 't') {
						added = 6;
						break;
					}


					break;

				}
			}
		}
	}
}

void interfaceTemplate() {
	gotoxy(2, 1);
	cout << "ISBN";

	gotoxy(11, 1);
	cout << "Title";

	gotoxy(38, 1);
	cout << "Price";

	gotoxy(48, 1);
	cout << "Qty";

	gotoxy(53, 1);
	cout << "Total";

	gotoxy(32, 10);
	cout << "PreTax Total";

	gotoxy(32, 11);
	cout << "HST(13%)";

	gotoxy(32, 12);
	cout << "After Tax Total";

}


int main() {

	int isbn[5] = { 11110, 12221, 13332, 24443, 25554 };
	string book_title[5] = { "Binary Kibbles and Bits", "Underwater Googles", "Vitamin C++", "Surf and Turf the Web", "Java-in: Olympic Favourite" };
	float retail[5] = { 155.95, 116.75, 126.50, 125.75, 138.99 };
	int storedISBN[5] = { 0, 0, 0, 0, 0 };
	char check = 'y';

	do {
		system("cls");
		interfaceTemplate();
		method(isbn, book_title, retail, storedISBN);

		gotoxy(48, 10);
		cout << "$" << setprecision(2) << fixed << total;

		gotoxy(48, 11);
		cout << setprecision(2) << fixed << total*0.13;

		gotoxy(48, 12);
		cout << "$" << setprecision(2) << fixed << total*0.13 + total;

		gotoxy(18, 13);
		cout << "Would you like to run the program again? y/n: ";
		cin >> check;

	} while (check == 'y');

	system("pause");

	return 0;

}
