/************************************************************************/
/*              ���ڼ��������ÿ�����ʵĳ��ֵĸ���                      */
/************************************************************************/
#include <iostream>
#include <map>	   //map���͵�ͷ�ļ�
#include <utility> //pair���͵�ͷ�ļ�
#include <vector>
#include <string>
using namespace std;
int main(){
	string word;
	map<string, int> wordCount;
	while (cin >> word)
	{
		//insert�������ص�һ����������һ��boolֵ��pair����,
		//ʵ��Ϊһ��value_type���͵�ֵ
		pair< map<string, int>::iterator, bool> ret = 
			wordCount.insert(make_pair(word, 1));
		if (!ret.second){
			++ret.first->second;//map��valueֵ��1
		}
	}
	//��ӡ���map���͵�ֵ
	map<string, int>::const_iterator map_it = wordCount.begin();
	for(; map_it != wordCount.end(); ++map_it){
		cout << "word: " << map_it->first 
			 << " occurs " << map_it->second << " times. \n";
	}
	system("pause");
	return 0;
}