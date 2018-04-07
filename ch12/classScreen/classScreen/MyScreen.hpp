#ifndef MYSCREEN_HPP
#define MYSCREEN_HPP
#include <ostream>
#include <string>
using namespace std;
class MyScreen
{
public:
	typedef std::string::size_type index;
	MyScreen& move(index r, index c);//�ƶ���ָ�����λ��
	MyScreen& set(char);
	MyScreen& set(index, index, char);//��ָ��λ�������ַ�
	MyScreen& display(std::ostream &os);//��ʾcontent������
	const MyScreen& display(std::ostream &os) const;
	MyScreen(int x, int y, string s):
		contents(" "), cursor(0), height(0), width(0), access_ctr(0){ }
	~MyScreen(void);
private:
	std::string contents;//��������
	index cursor;//
	index height, width;//�������λ��
	mutable size_t access_ctr;//��¼����display�����Ĵ���
	void do_display(std::ostream &os) const{
		++access_ctr;
		os << contents;
	};
};
#endif