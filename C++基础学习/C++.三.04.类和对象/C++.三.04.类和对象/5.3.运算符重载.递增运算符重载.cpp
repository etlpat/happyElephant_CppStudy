#include<iostream>
using namespace std;
#include<string>




//// 递增运算符重载
// 通过重载递增运算符，实现对象中整型的递增
// 注意：递增运算符要分为前置++ 和 后置++
//
// 
// ++运行逻辑：
//	  1.前置++：前置++允许链式调用，因此重载函数需要返回对象的引用
//	  2.后置++：后置++不允许链式调用，因此直接返回值递增前的对象的拷贝（不可返回引用，因为出了函数后对象所在的空间被释放）
// 注意：后置++，参数列表末尾必须添加 int占位参数（为了和前置++函数发生重载）
// 
//
// 
// 前置++函数语法：
//	 成员函数：MyClass& operator++() {...}
//   全局函数：MyClass& operator++(MyClass& m) {...}
// 后置++函数语法：
//	 成员函数：MyClass operator++(int) {...} // int占位参数 放在参数列表末尾
//   全局函数：MyClass operator++(MyClass& m, int) {...}




//class MyClass
//{
//private:
//	friend ostream& operator<<(ostream& cout, const MyClass& m);// 友元：<<的重载函数
//	//friend MyClass& operator++(MyClass& m);// 友元：前置++的重载函数
//	//friend MyClass operator++(MyClass& m, int);// 友元：后置++的重载函数
//
//	int a;
//	int b;
//
//public:
//	MyClass() :a(0), b(0)
//	{}
//	MyClass(int a1, int b1) :a(a1), b(b1)
//	{}
//
//	// 前置++的重载函数
//	MyClass& operator++() {
//		a++;
//		b++;
//		return *this;// 由于前置++支持链式调用，故返回引用
//	}
//
//	MyClass operator++(int) {// 注意：后置++，参数列表末尾必须添加 int占位符（为了和前置++函数发生重载）
//		MyClass tmp = *this;
//		a++;
//		b++;
//		return tmp;// 后置++不支持链式调用，返回属性值递增前的对象的拷贝
//		//（不可返回引用，因为出了函数后tmp所在的空间被释放）
//	}
//};
//
//
//// 重载<<运算符
//ostream& operator<<(ostream& cout, const MyClass& m) {
//	cout << m.a << ", " << m.b;
//	return cout;
//}
//
//
////// 全局函数重载前置++
////MyClass& operator++(MyClass& m) {
////	m.a++;
////	m.b++;
////	return m;
////}
////
////// 全局函数重载后置++
////MyClass operator++(MyClass& m, int) {// 注意：int占位符需要放在参数列表末尾
////	MyClass tmp = m;
////	m.a++;
////	m.b++;
////	return tmp;
////}
//
//
//int main()
//{
//	int a = 1;
//	cout << ++(++a) << endl;// 3，前置++允许链式调用
//	//cout << (a++)++ << endl;// 报错，后置++不允许链式调用
//
//
//	MyClass m(10, 20);
//	cout << m << endl;// 10, 20
//
//	cout << ++m << endl;// 11, 21
//	cout << m++ << endl;// 11, 21
//	cout << m << endl;// 12, 22
//
//
//	return 0;
//}