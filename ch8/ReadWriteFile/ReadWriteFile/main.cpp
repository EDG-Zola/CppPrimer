/*���ڽ�in.txt�ļ������ݿ�����out.txt��
*˼·���Ƚ�in.txt�е�ÿ�����ݴ洢��vector<string>���������
*�ٽ��������Ԫ��д��out.txt��
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main(){
	string s;
	//����in.txt��infile�ļ���,����infile(ע�⣬ÿ�δ�ǰӦclear��close�ļ���)
	ifstream infile("in.txt");
	if(!infile){
		cerr << "can not open file in.txt";
		return -1;
	}
	vector<string> vec_file;
	//���ж�ȡinfile
	while(getline(infile, s)){
		vec_file.push_back(s);
	}
	infile.close();//�ر��ļ�

	/*��׼���vec_file��Ԫ��*/
	vector<string>::const_iterator it = vec_file.begin();
	while(it != vec_file.end()){
		cout << *it << endl;
		++it;
	}

	/*��vec_file��Ԫ��д��out.txt*/
	//����out.txt��outfile�ļ�������appģʽ��out.txt(ע�⣬ÿ�δ�ǰӦclear��close�ļ���)
	//out.txt��·��ΪE:\Cpp Primer\CppPrimer\ch8\ReadWriteFile\ReadWriteFile
	ofstream outfile("out.txt", ofstream::app);
	it = vec_file.begin();
	while(it != vec_file.end()){
		outfile << *it << endl;
		++it;
	}
	system("pause");
	return 0;
}