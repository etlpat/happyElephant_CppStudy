#include "_05_ForestLinkedList.h"


bool initList(ForestLinkdeList& L) {
	L = new LNode;// ����ͷ���
	L->tree = NULL;
	L->prior = L;
	L->next = L;
	return true;
}


bool isEmpty(const ForestLinkdeList& L) {
	return L->next == L;
}


bool isOnlyOne(const ForestLinkdeList& L) {
	return !isEmpty(L) && L->next->next == L;
}


// ���β���
bool addTail(ForestLinkdeList& L, TNode* tree) {
	LNode* tmp = new LNode();
	tmp->tree = tree;
	tmp->prior = L->prior;
	tmp->next = L;
	L->prior->next = tmp;
	L->prior = tmp;
	return true;
}


// ��������ȫ��Ԫ����ӵ�������
bool addAll(ForestLinkdeList& L, Element* arr, int sz) {
	TNode* pt;
	for (int i = 0; i < sz; i++) {
		pt = new TNode();
		pt->data.key = arr[i].key;
		pt->data.value = arr[i].value;
		pt->leftChild = NULL;
		pt->rightChild = NULL;
		addTail(L, pt);
	}
	return true;
}


// ɾ����Ԫ���
bool removeHead(ForestLinkdeList& L, TNode*& tree) {
	if (isEmpty(L)) {
		return false;
	}
	tree = L->next->tree;
	LNode* tmp = L->next;
	L->next = tmp->next;
	tmp->next->prior = L;
	delete tmp;
	return true;
}


// ����Ԫ�أ����Ҳ����˫��������Ȼ����
bool insertByOrder(ForestLinkdeList& L, TNode* tree) {
	LNode* p = L;
	while (p->next != L && p->next->tree->data.value < tree->data.value) {// ʹpָ������ǰһ��Ϊֹ
		p = p->next;
	}
	LNode* tmp = new LNode();
	tmp->tree = tree;
	tmp->next = p->next;
	tmp->prior = p;
	p->next->prior = tmp;
	p->next = tmp;
	return true;
}


bool destroy(ForestLinkdeList& L) {
	L->prior->next = NULL;
	LNode* p = L->next;
	while (p) {
		delete L;
		L = p;
		p = L->next;
	}
	delete L;
	return true;
}