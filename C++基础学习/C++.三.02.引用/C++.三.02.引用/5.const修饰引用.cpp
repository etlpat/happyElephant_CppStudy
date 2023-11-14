#include<iostream>
using namespace std;




//// const修饰引用
// 作用：在函数形参列表中，可以用const修饰形参，防止误操作
// 用法：const int& b = a;（不能通过引用b改变a的内存）
//		（原理是将 int* const b 修饰为 const int* const b）
//
//
// 问：函数引用传参void func(const int& a)与值传递void func(int a)，二者都不能通过形参修改实参，二者的区别是什么？
// 答：值传递需要拷贝一份实参的副本，占用大量空间；引用传参的本质是传递指针常量，固定占4字节。



//void printNum(const int& num)
//{
//	cout << num << endl;
//}
//
//int main()
//{
//	int a = 10;
//	printNum(a);
//
//	return 0;
//}








//// const引用的特殊写法：
// C++允许如下写法：const int& ref = 10;
// 该写法在运行时转换为：int tmp = 10; const int& ref = tmp;
//                       系统为10创建了一个临时空间，并把ref作为该空间的引用
//
//
// int& ref，该引用只能接收变量
// const int& ref，该引用可以接收常量或变量



//int main()
//{
//	//int& ref = 10;// 报错，引用必须等于一块变量空间
//
//	// 但是下面这种写法不报错：
//	const int& ref = 10;
//	// 加上const之后，编译器将代码修改：int tmp = 10; const int& ref = tmp;
//}