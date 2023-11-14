#include <iostream>
using namespace std;


// char 字符型，1字节
// 字符型变量不是将字符本身放入内存中存储，而是将其对应的ASCII编码放入存储单元（如A为65，a为97）
// 语法：char ch = 'a'
// 注意：字符，是单引号引起来的一个字符，如'a'


// 强制类型转化：(类型名)变量


//int main()
//{
//	char ch = 'a';
//	cout << ch << "，所占空间大小为：" << sizeof(ch) << endl;// a，所占空间大小为：1
//
//	cout << "a:" << (int)'a' << "; b:" << (int)'b' << endl;// a:97; b:98
//
//
//	system("pause");
//	return 0;
//}