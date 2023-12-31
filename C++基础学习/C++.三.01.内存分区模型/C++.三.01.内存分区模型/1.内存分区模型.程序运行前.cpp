#include<iostream>
using namespace std;



//// 内存分区模型
//
// C++程序在执行时，将内存大方向划分为4个区域：
// 1.【代码区(文本区)】：存储程序的二进制代码，由操作系统进行管理
// 2.【栈区】：由编译器自动分配和释放，具有局部性。存放函数的参数值、局部变量等
// 3.【堆区】：由程序员分配和释放，具有动态性。若程序员不释放，则在程序结束时由操作系统系统回收
// 4.【全局(静态)区】：存放全局变量、静态变量以及常量。这些数据在程序结束后由操作系统释放
//
// 内存四区含义：
// 不同区域存放的数据，赋予不同的生命周期，增加编程灵活性






//// (1)程序运行前就存在的区域：（代码区、全局区）
// 注意：运行前指“编译后，运行前”
// 在程序编译后，生成了.exe可执行文件。
// 
// 
// 【在执行.exe文件前】分为两个区域：
// 
// 1.代码区：存放CPU执行的机器指令
//	特点：代码区是【共享】的，对于频繁执行的程序，只需要在内存中有一份代码即可
//		  代码区是【只读】的，防止程序意外地修改指令
//
// 
// 2.全局区：全局变量、静态变量存放在此
//           全局区还包含了常量区，字符串常量、const修饰的全局变量等也存放在此
//			 该区域的数据在程序结束后由系统释放





//// 全局区：包含全局变量、静态变量、常量
// 
// 全局区包含如下：
// 1.全局变量(globle)
// 2.静态变量(static)
// 3.常量：（常量分为字符串常量和const修饰的变量）
//		 字符串常量
//		 const修饰的全局变量(const_globle)
// 
// 
//	注意：const修饰的局部变量(const_local)存放在栈区。
// 【const的修饰不会改变变量的分区。局部变量在栈区，用const修饰后仍然在栈区。全局变量在全局区，用const修饰后仍在全局区】




//// 全局变量（全局区）
//int g_a = 0;
//int g_b = 0;
//
//// const修饰的全局变量（全局区）
//const int c_g_a = 0;
//const int c_g_b = 0;
//
//
//int main()
//{
//	// 局部变量（栈区）
//	int a = 0;
//	int b = 0;
//
//	// 静态变量（全局区）
//	static int s_a = 0;
//	static int s_b = 0;
//
//	// const修饰的局部变量（栈区）
//	const int c_l_a = 0;
//	const int c_l_b = 0;
//
//
//	cout << "局部变量a地址为：" << &a << endl;// 008FF85C
//	cout << "局部变量b地址为：" << &b << endl;// 008FF850
//	cout << "全局变量g_a地址为：" << &g_a << endl;// 0021C138
//	cout << "全局变量g_b地址为：" << &g_b << endl;// 0021C13C
//	cout << "静态变量s_a地址为：" << &s_a << endl;// 0021C140
//	cout << "静态变量s_b地址为：" << &s_b << endl;// 0021C144
//	cout << "字符串常量\"a\"地址为：" << &"a" << endl;// 00219BE8
//	cout << "字符串常量\"b\"地址为：" << &"b" << endl;// 00219C08
//	cout << "const修饰的全局变量c_g_a地址为：" << &c_g_a << endl;// 00219B30
//	cout << "const修饰的全局变量c_g_b地址为：" << &c_g_b << endl;// 00219B34
//	cout << "const修饰的局部变量c_l_a地址为：" << &c_l_a << endl;// 008FF844
//	cout << "const修饰的局部变量c_l_b地址为：" << &c_l_b << endl;// 008FF838
//	
//	// 由上数据可看出：
//	// 栈区的局部变量、const修饰的局部变量内存离得较近
//	// 全局区的全局变量、静态变量、字符串常量、const修饰的全局变量内存里的较近
//
//
//	return 0;
//}

