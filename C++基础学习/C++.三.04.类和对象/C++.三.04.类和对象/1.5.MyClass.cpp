#include"1.5.MyClass.h"



// ���ļ���дʱ��Ա���������﷨������������ ����::������(�����б�){...}��
// ע�⣺������ǰ�����д��MyClass::��
// ��ʾ�ú�����MyClass���������µĺ���

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