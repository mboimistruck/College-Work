#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h> //atoi
#include <cstdlib>


using namespace std;

//Declarations
int userInput = 0;
char userCheck;

void gotoxy(int x, int y) {
	COORD coords;
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);

}
void greetings() {
	cout << "\tWelcome to Vitto's!\n\tMangiare, Mangiare!" << endl;
	OutputDebugString(L"TOTALLY NOT THE GREETINGS CALL\n");
	system("pause");
}

void update_vending(string itemNames[], string itemPrices[], string quantities[]){
	int temp;

	cout << "\t\t\t\tVITTO'S VENDETTA VENDING\n" << endl;
	cout << "\t\t\tCHOICE\tITEM NAME\tPRICE\tQTY\n" << endl;

	for (int i = 0; i < 8; i++) {
		if (i == 7){
			cout << "\t\t\t" << 'E' << ".\t" << itemNames[i] << "\t" << itemPrices[i] << "\t" << quantities[i] << "\n";
			break;
		}
		cout << "\t\t\t" << i + 1 << ".\t" << itemNames[i] << "\t" << itemPrices[i] << "\t" << quantities[i] << "\n";
	}
	do{
		cout << "\n\t\t\t\tSelect an item: " << endl;
		gotoxy(48, 13);
		userInput = _getch() - '0';
		OutputDebugString(L"WATCH OUT BRO, INPUTS\n");
		//cin.ignore();
		if (quantities[userInput - 1] == "OUT") {
			break;
		}
		else if ((userInput <= 7 && stoi(quantities[userInput - 1]) <= 5) && (userInput > 0 && stoi(quantities[userInput - 1]) > 1)) {
			temp = (stoi(quantities[userInput - 1]));
			temp--;
			quantities[userInput - 1] = to_string(temp);

		}
		else if (stoi(quantities[userInput - 1]) == 1){
			quantities[userInput - 1] = "OUT";
		}
		else {
			OutputDebugString(L"NOPE, YA DUN GOOFED M8\n");
			userCheck = 'e';
		}
	} while(userInput == 0);
}


int main() {
	string itemNames[9] = { "Soprano Soup", "Godfather Pasta", "Gotti Gum", "Caprone Crisps", "Gambino Pie", "Luciano Lunch",
		"Mafia Muffin", "No More Purchases", "No More Purchases" };
	string itemPrices[8] = { "$4.75", "$5.85", "$2.50", "$3.00", "$6.75", "$8.50", "$1.75" };
	string quantities[8] = { "5", "5", "5", "5", "5", "5", "5" };

	char check = 'y';

	do {
		greetings();
		while (userCheck != 'e'){
			system("cls");
			update_vending(itemNames, itemPrices, quantities);
			OutputDebugString(L"LOOK AT ME I'M STILL LOOPING THIS SHIT BECAUSE YOU DIDNT TYPE E!!@!!11\n");
		}
		cout << "\n\tWould you like to run the program again? y/n." << endl;
		cin >> check;

	} while (check == 'y');

	system("pause");
	return 0;

}
