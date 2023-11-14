#include<iostream>
using namespace std;
#include<string>




//// 运算符重载
// 概念：对已有的运算符重新进行定义，赋予其另一种功能，以适应不同的
// C++通过手动创建成员或全局operator函数实现运算符的重载。（类似于Python中的魔术方法）
// operator：n.操作员、运算符
// 
// 
//
// 运算符重载的实现方式：
// 1.通过成员函数operator的方式重载
// 2.通过全局函数operator的方式重载
// 
//
// 注意：
// 1.通过以上两种方法实现运算符重载，函数名必须是（operator + 运算符）
//		如：加号运算符重载，函数名要叫(operate+)
//		如：赋值运算符重载，函数名要叫(operate=)
// 2.我们可以通过重载后的运算符直接操作对象，也可以调用该函数操作对象
// 3.不要滥用运算符重载，如把加法运算符重载实现为减法





// 加号运算符重载
// 作用：实现两个自定义数据类型相加的运算
// 
//步骤：
// 首先明确+的运行原理：a+b，将ab两项相加，返回相加后的结果。
// 换成对象后同理：将两对象的属性相加，返回一个新对象
// 
// 
//  实现方式：
// 1.成员函数：MyClass operator+(MyClass& a);
// 2.全局函数：MyClass operator+(MyClass& a, MyClass& b);
//
//
// 注意：
//	1.operator+函数也可以重载
//		如：可以先实现一个对象+对象的operator+函数，之后再实现一个对象+整型operator+函数。根据参数不同实现不同操作
//	2.可以用 + 实现函数的调用，也可以通过正常方式调用函数




//class MyClass
//{
//public:
//	int a;
//	int b;
//
//	MyClass() :a(0), b(0)
//	{}
//	MyClass(int a1, int b1) :a(a1), b(b1)
//	{}
//
//	//// 成员函数方式实现 + 的重载
//	//MyClass operator+ (MyClass& m1) {// 实现对象+对象
//	//	MyClass m2(a + m1.a, b + m1.b);
//	//	return m2;
//	//}
//};
//
//// 全局函数方式实现 + 的重载
//MyClass operator+ (MyClass& m1, MyClass& m2) {// 实现对象+对象
//	MyClass m3(m1.a + m2.a, m1.b + m2.b);
//	return m3;
//}
//
//
//int main()
//{
//	MyClass m1(10, 20);
//	MyClass m2(40, 30);
//
//	MyClass m3 = m1 + m2;
//	cout << m3.a << ", " << m3.b << endl;// 50, 50
//
//	//MyClass m4 = m1.operator+(m2);// 调用成员函数operator+
//	//cout << m4.a << ", " << m4.b << endl;// 50, 50
//
//	MyClass m5 = operator+(m1, m2);// 调用全局函数operator+
//	cout << m5.a << ", " << m5.b << endl;// 50, 50
//
//
//	return 0;
//}