#include "xheaders.h"

using namespace std;

extern bool flag;
extern string pulledFileName;
extern bool writeToFileFlag;
extern string gradeInput[25];
extern int fileSelection;
int lastRecordNumber;
int counter;
char letterValue; // sets up letter grades

void grabLetterGrade(string overallMark) {
	if (stof(overallMark) >= 80.0) {
		letterValue = 'A';
	}
	else if (stof(overallMark) >= 70.0) {
		letterValue = 'B';
	}
	else if (stof(overallMark) >= 60.0) {
		letterValue = 'C';
	}
	else if (stof(overallMark) >= 50.0) {
		letterValue = 'D';
	}
	else {
		letterValue = 'F';
	}
}

void viewClass() {
	system("cls");
	string a, b, c, d, e, f, g, h;
	string studentRecord = "";

	pullClassList();
	system("cls");
	fstream classFile;
	string lineArray[25];

	if (writeToFileFlag) {
		int tempCounter = 0;
		classFile.open("./Library/" + pulledFileName, ios::in | ios::out | ios::binary);
		while (classFile >> a >> b >> c >> d >> e >> f >> g >> h) {
			if (fileSelection == 1) {
				string overallMark = to_string((stof(gradeInput[tempCounter])*0.2) + ((stof(e) + 1)*0.3) + ((stof(f) + 1)*0.5)); // calculates overall average on each pass
				if (stof(overallMark) <= 99.9 || stof(overallMark) > 9.9) { // set up truncation based on mark, in case they get 100 in everything
					overallMark.resize(4);
				} else {
					overallMark.resize(3);
				}
				grabLetterGrade(overallMark);
				lineArray[tempCounter] = a + " " + b + " " + c + " " + gradeInput[tempCounter] + " " + e + " " + f + " " + overallMark + " " + letterValue + "\r\n";

			} else if (fileSelection == 2) {
				string overallMark = to_string((stof(d)*0.2) + ((stof(gradeInput[tempCounter]) + 1)*0.3) + ((stof(f) + 1)*0.5)); // calculates overall average on each pass
				if (stof(overallMark) <= 99.9 || stof(overallMark) > 9.9) { // set up truncation based on mark, in case they get 100 in everything
					overallMark.resize(4);
				}
				else {
					overallMark.resize(3);
				}
				grabLetterGrade(overallMark);
				lineArray[tempCounter] = a + " " + b + " " + c + " " + d + " " + gradeInput[tempCounter] + " " + f + " " + overallMark + " " + letterValue + "\r\n";

			} else if (fileSelection == 3) {
				string overallMark = to_string((stof(d)*0.2) + ((stof(e) + 1)*0.3) + ((stof(gradeInput[tempCounter]) + 1)*0.5)); // calculates overall average on each pass
				if (stof(overallMark) <= 99.9 || stof(overallMark) > 9.9) { // set up truncation based on mark, in case they get 100 in everything
					overallMark.resize(4);
				}
				else {
					overallMark.resize(3);
				}
				grabLetterGrade(overallMark);
				lineArray[tempCounter] = a + " " + b + " " + c + " " + d + " " + e + " " + gradeInput[tempCounter] + " " + overallMark + " " + letterValue + "\r\n";
			}
			tempCounter++;
			continue;
		}
		classFile.close();
		ofstream outfile("./Library/" + pulledFileName, ios::binary | ios::out);
		for (int i = 0; i < tempCounter; i++) {
			outfile << lineArray[i];
		}
		outfile.close();
		writeToFileFlag = false;
	}

	counter = 0;

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

	int temps = 0;
	classFile.open("./Library/" + pulledFileName, ios::in | ios::out | ios::binary);
	while (classFile >> a >> b >> c >> d >> e >> f >> g >> h) {
		gotoxy(2, 3 + counter);
		cout << a;
		gotoxy(5, 3 + counter);
		cout << b;
		gotoxy(21, 3 + counter);
		cout << c;
		gotoxy(36, 3 + counter);
		if (d != "N/A") {
			cout << "N/A";
		}
		else {
			cout << d;
		}
		gotoxy(46, 3 + counter);
		if (e != "N/A") {
			cout << "N/A";
		}
		else {
			cout << e;
		}
		gotoxy(56, 3 + counter);
		if (f != "N/A") {
			cout << "N/A";
		}
		else {
			cout << f;
		}
		gotoxy(63, 3 + counter);
		if (g != "N/A") {
			cout << "N/A";
		}
		else {
			cout << g;
		}
		gotoxy(72, 3 + counter);
		if (h != "N/A") {
			cout << "N/A";
		}
		else {
			cout << h << endl;
		}
		counter++;
		continue;
	}

	classFile.close();
	pulledFileName = "";
	flag = false;
}
