#include "HasPtr.h"
//复制操作符
HasPtr& HasPtr::operator=(const HasPtr &rhs){
	++rhs.ptr->use;	//右操作数的计数使用+1
	if ( --ptr->use == 0) //如果赋值时左操作数的计数使用为0,则删除指向U_Ptr的指针
		delete ptr;
	ptr = rhs.ptr;	//将右操作数的对象赋值给左操作数
	val = rhs.val;
	return *this;
}
