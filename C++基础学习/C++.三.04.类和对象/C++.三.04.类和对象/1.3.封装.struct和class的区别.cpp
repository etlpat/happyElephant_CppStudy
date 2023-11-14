#include<iostream>
using namespace std;
#include<string>




//// struct和class的区别：
// 
// 在C++中，struct和class的区别在于：
// 1.默认访问权限不同，class成员默认权限为私有，struct成员默认权限为公共
// 2.继承方式不同，class可以单继承和多继承，struct只能单继承
// 
// 访问权限区别：
//	struct：默认权限为公共(public)
//	class： 默认权限为私有(private)
// 
// 
// 注意：C++中，结构体内也允许写函数,但是C语言不行。
// （C++中，大部分时候，struct和class的写法格式没有太多区别）




//// 默认访问权限区别：
//
//struct Stu1
//{
//	string name;// 默认权限：公共
//
//	void printName() {
//		cout << name << endl;
//	}
//};
//
//class Stu2
//{
//	string name;// 默认权限：私有
//
//	void printName() {
//		cout << name << endl;
//	}
//};
//
//
//int main()
//{
//	Stu1 s1;
//	Stu2 s2;
//
//	// 结构体成员默认权限为公共
//	s1.name = "张三";
//	s1.printName();
//
//	// 类的成员默认权限为私有
//	//s2.name = "张三";// 报错，私有成员不可访问
//	//s2.printName();// 报错，私有成员不可访问
//
//
//	return 0;
//}