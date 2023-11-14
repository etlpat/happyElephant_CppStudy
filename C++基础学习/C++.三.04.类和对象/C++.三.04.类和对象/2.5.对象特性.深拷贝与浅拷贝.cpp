#include<iostream>
using namespace std;
#include<string>




//// 深拷贝与浅拷贝
// 
// 浅拷贝：对成员变量进行简单的逐字节拷贝
//		 （属性中若有堆区指针，浅拷贝就是将指针的值直接拷贝到另一个对象的指针中，两个对象中的指针指向同一块空间）
//		   如：int* p = MyClass.p;
// 
// 深拷贝：在堆区重新申请空间，进行拷贝操纵
//		 （深拷贝在拷贝对象时，创建一块新的空间来存放指针指向的值，两个对象中的指针指向不同的两块空间）
//         如：int* p = new int(*MyClass.p);
//
//
// 
// 提示：如果属性中有堆区指针，一定要自己提供深拷贝构造函数，防止浅指针带来的问题（默认提供的拷贝函数为浅拷贝）




////// 【系统默认创建的拷贝构造函数，拷贝方式是浅拷贝】
//class Person1
//{
//public:
//	int* age;// 要求age是堆区变量的指针
//
//	Person1() {	}
//	Person1(int num) {
//		age = new int(num);
//	}
//	// 如下是系统自动创建的默认拷贝构造函数（浅拷贝）
//	//Person1(const Person1& p) {
//	//	age = p.age;// 浅拷贝，简单的赋值，两个对象的age指向一块堆区空间
//	//}
//
//	~Person1() {// 析构函数，清理内存（将堆区数据进行释放）
//		if (age != NULL) {
//			delete age;
//			age = NULL;
//		}
//	}
//};
//void test1() 
//{
//	Person1 p1(18);
//	Person1 p2(p1);// 报错
//	// 空间被释放了两次（栈区先进后出，先释放p2，后释放p1）
//	// 浅拷贝是单纯的赋值，age是指向堆区空间的指针，p2中数据是p1数据的拷贝，p2的指针age的值和p1完全相同，指向同一块空间，造成空间被释放两次
//}
//
//
//
//
//////【属性中若存在指向堆区空间的指针，拷贝时，我们要自己实现深拷贝】
//class Person2
//{
//public:
//	int* age;// 堆区指针
//
//	Person2() {	}
//	Person2(int num) {
//		age = new int(num);
//	}
//	Person2(const Person2& p) {
//		age = new int(*p.age);// 深拷贝，对于堆区指针，为其设置了一块新的空间来存放数据。两个对象的age指向不同的两块堆区空间
//	}
//
//	~Person2() {
//		if (age != NULL) {
//			delete age;
//			age = NULL;
//		}
//	}
//};
//void test2()
//{
//	Person2 p1(18);
//	Person2 p2(p1);
//}
//
//
//
//int main()
//{
//	//test1();
//	test2();
//
//	return 0;
//}