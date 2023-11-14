#include<iostream>
using namespace std;
#include<string>


// ��ջ(LiStack)��������ʵ�ֵ�ջ
//
// ʵ�֣�
//	���°�ͷ��㴦�涨Ϊջ��
//	ֻ����ͷ��㴦������ɾ������ʵ����ջ




//typedef struct Person {
//	string name;
//	int age;
//	string sex;
//}Element;
//
//
//typedef struct LinkNode {
//	Element data;
//	LinkNode* next;
//}LinkNode, *LiStack;
//// ��ͷ����ָ�룬��ʾ��ջ
//
//
//// ��������ʼ����ջ
//bool initLiStack(LiStack& S) {
//	S = new LinkNode;
//	S->next = NULL;
//	return true;
//}
//
//
//// ������������ջ
//bool destroyLiStack(LiStack& S) {
//	LinkNode* p;
//	while (S) {
//		p = S;
//		S = S->next;
//		delete p;
//	}
//	p = NULL;
//	S = NULL;
//	return true;
//}
//
//
//// ��������ջ������
//bool push(LiStack& S, const Element& e) {
//	LinkNode* p = new LinkNode;
//	p->data = e;
//	p->next = S->next;
//	S->next = p;
//	return true;
//}
//
//
//// ��������ջ��ɾ��
//bool pop(LiStack& S, Element& e) {
//	if (!S->next) {
//		cout << "��ջΪ�գ��޷���ջ" << endl;
//		return false;
//	}
//
//	LinkNode* p = S->next;
//	e = p->data;
//	S->next = p->next;
//	delete p;
//	p = NULL;
//	return true;
//}
//
//
//// ��������ȡջ��Ԫ�ء��顿
//bool getTop(const LiStack& S, Element& e) {
//	if (!S->next) {
//		cout << "��ջΪ�գ��޷���ȡ" << endl;
//		return false;
//	}
//
//	e = S->next->data;
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
//// ��ջ�׵�ջ�״�ӡԪ�أ�������Ԫ�ظ���
//int stackDataList(const LiStack& S, bool isHead = true) {
//	int num = 0;
//	if (S->next) {
//		num = 1 + stackDataList(S->next, false);
//	}
//	if (!isHead) {
//		cout << "��" << num + 1 << "λ��" << elementToString(S->data) << endl;
//	}
//	return num;
//}
//
//
//// ��������ջ�׵�ջ����ӡջ������Ԫ��
//void printStack(const LiStack& S) {
//	int length = stackDataList(S);
//	if (length == 0) {
//		cout << "��ջΪ��" << endl;
//	}
//	else {
//		cout << "ջ��Ԫ�ظ���Ϊ��" << length << endl;
//	}
//}
//
//
//
//
//int main() {
//
//	// (1)��������ʼ����ջ
//	LiStack S;
//	initLiStack(S);
//	printStack(S);// ��ջΪ��
//	cout << "==========================" << endl;
//
//
//	// (2)Ԫ����ջ
//	push(S, Element{ "����", 34, "��" });
//	push(S, Element{ "����", 27, "Ů" });
//	push(S, Element{ "����", 45, "��" });
//	push(S, Element{ "����", 75, "��" });
//	printStack(S);
//	cout << "==========================" << endl;
//	//��1λ��{ name = ����, age = 34, sex = �� }
//	//��2λ��{ name = ����, age = 27, sex = Ů }
//	//��3λ��{ name = ����, age = 45, sex = �� }
//	//��4λ��{ name = ����, age = 75, sex = �� }
//	//ջ��Ԫ�ظ���Ϊ��4
//
//
//	// (3)��ȡջ��Ԫ��
//	Element e1;
//	getTop(S, e1);
//	cout << elementToString(e1) << endl;// {name=����, age=75, sex=��}
//	cout << "==========================" << endl;
//
//
//	// (4)Ԫ�س�ջ
//	Element e2, e3, e4, e5;
//	pop(S, e2);
//	pop(S, e3);
//	cout << elementToString(e2) << endl;// {name=����, age=75, sex=��}
//	cout << elementToString(e3) << endl;// {name=����, age=45, sex=��}
//	cout << "==========================" << endl;
//	printStack(S);
//	//��1λ��{ name = ����, age = 34, sex = �� }
//	//��2λ��{ name = ����, age = 27, sex = Ů }
//	//ջ��Ԫ�ظ���Ϊ��2
//
//	pop(S, e4);
//	pop(S, e5);
//	cout << "==========================" << endl;
//	printStack(S);// ��ջΪ��
//
//
//	return 0;
//}