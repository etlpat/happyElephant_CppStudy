#pragma once// ��ֹͷ�ļ��ظ�����
#include<iostream>
using namespace std;
#include<string>



// ���������
class MyClass
{
private:
	int a;// ��Ա����(������)
	int b;
	string str;

public:
	void setA(int a1);// ��Ա����������
	void setB(int b1);
	void setStr(string str1);
	int getA();
	int getB();
	string getStr();
	int getSumAB();
};