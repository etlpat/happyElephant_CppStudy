#include<iostream>
using namespace std;
#include<string>




// 案例：计算器类
// 分别利用普通写法和多态写法，设计对两个操作数进行运算的计算器
//
// 多态好处：
// 1.组织结构清晰
// 2.可读性强
// 3.后期拓展维护性高





//class Calculator1// 普通写法
//{
//public:
//	double num1;
//	double num2;
//
//	Calculator1() :num1(0), num2(0) {}
//	Calculator1(double a, double b) :num1(a), num2(b) {}
//
//	double getResult(char ch) {
//		switch (ch)
//		{
//		case '+':
//			return num1 + num2;
//		case '-':
//			return num1 - num2;
//		case '*':
//			return num1 * num2;
//		case '/':
//			return num1 / num2;
//		default:
//			cout << "输入非法操作符" << endl;
//		}
//	}
//};
//
//
//int main()
//{
//	// 普通写法的计算器
//	Calculator1 c1(3, 2);
//	cout << c1.getResult('+') << endl;// 5
//	cout << c1.getResult('-') << endl;// 1
//	cout << c1.getResult('*') << endl;// 6
//	cout << c1.getResult('/') << endl;// 1.5
//
//
//	return 0;
//}






//// 实际开发中提倡一种原则：开闭原则
//// 对拓展进行开放，对修改进行关闭（添加代码时不用修改之前的源码，而是直接添加拓展）
//
//
//class AbstractCalculator// 计算机的抽象类
//{
//public:
//	double num1;
//	double num2;
//
//	AbstractCalculator() :num1(0), num2(0) {}
//
//	virtual double getResult() { return 0; }
//};
//
//class jiaCalculator :public AbstractCalculator// 加法计算器类
//{
//public:
//	jiaCalculator(double a, double b) {
//		num1 = a;
//		num2 = b;
//	}
//
//	double getResult() {// 虚函数重写
//		return num1 + num2;
//	}
//};
//
//class jianCalculator :public AbstractCalculator// 减法计算器类
//{
//public:
//	jianCalculator(double a, double b) {
//		num1 = a;
//		num2 = b;
//	}
//
//	double getResult() {// 虚函数重写
//		return num1 - num2;
//	}
//};
//
//class chengCalculator :public AbstractCalculator// 乘法计算器类
//{
//public:
//	chengCalculator(double a, double b) {
//		num1 = a;
//		num2 = b;
//	}
//
//	double getResult() {// 虚函数重写
//		return num1 * num2;
//	}
//};
//
//class chuCalculator :public AbstractCalculator// 除法计算器类
//{
//public:
//	chuCalculator(double a, double b) {
//		num1 = a;
//		num2 = b;
//	}
//
//	double getResult() {// 虚函数重写
//		return num1 / num2;
//	}
//};
//
//double Calculator2(AbstractCalculator& ac)// 实现多态的函数
//{
//	return ac.getResult();
//}
//
//
//
//int main()
//{
//	// 多态写法的计算器
//	jiaCalculator a(3,2);
//	cout << Calculator2(a) << endl;// 5
//
//	jianCalculator b(3,2);
//	cout << Calculator2(b) << endl;// 1
//
//	chengCalculator c(3,2);
//	cout << Calculator2(c) << endl;// 6
//
//	chuCalculator d(3,2);
//	cout << Calculator2(d) << endl;// 1.5
//
//
//	return 0;
//}


