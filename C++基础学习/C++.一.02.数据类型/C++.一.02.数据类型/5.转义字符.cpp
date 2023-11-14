#include <iostream>
using namespace std;


// 转义字符：由反斜杠\开始，表示特殊意义的字符
// 
// \n:换行符（补充：<< endl 也表示换行）
// \\:表示一个反斜杠 \ （可以是字符或字符串）
// \t:水平制表符，跳到下一个tab位置（tab对齐8的倍数的空格）
// 
// 注意：单独一个反斜杠\报错


//int main()
//{
//	cout << "a\nb" << endl;
//	cout << "a\tb" << endl;
//	cout << "\\" << '\\' << endl;
//
//
//	system("pause");
//	return 0;
//}