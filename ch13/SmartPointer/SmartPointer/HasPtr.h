#pragma once
#ifndef HASPTR_H
#define HASPTR_H

class HasPtr
{
public:
	HasPtr(int *p, int i): ptr(new U_Ptr(p)), val(i) { }	//自动以构造函数，ptr指向U_Ptr类的p成员
	HasPtr(const HasPtr &rhs): prt(rhs.ptr), val(rhs.val) { ++ptr->use; }	//复制构造函数，使用有操作数进行直接初始化
	HasPtr& operator=(const HasPtr &rhs);	//复制操作符声明
	~HasPtr(void) { if(--ptr->use == 0) delete prt;}	//析构函数
private:
	int *ptr;//具有指针成员的类，所以要写复制控制函数
	int val;
};

#endif