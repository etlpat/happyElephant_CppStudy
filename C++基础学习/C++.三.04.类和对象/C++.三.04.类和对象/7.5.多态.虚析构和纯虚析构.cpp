#include<iostream>
using namespace std;
#include<string>




//// 虚析构和纯虚析构
// 多态使用时，如果子类对象中有属性开辟到堆区，那么用该对象的父类指针在释放时无法调用到子类的析构代码，造成内存泄漏
// 解决方式：将父类析构函数改为虚析构或纯虚析构
//
// 
// 虚析构和纯虚析构的共性：
//		1.可用解决父类指针释放子类对象的问题
//		2.都需要有具体的函数实现（即使是纯虚也要类外实现）
// 虚析构和纯虚析构的区别：
//		存在纯虚析构的类是抽象类，无法实例化对象
// 
// 
// 虚析构语法：
//		virtual ~类名() { }
// 纯虚析构语法： 
//		virtual ~类名() = 0; 
//		注意：纯虚析构之后也必须在类外实现（原因：若父类中存在堆区数据，需要靠纯虚析构释放）
//			  类外实现：类名::~类名() { }  






//// 父类指针在析构时，不会调用子类中的析构函数，若子类中有堆区属性，内存泄漏
//class Animal
//{
//public:
//	Animal() {
//		cout << "Animal构造" << endl;
//	}
//	~Animal() {
//		cout << "Animal析构" << endl;
//	}
//
//	virtual void speak() {}
//};
//
//class Cat : public Animal
//{
//public:
//	string* p_name;
//	Cat(string str) {
//		cout << "Cat构造" << endl;
//		p_name = new string(str);
//	}
//	~Cat() {
//		cout << "Cat析构" << endl;
//		if (p_name) {
//			delete p_name;
//			p_name = NULL;
//		}
//	}
//
//	virtual void speak() {
//		cout << *p_name << "：喵喵喵" << endl;
//	}
//};
//
//int main()
//{
//	// 主意：下面代码符合（1.子类对父类虚函数重写 2.父类的指针或引用执行子类对象）因此是多态
//
//	Animal* animal = new Cat("Tom");// Animal构造，Cat构造
//	animal->speak();// Tom：喵喵喵
//	delete animal;// Animal析构
//	
//	// 父类指针在析构时，不会调用子类中的析构函数，若子类中有堆区属性，则内存泄漏
//
//	return 0;
//}







//// 虚析构或纯虚析构能够解决以上问题：
//
//// （1）虚析构：
//class Animal1
//{
//public:
//	Animal1() {
//		cout << "Animal构造" << endl;
//	}
//	virtual ~Animal1() {// 虚析构
//		cout << "Animal虚析构" << endl;
//	}
//	virtual void speak() {}
//};
//
//class Cat1 : public Animal1
//{
//public:
//	string* p_name;
//	Cat1(string str) {
//		cout << "Cat构造" << endl;
//		p_name = new string(str);
//	}
//	~Cat1() {
//		cout << "Cat析构" << endl;
//		if (p_name) {
//			delete p_name;
//			p_name = NULL;
//		}
//	}
//	virtual void speak() {
//		cout << *p_name << "：喵喵喵" << endl;
//	}
//};
//
//void test1() {
//	Animal1* animal1 = new Cat1("Tom");
//	animal1->speak();
//	delete animal1;
//
//	//Animal构造
//	//Cat构造
//	//Tom：喵喵喵
//	//Cat析构// 子类对象正常析构
//	//Animal虚析构
//}
//
//
//
//// （2）纯虚析构
//class Animal2
//{
//public:
//	Animal2() {
//		cout << "Animal构造" << endl;
//	}
//	virtual ~Animal2() = 0;// 纯虚析构
//	virtual void speak() {}
//};
//
//Animal2:: ~Animal2() {// 纯虚析构也要在类外实现（原因：若父类中存在堆区数据，需要靠纯虚析构释放）
//	cout << "Animal纯虚析构" << endl;
//}
//
//class Cat2 : public Animal2
//{
//public:
//	string* p_name;
//	Cat2(string str) {
//		cout << "Cat构造" << endl;
//		p_name = new string(str);
//	}
//	~Cat2() {
//		cout << "Cat析构" << endl;
//		if (p_name) {
//			delete p_name;
//			p_name = NULL;
//		}
//	}
//	virtual void speak() {
//		cout << *p_name << "：喵喵喵" << endl;
//	}
//};
//
//void test2() {
//	Animal2* animal2 = new Cat2("Tom");
//	animal2->speak();
//	delete animal2;
//
//	//Animal构造
//	//Cat构造
//	//Tom：喵喵喵
//	//Cat析构// 子类对象正常析构
//	//Animal纯虚析构
//}
//
//
//
//int main()
//{
//	test1();
//	cout << endl;
//	test2();
//
//	return 0;
//}
