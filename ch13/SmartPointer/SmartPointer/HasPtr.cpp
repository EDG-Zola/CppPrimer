#include "HasPtr.h"
//���Ʋ�����
HasPtr& HasPtr::operator=(const HasPtr &rhs){
	++rhs.ptr->use;	//�Ҳ������ļ���ʹ��+1
	if ( --ptr->use == 0) //�����ֵʱ��������ļ���ʹ��Ϊ0,��ɾ��ָ��U_Ptr��ָ��
		delete ptr;
	ptr = rhs.ptr;	//���Ҳ������Ķ���ֵ���������
	val = rhs.val;
	return *this;
}
