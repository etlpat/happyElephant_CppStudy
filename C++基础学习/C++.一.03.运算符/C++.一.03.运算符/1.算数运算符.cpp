#include <iostream>
using namespace std;


// 算数运算符
// 作用：用于处理四则运算
//
// +：正号/加
// -：负号/减
// *：乘
// /：除
// %：取模(取余)
// ++a：前置自加（先自加，后运算）
// a++：后置自加（先运算，后自加）
// --a：前置自减（先自减，后运算）
// a--：后置自减（先运算，后自减）




//int main()
//{
//	int a = 10, b = 3;
//	cout << a + b << endl;// 13
//	cout << a - b << endl;// 7
//	cout << a * b << endl;// 30
//	cout << a / b << endl;// 3（两整形相除，结果仍是整形）
//	cout << a % b << endl;// 1（只有两个整形才能取余运算）
//
//
//	b = 0;
//	// cout << a / b << endl;// 报错，整数相除分母不能为0
//	// cout << a % b << endl;// 报错，取模也要相除，分母不能为0
//	cout << (float)a / (float)b << endl;// inf(无穷大)，将0转化为浮点型后，表示无穷小，可以当分母，结果为无穷大
//
//
//	system("pause");
//	return 0;
//}




// ++a 或 --a：先自加/自减，后运算
// a++ 或 a--：先运算，后自加/自减

//int main()
//{
//	int a = 10;
//	int b = 0;
//	b = a++;
//	cout << b << ", " << a << endl;// 10, 11
//	b = ++a;
//	cout << b << ", " << a << endl;// 12, 12
//	b = a--;
//	cout << b << ", " << a << endl;// 12, 11
//	b = --a;
//	cout << b << ", " << a << endl;// 10, 10
//
//
//	int a2 = 10;
//	int b2 = a2++ * 10;
//	cout << a2 << ", " << b2 << endl;// 11, 100
//
//
//	int a3 = 0;
//	cout << a3++ << endl;// 0
//	cout << ++a3 << endl;// 2
//	
//
//	system("pause");
//	return 0;
//}