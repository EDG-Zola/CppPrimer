#include <iostream>
#include <vector>
#include <list>
using namespace std;
int main(){
	vector<int> iodd;
	list<int> ieven;
	int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
	//将ia中的元素复制到iodd和ieven中
	for(int *ip = ia;ip != ia+sizeof(ia)/sizeof(int); ++ip){
		iodd.push_back(*ip);
		ieven.push_back(*ip);
	}
	//打印输出iodd和ieven中的元素
	cout << "elements in iodd : " << endl;
	for(vector<int>::iterator itv=iodd.begin(); itv != iodd.end(); ++itv)
		cout << *itv << " ";
	cout << endl;
	cout << "elements in ieven : " << endl;
	for(list<int>::iterator itl=ieven.begin(); itl != ieven.end(); ++itl)
		cout << *itl << " ";
	cout << endl;

	//删除iodd中的偶数值元素
	for(vector<int>::iterator itv=iodd.begin(); itv != iodd.end(); ){
		if ( (*itv) % 2 == 0 )
			itv = iodd.erase(itv);
		else ++itv;
	}
	//删除ieven中的奇数值元素
	for(list<int>::iterator itl=ieven.begin(); itl != ieven.end();){
		if ( (*itl) % 2 != 0 )
			itl = ieven.erase(itl);
		else ++itl;
	}
	//打印输出删除后iodd和ieven中的元素
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