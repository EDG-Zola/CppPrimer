#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main(){
	vector<int> iodd;
	list<int> ieven;
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	//��ia�е�Ԫ�ظ��Ƶ�iodd��ieven��
	for(int *ip = ia;ip != ia+sizeof(ia)/sizeof(int); ++ip){
		iodd.push_back(*ip);
		ieven.push_back(*ip);
	}
	//��ӡ���iodd��ieven�е�Ԫ��
	cout << "elements in iodd : " << endl;
	for(vector<int>::iterator itv=iodd.begin(); itv != iodd.end(); ++itv)
		cout << *itv << " ";
	cout << endl;
	cout << "elements in ieven : " << endl;
	for(list<int>::iterator itl=ieven.begin(); itl != ieven.end(); ++itl)
		cout << *itl << " ";
	cout << endl;

	//ɾ��iodd�е�ż��ֵԪ��
	for(vector<int>::iterator itv=iodd.begin(); itv != iodd.end(); ){
		if ( (*itv) % 2 == 0 )
			itv = iodd.erase(itv);
		else ++itv;
	}
	//ɾ��ieven�е�����ֵԪ��
	for(list<int>::iterator itl=ieven.begin(); itl != ieven.end();){
		if ( (*itl) % 2 != 0 )
			itl = ieven.erase(itl);
		else ++itl;
	}
	//��ӡ���ɾ����iodd��ieven�е�Ԫ��
	cout << "erase even elements in iodd : " << endl;
	for(vector<int>::iterator itv=iodd.begin(); itv != iodd.end(); ++itv)
		cout << *itv << " ";
	cout << endl;
	cout << "erase odd elements in ieven : " << endl;
	for(list<int>::iterator itl=ieven.begin(); itl != ieven.end(); ++itl)
		cout << *itl << " ";
	cout << endl;
	system("pause");

	return 0;		
}