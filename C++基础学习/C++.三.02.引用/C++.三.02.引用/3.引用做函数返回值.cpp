#include<iostream>
using namespace std;




//// 引用做函数的返回值
// 若想返回变量的引用，写函数时要把返回类型定义为引用类型
// （引用类型：如整型的引用，其类型为int&）


//int& func1()// 返回类型为引用类型
//{
//	static int a = 10;
//	int& b = a;
//	return b;// 返回a的引用
//}
//
//int& func2()
//{
//	static int c = 20;
//	return c;// 由于函数返回类型为引用类型，所以返回c时系统自动将其转换为c的引用。
//			 // 这种写法比较方便快捷，建议使用
//}
//
//int main()
//{
//	int& ref1 = func1();
//	cout << ref1 << endl;// 10
//
//	int& ref2 = func2();
//	cout << ref2 << endl;// 20
//
//	return 0;
//}








// 返回引用时的注意：
// 1.不要返回已被释放的局部变量的引用
// 2.返回引用时，函数调用可作为左值


//int& test1()
//{
//	int a = 10;// a在栈区
//	return a;// 返回a的引用
//}
//
//int& test2()
//{
//	static int b = 20;// 静态变量b，在全局区
//	return b;// 返回b的引用
//}
//
//
//int main()
//{
//	int& ref1 = test1();
//	cout << ref1 << endl;// 10（编译器会保留一次）
//	cout << ref1 << endl;// 1467779368
//	// 函数中a在栈区，函数结束空间释放，无法访问a的引用
//
//
//	int& ref2 = test2();
//	cout << ref2 << endl;// 20
//	cout << ref2 << endl;// 20
//	// 函数中b在全局区，无作用域
//
//
//	// 返回引用时，函数调用可作为左值，把50赋给b的引用
//	test2() = 50;
//	cout << ref2 << endl;// 50
//
//
//	return 0;
//}








// 一个变量可以有多个引用(别名)
// 一个变量的别名也可以有别名
// 以上这些引用都和原始变量是一块空间


//int main()
//{
//	int a = 10;
//	int& b = a;
//	int& c = a;
//	int& d = b;
//
//	cout << a << endl;// 10
//	cout << b << endl;// 10
//	cout << c << endl;// 10
//	cout << d << endl;// 10
//	// 这些引用都在描述同一块空间
//
//	return 0;
//}