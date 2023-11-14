#include<iostream>
using namespace std;
#include<string>




//// 继承方式
// 继承的语法：class 子类 : 继承方式 父类 {...};
//
// 继承方式一共有三类：
// 1.公共继承
// 2.保护继承  
// 3.私有继承
//
//
// 
//// 继承方式的运作规则：
// 注意：父类中的私有成员，无论用哪种继承方式，子类都无法访问 （子类只能访问父类中公共和保护权限的成员）
// 
// 1.公共继承(public)：父类中的成员是什么权限，子类继承到的成员就是什么权限
// 2.保护继承(protected)：子类继承父类的成员，并全部赋予保护(protected)权限
// 3.私有继承(private)：子类继承父类的成员，并全部赋予私有(private)权限




//class Base
//{
//public:
//	int a;
//protected:
//	int b;
//private:
//	int c;
//};
//
//
//
//class Son1 :public Base// 公共继承
//{
//public:
//	void func() {
//		a = 100;// 公共继承，父类a公共，子类继承的a也是公共
//		b = 100;// 公共继承，父类b保护，子类继承的a也是保护
//		//c = 100;// 子类无法访问父类的私有成员
//	}
//};
//
//void test1()
//{
//	Son1 s;
//	s.a;// 可以访问共有成员
//	//s.b;// 不可访问保护成员
//}
//
//
//
//class Son2 :protected Base// 保护继承
//{
//public:
//	void func() {
//		a = 100;// 保护继承，子类继承到的ab都是保护权限
//		b = 100; 
//		//c = 100;// 子类无法访问父类的私有成员
//	}
//};
//
//void test2()
//{
//	Son2 s;
//	//s.a;// 不可访问保护成员 
//	//s.b;
//}
//
//
//
//class Son3 :private Base// 私有继承
//{
//public:
//	void func() {
//		a = 100;// 私有继承，子类继承到的ab都是私有权限
//		b = 100;
//		//c = 100;// 子类无法访问父类的私有成员
//	}
//};
//
//void test3()
//{
//	Son3 s;
//	//s.a;// 不可访问私有成员 
//	//s.b;
//}
//
//class GrandSon3 : public Son3
//{
//public:
//	void func() {
//		//a = 100;// Son3的ab成员都是私有，无法访问
//		//b = 100;
//	}
//};
//
//
//
//
//int main()
//{
//	test1();
//	test2();
//	test3();
//
//	return 0;
//}
