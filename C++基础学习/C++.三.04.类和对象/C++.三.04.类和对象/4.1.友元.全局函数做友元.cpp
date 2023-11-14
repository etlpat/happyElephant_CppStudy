#include<iostream>
using namespace std;
#include<string>




//// 友元
// 在程序里，有些私有属性也想让类外的一些特殊函数或类进行访问，就需要友元技术
// 友元的目的：让一个函数或者类，访问另一个类中的私有成员
// 友元关键字：friend
//
//
// 友元的三种实现
// 1.全局函数做友元：	friend void func(...);
// 2.类做友元：			friend class MyClass;
// 3.成员函数做友元：	friend void MyClass::func(...);
//
//
// 总结：
// 1.三种写法的共同语法：friend 声明
// 2.友元的声明可以位于共用、私有、保护，其存在位置无关紧要
 


//// 全局函数做友元：
// 语法：friend 函数声明 
// 如：friend void func();
// 注意：想将全局函数作为类的友元，只要把如上语法写到类中即可（公共、保护、私有权限都可以）
// 
// 将如上语法写到类中，全局函数就是类的友元，该全局函数也可以访问类中的私有成员、保护成员





//class Building
//{
//private:
//	friend void func(Building* p);// friend + 函数声明，func便是Building类的友元
//
//	string bedroom;
//	string washroom;
//
//public:
//	Building() :bedroom("卧室"), washroom("洗手间") 
//	{ }
//};
//
//
//void func(Building* p) {
//	// 该函数是Building类的友元，可以访问类中的私有成员
//	cout << p->bedroom << endl;// 卧室
//	cout << p->washroom << endl;// 洗手间
//}
//
//
//int main()
//{
//	Building b;
//	func(&b);
//
//	return 0;
//}

