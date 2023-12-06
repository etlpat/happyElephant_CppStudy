#include "_05_ForestLinkedList.h"


// ��������
//
//
// (1)��������
//	1.����Ȩ�����Ȩֵ�Ĵ�С���Ƕ�ʵ���ĳЩ���Ե���ֵ������������������ʾ��Ҫ�Ե�
//	2.·�����ȣ����ڵ��ı���
//	3.���Ĵ�Ȩ·�����ȣ����������ýڵ��·������ * �ý���Ȩֵ
//	4.���Ĵ�Ȩ·������(WPL)���������С�Ҷ�ӽڵ㡿�Ĵ�Ȩ·������֮��
//	5.������������Ȩ·������(WPL)��С�Ķ�������Ҳ�����Ŷ�����
//
//
// (2)��ι������������
//	���裺������n����Ȩ�Ľ�㣩
//		1.����n�����ֱ���Ϊn�ɽ���1�����Ķ�����������ɭ��F
//		2.����һ���½ڵ㣬��F��ѡȡ���Ž��Ȩֵ��С������Ϊ�½�������������
//		  �����½ڵ��Ȩֵ��Ϊ���������ϸ��ڵ��Ȩֵ֮��
//		3.��F��ɾ���ղ�ѡ������������ͬʱ���µĵ���������F��
//		4.�ظ�����2��3��ֱ��F��ֻʣ��һ����Ϊֹ
//
//
// (3)��������������
//	1.ÿ����ʼ��㣬���ն����ΪҶ�ڵ㣬��ȨֵԽС�Ľ�㵽���ڵ��·������Խ��
//	2.����n����ʼ��㣬����������ܽ����Ϊ2n-1
//	3.���������в�����(��)��Ϊ1�Ľ�� 
//	4.����������Ψһ������ÿ������������WPL(���Ĵ�Ȩ·������)��Ȼ��ͬ������
// 
// 
// 
// (4)����������
//	�̶����ȱ��룺ÿ���ַ��õȳ�������λ��ʾ
//	�ɱ䳤�ȱ��룺����Բ�ͬ�ַ��ò��ȳ��Ķ�����λ��ʾ
//	ǰ׺���룺û��һ����������һ�������ǰ׺������A=1��B=10����AΪB��ǰ׺��
//	���������룺�ַ����е�ÿһ���ַ���Ϊһ��Ҷ�ӽڵ㣬�ַ����ֵ�Ƶ����Ϊ����Ȩֵ�������������
//				�涨���ڵ�����Ϊ0������Ϊ1���Ӹ��ڵ㿪ʼ��Ҷ�ӽ�㣬��õĶ����Ʊ�����ǹ���������





//// ���½ṹ��������Ѽ���ͷ�ļ�
//struct Element {
//	char key;
//	double value;// ����Ȩֵ
//};
//
//typedef struct TNode {
//	Element data;
//	TNode* leftChild = NULL;
//	TNode* rightChild = NULL;
//}*HuffmanTree;


// ��������������Ԫ�����鰴��Ȩֵ��������
bool bubbleSort(Element* arr, int sz) {
	Element tmp;
	bool flag = true;
	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz - i - 1; j++) {
			if (arr[j].value > arr[j + 1].value) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = false;
			}
		}
		if (flag) {
			break;
		}
	}
	return true;
}



// ������������������
bool createHuffmanTree(HuffmanTree& T, Element* arr, int sz) {
	if (sz <= 0) {
		T = NULL;
		return false;
	}
	
	// ��Ȩֵ������������
	bubbleSort(arr, sz);	

	// �����������Ԫ�أ�����Ϊֻ��һ�����Ķ�������ȫ������ɭ��������
	ForestLinkdeList L;
	initList(L);
	addAll(L, arr, sz);

	// ��ɭ���ж���һ��������ȡ�����ڵ�ֵ��С�����������ϳ�һ�������ٰ���˳����뵽ɭ����
	TNode* lchild, * rchild, * parent;
	while (!isOnlyOne(L)) {
		removeHead(L, lchild);
		removeHead(L, rchild);
		parent = new TNode();// ��Ȩֵ��С�����������ϲ�Ϊһ��������Ȩֵ֮�ͼ�����ڵ�
		parent->data.key = '*';
		parent->data.value = lchild->data.value + rchild->data.value;
		parent->leftChild = lchild;
		parent->rightChild = rchild;
		insertByOrder(L, parent);// ���ϲ������������Ȩֵ˳�����²��뵽ɭ��������
	}

	// ���յĹ���������ɭ����Ψһ��һ����
	T = L->next->tree;
	destroy(L);
	return true;
}


