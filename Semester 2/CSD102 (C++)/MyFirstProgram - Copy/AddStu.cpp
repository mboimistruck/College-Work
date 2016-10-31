#include "xheaders.h"

using namespace std;
void addStu() {
	extern string temp;
	extern int lastRecordNumber;
	extern bool flag;

	ofstream studentFile;
	string stuFName, stuLName;
	string output[2][2] = { // superfluous 2d array as elements were cut back, revise eventually
		{ stuFName, stuLName }, 
		{ "\nFirst Name: ", "\nLast Name: "}
	};
	system("cls");
	pullClassList();

	studentFile.open("./Library/"+temp, ios_base::app | ios::binary);
	for (int i = 0; i < 2; i++)	{
		cout << output[1][i];
		cin >> output[0][i];
		cin.ignore();
		cout << "TEST: " << output[0][i];

		if (output[0][i] == "\r" || output[0][i] == "" || output[0][i] == " ") {// replaces whitespace input with "N/A"
			output[0][i] = "N/A";
			cout << endl;
		}
	}
	string a, b, c, d, e, f, g, h;
	int counter = 0;
	fstream classFile;
	classFile.open("./Library/" + temp, ios::in | ios::out | ios::binary);
	while (classFile >> a >> b >> c >> d >> e >> f >> g >> h) { // grabs records from file
		if (a != "N/A"){
			lastRecordNumber = stoi(a); // grabs each student number from file and saves it as an int
		} // we're trying to get the last student number on file with this loop
	}


	studentFile << ++lastRecordNumber << " " << output[0][0] << "\t" << output[0][1] << "\t";
	studentFile << " N/A" << " N/A" <<" N/A" << " N/A" << " N/A" << "\r\n";
	studentFile.close();
	temp = "";
	flag = false;
}