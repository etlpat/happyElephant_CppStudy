#include<iostream>
using namespace std;
#include<string>




//// this指针
// 由于C++中成员变量和成员函数是分开存储的，非静态成员变量直接存储在每个对象的内存中
// 而无论创建多少对象，其非静态成员函数只会生成一份函数实例，多个同类型对象共用这一块函数代码。
// 问：这一块函数代码是如何区分哪个对象调用自己呢？
// 答：C++通过提供特殊的对象指针，this指针，解决上述问题。
// 
// 
// 
// this指针概念：
// 【this指针指向被调用的成员函数所属的对象】（this是指针常量，永远指向对象）
// e.g. MyClass类的对象m1调用函数，这时this指针为MyClass*类型，指向m1对象
//
// 注意：
// 1.this指针是隐含在每一个非静态成员函数内的一种指针（包括构造和析构函数）
// 2.this指针不需要定义，可以直接使用
// 3.成员函数中调用的所有自身属性，本质上都是通过this指针来调用（就算我们不写this->变量，运行时系统也会自动补上）
// 
// 
// this指针的用途：
// 1.当形参和成员变量同名时，可用this指针来区分
// 2.在类的非静态成员函数中返回对象本身，可以使用return *this 




//// 知识点补充：(以值的形式返回 和 以引用的形式返回)
// 若想链式调用成员函数，必须[以引用的形式返回]对象
// 【以值的形式返回】：(返回类型:MyClass) 返回的是对象的拷贝(副本)（以值的形式返回对象时，调用拷贝构造函数）
// 【以引用的形式返回】：(返回类型:MyClass&) 返回对象这块空间本身（本质上返回指向对象的常量指针）







//class Person
//{
//public:
//	int age;
//
//	Person() :age(0) { }
//	Person(int age) {
//		// this指针：指向调用该函数的对象
//		this->age = age;// 当形参和成员变量同名时，用this指针区分
//	}
//
//
//	// 注意：若成员函数想链式调用，以引用形式返回*this
//	// 返回引用(返回类型Person&)：返回*this对象这块空间本身（本质上返回指向*this对象的常量指针）
//	// 若返回对象的值(返回类型Person)：返回的是*this对象的拷贝（以值的形式返回对象时，调用拷贝构造函数）
//	Person& personAgeAdd(const Person& p) 
//	{
//		this->age += p.age;
//		return *this;// *this返回这个对象本身
//	}
//};
//
//
//int main()
//{
//	Person p1(18);
//	Person p2(10);
//
//	p1.personAgeAdd(p2);
//	cout << p1.age << endl;// 28
//
//	// 由于personAgeAdd()函数返回p1对象的引用，所以支持链式调用
//	p1.personAgeAdd(p2).personAgeAdd(p2).personAgeAdd(p2);
//	cout << p1.age << endl;// 58
//
//
//	return 0;
//}
