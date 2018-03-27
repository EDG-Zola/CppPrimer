/************************************************************************/
/*      �鱾P317ҳ��һ���ۺ���Ӧ�ã�ʵ�������ļ��еĵ��ʴ洢��ת��      */
/************************************************************************/
#include <iostream>
#include <fstream>//���ڶ�ȡ�ļ���ͷ�ļ�
#include <sstream>
#include <string>
#include <map>
#include <utility>
using namespace std;
int main(int argc, char* argv[]){
	map<string, string> trans_map;//���ڴ洢���ʵ�ת����
	string key, value;//���ڴ洢��ʱ��map_file.txt�ж�ȡ�ĵ���
	//�ж������в����Ƿ�����
	if (argc != 4)
		throw runtime_error("wrong number of arguments");
	//�󶨲���argv[1]�е��ļ�
	ifstream mapFile(argv[1]);
	//δ�ҵ�map_file.txt
	if(!mapFile)
		throw runtime_error("no transformation file");
	//��map_file.txt�е����ݴ洢��map���͵�ֵ��
	while(mapFile >> key >> value){
		trans_map.insert(make_pair(key, value));
	}
	//�󶨲���argv[2]�е��ļ�
	ifstream input(argv[2]);
	//δ�ҵ�input.txt
	if (!input)
		throw runtime_error("no input file");
	//���������output.txt�ļ���
	ofstream output(argv[3], ofstream::out);
	string line;//��ʱ�洢input.txt�е�ÿһ������
	while (getline(input, line))
	{
		istringstream stream(line);//ÿ�ζ�ȡһ���е�һ������
		string word;//������ʱ�洢һ������
		bool firstword = true;
		while(stream >> word){
			map<string, string>::const_iterator map_it =
								trans_map.find(word);
			//�ҵ�����wordƥ��ĵ���
			if(map_it != trans_map.end()){
				word = map_it->second;
			}
			if(firstword)
				firstword = false;
			else{
				cout << " ";
				output << " ";
			}
				
			cout << word;
			output << word;
		}
		cout << endl;
		output << endl;
	}
	mapFile.close();
	input.close();
	output.close();
	system("pause");
	return 0;
}
