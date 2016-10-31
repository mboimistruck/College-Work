#ifndef UpdateClass_H
#define UpdateClass_H

#include "xheaders.h"

using namespace std;

extern bool flag;
extern string pulledFileName;
extern int counter;
int fileSelection = 0;
bool writeToFileFlag = false;
string gradeInput[25]; // set to 25 under the assumption that the user won't enter more than 25 students at a time, otherwise use a vector


void updateClass() {
	fill_n(gradeInput, 25, 0);
	viewClass();
	
	gotoxy(5, 4 + counter);
	cout << "Please enter the number for which grades you are updating: \n\t\t1 - Assignments\n\t\t2 - Midterm\n\t\t3 - Final\n\t\t" << endl;
	fileSelection = _getch() - '0';

	if (fileSelection == 1 || fileSelection == 2 || fileSelection == 3) {
		for (int i = 0; i < counter; i++) {
			string firstChar = "";
			string secondChar = "";
			string combinedChar = "";

			gotoxy(26 + (fileSelection * 10), 3 + i);
			cout << "   ";
			gotoxy(26 + (fileSelection * 10), 3 + i);
			firstChar = _getche();
			gotoxy(27 + (fileSelection * 10), 3 + i);
			secondChar = _getche();
			combinedChar = firstChar + secondChar;
			gradeInput[i] = combinedChar;


		}
		writeToFileFlag = true;
		gotoxy(5, 9 + counter);
		system("pause");
		viewClass();
	}
	flag = false;
}
#endif