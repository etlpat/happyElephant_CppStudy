#include<iostream>
using namespace std;
#include<string>




//// 空指针访问成员函数
// C++中空指针也是可以调用成员函数的，但是要注意有没有用到this指针
// 如果用到this指针，需要加以判断保证代码的健壮性
//
//
// 注意：
// 成员函数中，所有的成员变量默认都是(this->成员变量)的形式，只不过(this->)不显示
// （如成员函数内 a 默认为 this->a）
// 此时，若this为空指针，程序崩溃。所以要加入判断语句，this是空指针，直接return




//class MyClass
//{
//public:
//	int a;
//	int b;
//	
//	void printClassName() {
//		cout << "MyClass" << endl;
//	}
//
//	void printA() {
//		cout << a << endl;// 这里的 a 默认为 this->a 的形式
//	}
//
//	void printB() {
//		if (!this) {// 判断对象的指针是否为空指针
//			return;
//		}
//		cout << b << endl;// 这里的 b 默认为 this->b 的形式
//	}
//
//
//
//};
//
//
//int main()
//{
//	MyClass* p = NULL;
//
//	// 空指针也可调用成员函数
//	p->printClassName();// MyClass
//
//	//p->printA();// 程序崩溃
//
//	p->printB();
//
//
//	return 0;
//}