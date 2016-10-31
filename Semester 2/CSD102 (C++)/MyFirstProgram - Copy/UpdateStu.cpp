#include "xheaders.h"

using namespace std;

extern bool flag;
extern string temp;
int testVal2 = 0;

void updateStu() {
	string test = "";
	string test2 = "";
	int test3 = 0;

	viewStu();
	gotoxy(5, 11);
	cout << "Please enter the number for which grades you are updating: \n\t\t1 - Assignments\n\t\t2 - Midterm\n\t\t3 - Final" << endl;
	testVal2 = _getch() - '0';

	gotoxy(42 + (testVal2 * 11), 3);
	cout << "   ";
	gotoxy(42 + (testVal2 * 11), 3);
	test = _getche();
	gotoxy(43 + (testVal2 * 11), 3);
	test2 = _getche();
	test3 = stoi(test + test2);

	gotoxy(5, 12);
	system("pause");
}
