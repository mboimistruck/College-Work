#include "xheaders.h"

using namespace std;

extern bool flag;
extern string temp;
extern int counter;
int testVal = 0;
bool writeToFileFlag = false;

void updateClass() {
	viewClass();
	int testArray[25]; // set to 25 under the assumption that the user won't enter more than 25 students at a time, otherwise use a vector

	gotoxy(5, 4 + counter);
	cout << "Please enter the number for which grades you are updating: \n\t\t1 - Assignments\n\t\t2 - Midterm\n\t\t3 - Final" << endl;
	testVal = _getch() - '0';

	for (int i = 0; i < counter; i++) {
		string test = "";
		string test2 = "";
		int test3 = 0;

		gotoxy(26 + (testVal * 10), 3 + i);
		cout << "   ";
		gotoxy(26  + (testVal * 10), 3 + i);
		test = _getche();
		gotoxy(27 + (testVal * 10), 3 + i);
		test2 = _getche();
		test3 = stoi(test + test2);
		testArray[i] = test3;

	}
	writeToFileFlag = true;
	gotoxy(5, 9 + counter);
	system("pause");
}