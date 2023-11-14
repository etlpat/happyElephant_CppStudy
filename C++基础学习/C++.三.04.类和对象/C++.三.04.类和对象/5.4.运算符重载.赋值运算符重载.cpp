#include<iostream>
using namespace std;
#include<string>




//// 赋值运算符重载
//
//
 //默认情况下，C++编译器至少给一个类添加4个函数
 //1.默认构造函数（空实现）
 //2.默认析构函数（空实现）
 //3.默认拷贝构造函数，对属性进行拷贝（默认浅拷贝）
 //4.赋值运算符operator=，对属性进行值拷贝（浅拷贝）
 // 
// 
// 系统默认赋值运算的operator=是浅拷贝。若类中属性有指向堆区的指针，赋值操作是也会出现深浅拷贝的问题。
// （浅拷贝问题：对象1中有堆区指针p1，令对象2=对象1，赋值默认为浅拷贝，对象2的指针p2的值=p1，p1和p2指向一块堆区空间，两对象析构时将这块空间释放两次，报错）
// 因此，若类中有指向堆区的指针，我们需要将赋值运算符= 重载为深拷贝
// 
//
// 
// 
// 赋值运算符
// 运算逻辑：a=b式子返回a的值，允许链式调用，从右向左结合（因此返回引用类型）
//
// 
// 赋值运算符重载
// 成员函数语法：Person& operator=(Person& p) {...}
// 全局函数语法：同理...
// 注意：
//	1.在堆区分配新空间前，先释放旧空间
//  2.赋值运算符允许链式调用，因此返回对象的引用




//class Person
//{
//public:
//	int* p_age;
//
//	Person() :p_age(NULL) {}
//	Person(int age) {
//		p_age = new int(age);
//	}
//	~Person() {
//		delete p_age;
//	}
//
//	Person& operator=(Person& p) {// 深拷贝的赋值运算符重载
//		if (this->p_age != NULL) {
//			delete p_age;// 分配新空间前，先释放旧空间
//			p_age = NULL;
//		}
//		this->p_age = new int(*(p.p_age));
//		return *this;// =允许链式调用，因此返回引用
//	}
//};
//
//
//
//int main()
//{
//	int a = 1, b = 2, c = 3;
//	cout << (a = b = c) << endl;// 3，=允许链式调用，从右向左结合
//
//
//	Person p1(18);
//	Person p2(25);
//
//	cout << *(p1.p_age) << endl;// 18
//	cout << *(p2.p_age) << endl;// 25
//
//	p1 = p2;// 直接调用 = 的重载
//	cout << *(p1.p_age) << endl;// 25
//
//	// 通过函数调用 = 的重载
//	p1.operator=(p2);
//
//
//	return 0;
//}