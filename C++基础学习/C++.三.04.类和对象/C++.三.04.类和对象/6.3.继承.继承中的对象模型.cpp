#include<iostream>
using namespace std;
#include<string>




//// 继承中的对象模型
// 问题：从父类中继承过来的成员，哪些属于子类对象中？
//
// 对象的大小：
// 对象的大小等于类中所有非静态成员变量大小的总和（公共、保护、私有变量都存放在对象中）
// 子类对象大小 = 父类所有成员变量大小 + 子类成员变量大小（子类会继承父类的全部属性）
// （若父类是空实现，子类也是空实现，则子类大小默认分配为1）
// 
// 
//
// 成员变量的继承：
// 父类中【所有】非静态成员变量都会被子类继承下去
// 子类会继承父类的私有成员变量，只是其会被编译器【隐藏】，不能访问




//class Base
//{
//public:
//	int a;
//protected:
//	int b;
//private:
//	int c;// 子类只是不能访问父类的私有成员，但还是会继承下去
//};
//
//class Son : public Base
//{
//private:
//	int d;
//};
//
//class GrandSon : public Son
//{
//public:
//	int e;
//};
//
//
//int main()
//{
//	Base b;
//	cout << sizeof(b) << endl;// 12
//
//	Son s;
//	cout << sizeof(s) << endl;// 16
//	
//	GrandSon g;
//	cout << sizeof(g) << endl;// 20
//
//
//	return 0;
//}





// 如下是利用开发者命令提示工具打印的GrandSon类的结构模型
// 步骤：开始菜单打开VS2022开发者命令提示工具，(D:)跳转到D盘，(cd)到当前.cpp文件路径，输入命令"报告单个类布局"(cl /d1 reportSingleClassLayout类名 文件名)
//
//class GrandSo// n  size(20) : 
//	+-- -
//	0 | +-- - (base class Son)
//	0      | | +-- - (base class Base)
//	0      | | | a
//	4      | | | b
//	8      | | | c
//	| | +-- -
//	12      | | d
//	| +-- -
//	16 | e
//	+ -- -