#include <iostream>
using std::ostream; using std::cout; using std::endl;
#include <string>

class U_Ptr
{
	friend class HasPtr;//友元类
	int *ip;
	size_t use;
	U_Ptr(int *p): ip(p), use(1){}//自定义构造函数
	~U_Ptr(){ delete ip; }//析构函数
};


class HasPtr
{
public:
	HasPtr(int *p, int i): ptr(new U_Ptr(p)), val(i) { }	//自动以构造函数，ptr指向U_Ptr类的p成员
	HasPtr(const HasPtr &rhs): ptr(rhs.ptr), val(rhs.val) { ++ptr->use; }	//复制构造函数，使用有操作数进行直接初始化
	HasPtr& operator=(const HasPtr &rhs);	//复制操作符声明
	~HasPtr(void) { if(--ptr->use == 0) delete ptr;}	//析构函数
	//由于不能访问私有成员，因此要编写函数来访问和设置私有成员的值
	int *get_ptr() const { return ptr->ip; }
	int get_int() const {return val; }
	void set_ptr(int *p) { ptr->ip = p;}
	void set_int(int i) { val = i;}
	int get_ptr_val() { return *ptr->ip; }
	void set_ptr_val(int i) {*ptr->ip = i; }
private:
	U_Ptr *ptr;//具有指针成员的类，所以要写复制控制函数
	int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs){
	++rhs.ptr->use;	//右操作数的计数使用+1
	if ( --ptr->use == 0) //如果赋值时左操作数的计数使用为0,则删除指向U_Ptr的指针
		delete ptr;
	ptr = rhs.ptr;	//将右操作数的对象赋值给左操作数
	val = rhs.val;
	return *this;
}


int main(){
	int x1 = 1;
	int y1 = 10;
	int x2 = 2;
	int y2 = 20;
	HasPtr hasptr1 = HasPtr(&x1, y1);//创建一个HasPtr类的对象hasptr1，并使用自定义构造函数初始化
	HasPtr hasptr2 = HasPtr(&x2, y2);//创建一个HasPtr类的对象hasptr1，并使用自定义构造函数初始化
	cout << "hasptr1:\n\tfirst member " << hasptr1.get_ptr_val() << "\n\tsecond member " << hasptr1.get_int() << endl;
	cout << "hasptr2:\n\tfirst member " << hasptr2.get_ptr_val() << "\n\tsecond member " << hasptr2.get_int() << endl;
	system("pause");
	return 0;
}

