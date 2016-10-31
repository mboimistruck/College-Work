#include <stdlib.h>// rands
#include <time.h> 

using namespace std;

void createClass() {
	system("cls");
	srand(time(NULL));

	int randomFNamePointer;
	int randomLNamePointer;
	extern bool flag;
	extern bool initialFlag;
	extern string className;

	string names[10][10] = { 
							{ "John", "Jane", "Frank", "Bob", "Clark", "Tom", "Melissa", "Joe", "Luis", "Ted" },
							{ " Doe", " Cat", " Griswald", " Sherbert", " Johnson", " West", " Jones", " Robertson", " Coleman", " Jordan" } 
							};
	if (initialFlag) {
		cout << "\n\tPlease enter a name for the class: " << endl;
		cin >> className;
	}
	ofstream outfile("./Library/" + className + ".dat", ios::binary | ios::out);
	for (int i = 0; i < 5; i++) {
		randomFNamePointer = rand() % 9;
		randomLNamePointer = rand() % 9;
		outfile << i + 1 << " " << names[0][randomFNamePointer] << names[1][randomLNamePointer] << " -1" << " -1" << " -1" << " -1" << " -1" << "\r\n";
		initialFlag = true;
	}
	outfile.close();
	flag = false;
}