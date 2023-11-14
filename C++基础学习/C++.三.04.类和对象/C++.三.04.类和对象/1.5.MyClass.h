#pragma once// 防止头文件重复包含
#include<iostream>
using namespace std;
#include<string>



// 类的声明：
class MyClass
{
private:
	int a;// 成员变量(的声明)
	int b;
	string str;

public:
	void setA(int a1);// 成员函数的声明
	void setB(int b1);
	void setStr(string str1);
	int getA();
	int getB();
	string getStr();
	int getSumAB();
};