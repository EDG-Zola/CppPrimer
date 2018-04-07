#ifndef MYSCREEN_HPP
#define MYSCREEN_HPP
#include <ostream>
#include <string>
using namespace std;
class MyScreen
{
public:
	typedef std::string::size_type index;
	MyScreen& move(index r, index c);//移动到指定光标位置
	MyScreen& set(char);
	MyScreen& set(index, index, char);//在指定位置设置字符
	MyScreen& display(std::ostream &os);//显示content的内容
	const MyScreen& display(std::ostream &os) const;
	MyScreen(int x, int y, string s):
		contents(" "), cursor(0), height(0), width(0), access_ctr(0){ }
	~MyScreen(void);
private:
	std::string contents;//光标的内容
	index cursor;//
	index height, width;//光标所在位置
	mutable size_t access_ctr;//记录访问display函数的次数
	void do_display(std::ostream &os) const{
		++access_ctr;
		os << contents;
	};
};
#endif