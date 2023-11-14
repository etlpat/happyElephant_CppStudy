#include<iostream>
using namespace std;
#include<string>




////  纯虚函数和抽象类
// 在多态中，通常父类中虚函数的实现是毫无意义的，我们主要都是调用子类重写的内容
// 因此可以将虚函数改为【纯虚函数】
// 
// 
// 纯虚函数语法：virtual 返回类型 函数名 (参数列表) = 0;
// 当类中有了纯虚函数，这个类也称为【抽象类】
//
// 抽象类特点：
// 1.无法实例化对象
// 2.子类必须重写抽象类中的纯虚函数，否则也属于抽象类




//class Base
//{
//	// 类中有纯虚函数，就被称为抽象类（无法实例化对象）
//public:
//	// 纯虚函数
//	virtual void func() = 0;
//};
//
//
//class Son1 : public Base
//{
//public:
//	void func() { cout << "多态Son1" << endl; }
//};
//class Son2 : public Base
//{
//public:
//	void func() { cout << "多态Son2" << endl; }
//};
//void do_func(Base& b) {// 实现多态
//	b.func();
//}
//
//
//int main()
//{
//	//Base b; // 报错，抽象类无法实例化 
//	//new Base;
//
//	Son1 s1;
//	Son2 s2;
//	do_func(s1);// 多态Son1
//	do_func(s2);// 多态Son2
//
//
//	return 0;
//}