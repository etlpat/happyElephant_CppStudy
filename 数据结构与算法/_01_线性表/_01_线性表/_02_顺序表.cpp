#include<iostream>
using namespace std;
#include<string>

#define MAX_SIZE 100


// ˳���sequence list��
//
// (1)���� 
//	˳�������˳��洢(����)�ķ�ʽʵ�����Ա�
//	
// (2)˳����ص�
//	1.������ʣ�����ֱ�ӷ���ָ���±��Ԫ�أ���O(1)ʱ���ڿ��ҵ���i��Ԫ��
//	2.�洢�ܶȸߣ�ÿ�����ֻ�洢����Ԫ��
//	3.��չ����������
//	4.���롢ɾ�������㣬��Ҫ�ƶ�����Ԫ��
//
//
// 
// (3)˳���ʵ��
//	����Ϊ˳����ʵ��
//	ע�⣺��������ջ������ʵ�����Ա��ڴ���SqList�ṹ��ͬʱ����ջ���ռ�
//	���飺����SqList�ṹ��ʱ���ṹ���д��Element*���͵������׵�ַ���ڵ���initList��ʼ��ʱ��Ϊ����new�����ռ�






//// ����Ԫ��
//typedef struct Student {
//	string name;
//	int age;
//	string sex;
//}Element;
//
//
//// ˳���
//typedef struct SqList {
//	Element arr[MAX_SIZE];// �������Ԫ�ص�����
//	int length;// ˳���ǰ����
//}SqList;
//
//
//
//
//// ��������ʼ�����Ա�
//void initList(SqList& list) {
//	list.length = 0;
//}
//
//
//// ����������Ԫ�أ��ڱ�β����һ��Ԫ�أ�
//bool listAdd(SqList& list, const Element& element) {
//	if (list.length >= MAX_SIZE) {
//		cout << "˳���ռ䲻��" << endl;
//		return false;
//	}
//	list.arr[list.length] = element;
//	list.length++;
//	return true;
//}
//
//
//// ����������Ԫ�أ��ڵ�index��λ�ò���Ԫ��element��
////	ʱ�临�Ӷȣ�O(n)
//bool listInsert(SqList& list, int index, const Element& element) {
//	if (list.length >= MAX_SIZE) {
//		cout << "˳���ռ䲻��" << endl;
//		return false;
//	}
//	if(index < 0 || index > list.length){// ��������±귶Χ��[0, list.length]
//		cout << "����λ�ó����±귶Χ" << endl;
//		return false;
//	}
//
//	for (int i = list.length - 1; i >= index; i--) {// �Ѳ���λ�úͺ����Ԫ�ض�����Ų1λ
//		list.arr[i + 1] = list.arr[i];
//	}
//	list.arr[index] = element;
//	list.length++;
//	return true;
//
//}
//
//
//// ������ɾ����βԪ�أ��ӱ�β����һ��Ԫ�أ������䷵�ظ����ò�����
//bool listSub(SqList& list, Element& element) {
//	if (list.length <= 0) {
//		cout << "��ǰΪ�ձ��޷�����Ԫ��" << endl;
//		return false;
//	}
//	element = list.arr[list.length - 1];
//	list.length--;
//	return true;
//}
//
//
//// ������ɾ��ָ��Ԫ�أ�ɾ��ָ���±��Ԫ�أ������䷵�ظ����ò�����
//bool listDelete(SqList& list, int index, Element& element) {// ʱ�临�Ӷȣ�O(n)
//	if (list.length <= 0) {
//		cout << "��ǰΪ�ձ��޷�����Ԫ��" << endl;
//		return false;
//	}
//	if (index < 0 || index > list.length - 1) {// ����ɾ���±귶Χ��[0, list.length-1]
//		cout << "ɾ��λ�ó����±귶Χ" << endl;
//		return false;
//	}
//
//	element = list.arr[index];// ��ָ���±�Ԫ�ص�ֵ�����������Ͳ���
//	for (int i = index; i <= list.length - 2; i++) {
//		list.arr[i] = list.arr[i + 1];
//	}
//	list.length--;
//	return true;
//}
//
//
//// ��������λ����Ԫ�أ�����ָ���±�Ԫ�أ�
//Element getElement(const SqList& list, int index) {
//	if (index < 0 || index > list.length - 1) {
//		cout << "����λ�ó����±귶Χ" << endl;
//		return { NULL, 0, NULL };
//	}
//	return list.arr[index];
//}
//
//
//// ��������ֵ����Ԫ���±꣨����ָ������Ԫ�ص��±꣩
//int locateElement(const SqList& list, const string& name) {
//	for (int i = 0; i < list.length; i++) {
//		if (name == list.arr[i].name) {
//			return i;
//		}
//	}
//	cout << "Ԫ�ز�����" << endl;
//	return -1;
//}
//
//
//// ����������Ԫ����Ϣ
//string elementToString(const Element& element) {
//	return "{name=" + element.name + 
//		", age=" + to_string(element.age) + 
//		", sex=" + element.sex + "}";
//}
//
//
//// ��������ӡ˳���ȫ��Ԫ��
//void printList(const SqList& list) {
//	if (list.length == 0) {
//		cout << "˳���Ϊ��" << endl;
//		return;
//	}
//	for (int i = 0; i < list.length; i++) {
//		cout << "��" << i+1 << "λ��" << elementToString(list.arr[i]) << endl;
//	}
//}
//
//
//
//
//
//int main() {
//	//  1.�������Ա�
//	SqList list1;
//
//
//	// 2.��ʼ�����Ա�
//	initList(list1);
//	printList(list1);// ˳���Ϊ��
//	cout << endl;
//
//
//
//	// 3.����Ԫ��
//	Element e1 = { "����", 12, "��" };
//	Element e2 = { "����", 14, "Ů" };
//	Element e3 = { "����", 15, "��" };
//	listAdd(list1, e1);
//	listAdd(list1, e2);
//	listAdd(list1, e3);
//	printList(list1);
//	cout << endl;
//	//	��1λ��{ name = ����, age = 12, sex = �� }
//	//	��2λ��{ name = ����, age = 14, sex = Ů }
//	//	��3λ��{ name = ����, age = 15, sex = �� }
//
//
//	// 4.����(ָ���±�)Ԫ��
//	Element e4 = { "С��", 44, "��" };
//	Element e5 = { "С��", 54, "Ů" };
//	Element eTest1;
//	listInsert(list1, 3, e4);
//	listInsert(list1, 1, e5);
//	listInsert(list1, 100, eTest1);// ����λ�ó����±귶Χ
//	cout << "===============" << endl;
//	printList(list1);
//	cout << endl;
//	//	��1λ��{ name = ����, age = 12, sex = �� }
//	//	��2λ��{ name = С��, age = 54, sex = Ů }
//	//	��3λ��{ name = ����, age = 14, sex = Ů }
//	//	��4λ��{ name = ����, age = 15, sex = �� }
//	//	��5λ��{ name = С��, age = 44, sex = �� }
//
//
//
//	// 5.��λ(�±�)����Ԫ��
//	Element ret1 = getElement(list1, 2);
//	cout << elementToString(ret1) << endl << endl;// {name=����, age=14, sex=Ů}
//
//	// 6.��ֵ(����)����Ԫ���±�
//	cout << locateElement(list1, "С��") << endl;// 1
//	cout << locateElement(list1, "������") << endl << endl;// Ԫ�ز����ڣ�-1
//
//
//
//	// 7.����(��β)Ԫ��
//	Element e6;
//	listSub(list1, e6);
//	cout << "===============" << endl;
//	cout << elementToString(e6) << endl;// {name=С��, age=44, sex=��}
//	cout << "===============" << endl;
//	printList(list1);
//	cout << endl;
//	//	��1λ��{ name = ����, age = 12, sex = �� }
//	//	��2λ��{ name = С��, age = 54, sex = Ů }
//	//	��3λ��{ name = ����, age = 14, sex = Ů }
//	//	��4λ��{ name = ����, age = 15, sex = �� }
//
//
//	// 8.ɾ��(ָ���±�)Ԫ��
//	Element e7, e8, eTest2;
//	listDelete(list1, 1, e7);
//	listDelete(list1, 0, e8);
//	listDelete(list1, 100, eTest2);// ɾ��λ�ó����±귶Χ
//	cout << "===============" << endl;
//	cout << elementToString(e7) << endl;// {name=С��, age=54, sex=Ů}
//	cout << elementToString(e8) << endl;// {name=����, age=12, sex=��}
//	cout << "===============" << endl;
//	printList(list1);
//	cout << endl;
//	//	��1λ��{ name = ����, age = 14, sex = Ů }
//	//	��2λ��{ name = ����, age = 15, sex = �� }
//
//
//	return 0;
//}