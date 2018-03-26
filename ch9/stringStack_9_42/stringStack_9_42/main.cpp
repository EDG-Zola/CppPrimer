#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main(){

	string s;
	stack<string> stk;
	while((stk.size() < 5) && (cin >> s)){
		stk.push(s);
	}
	while(stk.empty() == false){
		s = stk.top();
		cout << s << " ";
		stk.pop();
	}
	cout << endl;

	system("pause");
	return 0;
}