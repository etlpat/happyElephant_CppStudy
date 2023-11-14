#include <iostream>
using namespace std;

// 常量：用于记录不可修改的数据（修改直接报错）
//
// C++定义常量的两种方法：
// 1. #define 宏常量： #define 常量名 常量值
//		在文件上方定义，编译时直接替换为对应的常量
// 
// 2. const修饰的常量：const 数据类型 常量名 = 常量值
//		利用const关键词修饰常变量，位于静态区，不可修改
//		const 英文n,常量


#define a 100

//int main()
//{
//	cout << a << endl;
//
//	const int b = 99;
//	cout << b << endl;
//
//	system("pause");
//	return 0;
//}
