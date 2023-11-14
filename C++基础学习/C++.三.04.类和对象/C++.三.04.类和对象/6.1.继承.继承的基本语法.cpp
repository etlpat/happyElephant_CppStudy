#include<iostream>
using namespace std;
#include<string>




//// 继承
// 继承是面向对象三大特性之一
// 通过子类继承父类，减少代码的复用
// 子类继承父类，子类中包含：从父类继承过来的成员，和子类自己新增的成员
//
// 子类：也称为 派生类
// 父类：也称为 基类、超类
//
//
// 
// 子类继承父类
// 语法：  
//	class 子类名 : 继承方式 父类名
//	{
//	访问权限:
//		成员属性/函数;
//		...
//	};




//class FatherClass
//{
//public:
//	void father_func() {
//		cout << "父类成员函数" << endl;
//	}
//};
//
//
//// 子类继承父类语法：class 子类名 :继承方式 父类名
//class SonClass :public FatherClass
//{
//public:
//	void son_func() {
//		cout << "子类成员函数" << endl;
//	}
//};
//
//
//int main()
//{
//	SonClass s;
//	
//	s.father_func();// 子类对象调用父类成员方法
//	s.son_func();
//
//
//	return 0;
//}


