#include<iostream>
using namespace std;
#include<string>




//// 同名静态成员的处理
// 问题：继承中父类子类同名的静态成员在子类对象上如何进行访问？
// 静态成员同名，和非静态成员的处理方式一致
//
// 
// 关于静态成员的知识点： 
// （1）静态成员变量：static int a;
//		特点：1.所有对象共享同一份数据   2.在编译阶段在全局区分配内存   3.类内声明，类外初始化
// （2）静态成员函数：static void func(...) {...}
//		特点：1.所有对象共享一个函数   2.静态成员函数只能操作静态成员变量
// （3）静态成员访问方式：1.通过对象.访问   2.通过作用域::访问（静态成员所有对象共有，可以通过作用域(类)访问）
//
// 
//  
// 同名静态成员的访问方式：
// 1.访问子类同名静态成员：
//		通过子类对象直接访问：s.a （成员函数同理）
//      直接通过作用域访问：Son::a
// 2.访问父类同名静态成员：
//		通过对象访问，并加上父类作用域：s.Base::a
//		直接通过作用域访问：Base::a
//		间接通过作用域访问：Son::Base::a（表示Son作用域下的(Base作用域下的a)）




//class Base
//{
//public:
//	static int a;
//
//	static void func() {
//		cout << "父类静态func" << endl;
//	}
//};
//
//int Base::a = 20;
//
//
//class Son :public Base
//{
//public:
//	static int a;
//
//	static void func() {
//		cout << "子类静态func" << endl;
//	}
//};
//
//int Son::a = 100;
// 
//
//
//int main()
//{
//	Son s;
//
//	// 1.访问静态成员变量
//	// (1)通过对象访问：
//	cout << s.a << endl;// 100（父子类同名成员，优先访问子类成员）
//	cout << s.Base::a << endl;// 20（通过作用域，可访问父类成员）
//	// (2)通过作用域访问：
//	cout << Son::a << endl;// 100（静态成员，所有类对象共享，可通过作用域访问）
//	cout << Base::a << endl;// 20
//	cout << Son::Base::a << endl;// 20（表示Son作用域下的(Base作用域下的a)）
//	
//
//
//	// 2.访问静态成员函数
//	// (1)通过对象访问：
//	s.func();// 子类静态func
//	s.Base::func();// 父类静态func
//	// (2)通过作用域访问：
//	Son::func();// 子类静态func
//	Base::func();// 父类静态func
//	Son::Base::func();// 父类静态func， Son作用域下有两个func，父类被隐藏
//
//
//	return 0;
//}
