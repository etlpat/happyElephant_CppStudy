#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 100


// ����Ԫ��
typedef struct Element {
	double value;
}Element;

// ˳���
typedef struct SqList {
	Element arr[MAX_SIZE];// �������Ԫ�ص�����
	int length;// ˳���ǰ����
}SqList;


// ��������ʼ�����Ա�
void initList(SqList& list) {
	list.length = 0;
}


// ����������Ԫ�أ��ڵ�index��λ�ò���Ԫ��element��
bool listInsert(SqList& list, int index, const Element& element) {
	if (list.length >= MAX_SIZE) {
		cout << "˳���ռ䲻��" << endl;
		return false;
	}
	if(index < 0 || index > list.length){// ��������±귶Χ��[0, list.length]
		cout << "����λ�ó����±귶Χ" << endl;
		return false;
	}

	for (int i = list.length - 1; i >= index; i--) {// �Ѳ���λ�úͺ����Ԫ�ض�����Ų1λ
		list.arr[i + 1] = list.arr[i];
	}
	list.arr[index] = element;
	list.length++;
	return true;

}


// ��������λ����Ԫ�أ�����ָ���±�Ԫ�أ�
Element getElement(const SqList& list, int index) {
	if (index < 0 || index > list.length - 1) {
		cout << "����λ�ó����±귶Χ" << endl;
		return { 0 };
	}
	return list.arr[index];
}


// ����������˳�����Ԫ��
bool insertByOrder(SqList& list, double value) {
	if (list.length >= MAX_SIZE) {
		cout << "˳���ռ䲻��" << endl;
		return false;
	}

	Element e = { value };
	int i = 0;
	if (list.length != 0) {
		while (i < list.length && list.arr[i].value < value) {
			i++;
		}
	}
	return listInsert(list, i, e);
}


// ������ɾ����βԪ�أ��ӱ�β����һ��Ԫ�أ������䷵�ظ����ò�����
bool listSub(SqList& list, Element& element) {
	if (list.length <= 0) {
		cout << "��ǰΪ�ձ��޷�����Ԫ��" << endl;
		return false;
	}
	element = list.arr[list.length - 1];
	list.length--;
	return true;
}


// ������ɾ��ָ��Ԫ�أ�ɾ��ָ���±��Ԫ�أ������䷵�ظ����ò�����
bool listDelete(SqList& list, int index, Element& element) {// ʱ�临�Ӷȣ�O(n)
	if (list.length <= 0) {
		cout << "��ǰΪ�ձ��޷�����Ԫ��" << endl;
		return false;
	}
	if (index < 0 || index > list.length - 1) {// ����ɾ���±귶Χ��[0, list.length-1]
		cout << "ɾ��λ�ó����±귶Χ" << endl;
		return false;
	}

	element = list.arr[index];// ��ָ���±�Ԫ�ص�ֵ�����������Ͳ���
	for (int i = index; i <= list.length - 2; i++) {
		list.arr[i] = list.arr[i + 1];
	}
	list.length--;
	return true;
}


// ��������ֵ����Ԫ���±꣨����ָ������Ԫ�ص��±꣩
int locateElement(const SqList& list, const double value) {
	for (int i = 0; i < list.length; i++) {
		if (value == list.arr[i].value) {
			return i;
		}
	}
	cout << "Ԫ�ز�����" << endl;
	return -1;
}


// ����������Ԫ����Ϣ
string elementToString(const Element& element) {
	return "value=" + to_string(element.value);
}


// ��������ӡ˳���ȫ��Ԫ��
void printList(const SqList& list) {
	if (list.length == 0) {
		cout << "˳���Ϊ��" << endl;
		return;
	}
	for (int i = 0; i < list.length; i++) {
		cout << "��" << i + 1 << "λ��" << elementToString(list.arr[i]) << endl;
	}
}


int main() {
	SqList L;
	initList(L);

	insertByOrder(L, 44);
	insertByOrder(L, -10);
	insertByOrder(L, 26);
	insertByOrder(L, 467);
	insertByOrder(L, 6);
	insertByOrder(L, 1);
	insertByOrder(L, 61);
	insertByOrder(L, 7);
	
	printList(L);

	return 0;
}