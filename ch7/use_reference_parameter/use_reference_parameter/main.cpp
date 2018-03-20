#include<iostream>
#include<vector>
#include<string>
using std::cout; using std::string; using std::cin;
using std::endl; using std::vector;

enum VectorSize {
	small=5, medium=10, large=15
};

/**** 函数声明 ****/
vector<int>::const_iterator find_val(
	vector<int>::const_iterator beg,
	vector<int>::const_iterator end,
	int val, vector<int>::size_type &occurs);

int main(){
	vector<int> ivec;
	vector<int>::size_type occurs = 0;
	int value = 3;
	for (vector<int>::size_type i=0; i != small; ++i){
		ivec.push_back(i);
	}
	vector<int>::const_iterator location = 
		find_val(ivec.begin(), ivec.end(), value, occurs);
	/**** 打印输出 ****/
	if(occurs){
		cout << "value: " << value << " occurs " 
			 << occurs << " times" << endl;
	}

	

	system("pause");
	return 0;
}

/**** 查找一个值val，返回它出现的第一个位置，
**** 并使用引用形参返回它出现的次数val
****/
vector<int>::const_iterator find_val(
	vector<int>::const_iterator beg,
	vector<int>::const_iterator end,
	int val, vector<int>::size_type &occurs){
		vector<int>::const_iterator ref = end;
		occurs= 0;
		for(; beg != end; ++beg){
			if( *beg == val){
				if( ref == end )
					ref = beg;
				++occurs;
			}
		}
		return ref;

}

