/************************************************************************/
/* ��һϵ���㷨����������ʵ�ֶ������ڵ�Ԫ�ؽ�������                    */
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
/*  ��������ν�ʺ�������ʹ�÷����㷨stable_sort��count_if               */
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
		cerr << "���ı�words.txt����";
		return false;
	}
	vector<string> words;
	vector<string>::iterator it = words.begin();
	string word;
	//���ı��еĵ��ʴ洢��vector������
	while (input >> word){
			words.push_back(word);
	}
	//��׼���vector�еĵ���
	for (it = words.begin(); it != words.end(); ++it){
		cout << *it << " ";
	}
	cout << endl;
	//�ı�����
	sort(words.begin(),words.end());
	//�����ظ��ĵ��ʸ��Ƶ�����ǰ�ˣ�����ĵ��������к��
	vector<string>::iterator end_unique = unique(words.begin(), words.end());
	//ͨ����������ɾ������ĵ���
	words.erase(end_unique, words.end());

	//��vector�еĵ��ʰ����ʳ��ȴ�С��������
	stable_sort(words.begin(), words.end(), isShorter);
	//ͳ�Ƴ��Ȳ�С��6�ĵ���
	vector<string>::size_type wc = count_if(words.begin(), words.end(), GT6);
	//��ӡ�������6�����ȵĵ��ʸ���
	cout << wc << " " << make_plural(wc, "word", "s") << " 6 characters or longer" << endl;

	system("pause");
	return 0;
}