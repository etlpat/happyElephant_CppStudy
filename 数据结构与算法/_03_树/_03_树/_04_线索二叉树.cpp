#include<iostream>
using namespace std;
#include<string>



// ����������
// 
// (0)����
//	��������������Ϊ����/����/��������������
//	��������о���������������
//	����������������������ǰ�������������ϵ�ǰ������������������ϵĺ��
// 
// 
//
// (1)����
//	����������n����㣬����2n�������Լ�n-1���ߡ����ԣ�����������n+1��������
//	���ǽ������������������յ�����ָ��ָ��ý���ǰ�������յ��Һ���ָ��ָ��ý��ĺ�̡�
//
//
// (2)��������������
//	�����tag��������
//		Ϊ������ָ���ǲ���������������Ҫ���ltag��rtag
//		��ltag/rtag==0�����ʾָ��ָ���ӣ���ltag/rtag==1�����ʾ������
//
//
//
//



//struct Element {
//	char key;
//};
//
//
//typedef struct TNode {
//	Element data;
//	TNode* lchild;
//	TNode* rchild;
//	int ltag = 0;// 0��ʾ��������1��ʾ������
//	int rtag = 0;
//}*BiTree;
//
//
//
//// ������������������������ȫ�������У�
//string createBiTree(BiTree& T, string str) {
//	if (str[0] == '#') {
//		T = NULL;
//		return str.substr(1, str.length() - 1);
//	}
//
//	T = new TNode();
//	T->data.key = str[0];
//	str = createBiTree(T->lchild, str.substr(1, str.length() - 1));
//	str = createBiTree(T->rchild, str);
//	
//	// Ϊ������ǩ��ֵ������/�Һ���ΪNULL����֮���������������tag��Ϊ1
//	if (!T->lchild) { T->ltag = 1; }
//	else { T->ltag = 0; }
//	if (!T->rchild) { T->rtag = 1; }
//	else { T->rtag = 0; }
//
//	return str;
//}
//
//
//
//// �������������������������ӡ��������
//void inOrderTraverse(BiTree& T, int n = 0) {
//	if (T->ltag == 0) {
//		inOrderTraverse(T->lchild, 1);
//	}
//	cout << T->data.key;
//	if (T->rtag == 0) {
//		inOrderTraverse(T->rchild, 1);
//	}
//	if (n == 0) cout << endl;// ��������㺯�������ӡ����
//}
//
//
//
//// ������������(����)������
//TNode* pre = NULL;// ������ָ��ǰ����ȫ�ֱ�����
//void inThreading(BiTree& T, int start = 1) {
//	if (start == 1) {// ��������㺯������ǰ��ָ����ΪNULL
//		pre = NULL;
//	}
//	// 1.����������
//	if (T->ltag == 0) {// ע�⣺������ʱ�������������ж�����������tag==0��������child==NULL(����������󣬻�ָ��ǰ��/��̣���ΪNULL��������ѭ��)
//		inThreading(T->lchild, 0);
//	}
//
//	// 2.�������ڵ�
//	// (1)Ϊ��ǰ����ǰ������������
//	else if (T->ltag == 1) {// ����ǰ���ltag==1����������������ָ��ǰ����㣩
//		T->lchild = pre;
//	}
//	if (pre && pre->rtag == 1) {// ��ǰ�����rtag==1�������Һ�����������ָ��ǰ��㣩
//		pre->rchild = T;
//	}
//	// (2)��ǰ�������Ϊ��ǰ���
//	pre = T;
//	
//	// 3.��������������̽�㣺�������Ͻ��/��ǰС�������ĸ��ڵ㣩
//	if (T->rtag == 0) {
//		inThreading(T->rchild, 0);
//	}
//}
//
//
//
//// ������Ѱ����������������ĳ���ĺ�̽��
//TNode* findSuccessorNode(TNode* p) {
//	if (p->rtag == 1) {// ��rtag==1�����Һ�����������ָ���̽��
//		return p->rchild;
//	}
//	else {// ��rtag==0����ýڵ���������������½ǵĽ��������̽�㣨ԭ������ң�
//		TNode* tmp = p->rchild;
//		while (tmp->ltag == 0) {
//			tmp = tmp->lchild;
//		}
//		return tmp;
//	}
//}
//
//
//
//// ������������������ȡ���������������������������
//void printInOrderTraverse(BiTree& T) {
//	TNode* p = T;
//	while (p->ltag == 0) {// ��ȡ�����׸����
//		p = p->lchild;
//	}
//	while (p) {
//		cout << p->data.key;
//		p = findSuccessorNode(p);
//	}
//	cout << endl;
//}
//
//
//
// // ��������ӡ����������
//void printBiTree(const BiTree& T, string str = "", int num = 0) {
//	if (num == 1) {
//		cout << "#" << endl;
//		return;
//	}
//	// ��ӡ����
//	cout << T->data.key << "��ltag=" << T->ltag;
//	if (T->ltag == 1) {
//		cout << ",ǰ��:";
//		if (T->lchild)
//			cout << T->lchild->data.key;
//		else
//			cout << "NULL";
//	}
//	cout << " | rtag=" << T->rtag;
//	if (T->rtag == 1) {
//		cout << ",���:";
//		if (T->rchild)
//			cout << T->rchild->data.key;
//		else
//			cout << "NULL";
//	}
//	cout << "��" << endl;
//	// ��ӡ��ʽ
//	cout << str << "����";
//	if (T->rtag == 0) {
//		printBiTree(T->rchild, str + "�� ");
//	}
//	else {
//		printBiTree(T->rchild, str + "�� ", 1);
//	}
//	cout << str << "����";
//	if (T->ltag == 0) {
//		printBiTree(T->lchild, str + "  ");
//	}
//	else {
//		printBiTree(T->lchild, str + "  ", 1);
//	}
//}
//
//
//
//
//int main() {
//	// 1.����������
//	string str = "ABDH###E#I##CFJ###G##";
//	BiTree T = NULL;
//	createBiTree(T, str);
//	printBiTree(T);
//	
//
//	// 2.����������������
//	cout << endl << endl << "��������Ķ�������" << endl;
//	inThreading(T);
//	printBiTree(T);
//
//
//	// 3.�ݹ��������������
//	cout << endl << endl << "�������У�" << endl;
//	inOrderTraverse(T);// HDBEIAJFCG
//
//	// 4.ͨ�������������������
//	printInOrderTraverse(T);// HDBEIAJFCG
//
//
//	return 0;
//}
