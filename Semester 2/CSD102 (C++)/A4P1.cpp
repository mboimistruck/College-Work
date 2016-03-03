//Program Name: A4P1
//Programmer Name: Michael Boimistruck
//Date Last Compiled: Feb 24, 2016
//Program Summary: Generates five phrases using random elements of two arrays. Noun - Verb/Adj - Noun

#include <iostream>
#include <string>
#include <conio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

//Declarations

int randController1 = 0;
int randController2 = 0;
int randController3 = 0;

void print_phrase(string phrase[]) {

	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			phrase[i].at(0) = toupper(phrase[i].at(0));
			cout << "\n\t";

		}


		if (i == 2) {
			cout << phrase[i] << ".\n";

		}
		else {
			cout << phrase[i] << " ";

		}
	}
}

void create_phrase(string noun[], string verb_adj[]) {
	string phrase[3];
	randController1 = rand() % 6;
	randController2 = rand() % 3;
	randController3 = rand() % 6;

	while (randController1 == randController3) {
		randController3 = rand() % 6;

	}

	phrase[0] = noun[randController1];
	phrase[1] = verb_adj[randController2];
	phrase[2] = noun[randController3];

	print_phrase(phrase);

}

int main(string phrase[]) {
	srand(time(NULL));
	string noun[6] = { "programmers", "snowboarders", "drummers", "networkers",
												"bass players", "engineers" };
	string verb_adj[3] = { "are tougher than", "are not as cool as",
											"are more popular than" };
	char checkChar = 'y';

	do {
		system("cls");
		for (int i = 0; i < 5; i++) {
			create_phrase(noun, verb_adj);

		}

		cout << "\n\t\tWould you like to run the program again? y/n\n\n\n";
		checkChar = _getch();

	} while (checkChar == 'y');

	system("pause");

	return 0;

}
