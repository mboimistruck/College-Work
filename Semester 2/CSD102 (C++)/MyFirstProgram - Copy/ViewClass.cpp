#include "xheaders.h"

using namespace std;

extern bool flag;
extern string temp;
extern bool writeToFileFlag;
int lastRecordNumber;
int counter;

void viewClass() {
	system("cls");
	string a, b, c, d, e, f, g, h;
	string studentRecord = "";

	pullClassList();
	system("cls");
	fstream classFile;
	classFile.open("./Library/" + temp, ios::in | ios::out | ios::binary);
	string line;

	if (writeToFileFlag) {
		int tempCounter = 1;
		gotoxy(10, 10);

		while (getline(classFile, line)) {
			while (true) {
				size_t pos = line.find("N/A");
				if (pos != string::npos) {
					line.replace(pos, 2, "TEST");
					cout << "POS: " << pos << endl;
				}
				else {
					break;
				}
				classFile << line;
				tempCounter++;
			}
		}
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

	fpos_t pos;
	int temps = 0;
	while (classFile >> a >> b >> c >> d >> e >> f >> g >> h) {
		gotoxy(2, 3 + counter);
		cout << a;
		/*temps = classFile.tellg();
		ostream& seekp(streampos temps);
		classFile << "TE";
		gotoxy(10, 10);
		cout << "TEMPS: " << temps << endl;
		system("pause");*/
		gotoxy(5, 3 + counter);
		cout << b;
		gotoxy(21, 3 + counter);
		cout << c;
		gotoxy(36, 3 + counter);
		cout << d;
		gotoxy(46, 3 + counter);
		cout << e;
		gotoxy(56, 3 + counter);
		cout << f;
		gotoxy(63, 3 + counter);
		cout << g;
		gotoxy(72, 3 + counter);
		cout << h << endl;
		counter++;
		continue;
	}

	classFile.close();
	temp = "";
	flag = false;
}