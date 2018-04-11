//#include <iostream>
//using std::ostream; using std::cout; using std::endl;
//#include <string>
//
//class U_Ptr
//{
//	friend class HasPtr;//友元类
//	int *ip;
//	size_t use;
//	U_Ptr(int *p): ip(p), use(1){}//自定义构造函数
//	~U_Ptr(){ delete ip; }//析构函数
//};
//
//
//class HasPtr
//{
//public:
//	HasPtr(int *p, int i): ptr(new U_Ptr(p)), val(i) { }	//自动以构造函数，ptr指向U_Ptr类的p成员
//	HasPtr(const HasPtr &rhs): ptr(rhs.ptr), val(rhs.val) { ++ptr->use; }	//复制构造函数，使用有操作数进行直接初始化
//	HasPtr& operator=(const HasPtr &rhs);	//复制操作符声明
//	~HasPtr(void) { if(--ptr->use == 0) delete prt;}	//析构函数
//private:
//	int *ptr;//具有指针成员的类，所以要写复制控制函数
//	int val;
//};
//
//HasPtr& HasPtr::operator=(const HasPtr &rhs){
//	++rhs.ptr->use;	//右操作数的计数使用+1
//	if ( --ptr->use == 0) //如果赋值时左操作数的计数使用为0,则删除指向U_Ptr的指针
//		delete ptr;
//	ptr = rhs.ptr;	//将右操作数的对象赋值给左操作数
//	val = rhs.val;
//	return *this;
//}
//
//
//int main(){
//	int x1 = 1;
//	int y1 = 10;
//	int *p_x1 = &x;
//	int x2 = 2;
//	int y2 = 20;
//	int *p_x2 = &x;
//	HasPtr hasptr1 = HasPtr(p_x1, y1);//创建一个HasPtr类的对象hasptr1，并使用自定义构造函数初始化
//	HasPtr hasptr2 = HasPtr(p_x2, y2);//创建一个HasPtr类的对象hasptr1，并使用自定义构造函数初始化
//
//}
#include <iostream>
using std::ostream; using std::cout; using std::endl;
#include <string>
#include <cstddef>
using std::size_t;

//private class for use by HasPtr only
class U_Ptr {
	friend class HasPtr;
	int *ip;
	size_t use;
	U_Ptr(int *p): ip(p), use(1) { }
	~U_Ptr() { delete ip; }
};

class HasPtr {
public:
	// HasPtr owns the pointer; p must have been dynamically allocated
	HasPtr(int *p, int i): ptr(new U_Ptr(p)), val(i) { }

	// copy members and increment the use count
	HasPtr(const HasPtr &orig):
	ptr(orig.ptr), val(orig.val) { ++ptr->use; }
	HasPtr& operator=(const HasPtr&);

	// if use count goes to zero, delete the U_Ptr object
	~HasPtr() { if (--ptr->use == 0) delete ptr; } 

	friend ostream& operator<<(ostream&, const HasPtr&);
	// copy control and constructors as before

	// accessors must change to fetch value from U_Ptr object
	int *get_ptr() const { return ptr->ip; } 
	int get_int() const { return val; }

	// change the appropriate data member
	void set_ptr(int *p) { ptr->ip = p; }
	void set_int(int i) { val = i; }

	// return or change the value pointed to, so ok for const objects
	// Note: *ptr->ip is equivalent to *(ptr->ip)
	int get_ptr_val() const { return *ptr->ip; } 
	void set_ptr_val(int i) { *ptr->ip = i; }
private:
	U_Ptr *ptr;        // points to use-counted U_Ptr class
	int val;
};

HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
	++rhs.ptr->use;     // increment use count on rhs first
	if (--ptr->use == 0)
		delete ptr;    // if use count goes to 0 on this object, delete it
	ptr = rhs.ptr;      // copy the U_Ptr object
	val = rhs.val;      // copy the int member
	return *this;
}

ostream& operator<<(ostream &os, const HasPtr &hp)
{
	os << "*ptr: " << hp.get_ptr_val() << "\tval: " << hp.get_int() << endl;
	return os;
}

int main()
{
	int obj = 0;

	HasPtr ptr1(&obj, 42);
	HasPtr ptr2(ptr1);
	cout << "(1) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

	ptr1.set_ptr_val(42); // sets object to which both ptr1 and ptr2 point
	ptr2.get_ptr_val();   // returns 42

	cout << "(2) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;

	ptr1.set_int(0);   // changes s member only in ptr1
	ptr2.get_int();    // returns 42
	ptr1.get_int();    // returns 0

	cout << "(3) ptr1: " << ptr1 << endl << "ptr2: " << ptr2 << endl;
}

void f3()
{
	int obj;
	HasPtr p1(&obj, 42);
	HasPtr p2(p1);  // p1 and p2 both point to same int object
	HasPtr p3(p1);  // p1, p2, and p3 all point to same int object
}
