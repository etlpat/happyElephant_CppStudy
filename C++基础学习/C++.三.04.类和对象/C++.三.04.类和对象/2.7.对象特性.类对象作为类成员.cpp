#include<iostream>
using namespace std;
#include<string>




//// 类对象作为类成员
// C++类中的成员可以是另一个类的对象，我们成该成员为“对象成员”
//
// 执行顺序：先构造内部对象，后构造外部对象；先析构外部构造，后析构内部构造
// 原因：两个对象都在栈上，栈先进后出，后进先出





//class Phone
//{
//public:
//	string phoneName;
//
//	Phone() {
//		cout << "Phone构造" << endl;
//	}
//
//	~Phone() {
//		cout << "Phone析构" << endl;
//	}
//};
//
//class Person
//{
//public:
//	string name;
//	Phone phone;
//
//	Person(string n, string p) {
//		name = n;
//		phone.phoneName = p;
//		cout << "Person构建" << endl;
//	}
//
//	~Person() {
//		cout << "Person析构" << endl;
//	}
//};
//
//int main()
//{
//	Person p1("张三", "华为");
//	
//	//Phone构造		// 先构建内部对象，再构建外部对象
//	//Person构建
//	//Person析构	// 后进先出
//	//Phone析构		// 先进后出
//
//	return 0;
//}