#pragma once
#ifndef HASPTR_H
#define HASPTR_H

class HasPtr
{
public:
	HasPtr(int *p, int i): ptr(new U_Ptr(p)), val(i) { }	//�Զ��Թ��캯����ptrָ��U_Ptr���p��Ա
	HasPtr(const HasPtr &rhs): prt(rhs.ptr), val(rhs.val) { ++ptr->use; }	//���ƹ��캯����ʹ���в���������ֱ�ӳ�ʼ��
	HasPtr& operator=(const HasPtr &rhs);	//���Ʋ���������
	~HasPtr(void) { if(--ptr->use == 0) delete prt;}	//��������
private:
	int *ptr;//����ָ���Ա���࣬����Ҫд���ƿ��ƺ���
	int val;
};

#endif