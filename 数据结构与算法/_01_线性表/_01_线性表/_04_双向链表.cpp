#include<iostream>
using namespace std;
#include<string>




// (ѭ��)˫������double linked list��
// 
//	˫������Ľ���������ָ�룬ָ��priorָ��ǰ����㣬ָ��nextָ���̽��
//	ѭ����ͷ����ǰ��Ϊβ��㣬β���ĺ��Ϊͷ���






// ����Ԫ��
typedef struct Student {
	string name;
	int age;
	string sex;
}Element;


// ˫��������
typedef struct DulNode {
	Element data;
	DulNode* prior;// ǰ��ָ��
	DulNode* next;// ���ָ��
}DulNode, *DulLinkList;
// ��typedef��DulNode*����ΪDulLinkList��������ͷָ���ʾ����˫������



// ��������ʼ��˫������Ϊͷָ�봴��ͷ��㣩
bool initDulLinkList(DulLinkList& L) {
	L = new DulNode;
	L->prior = L;
	L->next = L;
	return true;
}


// �������ڱ�ͷ����һ��Ԫ�ء�����
bool dulListHeadAdd(DulLinkList& L, const Element e) {
	DulNode* p = new DulNode;
	p->data = e;
	p->prior = L;
	p->next = L->next;
	L->next->prior = p;
	L->next = p;
	return true;
}


// �������ڱ�β����һ��Ԫ�ء�����
bool dulListTailAdd(DulLinkList& L, const Element e) {
	DulNode* p = new DulNode;
	p->data = e;
	p->prior = L->prior;
	p->next = L;
	L->prior->next = p;
	L->prior = p;
	return true;
}


// �������ڵ�i��λ�ò���Ԫ�ء�����
bool dulListInsert(DulLinkList& L, int i, const Element e) {
	if (i <= 0) {
		cout << "����λ����Ч" << endl;
		return false;
	}

	DulNode* p = L;
	while (--i && p->next != L) {// ʹpָ���i-1�����
		p = p->next;
	}
	if (i != 0) {
		cout << "����λ����Ч" << endl;
		return false;
	}

	DulNode* newNodePoint = new DulNode;
	newNodePoint->data = e;
	newNodePoint->prior = p;
	newNodePoint->next = p->next;
	p->next->prior = newNodePoint;
	p->next = newNodePoint;
	return true;
}


// �������ӱ�ͷɾ��һ��Ԫ�أ�������ɾ���ݷ��ظ����ò�������ɾ��
bool dulListHeadDelete(DulLinkList& L, Element& e) {
	if (L->next == L) {
		cout << "˫������Ϊ�գ��޷�ɾ��Ԫ��" << endl;
		return false;
	}

	DulNode* p = L->next;
	e = p->data;
	L->next = p->next;
	L->next->prior = L;
	delete p;
	return true;
}


// �������ӱ�βɾ��һ��Ԫ�أ�������ɾ���ݷ��ظ����ò�������ɾ��
bool dulListTailDelete(DulLinkList& L, Element& e) {
	if (L->next == L) {
		cout << "˫������Ϊ�գ��޷�ɾ��Ԫ��" << endl;
		return false;
	}

	DulNode* p = L->prior;
	e = p->data;
	L->prior = p->prior;
	L->prior->next = L;
	delete p;
	return true;
}


// ������ɾ��ָ��Ԫ�أ�������ɾ���ݷ��ظ����ò�������ɾ��
bool dulListDelete(DulLinkList& L, int i, Element& e) {
	if (i <= 0) {
		cout << "ɾ��λ����Ч" << endl;
		return false;
	}
	if (L->next == L) {
		cout << "˫������Ϊ�գ��޷�ɾ��Ԫ��" << endl;
		return false;
	}

	DulNode* p = L->next;
	while (--i && p->next != L) {// ʹpָ���i�����
		p = p->next;
	}
	if (i != 0) {
		cout << "ɾ��λ����Ч" << endl;
		return false;
	}

	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return true;
}


// ����������ָ��λ�õ�Ԫ������(��ָ��)���顿
Element* getElement(const DulLinkList& L, int i) {
	if (i <= 0) {
		cout << "����λ����Ч" << endl;
		return NULL;
	}
	if (L->next == L) {
		cout << "˫������Ϊ��" << endl;
		return NULL;
	}

	DulNode* p = L->next;
	while (--i && p->next != L) {// ʹpָ���i�����
		p = p->next;
	}
	if (i != 0) {
		cout << "����λ����Ч" << endl;
		return NULL;
	}
	return &(p->data);
}


// ���������ؼ��ֲ���Ԫ�ء��顿
Element* getElementForName(const DulLinkList& L, string name) {
	if (L->next == L) {
		cout << "˫������Ϊ��" << endl;
		return NULL;
	}

	DulNode* p = L->next;
	while (p != L) {
		if (p->data.name == name) {
			return &(p->data);
		}
		p = p->next;
	}
	cout << "���ҹؼ���Ԫ�ز�����" << endl;
	return NULL;
}


// ����������Ԫ�ص���Ϣ
string elementToString(const Element& element) {
	return "{name=" + element.name +
		", age=" + to_string(element.age) +
		", sex=" + element.sex + "}";
}


