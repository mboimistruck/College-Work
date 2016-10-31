//Program Name: A4P2.cpp
//Programmer Name: Michael Boimistruck
//Date Last Compiled: 3:22AM March 7th, 2016

#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

string GameWords[10] = { "intricate","list","containing","absolutely","amazing","strings","forever","unsolvable","unless","inhuman" };
char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'Y', 'X', 'Z' };
int randController = 0;
int attempts = 6;
int wordLength;
int correctLetters;
int control = 0;
char storedChars[7];

void gotoxy(int x, int y) {
	COORD coords;
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);

}

void StartNewGame() {
	randController = rand() % 10;
	wordLength = GameWords[randController].length();

	gotoxy(29, 2);
	cout << "HANGMAN GAME";

	gotoxy(25, 6);
	cout << "Choose a letter:";

	for (int i = 0; i < 52; i += 2) {
		gotoxy(i + 10, 4);
		cout << alphabet[i / 2];

	}

	for (int i = 0; i < 8; i++) {
		gotoxy(35, 8 + i);
		cout << "|";
	}
	for (int i = 0; i < 13; i++) {
		gotoxy(36 + i, 8);
		cout << "=";
	}
	for (int i = 0; i < 20; i++) {
		gotoxy(36 + i, 15);
		cout << "_";
	}
	gotoxy(48, 9);
	cout << "|";

	for (int i = 0; i < GameWords[randController].length() * 2; i += 2) {
		gotoxy(i + 10, 15);
		cout << "_" << ' ';
	}
}

void DrawHangman() {
	attempts--;

	if (attempts == 5) {
		gotoxy(48, 10);
		cout << "O";

	}
	else if (attempts == 4) {
		gotoxy(48, 11);
		cout << "|";

	}
	else if (attempts == 3) {
		gotoxy(47, 11);
		cout << (char)47;

	}
	else if (attempts == 2) {
		gotoxy(49, 11);
		cout << (char)92;

	}
	else if (attempts == 1) {
		gotoxy(47, 12);
		cout << (char)47;
	}
	else if (attempts == 0) {
		gotoxy(49, 12);
		cout << (char)92;

		gotoxy(40, 20);
		cout << "Sorry! GAME OVER!";

		gotoxy(40, 21);
		cout << "The correct word is: ";

		string tempString = GameWords[randController];
		char tempChar;

		for (int i = 0; i < tempString.length(); i++) {
			tempChar = toupper(tempString[i]);
			tempString[i] = putchar(toupper(tempChar)); // convert chars to upper and save as string
		}
	}
}

void LetterMatchInWord(char userInput) {
	string tempWord = GameWords[randController];
	int temp = tempWord.find(userInput);
	bool flag = false;

	for (int i = 0; i < 7; i++) {
		if (storedChars[i] == userInput) { // checks array of entered chars to flag if they exist already
			flag = true;
			break;
		}
	}

	if (temp == string::npos || flag == true) { // calls method if letter isn't found
		DrawHangman();
		flag = false;

	}
	else if (temp != string::npos && flag != true) {

		while (temp != string::npos) {

			for (int j = 0; j < 26; j++) {

				if (alphabet[j] == toupper(tempWord[temp])) {
					gotoxy((j + 5) * 2, 4);
					cout << ' '; // overwrites letter on the alphabet line

				}
			}
			gotoxy(10 + temp * 2, 14);
			putchar(toupper(tempWord[temp])); // outputs the letters found
			storedChars[control] = tempWord[temp]; // stores instances of letter in selected word to array to prevent repeat
			control++;
			correctLetters++;

			if (correctLetters == wordLength) {
				attempts = 0;
				gotoxy(40, 20);
				cout << "You got it!";
			}
			temp = GameWords[randController].find(userInput, temp + 1); // start find on the next position
		}
	}
}

void GetLetterFromUser() {
	char userInput;
	while (attempts != 0) {

		for (int i = 0; i < 10; i++) {
			gotoxy(42 + i, 6);
			cout << ' ';
		}
		gotoxy(42, 6);
		cin >> setw(1) >> userInput;
		cin.ignore();
		userInput = tolower(userInput);

		LetterMatchInWord(userInput);
	}
}

int main() {
	srand(time(NULL));
	char checkChar = 'y';

	do {
		system("cls");
		StartNewGame();
		GetLetterFromUser();

		if (attempts == 0) {
			gotoxy(20, 22);
			cout << "Would you like to run the program again? y/n";
			checkChar = _getch();
			attempts = 6;
			correctLetters = 0;
			control = 0;

			for (int i = 0; i < 7; i++) {
				storedChars[i] = '\0';
			}
		}
	} while (checkChar == 'y' || checkChar == 'Y');

	return 0;
}
