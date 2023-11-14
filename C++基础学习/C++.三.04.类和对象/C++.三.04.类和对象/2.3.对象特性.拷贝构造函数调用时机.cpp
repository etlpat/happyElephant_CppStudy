#include<iostream>
using namespace std;
#include<string>




//// 拷贝构造函数调用时机
// 
// C++拷贝构造函数调用时机通常有三种情况
// 1.使用一个已经创建完毕的对象来初始化一个新对象
// 2.值传递的方式给函数参数传递对象（值传递时形参是实参的临时拷贝，形参创建对象时调用拷贝构造函数）
// 3.以值的方式返回局部对象（主函数中接收的返回值，是函数中局部对象的拷贝）
//
//
// 总结：除了我们手动创建某个对象的拷贝以外，
//       以值传递的方式向形参传递对象、以值的方式返回对象，这两过程中创建的对象都调用拷贝构造函数




//class Person
//{
//public:
//	string name;
//	int age;
//
//	Person() {
//		cout << "默认构造函数调用" << endl;
//	}
//	Person(string s, int a) {
//		name = s, age = a;
//		cout << "有参构造函数调用" << endl;
//	}
//	Person(const Person& p) {
//		name = p.name, age = p.age;
//		cout << "拷贝构造函数调用" << endl;
//	}
//
//	~Person() {
//		cout << "析构函数调用" << endl;
//	}
//};
//
//
//// 1.使用一个已经创建完毕的对象来初始化一个新对象
//
//void test1(){
//	Person p1("张三", 18);// 有参构造函数调用
//	Person p2(p1);// 拷贝构造函数调用
//	return;// 析构函数调用
//           // 析构函数调用
//}
//
//
//// 2.值传递的方式给函数参数传递对象
//
//void doWork1(Person p){// 拷贝构造函数调用
//	cout << &p << endl;// 008FF7C8
//	return;// 析构函数调用
//}
//void test2(){
//	Person p("张三", 18);// 有参构造函数调用
//	cout << &p << endl;// 008FF8D8
//	doWork1(p);
//	return;// 析构函数调用
//}
//
//
//// 3.以值的方式返回局部对象
//
//Person doWork2() {
//	Person p("张三", 18);// 有参构造函数调用
//	cout << &p << endl;// 012FFAE8
//	return Person(p);// 析构函数调用
//}
//void test3() {
//	Person p = doWork2();// 拷贝构造函数调用
//	cout << &p << endl;// 012FFBFC
//	return;// 析构函数调用
//}
//
//
//int main()
//{
//	//test1();
//	//test2();
//	test3();
//
//	return 0;
//}


