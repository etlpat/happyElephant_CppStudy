#include<iostream>
using namespace std;
#include<string>




//// 初始化列表
// C++提供了初始化列表语法，对属性赋默认值和初始化
// 语法：构造函数(参数列表):属性1(值1), 属性2(值2)...{ 函数体 }
//
//
// 作用：
// 1.为属性赋默认值：当初始化列表中放入常量时，常量作为属性的默认值
//		如：MyClass() :a(0), b(0), c(0) { }
// 
// 2.为属性赋初值：当初始化列表放入变量时，就能通过传入变量来赋初值
//		如：MyClass(int a1, int b1, int c1) :a(a1), b(b1), c(c1) { }
//
//
// 注意：在手动赋值和默认值之间，属性优先赋为手动赋的值




//class MyClass
//{
//public:
//	int a;
//	int b;
//	int c;
//
//	MyClass() :a(0), b(0), c(0) 
//	{ }// 为属性提供默认值
//
//	MyClass(int a1, int b1, int c1) :a(a1), b(b1), c(c1)
//	{ }// 为属性赋初值
//};
//
//
//int main()
//{
//	MyClass m1;// 初始化列表为属性赋默认值
//	cout << m1.a << ", " << m1.b << ", " << m1.c << endl;// 0, 0, 0
//
//	MyClass m2(1, 2, 3);// 通过初始化列表为属性赋初值
//	cout << m2.a << ", " << m2.b << ", " << m2.c << endl;// 1, 2, 3
//
//
//	return 0;
//}
