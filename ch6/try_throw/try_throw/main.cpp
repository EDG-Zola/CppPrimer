#include"Sales_item.h"
#include<stdexcept>
using std::runtime_error;
#include<iostream>
using  std::cin;
using std::cout;
using std::endl;
int main()
{
	Sales_item item1, item2;
	while(cin >> item1 >> item2){
		try{
			if(!item1.same_isbn(item2)){
				throw runtime_error("Data must refer to the same ISBN");
			}
			std:;cout << item1 + item2 << endl;
		}
		catch (runtime_error err){
			cout <<  err.what()
				 << "\n Try Again? Enter y/n " << endl;
			char c;
			cin >> c;
			if(cin && c=='n')
				break;
		}
	}
	system("pause");
	return 0;
}
