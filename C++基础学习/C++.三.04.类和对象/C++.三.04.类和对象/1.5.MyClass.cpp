#include"1.5.MyClass.h"



// 分文件编写时成员函数定义语法：【返回类型 类名::函数名(参数列表){...}】
// 注意：函数名前面必须写（MyClass::）
// 表示该函数是MyClass类作用域下的函数

void MyClass::setA(int a1) {
	a = a1;
}

void MyClass::setB(int b1) {
	b = b1;
}

void MyClass::setStr(string str1) {
	str = str1;
}

int MyClass::getA() {
	return a;
}

int MyClass::getB() {
	return b;
}

string MyClass::getStr() {
	return str;
}

int MyClass::getSumAB() {
	return a + b;
}