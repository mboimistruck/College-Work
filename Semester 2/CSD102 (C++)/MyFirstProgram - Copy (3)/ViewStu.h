#ifndef ViewStu_H
#define ViewStu_H

#include "xheaders.h"

using namespace std;

extern bool flag;
extern string pulledFileName;

void viewStu() {
	system("cls");
	string a, b, c, d, e, f, g, h;
	string studentRecord = "";
	int counter = 0;
	int userInput;

	pullClassList();

	cout << "\n\tPlease enter the student ID number: " << endl;
	userInput = _getch() - '0';
	system("cls");
	fstream classFile;
	classFile.open("./Library/" + pulledFileName, ios::in | ios::out | ios::binary);

	while (classFile >> a >> b >> c >> d >> e >> f >> g >> h) {
		counter++;

		if (counter == userInput) {
			gotoxy(2, 1);
			cout << "#";
			gotoxy(6, 1);
			cout << "First";
			gotoxy(22, 1);
			cout << "Last";
			gotoxy(34, 1);
			cout << "Assignment";
			gotoxy(46, 1);
			cout << "Midterm";
			gotoxy(55, 1);
			cout << "Final";
			gotoxy(61, 1);
			cout << "Overall";
			gotoxy(70, 1);
			cout << "Letter";
			gotoxy(2, 3);
			cout << a;
			gotoxy(5, 3);
			cout << b;
			gotoxy(21, 3);
			cout << c;
			gotoxy(36, 3);
			cout << d;
			gotoxy(48, 3);
			cout << e;
			gotoxy(56, 3);
			cout << f;
			gotoxy(63, 3);
			cout << g;
			gotoxy(72, 3);
			cout << h << endl;
			break;

		}
	}
	if (userInput > counter) {
		cout << "\n\tStudent number does not exist, check to make sure you selected the right class!" << endl;
	}
	classFile.close();

	pulledFileName = "";
	flag = false;
}
#endif