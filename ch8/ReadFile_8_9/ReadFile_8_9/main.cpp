#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main(){
	string s;//用于保存tesrt.txt的每一行数据
	/*string filename = "test.txt";*/
	vector<string> file;
	//注意此行代码！！一定要写上全部路径名称！！因为在IDE中运行程序的时候，程序的根目录不是debug目录
	ifstream input("E:\\GitWorkstation\\CppPrimer\\ch8\\ReadFile_8_9\\test.txt");
	/*input.open("E:\\GitWorkstation\\CppPrimer\\ch8\\ReadFile_8_9\\test.txt");*/
	if (!input){
		cerr << "can't open file" << endl;
		return -1;
	}
	//按行读取test.txt的内容
	while (getline(input,s)){
			file.push_back(s);
	}
	input.close();
	//打印出入容器file的内容
	vector<string>::const_iterator it = file.begin();
	while (it != file.end()){
		cout << *it++ << endl; 
	}

	system("pause");
	return 0;
}