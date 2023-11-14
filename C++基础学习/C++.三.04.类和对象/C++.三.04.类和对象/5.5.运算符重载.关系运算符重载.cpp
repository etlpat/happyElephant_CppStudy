#include<iostream>
using namespace std;
#include<string>




//// 关系运算符重载
// 作用：重载关系运算符，可以让两个自定义类型对象进行对比操作
// 重载 == != > < 等运算符，比对对象指定属性，返回布尔值
//
// 
// 语法：
//	成员==函数：bool operator==(Person& p) {...}
//  成员!=函数：bool operator!=(Person& p) {...}
//	全局、其他关系运算符同理




//class Person
//{
//public:
//	string name;
//	int age;
//
//	Person(string str, int n) :name(str), age(n)
//	{}
//
//	bool operator==(Person& p) {// ==关系运算符的重载
//		if (name == p.name && age == p.age)
//			return 1;
//		return 0;
//	}
//
//	bool operator!=(Person& p) {// !=关系运算符的重载
//		if (name != p.name || age != p.age)
//			return 1;
//		return 0;
//	}
//};
//
//
//int main()
//{
//	Person p1("张三", 18);
//	Person p2("张三", 18);
//	Person p3("李四", 25);
//
//	cout << (p1 == p2) << endl;// 1
//	cout << (p1 != p2) << endl;// 0
//	cout << (p1 == p3) << endl;// 0
//	cout << (p1 != p3) << endl;// 1
//
//
//	return 0;
//}