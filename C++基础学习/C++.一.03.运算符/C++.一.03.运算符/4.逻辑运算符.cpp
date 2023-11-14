#include <iostream>
using namespace std;


// 逻辑运算符
// 作用：根据两侧表达式返回true或false
//
// !：非（!真 = 假，!假 = 真）
// &&：短路与（两式均真才返回真，否则返回假）
// ||：短路或（两式有真就返回真，否则返回假）


//int main()
//{
//	bool a = 1, b = 1, c = 0, d = 0;
//	cout << !a << endl;// 0
//	cout << (a && b) << endl;// 1
//	cout << (a && c) << endl;// 0
//	cout << (a || c) << endl;// 1
//	cout << (c || d) << endl;// 0
//
//	system("pause");
//	return 0;
//}