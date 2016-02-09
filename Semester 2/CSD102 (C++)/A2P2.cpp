//Program Name: A2P2.cpp
//Prorgammer Name: Michael Boimistruck
//Date Last Compiled: Feb 07, 2016. 2:05 AM
//Program Description: Emulates a vending machine with a set stock/price. Returns total amount of product purchases.

//Note: I apologize for the really disgusting code in update_vending(),
//		 it was a lot cleaner before I remembered I had to not rewrite to the screen
//		 every input causing screen flickers. So I had to change a lot around.
//		 Hoping the comments make more sense of the code!

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

//Declarations
int userInput = 0;
int purchasedCounter;
int loopControl = 0;

void gotoxy(int x, int y) {
	COORD coords;
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);

}
void greetings() {
	system("cls");
	gotoxy(25, 1);
	cout << "Welcome to Vitto's!";
	gotoxy(25, 2);
	cout << "Mangiare, Mangiare!";
	system("pause > nul");
}

void update_vending(string itemNames[], string itemPrices[], string quantities[]) {
	int temp;

	gotoxy(25, 1);
	cout << "      VITTO'S VENDETTA VENDING" << endl; //intentional spacing to overwite the "Welcome" in 'Welcome to Vitto's from previous screen
	gotoxy(25, 3);									  //^could have left this out but it makes it look more fluid^
	cout << "CHOICE";
	gotoxy(32, 3);
	cout << "ITEM NAME";
	gotoxy(51, 3);
	cout << "PRICE";
	gotoxy(58, 3);
	cout << "QTY";

	for (int i = 0; i < 8; i++) { 	//Builds/Fills the menu
		if (i == 7) {
			gotoxy(25, i + 4);
			cout << "E."; // Puts an "E." as the last option, otherwise fills with ints from 1>7
		}

		else {
			gotoxy(25, i + 4);
			cout << i + 1 << ".";
		}
		gotoxy(24, 2);
		for (int i = 0; i < 19; i++) { // Gets rid of the "Mangiare, Mangiare" on screen
			gotoxy(25 + i, 2);
			cout << ' ';
		}
		gotoxy(32, i + 4);
		cout << itemNames[i];
		gotoxy(51, i + 4);
		cout << itemPrices[i];
		gotoxy(59, i + 4);
		cout << quantities[i];
	}

	gotoxy(25, 13);
	cout << "Select an item: ";

	do {

		if (purchasedCounter >= 35) { // break out if the user purchases all available stock
			gotoxy(40, 13);
			cout << " All stock is sold out, ";
			gotoxy(40, 14);
			cout << " please type 'E' to exit."; // Could have used break; here but didn't want
												// to force the ui change on the user
		}

		loopControl++;
		gotoxy(40, 13);
		userInput = _getch();

		if (userInput != 'e') {
			userInput -= '0';
			for (int i = 0; i < 9; i++) { // kills the stupid "SOLD OUT" that will appear if you try to buy stuff that is sold out
				gotoxy(40 + i, 13);
				cout << ' ';
			}

		}

		else if (userInput == 'e') {
			break;

		}

		if (quantities[userInput - 1] == "OUT") { // prints "Sold out!" if the user attempts to buy sold out stuff
			gotoxy(40, 13);
			cout << "Sold out!";
		}

		else if ((userInput <= 7 && stoi(quantities[userInput - 1]) <= 5) && (userInput > 0 && stoi(quantities[userInput - 1]) > 1)) { // Converts input char to int,
			temp = (stoi(quantities[userInput - 1]));																				   // does int math, converts &
			temp--;																													   // saves to string array
			purchasedCounter++;
			quantities[userInput - 1] = to_string(temp);

		}

		else if (stoi(quantities[userInput - 1]) == 1) { // If the product chosen has 1 stock left and
			quantities[userInput - 1] = "OUT";			 // the user attempts to purchase it, switch the display to say OUT instead of 0
			purchasedCounter++;

		}
		if (loopControl == 1) { // resets the input for the user and writes the new quantity on screen
			gotoxy(59, (int)userInput + 3);
			cout << quantities[userInput - 1];
			loopControl = 0;
		}
	} while (loopControl == 0);

}

void thanks_for_shopping() {
	system("cls");

	gotoxy(15, 1);
	cout << "You have purchased " << purchasedCounter << " number of items.";
	gotoxy(15, 2);
	cout << "Thank You for Shopping at Vitto's!";

	purchasedCounter = 0;
	loopControl = 0;

}


int main() {
	string itemNames[8] = { "Soprano Soup", "Godfather Pasta", "Gotti Gum", "Caprone Crisps", "Gambino Pie", "Luciano Lunch",
		"Mafia Muffin", "No More Purchases" };
	string itemPrices[8] = { "$4.75", "$5.85", "$2.50", "$3.00", "$6.75", "$8.50", "$1.75" };

	char check = 'y';

	do {
		string quantities[8] = { "5", "5", "5", "5", "5", "5", "5" };

		greetings();
		update_vending(itemNames, itemPrices, quantities);
		thanks_for_shopping();

		gotoxy(15, 3);
		cout << "Would you like to run the program again? y/n: ";
		cin >> check;

	} while (check == 'y');

	system("pause");
	return 0;

}
