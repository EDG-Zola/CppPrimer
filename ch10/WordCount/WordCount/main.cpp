/************************************************************************/
/*              用于计算输入的每个单词的出现的个数                      */
/************************************************************************/
#include <iostream>
#include <map>	   //map类型的头文件
#include <utility> //pair类型的头文件
#include <vector>
#include <string>
using namespace std;
int main(){
	string word;
	map<string, int> wordCount;
	while (cin >> word)
	{
		//insert方法返回的一个迭代器和一个bool值的pair对象,
		//实参为一个value_type类型的值
		pair< map<string, int>::iterator, bool> ret = 
			wordCount.insert(make_pair(word, 1));
		if (!ret.second){
			++ret.first->second;//map的value值加1
		}
	}
	//打印输出map类型的值
	map<string, int>::const_iterator map_it = wordCount.begin();
	for(; map_it != wordCount.end(); ++map_it){
		cout << "word: " << map_it->first 
			 << " occurs " << map_it->second << " times. \n";
	}
	system("pause");
	return 0;
}