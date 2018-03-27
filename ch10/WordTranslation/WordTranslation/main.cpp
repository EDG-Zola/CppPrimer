/************************************************************************/
/*      书本P317页的一个综合型应用：实现两个文件中的单词存储与转换      */
/************************************************************************/
#include <iostream>
#include <fstream>//用于读取文件的头文件
#include <sstream>
#include <string>
#include <map>
#include <utility>
using namespace std;
int main(int argc, char* argv[]){
	map<string, string> trans_map;//用于存储单词的转换对
	string key, value;//用于存储临时从map_file.txt中读取的单词
	//判断命令行参数是否满足
	if (argc != 4)
		throw runtime_error("wrong number of arguments");
	//绑定并打开argv[1]中的文件
	ifstream mapFile(argv[1]);
	//未找到map_file.txt
	if(!mapFile)
		throw runtime_error("no transformation file");
	//将map_file.txt中的内容存储到map类型的值中
	while(mapFile >> key >> value){
		trans_map.insert(make_pair(key, value));
	}
	//绑定并打开argv[2]中的文件
	ifstream input(argv[2]);
	//未找到input.txt
	if (!input)
		throw runtime_error("no input file");
	//用于输出到output.txt文件中
	ofstream output(argv[3], ofstream::out);
	string line;//暂时存储input.txt中的每一行数据
	while (getline(input, line))
	{
		istringstream stream(line);//每次读取一行中的一个单词
		string word;//用于临时存储一个单词
		bool firstword = true;
		while(stream >> word){
			map<string, string>::const_iterator map_it =
								trans_map.find(word);
			//找到了与word匹配的单词
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
