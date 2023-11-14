#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 1000


// ˳��ջ(SqStack)���洢�ṹΪ˳���
//
// ע�⣺˳��ջ�Ľṹ���а�����
//	1.�������Ԫ�ص������׵�ַarr
//	2.ջ��Ԫ�ص��±�top
// ��ע�⣺����ϰ����top��Ҳ���Դ��ջ��Ԫ�ظ���length��



//typedef struct Person {
//	string name;
//	int age;
//	string sex;
//}Element;
//
//
//typedef struct SqStack {
//	Element* arr = NULL;// ����Ԫ��������׵�ַ
//	int top = -1;// ջ��Ԫ�ص��±�
//}SqStack;
//
//
//
//// ��������ʼ��ջ
//bool initStack(SqStack& S) {
//	if (S.arr) {
//		cout << "ջ�����鲻ΪNULL�����ܳ�ʼ��" << endl;
//		return false;
//	}
//
//	S.arr = new Element[MAX_SIZE];// �����������ռ�
//	S.top = -1;// ��ջ����ջ��Ԫ���±�Ϊ-1
//	return true;
//}
//
//
//// ����������ջ
//bool destroyStack(SqStack& S) {
//	S.top = -1;
//	if (S.arr) {
//		delete[] S.arr;// �ͷŶ�������ռ�
//		S.arr = NULL;
//	}
//	return true;
//}
//
//
//// ��ջ������
//bool push(SqStack& S, const Element& e) {
//	if (S.top + 1 == MAX_SIZE) {
//		cout << "ջ������������ջԪ��" << endl;
//		return false;
//	}
//
//	S.arr[++S.top] = e;
//	return true;
//}
//
//
//// ��ջ��ɾ��
//bool pop(SqStack& S, Element& e) {
//	if (S.top == -1) {
//		cout << "ջΪ��ջ�����ܳ�ջԪ��" << endl;
//		return false;
//	}
//
//	e = S.arr[S.top--];
//	return true;
//}
//
//
//// ��ȡջ��Ԫ�ء��顿
//bool getTop(const SqStack& S, Element& e) {
//	if (S.top == -1) {
//		cout << "ջΪ��ջ�����ܶ�ȡջ��Ԫ��" << endl;
//		return false;
//	}
//
//	e = S.arr[S.top];
//	return true;
//}
//
//
//// ��������������Ԫ�ص��ַ�����Ϣ
//string elementToString(const Element& e) {
//	return "{name=" + e.name +
//		", age=" + to_string(e.age) +
//		", sex=" + e.sex + "}";
//}
//
//
//// ��������ջ�׵�ջ����ӡջ������Ԫ��
//void printStack(const SqStack& S) {
//	if (S.top == -1) {
//		cout << "ջΪ��" << endl;
//		return;
//	}
//
//	for (int i = 0; i <= S.top; i++) {
//		cout << "��" << i + 1 << "λ��" << elementToString(S.arr[i]) << endl;
//	}
//}
//
//
//
//
//int main() {
//
//	// (1)��������ʼ��ջ
//	SqStack S;
//	initStack(S);
//	printStack(S);// ջΪ��
//	cout << "==========================" << endl;
//
//
//	// (2)Ԫ����ջ
//	push(S, Element{ "����", 34, "��" });
//	push(S, Element{ "����", 27, "Ů" });
//	push(S, Element{ "����", 45, "��" });
//	printStack(S);
//	cout << "==========================" << endl;
//	//��1λ��{ name = ����, age = 34, sex = �� }
//	//��2λ��{ name = ����, age = 27, sex = Ů }
//	//��3λ��{ name = ����, age = 45, sex = �� }
//
//
//	// (3)��ȡջ��Ԫ��
//	Element e1;
//	getTop(S, e1);
//	cout << elementToString(e1) << endl;// {name=����, age=45, sex=��}
//	cout << "==========================" << endl;
//
//
//	// (4)Ԫ�س�ջ
//	Element e2, e3, e4;
//	pop(S, e2);
//	pop(S, e3);
//	pop(S, e4);
//	cout << elementToString(e2) << endl;// {name=����, age=45, sex=��}
//	cout << elementToString(e3) << endl;// {name=����, age=27, sex=Ů}
//	cout << elementToString(e4) << endl;// {name=����, age=34, sex=��}
//	cout << "==========================" << endl;
//	printStack(S);// ջΪ��
//
//
//	return 0;
//}