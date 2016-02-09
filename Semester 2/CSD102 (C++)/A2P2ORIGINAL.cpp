//Program Name: A2P2.cpp
//Prorgammer Name: Michael Boimistruck
//Date Last Compiled: Feb 07, 2016. 2:05 AM
//Program Description: Emulates a vending machine with a set stock/price. Returns total amount of product purchases.

#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <cstdlib>

using namespace std;

//Declarations
int userInput = 0;
int OUTCounter = 0;
int purchasedCounter;

char userCheck;

void gotoxy(int x, int y) {
	COORD coords;
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);

}
void greetings() {
	system("cls");
	gotoxy(25,1);
	cout << "Welcome to Vitto's!";
	gotoxy(25, 2);
	cout << "Mangiare, Mangiare!";
	system("pause > nul");
}

void update_vending(string itemNames[], string itemPrices[], string quantities[]){
	int temp;

	gotoxy(25, 1);
	cout << "VITTO'S VENDETTA VENDING" << endl;
	gotoxy(25, 3);
	cout << "CHOICE";
	gotoxy(32, 3);
	cout << "ITEM NAME";
	gotoxy(51, 3);
	cout << "PRICE";
	gotoxy(57, 3);
	cout << "QTY";

	//Builds/Fills the menu
	for (int i = 0; i < 8; i++) {
		if (i == 7){
			gotoxy(25, i + 4);
			cout << "E.";
		}

		else {
			gotoxy(25, i + 4);
			cout << i + 1 << ".";
		}

		gotoxy(32, i + 4);
		cout << itemNames[i];
		gotoxy(51, i + 4);
		cout << itemPrices[i];
		gotoxy(57, i + 4);
		cout << quantities[i];
	}

	do{
		gotoxy(25, 13);
		cout << "Select an item: ";
		gotoxy(40, 13);
		userInput = _getch();
		//The below if statement converts user input that isn't an e to an integer, if it is an e it will switch the userCheck var to e...
		//causing the program to break out.
		if (userInput != 'e') {
			userInput -= '0';
		}

		else if (userInput == 'e') {
			userCheck = 'e';
			break;
		}

		if (quantities[userInput - 1] == "OUT") {
			break;
		}
		//Below converts the input to an int, does int subtraction, stores it back in the array as a string.
		else if ((userInput <= 7 && stoi(quantities[userInput - 1]) <= 5) && (userInput > 0 && stoi(quantities[userInput - 1]) > 1)) {
			temp = (stoi(quantities[userInput - 1]));
			temp--;
			purchasedCounter++;
			quantities[userInput - 1] = to_string(temp);

		}
		//If the product chosen has 1 stock left and the user attempts to purchase it, switch the display to say OUT instead of 0
		else if (stoi(quantities[userInput - 1]) == 1){
			quantities[userInput - 1] = "OUT";
			OUTCounter++;
			purchasedCounter++;

		}

	} while(userInput == 0);
}

void thanks_for_shopping() {
	system("cls");

	gotoxy(15, 1);
	cout << "You have purchased " << purchasedCounter << " number of items.";
	gotoxy(15, 2);
	cout << "Thank You for Shopping at Vitto's!";

	purchasedCounter = 0;
	userCheck = '0';
	OUTCounter = 0;

}


int main() {
	string itemNames[8] = { "Soprano Soup", "Godfather Pasta", "Gotti Gum", "Caprone Crisps", "Gambino Pie", "Luciano Lunch",
							"Mafia Muffin", "No More Purchases" };
	string itemPrices[8] = { "$4.75", "$5.85", "$2.50", "$3.00", "$6.75", "$8.50", "$1.75" };

	char check = 'y';

	do {
		string quantities[8] = { "5", "5", "5", "5", "5", "5", "5" };

		greetings();

		while (userCheck != 'e' && OUTCounter < 7) {
			system("cls");
			update_vending(itemNames, itemPrices, quantities);
		}

		thanks_for_shopping();

		gotoxy(15, 3);
		cout << "Would you like to run the program again? y/n: ";
		cin >> check;

	} while (check == 'y');

	system("pause");
	return 0;

}
