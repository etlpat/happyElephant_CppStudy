#include<iostream>
using namespace std;
#include<string>




//// 函数调用运算符重载
// 函数调用运算符：()
// ()重载后，函数调用MyClass.operator()(参数列表);可以直接写为MyClass(参数列表);
// 其使用方式非常像函数的调用，因此称为仿函数
// 注意：仿函数没有固定写法，非常灵活
// 
//
//
// 知识补充：匿名对象
// 语法：类名(参数列表)		如：MyClass("张三", 18);
// 特点：执行完所在行后，系统会立即回收匿名对象。匿名对象常常配合仿函数使用
//
//
// 
// 函数调用擦粉()的重载：
// 语法：返回类型 operator()(参数列表) {...}
// 调用方式：
// 1.通过成员函数调用：对象.operator()(参数列表);
// 2.直接用()调用：对象(参数列表);
// 3.使用匿名对象来调用：MyClass(属性列表)(参数列表); 
//		 MyClass(属性列表)创建了匿名对象，之后调用()的重载
//




//class MyPrint
//{
//public:
//	void operator()(string str) {// ()函数调用运算符的重载
//		cout << str << endl;
//	}
//};
//
//
//class MyAdd
//{
//public:
//	double operator()(double a, double b) {// ()函数调用运算符的重载
//		return a + b;
//	}
//};
//
//
//int main()
//{
//	MyPrint mp;
//	mp.operator()("hello world");// 调用()重载函数
//	mp("hello world");// 直接使用()
//
//
//	MyAdd ma;
//	cout << ma.operator()(2, 3) << endl;// 5，调用()重载函数
//	cout << ma(4, 3) << endl;// 7，直接使用()
//
//	
//	cout << MyAdd()(3, 5) << endl;// 8，创建匿名对象MyAdd()，用匿名对象调用()的重载
//
//
//	return 0;
//}