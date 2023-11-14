#include<iostream>
using namespace std;




//// 函数的重载
// 重(chong)载：不同函数的函数名可以相同，提高复用性
//
// 
// 函数重载满足条件：
// 1.同一个作用域下（这里指全局作用域）
// 2.函数名相同
// 3.函数【参数】的类型不同，或个数不同，或顺序不同（必须使传参产生区别）
// （注意：函数的返回值不作为函数重载的判断条件，函数重载也不要求返回值一定相同）
//
//
// 注意：
// 函数重载，要求一组实参只能存在一种与之匹配的形参



//void func()// 每个重载返回类型可以不同
//{
//	cout << "无参数" << endl;
//}
//
//int func(int a, double b)
//{
//	cout << "整型, 浮点" << endl;
//	return 0;
//}
//
//int func(double a, int b)
//{
//	cout << "浮点, 整型" << endl;
//	return 0;
//}
//
//
//int main()
//{
//	func();// 无参数
//	func(1, 1.0);// 整型, 浮点
//	func(1.0, 1);// 浮点, 整型
//
//	return 0;
//}










//// 函数重载的注意事项
// 1.引用作为重载条件（是否加const可作为重载条件）
// 2.函数重载碰到函数默认参数



//// 1.引用作为重载的条件（引用是否加const可以作为函数重载条件）
//
//void func(int& a)// 形参引用不加const，默认接收变量
//{
//	cout << "func(int& a)调用" << endl;
//}
//
//void func(const int& a)// 形参const修饰引用，接收常量
//{
//	cout << "func(const int& a)调用" << endl;
//}
//
//int main()
//{
//	int a = 10;
//	func(a);// func(int& a)调用
//	// 形参引用无const修饰时，默认接收变量
//	
//	func(10);// func(const int& a)调用
//	// 对于10，只有const int& a = 10;这种写法合法
//	// 形参是有const修饰的引用时，接收常量
//
//	return 0;
//}



//// 2.函数重载碰到函数默认参数
//
//void func(int a)
//{ }
//
//void func(int a, int b = 10)
//{ }
//
//int main()
//{
//	//func(10);// 报错
//	// 由于第二个函数具有默认参数。当只传一个实参时，对于两个函数都成立，具有二义性，编译器无法判断
//	
//	return 0;
//}