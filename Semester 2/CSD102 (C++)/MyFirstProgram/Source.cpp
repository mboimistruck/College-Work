//Program Name: A5P1.cpp
//Programmer Name: Michael Boimistruck
//Date Last Compiled: April 20th, 2017
//Program Summary:

/*

Update student needs to implement data change for grades

Clean up, UI/UX

*/

#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
#include <direct.h>
#include <tchar.h>
#include <windows.h>

#include "ViewStu.cpp"
#include "ViewClass.cpp"
#include "UpdateStu.cpp"
#include "UpdateClass.cpp"
#include "CreateClass.cpp"
#include "AddStu.cpp"

#include "xheaders.h"

using namespace std;
bool flag = false;
bool initialFlag = true;
string className;
wstring fileName;
string pulledFileName = "";

void gotoxy(int x, int y) {
	COORD coords;
	coords.X = x;
	coords.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coords);

}

bool dirExists(const string& dirName_in) { //gypsy magic method to check file for directory attributes
	DWORD ftype = GetFileAttributesA(dirName_in.c_str());
	if (ftype == INVALID_FILE_ATTRIBUTES) {
		return false;  
	}
	if (ftype & FILE_ATTRIBUTE_DIRECTORY) { // if it is a directory
		return true;   
	}
	return false;    
}

void pullClassList() {
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	int counter = 0;
	int userSelection = 0;
	cout << "\n\tPlease select the number for the class you would like to add the student too" << endl;
	hFind = FindFirstFile(LPCWSTR(_T("./Library/*.dat")), &FindFileData); // grab the first file name and set as a starting point for FindNextFile
	do { // lists all of the files + associates a number value to them
		counter++;
		fileName = FindFileData.cFileName;
		wcout << "\t" << counter << " - " << fileName << "\n";

	} while (FindNextFile(hFind, &FindFileData));

	userSelection = _getch() - '0';
	hFind = FindFirstFile(LPCWSTR(_T("./Library/*.dat")), &FindFileData); // reset pointer to first file in directory

	for (int i = 0; i < (int)userSelection; i++) { // loop through the directory based on the value the user selected in order to select the correct file
		if (i == userSelection - 1) {
			fileName = FindFileData.cFileName;
			break; // break to prevent findnextfile to execute a redundant search after
		}
		FindNextFile(hFind, &FindFileData);
	}
	for (char x : fileName) { // converts the wstring filename to a string (char by char) to use as a directory for opening files below
		pulledFileName += x;
	}
}

void checkForAssets() { // checks this on every execution in order to create required files/directory
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;

	if (!dirExists("./Library")){ // check for directory's existence, if not, make it exist
		_mkdir("./Library");
	}

	hFind = FindFirstFile(LPCWSTR(_T("./Library/*.dat")), &FindFileData); // check for the existence of a file, create one if it doesn't exist

	if (hFind == INVALID_HANDLE_VALUE) {		
		initialFlag = false;
		cout << "\tNo classes are on record, please provide a class name in order to proceed: " << endl;
		cin >> className; // assuming the user will only input one grouping of chars, else use a getline
		createClass(); // calls default createClass to fill generic class

	}
}

void intro() {

	checkForAssets();

	while (!flag){
		system("cls");
		cout << "\n\t\t\tIntro screen\n\t1: Create class\n\t2: Add student\n\t3: Update class\n\t4: Update student data\n\t5: View class data\n\t6: View student data\n\t7: Exit" << endl;
		int uInput = 0;
		uInput = _getch() - '0';
		
		if (uInput == 1){
			flag = true;
			createClass();
		}
		else if (uInput == 2){
			flag = true;
			addStu();
		}
		else if (uInput == 3){
			char check = 'y';
			do {
				flag = true;
				updateClass();
				gotoxy(10, 15);
				cout << "Add more grades? y/n";
				check = _getch();
			} while (check == 'y' || check == 'Y');
		}
		else if (uInput == 4){
			flag = true;
			updateStu();
		}
		else if (uInput == 5){
			flag = true;
			viewClass();
			system("pause");
		}
		else if (uInput == 6){
			flag = true;
			viewStu();
		}
		else if (uInput == 7){
			flag = true;
		}
		else{
			continue;
		}
	}

}
int main() {
	while (!flag) {
		intro();
	}

	system("pause");

	return 0;
}
