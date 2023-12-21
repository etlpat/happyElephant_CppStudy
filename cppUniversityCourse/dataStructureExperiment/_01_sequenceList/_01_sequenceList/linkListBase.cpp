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
		cout << "插入位置无效" << endl;
		return false;
	}

	LNode* p1 = L;
	// 让p1指向第i-1个元素结点 （共n个元素，则可插入范围是[1, n+1]）
	while (p1 && --i) {// --i可使p1指向第i-1个元素
		p1 = p1->next;
	}
	if (!p1) {// 插入第i位置，i结点可为NULL，但i-1结点必须存在
		cout << "插入位置超出元素范围" << endl;
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
		cout << "传入无效结点" << endl;
		return false;
	}
	LNode* p1 = new LNode;
	p1->data = p->data;// 在p结点后面再插入一个p结点的拷贝p1
	p1->next = p->next;
	p->next = p1;
	p->data = element;// 把p结点的数据赋为element
	return true;
}


bool listHeadSub(LinkList& L, Element& element) {
	if (!L->next) {
		cout << "链表为空，无法删除元素" << endl;
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
		cout << "链表为空，无法删除元素" << endl;
		return false;
	}
	LNode* p = L;
	while (p->next->next) {// p最终为尾结点的前驱
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
		cout << "链表为空，无法删除元素" << endl;
		return false;
	}
	if (i < 1) {
		cout << "删除位置无效" << endl;
		return false;
	}

	LNode* p = L;
	// 让p指向第i-1个元素结点 （共n个元素，则可插入范围是[1, n]）
	while (p->next && --i) {
		p = p->next;
	}
	if (!p->next) {// 删除第i位置，i-1和i结点都必须存在（对比按位插入代码）
		cout << "删除位置超出元素范围" << endl;
		return false;
	}

	LNode* q = p->next;// q为要删除的第i个元素
	element = q->data;
	p->next = q->next;
	delete q;
	return true;
}


bool deleteNode(LNode* p) {
	if (!p) {
		cout << "结点为空，无法删除" << endl;
		return false;
	}
	if (!p->next) {
		cout << "若后继结点为NULL，本方法无法使用" << endl;
		return false;
	}
	LNode* q = p->next;
	p->data = q->data;// 将p后继的值赋给p
	p->next = q->next;// 删除p的后继
	delete q;
	return true;
}


LNode* getElement(LinkList L, int i) {
	if (i < 1) {
		cout << "查找位置无效" << endl;
		return NULL;
	}

	LNode* p = L;
	while (p && i--)// i--可以让p指向第i个元素
	{
		p = p->next;
	}
	if (!p) {
		cout << "查找位置超出界限" << endl;
		return NULL;
	}
	return p;
}


string elementToString(const Element& element) {
	return "系数=" + to_string(element.num) +
		", 次数=" + to_string(element.index);
}


void printLinkList(const LinkList& L) {
	if (!L || !L->next) {
		cout << "链表为空" << endl;
		return;
	}

	cout << "x的值为：" << L->data.num << endl;
	LNode* p = L->next;// 首元结点
	int i = 1;
	while (p) {
		cout << "第" << i << "位：" << elementToString(p->data) << endl;
		p = p->next;
		i++;
	}
}


LinkList createList_HeadInsert(double x, Element* arr, int length) {
	if (!arr || length < 0) {
		cout << "传入异常数据" << endl;
		return NULL;
	}

	LinkList L = NULL;
	initList(L, x);// 创建头结点
	LNode* tmp = NULL;
	for (int i = length - 1; i >= 0; i--) {// 头插：在表头倒叙存储数组元素
		tmp = new LNode;
		tmp->data = arr[i];
		tmp->next = L->next;
		L->next = tmp;
	}
	return L;
}


LinkList createList_TailInsert(double x, Element* arr, int length) {
	if (!arr || length < 0) {
		cout << "传入异常数据" << endl;
		return NULL;
	}

	LinkList L = NULL;
	initList(L, x);// 创建头结点
	LNode* pTail = L;// 保存尾指针
	for (int i = 0; i < length; i++) {// 尾插：在表尾顺序存储数组元素
		pTail->next = new LNode;
		pTail = pTail->next;
		pTail->data = arr[i];
	}
	pTail->next = NULL;
	return L;
}