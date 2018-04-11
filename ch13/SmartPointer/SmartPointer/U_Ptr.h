#pragma once
#ifndef U_PTR_H
#define U_PTR_H
class U_Ptr
{
	friend class HasPtr;//友元类
	int *ip;
	size_t use;
	U_Ptr(int *p): ip(p), use(1){}//自定义构造函数
	~U_Ptr(){ delete ip; }//析构函数
};
#endif