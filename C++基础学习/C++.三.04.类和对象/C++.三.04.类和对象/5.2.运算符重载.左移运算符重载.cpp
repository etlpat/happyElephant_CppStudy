#include<iostream>
using namespace std;
#include<string>




//// 左移运算符重载
// 目的：输出自定义的数据类型的属性
// 全局函数实现语法：ostream& operator<<(ostream& cout, const MyClass& m)
//
// 
// cout：标准输出流的对象，类型是ostream（输出流）
// 注意：
//  1.若想用 cout<<对象值 的方式输出，在参数列表中必须把cout放在要输出的对象左边
//		（由于成员函数不需要将自身对象作为参数，因此无法判断cout在<<的左侧还是右侧。所以不能用成员函数重载<<）
//  2.cout对象在全局只能有一个，必须通过引用传参
//  3.由于<<可以链式调用，所以必须返回cout的引用
//
//
// 
// 由于左移运算符不能作为成员函数，只能在全局中实现。若想要访问私有属性，需要将operator<<函数作为类的友元




//class MyClass
//{
//private:
//	friend ostream& operator<<(ostream& cout, const MyClass& m);// 将左移运算符重载函数声明为类的友元
//	int a;
//	int b;
//
//public:
//	MyClass() :a(0), b(0)
//	{}
//	MyClass(int a1, int b1) :a(a1), b(b1)
//	{}
//};
//
//
//// 全局函数重载左移运算符
//ostream& operator<<(ostream& cout, const MyClass& m) {// 本质是operator<<(cout,m),简化为cout<<m
//	// 注意：cout是标准输出流的对象，全局只能有一个，必须通过引用传参
//	cout << m.a << ", " << m.b;
//	return cout;
//	// 必须返回cout，才能让链式调用左移运算符 <<
//}
//
//
//int main()
//{
//	MyClass m(10, 20);
//	
//	// 通过经过重载的<<输出对象
//	cout << m << endl;// 10, 20
//
//	// 通过全局函数输出对象
//	operator<<(cout, m);// 10, 20
//
//
//	return 0;
//}