// ��������ӡ˫�������ȫ��Ԫ��
void printDulLinkList(const DulLinkList& L) {
	if (L->next == L) {
		cout << "˫������Ϊ��" << endl;
		return;
	}

	DulNode* p = L->next;
	int i = 1;
	while (p != L) {
		cout << "��" << i << "λ��" << elementToString(p->data) << endl;
		p = p->next;
		i++;
	}
}




int main() {

	// (1)���岢��ʼ��˫������
	DulLinkList L = NULL;
	initDulLinkList(L);
	printDulLinkList(L);// ˫������Ϊ��
	cout << "==============================" << endl;


	// (2)ͷ�巨/β�巨
	dulListTailAdd(L, Element{ "����", 18, "��" });
	dulListTailAdd(L, Element{ "����", 26, "Ů" });
	dulListTailAdd(L, Element{ "����", 37, "��" });
	dulListHeadAdd(L, Element{ "����", 31, "Ů" });
	dulListHeadAdd(L, Element{ "����", 55, "��" });
	printDulLinkList(L);
	cout << "==============================" << endl;
	//��1λ��{name=����, age=55, sex=��}
	//��2λ��{name=����, age=31, sex=Ů}
	//��3λ��{name=����, age=18, sex=��}
	//��4λ��{name=����, age=26, sex=Ů}
	//��5λ��{name=����, age=37, sex=��}


	// (3)��ָ��λ�ò���Ԫ�� 
	dulListInsert(L, 0, Element{ "С��", 7, "��" });// ����λ����Ч
	dulListInsert(L, 1, Element{ "С��", 9, "Ů" });
	dulListInsert(L, 5, Element{ "С��", 8, "��" });
	dulListInsert(L, 8, Element{ "С��", 6, "Ů" });
	dulListInsert(L, 10, Element{ "Сŵ", 8, "��" });// ����λ����Ч
	printDulLinkList(L);
	cout << "==============================" << endl;
	//��1λ��{ name = С��, age = 9, sex = Ů }
	//��2λ��{ name = ����, age = 55, sex = �� }
	//��3λ��{ name = ����, age = 31, sex = Ů }
	//��4λ��{ name = ����, age = 18, sex = �� }
	//��5λ��{ name = С��, age = 8, sex = �� }
	//��6λ��{ name = ����, age = 26, sex = Ů }
	//��7λ��{ name = ����, age = 37, sex = �� }
	//��8λ��{ name = С��, age = 6, sex = Ů }


	// (4)����ָ��λ�õ�Ԫ��
	getElement(L, 0);// ����λ����Ч
	cout << elementToString(*getElement(L, 1)) << endl;// {name=С��, age=9, sex=Ů}
	cout << elementToString(*getElement(L, 3)) << endl;// {name=����, age=31, sex=Ů}
	cout << elementToString(*getElement(L, 6)) << endl;// {name=����, age=26, sex=Ů}
	cout << elementToString(*getElement(L, 8)) << endl;// {name=С��, age=6, sex=Ů}
	getElement(L, 9);// ����λ����Ч
	cout << "==============================" << endl;


	// (5)����ָ���ؼ��ֵ�Ԫ��
	getElementForName(L, "�ϰ�");// ���ҹؼ���Ԫ�ز�����
	getElementForName(L, "��ţ");// ���ҹؼ���Ԫ�ز�����
	cout << elementToString(*getElementForName(L, "����")) << endl;// {name=����, age=18, sex=��}
	cout << elementToString(*getElementForName(L, "С��")) << endl;// {name=С��, age=9, sex=Ů}
	cout << elementToString(*getElementForName(L, "С��")) << endl;// {name=С��, age=6, sex=Ů}
	cout << "==============================" << endl;


	// (6)ɾ��ָ��λ�õ�Ԫ��
	Element e1, e2, e3, e4, e5;
	dulListDelete(L, 0, e1);// ɾ��λ����Ч
	dulListDelete(L, 1, e2);
	dulListDelete(L, 4, e3);
	dulListDelete(L, 6, e4);
	dulListDelete(L, 6, e5);// ɾ��λ����Ч
	printDulLinkList(L);
	cout << "==============================" << endl;
	cout << elementToString(e2) << endl;// {name=С��, age=9, sex=Ů}
	cout << elementToString(e3) << endl;// {name=С��, age=8, sex=��}
	cout << elementToString(e4) << endl;// {name=С��, age=6, sex=Ů}
	cout << "==============================" << endl;
	//��1λ��{ name = ����, age = 55, sex = �� }
	//��2λ��{ name = ����, age = 31, sex = Ů }
	//��3λ��{ name = ����, age = 18, sex = �� }
	//��4λ��{ name = ����, age = 26, sex = Ů }
	//��5λ��{ name = ����, age = 37, sex = �� }


	// (7)ɾ��ͷ/βԪ��
	Element e6, e7, e8, e9;
	dulListHeadDelete(L, e6);
	dulListTailDelete(L, e7);
	dulListHeadDelete(L, e8);
	dulListTailDelete(L, e9);
	printDulLinkList(L);// ��1λ��{name=����, age=18, sex=��}
	cout << "==============================" << endl;
	cout << elementToString(e6) << endl;// {name=����, age=55, sex=��}
	cout << elementToString(e7) << endl;// {name=����, age=37, sex=��}
	cout << elementToString(e8) << endl;// {name=����, age=31, sex=Ů}
	cout << elementToString(e9) << endl;// {name=����, age=26, sex=Ů}
	cout << "==============================" << endl;


	return 0;
}