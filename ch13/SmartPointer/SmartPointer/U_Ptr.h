#pragma once
#ifndef U_PTR_H
#define U_PTR_H
class U_Ptr
{
	friend class HasPtr;//��Ԫ��
	int *ip;
	size_t use;
	U_Ptr(int *p): ip(p), use(1){}//�Զ��幹�캯��
	~U_Ptr(){ delete ip; }//��������
};
#endif