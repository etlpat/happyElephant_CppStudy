#include<iostream>
using namespace std;
#include<string>




//// 静态成员
// 静态成员就是在成员变量、成员函数前面加上static关键字
//
// 静态成员分为：
// 
// 1.静态成员变量（static int a;）
//	特点：(1)所有对象共享同一份数据
//		  (2)在编译阶段分配内存（全局区）
//		  (3)类内声明，类外初始化（this指针不能指向静态变量，无法通过成员函数赋值，只能类外初始化）
//	访问方式：
//		  (1)通过对象调用：对象.成员
//		  (2)通过作用域调用：类名::成员
// 
// 
// 2.静态成员函数（static void func(){}）
//	特点：所有对象共享一个函数
//		  静态成员函数只能操作静态成员变量（因为不含this指针，无法判断非静态变量属于哪个对象）
//	访问方式：
//		  (1)通过对象调用：对象.函数
//		  (2)通过作用域调用：类名::函数
//
//
// 
// 静态成员、静态函数共同点：
// 1.所有类对象共有
// 2.编译阶段分配内存，在全局区
// 3.都可通过对象调用或通过作用域调用
//
// 
// 注意：this指针和静态成员无关
//	     由于this指针不可指向静态成员变量，所以只能类外通过作用域初始化
//	     由于静态成员函数不含this指针，所以只能操作静态成员





////// 静态成员变量：
//
//class MyClass
//{
//public:
//	static int s_a;
//private:
//	static int s_b;
//};
//
//// 静态成员必须类内声明，类外初始化
//int MyClass::s_a = 100;// MyClass:: 表示在MyClass类的作用域下（静态成员作用域是整个类，而非某个对象）
//int MyClass::s_b = 20;// 私有静态成员也在类外初始化
//// 注意：其他初始化方式均报错
//
//
//int main()
//{
// // 静态成员可以通过对象访问
//	MyClass m1;
//	cout << m1.s_a << endl;// 100
//
//	MyClass m2;
//	m2.s_a = 200;
//	cout << m1.s_a << endl;// 200（所有对象共用一份数据）
//	cout << m2.s_a << endl;// 200
//
//
//	// 静态成员可以通过类名(作用域)的方式访问
//	cout << MyClass::s_a << endl;// 200
//
//
//	return 0;
//}






////// 静态成员函数
//
//class Student
//{
//public:
//	string name;
//	static string school;
//
//	static void printSchool() {
//		cout << school << endl;// 静态函数只能访问静态变量
//		//cout << name << endl;// 报错，无法访问非静态变量。原因：无法区分非静态变量属于哪个对象
//	}
//
//};
//
//string Student::school = "XXXschool";// 静态成员--类内声明，类外初始化
//
//int main()
//{
//	// 静态函数调用方式：1.通过对象调用
//	Student s1;
//	s1.printSchool();// XXXschool
//	s1.school = "SSSschool";
//
//	Student s2;
//	s2.printSchool();// SSSschool（所有对象共享一个函数）
//
//
//	// 静态函数调用方式：2.通过作用域调用
//	Student::printSchool();// SSSschool
//	
//
//	return 0;
//}
