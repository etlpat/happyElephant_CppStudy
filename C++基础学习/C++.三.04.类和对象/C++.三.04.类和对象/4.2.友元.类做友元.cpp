#include<iostream>
using namespace std;
#include<string>




//// 类做友元
//
// 补充：类的声明
//  语法：class 类名;
//  如：class MyClass；// 声明MyClass类
//
// 类做友元
// 语法：friend 类的声明;
// 如：friend class MyClass;
// 注意：将如上代码写到类2中，MyClass类就是类2的友元，在MyClass中也可访问类2的私有成员


 

//class Building
//{
//private:
//	friend class Person;// friend + 类的声明，Person类就是Building类的友元
//
//	string bedroom;
//	string washroom;
//
//public:
//	Building() :bedroom("卧室"), washroom("洗手间") 
//	{ }
//};
//
//
//class Person
//{
//public:
//	string name;
//	Building* pb;
//
//	Person() {// 构造类型
//		name = "xxx";
//		pb = new Building;// 在堆区创建对象：new 类名
//	}
//
//	void visit() {
//		// Person类是Building类的友元，可以访问其中的私有变量
//		cout << pb->bedroom << ", ";
//		cout << pb->washroom << endl;
//	}
//};
//
//
//int main()
//{
//	Person p;
//	p.visit();// 卧室, 洗手间
//
//	return 0;
//}