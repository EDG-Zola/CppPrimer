#include "MyScreen.hpp"

MyScreen& MyScreen::set(char c){
	contents[cursor] = c;
	return *this;
}



MyScreen& MyScreen::move(index r, index c){
	index row = r * width;
	cursor = row + c;
	return *this;
}

MyScreen&  MyScreen::display(std::ostream &os){
	do_display(os);
	return *this;
}

const MyScreen&  MyScreen::display(std::ostream &os) const{
	do_display(os);
	return *this;
}

MyScreen::MyScreen(int x, int y, string s)
{
}	


MyScreen::~MyScreen(void)
{
}
