#include <iostream>
using namespace std;


int gatherInput(int lowest = 9999999, int highest = 0) {
	char x[12];
	string months[12] = {"January", "February", "March", "April", "May", "June",
              "July", "August", "September", "October", "November", "December"};
	for (int i = 0; i < 12; i++) {
		cout << "Please enter the amount of rainfall(mm) for the month of "
                                                              << months[i] << ":\n";
                                                              cout << i << endl;
        cin >> x[i];
        cin.ignore();
        if (x[i] <=  lowest) {
        	lowest = (int)x[i];
        	cout << x[i] << endl;
        	cout << lowest << endl;
        }

  }
  cout << "\n";
  cout << "Test\n";
  cout << x[0] << endl;
  cout << x[11] << endl;
  cout << lowest << endl;

  return lowest;
}

int calculateMonths() {
  
  return 0;
}

int outputResults() {

  return 0;
}



void test(){
	char ssid[9];


// Print out the SSID
for (int i = 0; i < 9; i ++)
	cout << "Please enter the SSID: ";
// This will store each character entered into each index of the array
	cin >> ssid;
	cin.ignore();
   // This will display each character on it's own line
   cout << ssid << "\n";

}

int main () {
	//gatherInput();
	test();
  return 0;
}