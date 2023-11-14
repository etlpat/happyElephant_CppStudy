#include<iostream>
using namespace std;
#include<string>




//// 成员函数做友元
// 语法：friend 成员函数声明 （必须加 作用域::）
// 如：friend void MyClass::func();
// 注意：将如上代码写到类2中，MyClass类的成员函数func就是类2的友元
//
//
// 成员函数做友元，因编译环境不同容易造成bug，平时直接用类做友元即可




//class Building;
//
//
//class Person
//{
//private:
//	Building* pb;
//
//public:
//	Person() {
//		pb = new Building;
//	}
//
//	void visit(); // visit函数的声明，在类外实现
//};
//
//
//class Building
//{
//private:
//	friend void Person::visit();// 成员函数做友元（成员函数声明时带作用域）
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
//void Person::visit() {// visit函数的实现（类外实现成员函数要加作用域）
//	cout << pb->bedroom << endl;
//	cout << pb->washroom << endl;
//}
//
//
//int main()
//{
//	Person p;
//	p.visit();
//
//	return 0;
//}


