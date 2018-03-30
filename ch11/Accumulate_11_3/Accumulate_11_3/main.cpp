/************************************************************************/
/*							 ��ϰ��11.3��11.5                           */
/************************************************************************/
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>
#include <String>
using namespace std;

/************************************************************************/
/*					��ϰ��11.3����:accumulate						    */
/************************************************************************/
int sumOfIvec(){
	vector<int> ivec(5, 1);//5��1���
	int sum = accumulate(ivec.begin(), ivec.end(), 0);
	return sum;
}

/************************************************************************/
/*					��ϰ��11.5���֣�find_first_of					    */
/************************************************************************/
size_t cntOfMatches(){
	size_t cnt = 0;
	list<string> restor1(5, "hello world");
	list<string> restor2(5, "hello world");
	list<string>::iterator it = restor1.begin();
	while((it = find_first_of(it, restor1.end(), restor2.begin(), restor2.end()))
		!= restor1.end()){
			++cnt;
			it;
	}
	return cnt;
}
int main(){
	system("color 5E");
	//������ϰ��11.3
	int sum = sumOfIvec();
	cout << "the cnt of ivec is " << sum << endl;
	//������ϰ��11.5
	size_t cnt = cntOfMatches();
	cout << "the sum of ivec is " << cnt << endl;
	system("pause");
	return 0;
}
