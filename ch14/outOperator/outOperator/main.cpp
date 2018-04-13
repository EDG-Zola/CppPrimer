#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

class Date{
public:
	friend class CheckoutRecord;
	Date(int y = 0, int m = 0, int d = 0): year(y), month(m), day(d){}
	friend ostream& operator<<(ostream os, const Date &s);
private:
	int year, month, day;
};
ostream& operator<<(ostream os, const Date &s){
	os << s.year << "\t" << s.month << "\t" << s.day;
}

class CheckoutRecord{
public:
	friend ostream& operator<<(ostream &out, CheckoutRecord &s);
	CheckoutRecord(double x, std::string s, Date borrowed, Date due, pair<string, string> bor, vector<pair<string, string>* > wali) 
	{
		book_id = x;
		title = s;
		date_borrowed= borrowed;
		date_due = due;
		borrower = bor;
		wait_list = wali;
	}
private:
	double book_id;
	string title;
	Date date_borrowed;
	Date date_due;
	pair<string, string> borrower;
	std::vector<pair<string, string>* > wait_list;
};
//重载输入操作符
 ostream& operator<<(ostream &out, CheckoutRecord &s){
	out << s.book_id << "\t" << s.title << "\t" << s.date_borrowed << "\t" << s.date_due << "\t"
		<< "bowwrower: " << s.borrower.first << "\t" << s.borrower.second << "\t";
	out	<< "wait_list: ";
		for (vector<pair<string, string>* >::const_iterator it = s.wait_list.begin(); it != s.wait_list.end(); ++it){
			out << (*it)->first << "\t" << (*it)->second << "\t";
		}
		return out;
}

//int main(){
//	//使用构造函数生成一个CheckoutRecord类的对象
//	string title = "title";
//	Date borrowed = Date();
//	Date due = Date();
//	pair<string, string> bor = make_pair("1", "2");
//	pair<string, string>* wali_element = &bor; 
//	std::vector<pair<string, string>* > wali(wali_element);
//	CheckoutRecord checkoutRecord(0.0, title, borrowed, due, bor, wali);
//	cout << operator<<(cout, checkoutRecord);
//	system("pause");
//	return 0;
//}