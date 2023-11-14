#include<iostream>
using namespace std;


//// 指针所占的内存空间
// 
// 指针也是变量，会占据内存空间
// 32为操作系统下：4字节
// 64为操作系统下：8字节
//
// 注意：【指针所占空间只32或64位系统有关，与指针类型无关】
// 原因：若由32根地址线产生地址，则地址由全0到全1，一共有2的32次方种，二进制下占32位，32bit=4byte(字节)



//int main()
//{
//	// 如下，无论什么类型的指针，在32位(x86)系统下都占4字节
//	cout << sizeof(char*) << endl;// 4
//	cout << sizeof(int*) << endl;// 4
//	cout << sizeof(float*) << endl;// 4
//	cout << sizeof(double*) << endl;// 4
//	cout << sizeof(int(*)[10]) << endl;// 4（数组指针）
//	cout << sizeof(char(*)(int, int)) << endl;// 4（函数指针）
//
//
//	system("pause");
//	return 0;
//}