// ��������ӡ��������
void printHuffmanTree(const HuffmanTree& T, string str = "") {
	if (T->data.key != '*') {
		cout << T->data.value << ", key:" << T->data.key << endl;
	}
	else {
		cout << T->data.value << endl;
	}

	if (T->rightChild) {
		cout << str << "����";
		printHuffmanTree(T->rightChild, str + "�� ");
	}
	if (T->leftChild) {
		cout << str << "����";
		printHuffmanTree(T->leftChild, str + "  ");
	}
}



// ����������ṹ��
struct HuffmanCoding {
	char key;// Ӣ����ĸ
	string coding;// ��Ӧ�ı���
};

// �������ݹ������������ȡҶ�ӽ��Ĺ��������루�涨������Ϊ0��������Ϊ1��
string getHuffmanCodingRecursion(const HuffmanTree& T, HuffmanCoding*& arr, int& index, string str = "") {
	if (!T->leftChild && !T->rightChild) {// ����Ҷ�ӽ��
		arr[index].key = T->data.key;// ��Ҷ�ӽ�����ĸ�͹������������������
		arr[index].coding = str;
		index++;
		return "";
	}
	if (T->leftChild) {
		getHuffmanCodingRecursion(T->leftChild, arr, index, str + "0");
	}
	if (T->rightChild) {
		getHuffmanCodingRecursion(T->rightChild, arr, index, str + "1");
	}
	return "";
}

// ��������ȡ���������и�Ҷ�ӽ���Ӧ�Ĺ���������
HuffmanCoding* getHuffmanCoding(const HuffmanTree& T, int sz) {
	// 1.��ȡ��������������
	HuffmanCoding* arr = new HuffmanCoding[sz];
	int index = 0;
	getHuffmanCodingRecursion(T, arr, index);
	// 2.��������
	HuffmanCoding tmp;
	bool flag = true;
	for (int i = 0; i < sz - 1; i++) {
		for (int j = 0; j < sz - i - 1; j++) {
			if (arr[j].key > arr[j + 1].key) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = false;
			}
		}
		if (flag) {
			break;
		}
	}
	return arr;
}





int main() {

	// ��1����������
	// ��1��������������
	HuffmanTree T1;
	Element arr1[] = { {'A', 5},{'B', 25},{'C', 40},{'D', 30},{'E', 10} };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	createHuffmanTree(T1, arr1, sz1);// ������������
	printHuffmanTree(T1);	
	//  110
	//	����70
	//	�� ����40
	//	�� �� ����25, key:B
	//	�� �� ����15
	//	�� ��   ����10, key : E
	//	�� ��   ����5, key : A
	//	�� ����30, key : D
	//	����40, key : C
	cout << "=================" << endl;

	// ��2����ӡ�����Ĺ���������
	HuffmanCoding* huffmanCoding1 = getHuffmanCoding(T1, sz1);// ��ȡ����������
	for (int i = 0; i < sz1; i++) {
		cout << huffmanCoding1[i].key << ":" << huffmanCoding1[i].coding << endl;
	}
	//	A:1100
	//	B : 111
	//	C : 0
	//	D : 10
	//	E : 1101
	cout << "=================\n\n\n" << endl;




	// ��2����������ȡ��Ӣ����ĸ�Ĺ���������
	// ��1��������������
	cout << "=======================================" << endl;
	HuffmanTree T2;
	Element arr2[] = { {'A', 8.19},{'B', 1.47},{'C', 3.83},{'D', 3.91},{'E', 12.25},
		{'F', 2.26},{'G', 1.71},{'H', 4.57},{'I', 7.10},{'J', 0.14},{'K', 0.41},{'L', 3.77},
		{'M', 3.34},{'N', 7.06},{'O', 7.26},{'P', 2.89},{'Q', 0.09},{'R', 6.85},{'S', 6.36},
		{'T', 9.41},{'U', 2.58},{'V', 1.09},{'W', 1.59},{'X', 0.21},{'Y', 1.58},{'Z', 0.08} };// ���Ǹ���Ӣ����ĸ���ճ��е�ʹ��Ƶ��
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	createHuffmanTree(T2, arr2, sz2);
	printHuffmanTree(T2);
	cout << "=======================================" << endl;

	// ��2����ȡ����������
	HuffmanCoding* huffmanCoding2 = getHuffmanCoding(T2, sz2);
	for (int i = 0; i < sz2; i++) {
		cout << huffmanCoding2[i].key << ":" << huffmanCoding2[i].coding << endl;
	}


	return 0;
}