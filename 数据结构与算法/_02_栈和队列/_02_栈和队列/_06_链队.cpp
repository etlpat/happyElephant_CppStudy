#include<iostream>
using namespace std;
#include<string>


// ����
//
//
// 1.�����а�����
//		��ͷָ�룺ָ��ͷ�ڵ�
//		��βָ�룺ָ��β���
//
//
// 2.ע�����
//	����������Ҫ��ͷ����β����ָ�룬
//	��˲�����ֻ��ͷ���ָ���ʾ���������ˣ�
//	������Ҫ�¶���һ���ṹ�壬��������ͷָ���βָ��
//
//




//typedef struct Person {
//	string name;
//	int age;
//	string sex;
//}Element;
//
//
//typedef struct LNode {
//	Element data;
//	LNode* next = NULL;
//}LNode;
//
//
//typedef struct LinkQueue {
//	LNode* front = NULL;
//	LNode* rear = NULL;
//}LinkQueue;
//
//
//
//// ��������ʼ������
//bool initQueue(LinkQueue& Q) {
//	Q.front = new LNode;
//	Q.front->next = NULL;
//	Q.rear = Q.front;
//	return true;
//}
//
//
//// ��������������
//bool destroyQueue(LinkQueue& Q) {
//	Q.rear = NULL;
//	LNode* p;
//	while (Q.front) {
//		p = Q.front;
//		Q.front = Q.front->next;
//		delete p;
//	}
//	p = NULL;
//	return true;
//}
//
//
//// ������Ԫ����ӡ�����
//bool enQueue(LinkQueue& Q, const Element& e) {
//	Q.rear->next = new LNode;
//	Q.rear = Q.rear->next;
//	Q.rear->data = e;
//	Q.rear->next = NULL;
//	return true;
//}
//
//
//// ������Ԫ�س��ӡ�ɾ��
//bool deQueue(LinkQueue& Q, Element& e) {
//	if (Q.front == Q.rear) {
//		cout << "����Ϊ�գ��޷�����" << endl;
//		return false;
//	}
//
//	LNode* p = Q.front->next;
//	if (p == Q.rear) {		// �����ӵ���Ԫ��������β��㣬
//		Q.rear = Q.front;	// ��βָ��ָ��ͷ���
//	}
//	Q.front->next = p->next;
//	e = p->data;
//	delete p;
//	p = NULL;
//	return true;
//}
//
//
//// ��������ȡ��ͷԪ�ء��顿
//bool getFront(const LinkQueue& Q, Element& e) {
//	if (Q.front == Q.rear) {
//		cout << "����Ϊ�գ��޷���ȡ��ͷԪ��" << endl;
//		return false;
//	}
//
//	e = Q.front->next->data;
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
//// �������Ӷ�ͷ����β��ӡ���е�����Ԫ��
//void printQueue(const LinkQueue& Q) {
//	if (Q.front == Q.rear) {
//		cout << "����Ϊ��" << endl;
//		return;
//	}
//
//	LNode* p = Q.front->next;
//	int num = 1;
//	while (p) {
//		cout << "��" << num << "λ��" << elementToString(p->data) << endl;
//		num++;
//		p = p->next;
//	}
//}
//
//
//
//
//int main() {
//
//	// (1)��������ʼ������
//	LinkQueue Q;
//	initQueue(Q);
//	printQueue(Q);// ����Ϊ��
//	cout << "==========================" << endl;
//
//
//	// (2)Ԫ�����
//	enQueue(Q, Element{ "����", 34, "��" });
//	enQueue(Q, Element{ "����", 27, "Ů" });
//	enQueue(Q, Element{ "����", 45, "��" });
//	enQueue(Q, Element{ "����", 55, "��" });
//	printQueue(Q);
//	cout << "==========================" << endl;
//	//��1λ��{ name = ����, age = 34, sex = �� }
//	//��2λ��{ name = ����, age = 27, sex = Ů }
//	//��3λ��{ name = ����, age = 45, sex = �� }
//	//��4λ��{ name = ����, age = 55, sex = �� }
//
//
//	// (3)Ԫ�س���
//	Element e1, e2;
//	deQueue(Q, e1);
//	deQueue(Q, e2);
//	cout << elementToString(e1) << endl;// {name=����, age=34, sex=��}
//	cout << elementToString(e2) << endl;// {name=����, age=27, sex=Ů}
//	cout << "==========================" << endl;
//	printQueue(Q);
//	cout << "==========================" << endl;
//	//��1λ��{ name = ����, age = 45, sex = �� }
//	//��2λ��{ name = ����, age = 55, sex = �� }
//	
//
//	// (4)��ȡ��ͷԪ��
//	Element e3;
//	getFront(Q, e3);
//	cout << elementToString(e3) << endl;
//	cout << "==========================" << endl;// {name=����, age=45, sex=��}
//
//
//	return 0;
//}