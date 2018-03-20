#include<iostream>
#include<string>
using namespace std;
#define TREESHOLD 10
int main () {
    #ifndef NDEBUG
    cerr << "starting main" << endl;
    #endif
	string word;
	cin >> word;
	if (word.size() <= TREESHOLD ){
		cerr << "Error: " << __FILE__ << endl 
			 << " : line " << __LINE__ << endl
			 << "compile on " << __DATE__ << endl
			 << " at " << __TIME__ << endl
			 << "Word read was " << word << endl;
	}
    system("pause");
    return 0;
}