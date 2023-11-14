#include<iostream>
using namespace std;
#include<string>




// ������linked list��
//
// (1)���
//	�������ÿ����������������(�������Ԫ��) �� ָ����(����¸�����ָ��)
// 
// 
// (2)ͷָ�롢ͷ��㡢��Ԫ���
//	ͷָ�룺ָ��ͷ����ָ�룬�����������ͷָ�뿪ʼ
//	ͷ��㣺��Ԫ���ǰ�����һ����㣬���ڴ洢������Ϣ���򲻴洢��Ϣ	
//	��Ԫ��㣺��ŵ�һ��Ԫ�صĽ�㣬��ͷ���ĺ��
// 
// 
// (3)����ͷ���ĺô�
//	1.�������ݴ���
//		ͷ���������Ԫ��㣬��֤����Ե�һ��Ԫ�صĴ������������Ԫ����ͬ���������⴦��
//	2.���ڷǿձ�Ϳձ��ͳһ����
//		���������Ƿ�Ϊ�գ�������ͷ���






//// ����Ԫ��
//typedef struct Student {
//	string name;
//	int age;
//	string sex;
//}Element;
//
// 
//// ������
//typedef struct LNode {
//	Element data;// ������
//	LNode* next;// ָ����
//}LNode, *LinkList;
//// ������typedef��LNode*����ΪLinkList
//
//
//
//
//// ��������ʼ������Ϊͷָ�봴��ͷ��㣩
//bool initList(LinkList& L) {// ��������ͷָ��
//	L = new LNode;// newͷ���
//	L->next = NULL;
//	return true;
//}
//
//
//// ������ͷ�巨����һ��Ԫ�ء�����
//bool listHeadAdd(LinkList& L, const Element& element) {
//	LNode* p = new LNode;
//	p->data = element;
//	p->next = L->next;
//	L->next = p;
//	return true;
//}
//
//
//// ��������ȡ����βָ�루����ָ�����һ������ָ�룩
//LNode* getTailPointer(const LinkList& L) {
//	LNode* p = L;
//	while (p->next) {// ����pָ��β���
//		p = p->next;
//	}
//	return p;
//}
//
//
//// ������β�巨����һ��Ԫ�ء�����
//bool listTailAdd(LinkList& L, const Element& element) {
//	LNode* p = new LNode;
//	p->data = element;
//	p->next = NULL;
//	getTailPointer(L)->next = p;
//	return true;
//}
//
//
//// ��������λ����Ԫ�ء��������ڵ�i��λ�ò���Ԫ��element��
//bool listInsert(LinkList& L, int i, const Element& element) {
//	if (i < 1) {
//		cout << "����λ����Ч" << endl;
//		return false;
//	}
//
//	LNode* p1 = L;
//	// ��p1ָ���i-1��Ԫ�ؽ�� ����n��Ԫ�أ���ɲ��뷶Χ��[1, n+1]��
//	while (p1 && --i) {// --i��ʹp1ָ���i-1��Ԫ��
//		p1 = p1->next;
//	}
//	if (!p1) {// �����iλ�ã�i����ΪNULL����i-1���������
//		cout << "����λ�ó���Ԫ�ط�Χ" << endl;
//		return false;
//	}
//
//	LNode* p2 = new LNode;
//	p2->data = element;
//	p2->next = p1->next;
//	p1->next = p2;
//	return true;
//}
//
//
//// ��������ָ�����ǰ����һ��Ԫ�ء�����
//// ˼·��e.g.����������x->y->z����Ҫ��yǰ����һ��e���
////		 ���ڵ�����ֻ�ܷ��ʺ�̣��޷����ʵ�ǰ��
////		 ���ǿ�����ת˼·����y�����ֲ���һ��y'��Ȼ���ǰ���y�ĳ�e
////		 ��(x->y->z)  ��(x->y->y'->z)  ��(x->e->y'->z)
//// ʱ�临�Ӷȣ�O(1)����
//bool insertPriorNode(LNode* p, const Element& element) {
//	if (!p) {
//		cout << "������Ч���" << endl;
//		return false;
//	}
//	LNode* p1 = new LNode;
//	p1->data = p->data;// ��p�������ٲ���һ��p���Ŀ���p1
//	p1->next = p->next;
//	p->next = p1;
//	p->data = element;// ��p�������ݸ�Ϊelement
//	return true;
//}
//
//
//
//// ������ɾ����ͷԪ�ء�ɾ����������ɾ���ݷ��ظ����ò�����
//bool listHeadSub(LinkList& L, Element& element) {
//	if (!L->next) {
//		cout << "����Ϊ�գ��޷�ɾ��Ԫ��" << endl;
//		return false;
//	}
//	LNode* q = L->next;
//	element = q->data;
//	L->next = q->next;
//	delete q;
//	return true;
//}
//
//
//// ������ɾ����βԪ�ء�ɾ����������ɾ���ݷ��ظ����ò�����
//bool listTailSub(LinkList& L, Element& element) {
//	if (!L->next) {
//		cout << "����Ϊ�գ��޷�ɾ��Ԫ��" << endl;
//		return false;
//	}
//	LNode* p = L;
//	while (p->next->next) {// p����Ϊβ����ǰ��
//		p = p->next;
//	}
//	LNode* q = p->next;
//	element = q->data;
//	p->next = NULL;
//	delete q;
//	return 0;
//}
//
//
//// ��������λɾ��Ԫ�ء�ɾ����������ɾ���ݷ��ظ����ò�����
//bool listDelete(LinkList& L, int i, Element& element) {
//	if (!L->next) {
//		cout << "����Ϊ�գ��޷�ɾ��Ԫ��" << endl;
//		return false;
//	}
//	if (i < 1) {
//		cout << "ɾ��λ����Ч" << endl;
//		return false;
//	}
//
//	LNode* p = L;
//	// ��pָ���i-1��Ԫ�ؽ�� ����n��Ԫ�أ���ɲ��뷶Χ��[1, n]��
//	while (p->next && --i) {
//		p = p->next;
//	}
//	if (!p->next) {// ɾ����iλ�ã�i-1��i��㶼������ڣ��ԱȰ�λ������룩
//		cout << "ɾ��λ�ó���Ԫ�ط�Χ" << endl;
//		return false;
//	}
//
//	LNode* q = p->next;// qΪҪɾ���ĵ�i��Ԫ��
//	element = q->data;
//	p->next = q->next;
//	delete q;
//	return true;
//}
//
//
//// ������ɾ��������㡾ɾ��
//// ˼·�����ڵ�������ֱ�ӻ�ø������p��ǰ����
////		 �����ת˼·���ȰѺ�̵�ֵ����p���ٰ�p�ĺ��ɾ������
////		 ɾ��p��(x->p->y) (x->y'->y) (x->y')
//// ע�⣺��pΪβ��㣬ָ��NULL���޷�����ɾ����̣������������޷�ʹ��
//bool deleteNode(LNode* p) {
//	if (!p) {
//		cout << "���Ϊ�գ��޷�ɾ��" << endl;
//		return false;
//	}
//	if (!p->next) {
//		cout << "����̽��ΪNULL���������޷�ʹ��" << endl;
//		return false;
//	}
//	LNode* q = p->next;
//	p->data = q->data;// ��p��̵�ֵ����p
//	p->next = q->next;// ɾ��p�ĺ��
//	delete q;
//	return true;
//}
//
//
//
//// ��������λ����Ԫ�ء��顿������ָ��λ�õ�Ԫ�أ�
//LNode* getElement(LinkList L, int i) {
//	if (i < 1) {
//		cout << "����λ����Ч" << endl;
//		return NULL;
//	}
//
//	LNode* p = L;
//	while (p && i--)// i--������pָ���i��Ԫ��
//	{
//		p = p->next;
//	}
//	if (!p) {
//		cout << "����λ�ó�������" << endl;
//		return NULL;
//	}
//	return p;
//}
//
//
//// ��������ֵ(�ؼ���)����Ԫ�ء��顿
//LNode* locateElement(LinkList L, string name) {
//	LNode* p = L->next;
//	while (p) {
//		if (p->data.name == name) {
//			return p;
//		}
//		p = p->next;
//	}
//
//	cout << "���ҹؼ���Ԫ�ز�����" << endl;
//	return NULL;
//}
//
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
//void printLinkList(const LinkList& L) {
//	if (!L || !L->next) {
//		cout << "����Ϊ��" << endl;
//		return;
//	}
//	LNode* p = L->next;// ��Ԫ���
//	int i = 1;
//	while (p) {
//		cout << "��" << i << "λ��" << elementToString(p->data) << endl;
//		p = p->next;
//		i++;
//	}
//}
//
//
//
//// ������(ͷ�巨)�����������������������ת��Ϊ������
//LinkList createList_HeadInsert(Element* arr, int length) {
//	if (!arr || length < 0) {
//		cout << "�����쳣����" << endl;
//		return NULL;
//	}
//
//	LinkList L = NULL;
//	initList(L);// ����ͷ���
//	LNode* tmp = NULL;
//	for (int i = length - 1; i >= 0; i--) {// ͷ�壺�ڱ�ͷ����洢����Ԫ��
//		tmp = new LNode;
//		tmp->data = arr[i];
//		tmp->next = L->next;
//		L->next = tmp;
//	}
//	return L;
//}
//
//
//// ������(β�巨)�����������������������ת��Ϊ������
//LinkList createList_TailInsert(Element* arr, int length) {
//	if (!arr || length < 0) {
//		cout << "�����쳣����" << endl;
//		return NULL;
//	}
//
//	LinkList L = NULL;
//	initList(L);// ����ͷ���
//	LNode* pTail = L;// ����βָ��
//	for (int i = 0; i < length; i++) {// β�壺�ڱ�β˳��洢����Ԫ��
//		pTail->next = new LNode;
//		pTail = pTail->next;
//		pTail->data = arr[i];
//	}
//	pTail->next = NULL;
//	return L;
//}
//
//
//
//
//
//int main() {
//	// 1.��������
//	//�������Lʵ�����������ͷָ�룬������ʾ����
//	LinkList L = NULL;
//
//	// 2.��ʼ��������
//	initList(L);
//	printLinkList(L);// ����Ϊ��
//
//
//
//	// 3.ͷ/β�巨Ϊ�������Ԫ��
//	Element e1 = { "����", 22, "��" };
//	Element e2 = { "����", 33, "Ů" };
//	Element e3 = { "����", 44, "��" };
//	listHeadAdd(L, e2);
//	listHeadAdd(L, e1);
//	listTailAdd(L, e3);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	//	��1λ��{ name = ����, age = 22, sex = �� }
//	//	��2λ��{ name = ����, age = 33, sex = Ů }
//	//	��3λ��{ name = ����, age = 44, sex = �� }
//
//
//	// 4.��ָ��λ�ò�����Ԫ��
//	Element e4 = { "С��", 14, "��" };
//	Element e5 = { "С��", 15, "Ů" };
//	listInsert(L, 2, e4);
//	listInsert(L, 5, e5);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	//	��1λ��{ name = ����, age = 22, sex = �� }
//	//	��2λ��{ name = С��, age = 14, sex = �� }
//	//	��3λ��{ name = ����, age = 33, sex = Ů }
//	//	��4λ��{ name = ����, age = 44, sex = �� }
//	//	��5λ��{ name = С��, age = 15, sex = Ů }
//
//
//	// 5.��ָ�����ǰ����һ��ǰ���������ݣ�
//	Element e6 = { "����", 88, "��" };
//	insertPriorNode(L->next->next->next, e6);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	//	��1λ��{ name = ����, age = 22, sex = �� }
//	//	��2λ��{ name = С��, age = 14, sex = �� }
//	//	��3λ��{ name = ����, age = 88, sex = �� }
//	//	��4λ��{ name = ����, age = 33, sex = Ů }
//	//	��5λ��{ name = ����, age = 44, sex = �� }
//	//	��6λ��{ name = С��, age = 15, sex = Ů }
//
//
//
//	// 6.��λ����Ԫ��
//	LNode* p1 = getElement(L, 3);
//	LNode* p2 = getElement(L, 4);
//	LNode* p3 = getElement(L, 0);// ����λ����Ч
//	LNode* p4 = getElement(L, 7);// ����λ�ó�������
//	cout << "\n================" << endl;
//	cout << elementToString(p1->data) << endl;
//	cout << elementToString(p2->data) << endl;
//	cout << p3 << endl;
//	cout << p4 << endl;
//	//	{name = ����, age = 88, sex = ��}
//	//	{name = ����, age = 33, sex = Ů}
//	//	0000000000000000
//	//	0000000000000000
//
//
//	// 7.���ؼ��ֲ���Ԫ��
//	LNode* p5 = locateElement(L, "����");
//	LNode* p6 = locateElement(L, "������");// ���ҹؼ���Ԫ�ز�����
//	cout << "\n================" << endl;
//	cout << elementToString(p5->data) << endl;
//	cout << p6 << endl;
//	//	{name = ����, age = 44, sex = ��}
//	//	0000000000000000
//
//
//
//	// 8.ɾ��(������)ָ��λ�õ�Ԫ��
//	Element ret1;
//	Element ret2;
//	listDelete(L, 2, ret1);
//	listDelete(L, 5, ret2);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	cout << "================" << endl;
//	cout << elementToString(ret1) << endl;
//	cout << elementToString(ret2) << endl;
//	//	��1λ��{ name = ����, age = 22, sex = �� }
//	//	��2λ��{ name = ����, age = 88, sex = �� }
//	//	��3λ��{ name = ����, age = 33, sex = Ů }
//	//	��4λ��{ name = ����, age = 44, sex = �� }
//	//	================
//	//	{name = С��, age = 14, sex = ��}
//	//	{name = С��, age = 15, sex = Ů}
//
//
//	// 9.ɾ��������ͷ/βԪ��
//	Element ret3;
//	Element ret4;
//	listHeadSub(L, ret3);
//	listTailSub(L, ret4);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	cout << "================" << endl;
//	cout << elementToString(ret3) << endl;
//	cout << elementToString(ret4) << endl;
//	//	��1λ��{ name = ����, age = 88, sex = �� }
//	//	��2λ��{ name = ����, age = 33, sex = Ů }
//	//	================
//	//	{name = ����, age = 22, sex = ��}
//	//	{name = ����, age = 44, sex = ��}
//
//
//	// 10.ɾ��ָ�����
//	deleteNode(L->next);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	//	��1λ��{name=����, age=33, sex=Ů}
//
//
//
//
//	// 11.ͷ�巨������ת��Ϊ����
//	cout << "\n================" << endl;
//	Element arr[] = {{"����", 11, "��"}, {"����", 15, "Ů"}, 
//		{"����", 21, "��"}, {"����", 37, "��"}, {"����", 51, "Ů"}};
//	int length = sizeof(arr) / sizeof(arr[0]);
//	LinkList L1 = createList_HeadInsert(arr, length);
//	printLinkList(L1);
//	//	��1λ��{ name = ����, age = 11, sex = �� }
//	//	��2λ��{ name = ����, age = 15, sex = Ů }
//	//	��3λ��{ name = ����, age = 21, sex = �� }
//	//	��4λ��{ name = ����, age = 37, sex = �� }
//	//	��5λ��{ name = ����, age = 51, sex = Ů }
//
//
//	// 12.β�巨������ת��Ϊ����
//	cout << "\n================" << endl;
//	LinkList L2 = createList_TailInsert(arr, length);
//	//	��1λ��{ name = ����, age = 11, sex = �� }
//	//	��2λ��{ name = ����, age = 15, sex = Ů }
//	//	��3λ��{ name = ����, age = 21, sex = �� }
//	//	��4λ��{ name = ����, age = 37, sex = �� }
//	//	��5λ��{ name = ����, age = 51, sex = Ů }
//	printLinkList(L2);
//
//
//	return 0;
//}