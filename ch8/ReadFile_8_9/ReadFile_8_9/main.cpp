#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main(){
	string s;//���ڱ���tesrt.txt��ÿһ������
	/*string filename = "test.txt";*/
	vector<string> file;
	//ע����д��룡��һ��Ҫд��ȫ��·�����ƣ�����Ϊ��IDE�����г����ʱ�򣬳���ĸ�Ŀ¼����debugĿ¼
	ifstream input("E:\\GitWorkstation\\CppPrimer\\ch8\\ReadFile_8_9\\test.txt");
	/*input.open("E:\\GitWorkstation\\CppPrimer\\ch8\\ReadFile_8_9\\test.txt");*/
	if (!input){
		cerr << "can't open file" << endl;
		return -1;
	}
	//���ж�ȡtest.txt������
	while (getline(input,s)){
			file.push_back(s);
	}
	input.close();
	//��ӡ��������file������
	vector<string>::const_iterator it = file.begin();
	while (it != file.end()){
		cout << *it++ << endl; 
	}

	system("pause");
	return 0;
}