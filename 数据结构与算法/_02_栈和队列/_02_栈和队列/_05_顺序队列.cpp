#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 5


// ˳�����
//
//
// 1.˳������а�����
//		1.�������Ԫ�ص�����
//		2.��ͷ�±�(ָ���ͷԪ��)
//		3.��β�±�(ָ���βԪ�ص���һ��λ��)
// 
// 
// 2.˼·
//	���У�ʹ�õ��ǡ�ѭ�����顿�����е�Ԫ�ش����[��ͷ�±�, ��β�±�)���䣬0�±�δ���Ƕ�ͷ
// 		����(��β�±�++) % MAN_SIZE
//		ɾ��(��ͷ�±�++) % MAN_SIZE
//		�ն��У���ͷ�±� == ��β�±�
//		�����У�(��β�±� + 1) % MAX_SIZE == ��ͷ�±�
//	ע�⣺���ϵĶ�β�±꣬ʵ���Ƕ�βԪ�ص���һ��λ��
//
//
// 3.ע������
//	���������е�Ԫ�ظ���ΪMAX_SIZE - 1����Ϊ�����һ��λ�ã�
//	�� (rear+1)%MAX_SIZE == front ��ʾ��������
//	��һ��λ�õ�ԭ���ǣ���������һ��λ�ã�����ʱ rear == front���޷����ֶԿպͶ���
//
// 
// 4.��������
//	1.�����ڶ��������length��ʾԪ�ظ����������Ͳ�����һ��λ�������Ƿ������
//	2.������rearֱ�ӱ�ʾ��βԪ�أ������Ƕ�βԪ�ص���һ��λ�á�������ʼ��ʱrear����Ϊlength-1��������0
//	......





//typedef struct Person {
//	string name;
//	int age;
//	string sex;
//}Element;
//
//
//typedef struct SqQueue {
//	Element* arr = NULL;// ����Ԫ��������׵�ַ
//	int front = 0;// ��ͷָ��
//	int rear = 0;// ��βָ��
//}SqQueue;
//
//
//
//// ��������ʼ������
//bool initQueue(SqQueue& Q) {
//	if (Q.arr) {
//		cout << "˳��������鲻ΪNULL���޷���ʼ��" << endl;
//		return false;
//	}
//
//	Q.arr = new Element[MAX_SIZE];
//	Q.front = 0;
//	Q.rear = 0;
//	return true;
//}
//
//
//// ���������ٶ���
//bool destroyQueue(SqQueue& Q) {
//	Q.front = 0;
//	Q.rear = 0;
//	if (Q.arr) {
//		delete[] Q.arr;
//		Q.arr = NULL;
//	}
//	return true;
//}
//
//
//// ������Ԫ����ӡ�����
//bool enQueue(SqQueue& Q, const Element& e) {
//	if ((Q.rear + 1) % MAX_SIZE == Q.front) {
//		cout << "�����������޷����" << endl;
//		return false;
//	}
//
//	Q.arr[Q.rear] = e;
//	Q.rear = (Q.rear + 1) % MAX_SIZE;
//	return true;
//}
//
//
//// ������Ԫ�س��ӡ�ɾ��
//bool deQueue(SqQueue& Q, Element& e) {
//	if (Q.front == Q.rear) {
//		cout << "����Ϊ�գ��޷�����" << endl;
//		return false;
//	}
//
//	e = Q.arr[Q.front];
//	Q.front = (Q.front + 1) % MAX_SIZE;
//	return true;
//}
//
//
//// ��������ȡ��ͷԪ�ء��顿
//bool getFront(const SqQueue& Q, Element& e) {
//	if (Q.front == Q.rear) {
//		cout << "����Ϊ�գ��޷���ȡ��ͷԪ��" << endl;
//		return false;
//	}
//
//	e = Q.arr[Q.front];
//	return true;
//}
//
//
//// ��������ȡ����Ԫ�ظ���
//int getLength(const SqQueue& Q) {
//	return Q.front <= Q.rear ? Q.rear - Q.front : Q.rear - Q.front + MAX_SIZE;
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
//void printQueue(const SqQueue& Q) {
//	if (Q.front == Q.rear) {
//		cout << "˳�����Ϊ��" << endl;
//		return;
//	}
//
//	int i = Q.front;
//	int num = 1;
//	while (i != Q.rear) {
//		cout << "��" << num << "λ(�±�Ϊ" << i << ")��" << elementToString(Q.arr[i]) << endl;
//		num++;
//		i = (i + 1) % MAX_SIZE;
//	}
//}
//
//
//
//
//int main() {
//
//	// (1)��������ʼ��˳�����
//	SqQueue Q;
//	initQueue(Q);
//	printQueue(Q);
//	cout << "==========================" << endl;
//
//
//	// (2)Ԫ�����
//	enQueue(Q, Element{ "����", 34, "��" });
//	enQueue(Q, Element{ "����", 27, "Ů" });
//	enQueue(Q, Element{ "����", 45, "��" });
//	enQueue(Q, Element{ "����", 55, "��" });
//	enQueue(Q, Element{ "����", 75, "Ů" });// �����������޷����
//	printQueue(Q);
//	cout << "����Ԫ�ظ���Ϊ��" << getLength(Q) << endl;
//	cout << "==========================" << endl;
//	//��1λ(�±�Ϊ0)�� { name = ����, age = 34, sex = �� }
//	//��2λ(�±�Ϊ1)�� { name = ����, age = 27, sex = Ů }
//	//��3λ(�±�Ϊ2)�� { name = ����, age = 45, sex = �� }
//	//��4λ(�±�Ϊ3)�� { name = ����, age = 55, sex = �� }
//	//����Ԫ�ظ���Ϊ��4
//
//
//	// (4)Ԫ�س���
//	Element e1, e2, e3;
//	deQueue(Q, e1);
//	deQueue(Q, e2);
//	deQueue(Q, e3);
//	cout << elementToString(e1) << endl;// {name=����, age=34, sex=��}
//	cout << elementToString(e2) << endl;// {name=����, age=27, sex=Ů}
//	cout << elementToString(e3) << endl;// {name=����, age=45, sex=��}
//	cout << "==========================" << endl;
//	printQueue(Q);
//	cout << "����Ԫ�ظ���Ϊ��" << getLength(Q) << endl;
//	cout << "==========================" << endl;
//	//��1λ(�±�Ϊ3)��{name=����, age=55, sex=��}
//	//����Ԫ�ظ���Ϊ��1
//
//
//	// (5)���˳����е�ѭ������
//	enQueue(Q, Element{ "С��", 7, "��" });
//	enQueue(Q, Element{ "С��", 9, "Ů" });
//	enQueue(Q, Element{ "��׳", 8, "��" });
//	printQueue(Q);
//	cout << "����Ԫ�ظ���Ϊ��" << getLength(Q) << endl;
//	cout << "==========================" << endl;
//	//��1λ(�±�Ϊ3)�� { name = ����, age = 55, sex = �� }
//	//��2λ(�±�Ϊ4)�� { name = С��, age = 7, sex = �� }
//	//��3λ(�±�Ϊ0)�� { name = С��, age = 9, sex = Ů }
//	//��4λ(�±�Ϊ1)�� { name = ��׳, age = 8, sex = �� }
//	//����Ԫ�ظ���Ϊ��4
//	
//
//	// (5)��ȡ��ͷԪ��
//	Element e4;
//	getFront(Q, e4);
//	cout << elementToString(e4) << endl;// {name=����, age=55, sex=��}
//	cout << "==========================" << endl;
//
//
//	return 0;
//}
