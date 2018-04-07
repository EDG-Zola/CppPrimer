#include "MyScreen.hpp"
#include <ostream>
#include <string>
using namespace std;
int main(){
	MyScreen myScreen(5, 5, "bbbbb\nggggg\nffff\niiiii\n");
	myScreen.move(4,0).set('#').display(cout);
	system("pause");
	return 0;
}