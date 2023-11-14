#include<iostream>
using namespace std;
#include<string>




//// 继承中的构造和析构顺序
//
// 1.构造顺序：先构造父类，后构造子类
//		 原因：若想要构造子类对象，必须先构造好父类对象
// 2.析构顺序：先析构子类，后析构父类（与构造顺序相反）
//       原因：对象构造在栈上，先进后出，后进先出
// 
// 以上构造析构顺序，对于多次继承的子类也同理




//class Base
//{
//public:
//	Base() {
//		cout << "Base构造" << endl;
//	}
//	~Base() {
//		cout << "Base析构" << endl;
//	}
//};
//
//class Son : public Base
//{
//public:
//	Son() {
//		cout << "Son构造" << endl;
//	}
//	~Son() {
//		cout << "Son析构" << endl;
//	}
//};
//
//class GrandSon :public Son
//{
//public:
//	GrandSon() {
//		cout << "GrandSon构造" << endl;
//	}
//	~GrandSon() {
//		cout << "GrandSon析构" << endl;
//	}
//};
//
//
//int main()
//{
//	GrandSon g;
//
//	//Base构造
//	//Son构造
//	//GrandSon构造
//	//GrandSon析构
//	//Son析构
//	//Base析构
//
//	return 0;
//}