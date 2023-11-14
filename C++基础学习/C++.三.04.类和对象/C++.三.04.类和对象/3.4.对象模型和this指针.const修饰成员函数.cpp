#include<iostream>
using namespace std;
#include<string>




//// const修饰成员函数
//
// 1.常函数：
//	语法：函数参数列表后加const（本质是给this加const）
//        如：void func(...) const {...}
// 
//	注意：1.常函数内不可以修改成员属性
//			  原因：this是指针常量，函数后面加const，本质是给this加const，this类型变为const MyClass* const this，指向的值无法修改。
//		 		    由于成员函数中所有的成员变量，默认都是通过this->来调用，加函数const后无法修改成员属性
//		  2.成员属性声明时附加mutable关键字，在常函数中依然可以修改
//			  mutable adj.可变的
// 
// 
// 
// 2.常对象：
//	语法：const 类名 对象名;
//	注意：1.常对象也不可以修改成员属性（可修改带mutable关键字的成员）
//        2.常对象只能调用常函数（不可调用普通函数，因为普通函数可修改属性）




//class MyClass
//{
//public:
//	int a;
//	mutable int b;
//
//	void func() {
//		cout << "func执行" << endl;
//	}
//
//	void con_func() const {// 这里const作用是修饰this
//		//a = 100;// 报错，常函数中无法修改成员变量（a默认为this->a，this变为常量指针，a的值无法修改）
//		b = 100;// 常函数中可修改带mutable关键字修饰的变量
//		cout << "con_func执行" << endl;
//	}
//
//};
//
//
//int main()
//{
//	MyClass m1;
//	m1.func();
//	m1.con_func();
//
//
//	const MyClass m2;// 常对象
//
//	//m2.a = 10;// 报错，常对象无法修改属性
//	//m2.func()// 报错，常对象无法调用普通成员函数
//
//	m2.b = 10; // 常对象可修改带mutable关键字修饰的变量
//	m2.con_func();// 常对象只能调用常函数
//
//
//	return 0;
//}

