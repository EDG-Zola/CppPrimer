#include <iostream>
using std::ostream; using std::cout; using std::endl;
#include <string>

class U_Ptr
{
	friend class HasPtr;//��Ԫ��
	int *ip;
	size_t use;
	U_Ptr(int *p): ip(p), use(1){}//�Զ��幹�캯��
	~U_Ptr(){ delete ip; }//��������
};


class HasPtr
{
public:
	HasPtr(int *p, int i): ptr(new U_Ptr(p)), val(i) { }	//�Զ��Թ��캯����ptrָ��U_Ptr���p��Ա
	HasPtr(const HasPtr &rhs): ptr(rhs.ptr), val(rhs.val) { ++ptr->use; }	//���ƹ��캯����ʹ���в���������ֱ�ӳ�ʼ��
	HasPtr& operator=(const HasPtr &rhs);	//���Ʋ���������
	~HasPtr(void) { if(--ptr->use == 0) delete ptr;}	//��������
	//���ڲ��ܷ���˽�г�Ա�����Ҫ��д���������ʺ�����˽�г�Ա��ֵ
	int *get_ptr() const { return ptr->ip; }
	int get_int() const {return val; }
	void set_ptr(int *p) { ptr->ip = p;}
	void set_int(int i) { val = i;}
	int get_ptr_val() { return *ptr->ip; }
	void set_ptr_val(int i) {*ptr->ip = i; }
private:
	U_Ptr *ptr;//����ָ���Ա���࣬����Ҫд���ƿ��ƺ���
	int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs){
	++rhs.ptr->use;	//�Ҳ������ļ���ʹ��+1
	if ( --ptr->use == 0) //�����ֵʱ��������ļ���ʹ��Ϊ0,��ɾ��ָ��U_Ptr��ָ��
		delete ptr;
	ptr = rhs.ptr;	//���Ҳ������Ķ���ֵ���������
	val = rhs.val;
	return *this;
}


int main(){
	int x1 = 1;
	int y1 = 10;
	int x2 = 2;
	int y2 = 20;
	HasPtr hasptr1 = HasPtr(&x1, y1);//����һ��HasPtr��Ķ���hasptr1����ʹ���Զ��幹�캯����ʼ��
	HasPtr hasptr2 = HasPtr(&x2, y2);//����һ��HasPtr��Ķ���hasptr1����ʹ���Զ��幹�캯����ʼ��
	cout << "hasptr1:\n\tfirst member " << hasptr1.get_ptr_val() << "\n\tsecond member " << hasptr1.get_int() << endl;
	cout << "hasptr2:\n\tfirst member " << hasptr2.get_ptr_val() << "\n\tsecond member " << hasptr2.get_int() << endl;
	system("pause");
	return 0;
}

