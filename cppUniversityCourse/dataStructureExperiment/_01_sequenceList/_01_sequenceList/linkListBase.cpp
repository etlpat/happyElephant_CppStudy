#include"myHead.h"


bool initList(LinkList& L) {
	L = new LNode;
	L->next = NULL;
	return true;
}

bool initList(LinkList& L, double x) {
	L = new LNode;
	L->data.num = x;
	L->next = NULL;
	return true;
}


bool listHeadAdd(LinkList& L, const Element& element) {
	LNode* p = new LNode;
	p->data = element;
	p->next = L->next;
	L->next = p;
	return true;
}


LNode* getTailPointer(const LinkList& L) {
	LNode* p = L;
	while (p->next) {
		p = p->next;
	}
	return p;
}


bool listTailAdd(LinkList& L, const Element& element) {
	LNode* p = new LNode;
	p->data = element;
	p->next = NULL;
	getTailPointer(L)->next = p;
	return true;
}


bool listInsert(LinkList& L, int i, const Element& element) {
	if (i < 1) {
		cout << "����λ����Ч" << endl;
		return false;
	}

	LNode* p1 = L;
	// ��p1ָ���i-1��Ԫ�ؽ�� ����n��Ԫ�أ���ɲ��뷶Χ��[1, n+1]��
	while (p1 && --i) {// --i��ʹp1ָ���i-1��Ԫ��
		p1 = p1->next;
	}
	if (!p1) {// �����iλ�ã�i����ΪNULL����i-1���������
		cout << "����λ�ó���Ԫ�ط�Χ" << endl;
		return false;
	}

	LNode* p2 = new LNode;
	p2->data = element;
	p2->next = p1->next;
	p1->next = p2;
	return true;
}


bool insertPriorNode(LNode* p, const Element& element) {
	if (!p) {
		cout << "������Ч���" << endl;
		return false;
	}
	LNode* p1 = new LNode;
	p1->data = p->data;// ��p�������ٲ���һ��p���Ŀ���p1
	p1->next = p->next;
	p->next = p1;
	p->data = element;// ��p�������ݸ�Ϊelement
	return true;
}


bool listHeadSub(LinkList& L, Element& element) {
	if (!L->next) {
		cout << "����Ϊ�գ��޷�ɾ��Ԫ��" << endl;
		return false;
	}
	LNode* q = L->next;
	element = q->data;
	L->next = q->next;
	delete q;
	return true;
}


bool listTailSub(LinkList& L, Element& element) {
	if (!L->next) {
		cout << "����Ϊ�գ��޷�ɾ��Ԫ��" << endl;
		return false;
	}
	LNode* p = L;
	while (p->next->next) {// p����Ϊβ����ǰ��
		p = p->next;
	}
	LNode* q = p->next;
	element = q->data;
	p->next = NULL;
	delete q;
	return 0;
}


bool listDelete(LinkList& L, int i, Element& element) {
	if (!L->next) {
		cout << "����Ϊ�գ��޷�ɾ��Ԫ��" << endl;
		return false;
	}
	if (i < 1) {
		cout << "ɾ��λ����Ч" << endl;
		return false;
	}

	LNode* p = L;
	// ��pָ���i-1��Ԫ�ؽ�� ����n��Ԫ�أ���ɲ��뷶Χ��[1, n]��
	while (p->next && --i) {
		p = p->next;
	}
	if (!p->next) {// ɾ����iλ�ã�i-1��i��㶼������ڣ��ԱȰ�λ������룩
		cout << "ɾ��λ�ó���Ԫ�ط�Χ" << endl;
		return false;
	}

	LNode* q = p->next;// qΪҪɾ���ĵ�i��Ԫ��
	element = q->data;
	p->next = q->next;
	delete q;
	return true;
}


bool deleteNode(LNode* p) {
	if (!p) {
		cout << "���Ϊ�գ��޷�ɾ��" << endl;
		return false;
	}
	if (!p->next) {
		cout << "����̽��ΪNULL���������޷�ʹ��" << endl;
		return false;
	}
	LNode* q = p->next;
	p->data = q->data;// ��p��̵�ֵ����p
	p->next = q->next;// ɾ��p�ĺ��
	delete q;
	return true;
}


LNode* getElement(LinkList L, int i) {
	if (i < 1) {
		cout << "����λ����Ч" << endl;
		return NULL;
	}

	LNode* p = L;
	while (p && i--)// i--������pָ���i��Ԫ��
	{
		p = p->next;
	}
	if (!p) {
		cout << "����λ�ó�������" << endl;
		return NULL;
	}
	return p;
}


string elementToString(const Element& element) {
	return "ϵ��=" + to_string(element.num) +
		", ����=" + to_string(element.index);
}


void printLinkList(const LinkList& L) {
	if (!L || !L->next) {
		cout << "����Ϊ��" << endl;
		return;
	}

	cout << "x��ֵΪ��" << L->data.num << endl;
	LNode* p = L->next;// ��Ԫ���
	int i = 1;
	while (p) {
		cout << "��" << i << "λ��" << elementToString(p->data) << endl;
		p = p->next;
		i++;
	}
}


LinkList createList_HeadInsert(double x, Element* arr, int length) {
	if (!arr || length < 0) {
		cout << "�����쳣����" << endl;
		return NULL;
	}

	LinkList L = NULL;
	initList(L, x);// ����ͷ���
	LNode* tmp = NULL;
	for (int i = length - 1; i >= 0; i--) {// ͷ�壺�ڱ�ͷ����洢����Ԫ��
		tmp = new LNode;
		tmp->data = arr[i];
		tmp->next = L->next;
		L->next = tmp;
	}
	return L;
}


LinkList createList_TailInsert(double x, Element* arr, int length) {
	if (!arr || length < 0) {
		cout << "�����쳣����" << endl;
		return NULL;
	}

	LinkList L = NULL;
	initList(L, x);// ����ͷ���
	LNode* pTail = L;// ����βָ��
	for (int i = 0; i < length; i++) {// β�壺�ڱ�β˳��洢����Ԫ��
		pTail->next = new LNode;
		pTail = pTail->next;
		pTail->data = arr[i];
	}
	pTail->next = NULL;
	return L;
}