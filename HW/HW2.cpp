/*
*Name:Cory Hutson
*CEH0050
*HW2.cpp
*To Compile and run
*In terminal type g++ -o HW2 HW2.cpp
*./HW2 
*/
#include <iostream>
using namespace std; 
int main() {
	double amountSweetenerMouse=0;
	int mouseWeight=0;
        const double SODA_SWEETENER = .001;
        int dietWeight=0;

	cout << "What is the amount of artificial sweetener needed to kill a mouse: " << endl;
	cin >> amountSweetenerMouse;
	cout << "What is the weight of the mouse: "<<  endl;
	cin >> mouseWeight;
	cout << "What is the weight of dieter: " << endl;
	cin >> dietWeight;
	cout << "You can drink " << (amountSweetenerMouse/mouseWeight)*(dietWeight/SODA_SWEETENER) << " diet sodas without dying as a result."<<endl;
        return 0;
}
