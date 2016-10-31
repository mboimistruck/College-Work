//Program Name: A4P3.cpp
//Programmer Name: Michael Boimistruck
//Date Last Compiled: Mar 13, 2016

#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

string userNames[10] = { "johndoe","doejohn","janedoe","doejane","joebloggs","generic","anonymous","cplusplus","noname","toronto" };
string passWords[10] = { "pw1234","1234pw","pw2016","2016pw","joeblow","thingy123","thingy321","123thingy","bestbrand","gohabsgo" };
int attempts = 3;

bool userCheck;
bool passCheck;
int elementCheck;

void gotoxy(int x, int y) {
	COORD coords;
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);

}

void gatherUserName() {
	int charCounter = 0;
	char usersChar;
	string userName = "           ";

	while (charCounter < 9) {
		gotoxy(charCounter + 15, 5);
		usersChar = _getche();

		if (usersChar == 13) {
			gotoxy(charCounter + 15, 5);
			break;
		}
		else if (usersChar == 8) {
			if (charCounter == 0) {
				charCounter++;
			}
				charCounter--;
				gotoxy(charCounter + 15, 5);
				cout << ' ';
				gotoxy(charCounter + 15, 5);
		}
		else {
			userName[charCounter] = usersChar;
			charCounter++;
		}
	}
	for (int i = 0; i < 10 - charCounter; i++) {
		userName.erase(10 - (i+1));
	}
	for (int i = 0; i < 10; i++) {
		if (userName == userNames[i]) {
			elementCheck = i;
			userCheck = true;
			break;
		}
	}
}
void gatherPassword() {
	int charCounter = 0;
	char usersChar;
	int testCounter = 0;
	string passWord = "           ";

	while (charCounter < 9) {
		gotoxy(charCounter + 15, 6);
		usersChar = _getch();

		if (usersChar == 13) {
			gotoxy(charCounter + 15, 6);
			break;
		}
		else if (usersChar == 8) {
			if (charCounter == 0) {
				charCounter++;
			}
			charCounter--;
			testCounter--;
			gotoxy(charCounter + 15, 6);
			cout << ' ';
			gotoxy(charCounter + 15, 6);
		}
		else {
			cout << "*";
			passWord[charCounter] = usersChar;
			testCounter++;
			charCounter++;
		}
	}
	for (int i = 0; i < 10 - testCounter; i++) {
		passWord.erase(10 - (i + 1));
	}
	for (int i = 0; i < 10; i++) {
		if (passWord == passWords[i] && elementCheck == i) {
			passCheck = true;
			break;
		}
	}
}

int main() {
	char checkChar = 'y';

	do {
		system("cls");
		gotoxy(5, 5);
		cout << "Username: ";

		gotoxy(5, 6);
		cout << "Password: ";

		while (attempts > 0) {
			userCheck = false;
			passCheck = false;
			elementCheck = 0;

			for (int i = 15; i < 25; i++) {
				gotoxy(i, 5);
				cout << ' ';
				gotoxy(i, 6);
				cout << ' ';
			}

			gatherUserName();
			gatherPassword();
			if (passCheck == true && userCheck && true) {
				gotoxy(10, 10);
				cout << "\a\a\a\aYou have gained access...";
				break;

			}
			else {
				gotoxy(10, 10);
				cout << "Invalid password";
				attempts--;

			}
		}
		gotoxy(5, 18);
		if (attempts > 0) {
			cout << "Would you like to run the program again? y/n";
		}
		else {
			cout << "You have used up your three attempts! Would you like to run the program again ? y/n";
		}
		checkChar = _getch();
		attempts = 3;
	} while (checkChar == 'y' || checkChar == 'Y');

	return 0;
}
