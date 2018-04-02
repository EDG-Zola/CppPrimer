/************************************************************************/
/* 用一系列算法和容器操作实现对容器内的元素进行排序                    */
/************************************************************************/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

string make_plural(size_t ctr,  const string &worddd, const string &ending){
	return (ctr == 1) ? worddd : worddd + ending;
}
/************************************************************************/
/*  定义两个谓词函数，来使用泛型算法stable_sort和count_if               */
/************************************************************************/
bool isShorter(const string &s1, const string &s2){
	return s1.size() < s2.size();
}

bool GT6(const string &s){
	return s.size() >= 6;
}

int main(){
	system("color 5E");
	ifstream input("wordstext.txt");
	if(!input){
		cerr << "打开文本words.txt错误";
		return false;
	}
	vector<string> words;
	vector<string>::iterator it = words.begin();
	string word;
	//将文本中的单词存储在vector容器中
	while (input >> word){
			words.push_back(word);
	}
	//标准输出vector中的单词
	for (it = words.begin(); it != words.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	//文本排序
	sort(words.begin(),words.end());
	//将无重复的单词复制到序列前端，多余的单词在序列后端
	vector<string>::iterator end_unique = unique(words.begin(), words.end());
	//通过容器操作删除多余的单词
	words.erase(end_unique, words.end());

	//将vector中的单词按单词长度从小到大排序
	stable_sort(words.begin(), words.end(), isShorter);
	//统计长度不小于6的单词
	vector<string>::size_type wc = count_if(words.begin(), words.end(), GT6);
	//打印输出大于6个长度的单词个数
	cout << wc << " " << make_plural(wc, "word", "s") << " 6 characters or longer" << endl;

	system("pause");
	return 0;
}