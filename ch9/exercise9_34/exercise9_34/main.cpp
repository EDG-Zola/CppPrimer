#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	string s("hello world!");
	for(string::iterator it = s.begin(); it != s.end(); ++it)
		cout << *it;
	cout << endl;
	for(string::iterator it = s.begin(); it != s.end(); ++it)
		*it = toupper(*it);
	for(string::iterator it = s.begin(); it != s.end(); ++it)
		cout << *it;
	cout << endl;
	system("pause");
	return 0;
}