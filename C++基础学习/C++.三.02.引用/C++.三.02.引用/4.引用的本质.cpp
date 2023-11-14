#include<iostream>
using namespace std;




//// 引用的本质
// [引用的本质在C++内部实现]是一个【指针常量】
// 指针常量：如 int* const p;（p中存放的地址不能改变，但是p指向的值可以改变）
// 
// 引用一旦初始化后，就不可以发生改变：原因是引用本质为指针常量，指向的对象不可修改。
// 
// 
// 引用在程序执行时的转化： 
// 定义引用时，(int& b = a;)会自动转化为(int* const b = &a;)
// 使用引用时，任何情况下b都会自动解引用来访问a的值



//void func(int& ref)// 发现是引用，自动转化为int* const ref = &a;
//{
//	ref = 100;// 自动解引用为*ref = 100
//}
//
//int main()
//{
//	int a = 10;
//
//	int& ref = a;
//	// 自动转化为：int* const ref = &a;（ref永远指向a）
//
//	ref = 20;
//	// 内部发现ref是引用，自动转化为：*ref = 20;
//
//	cout << a << endl;// 20
//	cout << ref << endl;// 20
//
//	func(a);
//
//	return 0;
//}
