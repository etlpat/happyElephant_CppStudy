#include<iostream>
using namespace std;
#include<string>




//// 多继承语法
// 多继承：C++允许一个子类继承多个父类
// 语法：class 子类 : 继承方式 父类1, 继承方式 父类2... {...};
// 注意：多继承可能引发父类中有同名成员出现，需要加以区分
// （实际开发中不建议用多继承）
//
// 
// 注意：
//   1.多继承中，若父类有同名成员，需要用作用域加以区分
//   2.多继承对象的大小，等于所有父类以及子类中成员变量大小之和（包括父类私有以及父子同名的变量(它们仍在内存中，只是被隐藏)）




//class Base1
//{
//public:
//	int a;
//	int same;
//
//	Base1() :a(1), same(100) {}
//};
//
//
//class Base2
//{
//public:
//	int b;
//	int same;
//
//	Base2() :b(2), same(200) {}
//};
//
//
//class Son :public Base1, public Base2
//{
//public:
//	int c;
//
//	Son() :c(3) {}
//};
//
//
//int main()
//{
//	Son s;
//	cout << sizeof(s) << endl;// 20（多继承对象的大小=所有父类成员变量大小+子类成员变量大小）
//
//
//	cout << s.a << endl;// 1
//	cout << s.b << endl;// 2
//	cout << s.c << endl;// 3
//
//	cout << s.Base1::same << endl;// 100（当多继承中父类成员同名，需要用作用域加以区分）
//	cout << s.Base2::same << endl;// 200
//
//
//	return 0;
//}

