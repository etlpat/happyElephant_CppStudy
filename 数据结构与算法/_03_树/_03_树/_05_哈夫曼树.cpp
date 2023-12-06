#include "_05_ForestLinkedList.h"


// 哈夫曼树
//
//
// (1)基础概念
//	1.结点的权：结点权值的大小，是对实体的某些属性的数值化描述，可以用来表示重要性等
//	2.路径长度：两节点间的边数
//	3.结点的带权路径长度：从树根到该节点的路径长度 * 该结点的权值
//	4.树的带权路径长度(WPL)：树中所有【叶子节点】的带权路径长度之和
//	5.哈夫曼树：带权路径长度(WPL)最小的二叉树，也叫最优二叉树
//
//
// (2)如何构造哈夫曼树？
//	步骤：（给定n个带权的结点）
//		1.将这n个结点分别作为n可仅有1个结点的二叉树，构成森林F
//		2.构造一个新节点，从F中选取两颗结点权值最小的树作为新结点的左右子树，
//		  并将新节点的权值置为左右子树上根节点的权值之和
//		3.从F中删除刚才选出的两棵树，同时将新的到的树加入F中
//		4.重复步骤2、3，直至F中只剩下一棵树为止
//
//
// (3)哈夫曼树的性质
//	1.每个初始结点，最终都会成为叶节点，且权值越小的结点到根节点的路径长度越大
//	2.若有n个初始结点，则哈夫曼树总结点数为2n-1
//	3.哈夫曼树中不存在(出)度为1的结点 
//	4.哈夫曼树不唯一，但是每个哈夫曼树的WPL(树的带权路径长度)必然相同且最优
// 
// 
// 
// (4)哈夫曼编码
//	固定长度编码：每个字符用等长二进制位表示
//	可变长度编码：允许对不同字符用不等长的二进制位表示
//	前缀编码：没有一个编码是另一个编码的前缀（若：A=1，B=10，则A为B的前缀）
//	哈夫曼编码：字符集中的每一个字符作为一个叶子节点，字符出现的频度作为结点的权值，构造哈夫曼树
//				规定根节点向左为0，向右为1。从根节点开始到叶子结点，获得的二进制编码就是哈夫曼编码





//// 如下结构体的声明已加入头文件
//struct Element {
//	char key;
//	double value;// 结点的权值
//};
//
//typedef struct TNode {
//	Element data;
//	TNode* leftChild = NULL;
//	TNode* rightChild = NULL;
//}*HuffmanTree;


// 方法：将给定的元素数组按照权值升序排序
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



// 方法：创建哈夫曼树
bool createHuffmanTree(HuffmanTree& T, Element* arr, int sz) {
	if (sz <= 0) {
		T = NULL;
		return false;
	}
	
	// 按权值升序排序数组
	bubbleSort(arr, sz);	

	// 将升序数组的元素，构造为只有一个结点的二叉树，全部存入森林链表中
	ForestLinkdeList L;
	initList(L);
	addAll(L, arr, sz);

	// 若森林中多于一棵树，则取出根节点值最小的两棵树，合成一棵树，再按照顺序插入到森林中
	TNode* lchild, * rchild, * parent;
	while (!isOnlyOne(L)) {
		removeHead(L, lchild);
		removeHead(L, rchild);
		parent = new TNode();// 将权值最小的两棵子树合并为一棵树，将权值之和加入根节点
		parent->data.key = '*';
		parent->data.value = lchild->data.value + rchild->data.value;
		parent->leftChild = lchild;
		parent->rightChild = rchild;
		insertByOrder(L, parent);// 将合并后的树，按照权值顺序重新插入到森林链表中
	}

	// 最终的哈夫曼树是森林中唯一的一棵树
	T = L->next->tree;
	destroy(L);
	return true;
}


// 方法：打印哈夫曼树
void printHuffmanTree(const HuffmanTree& T, string str = "") {
	if (T->data.key != '*') {
		cout << T->data.value << ", key:" << T->data.key << endl;
	}
	else {
		cout << T->data.value << endl;
	}

	if (T->rightChild) {
		cout << str << "├─";
		printHuffmanTree(T->rightChild, str + "│ ");
	}
	if (T->leftChild) {
		cout << str << "└─";
		printHuffmanTree(T->leftChild, str + "  ");
	}
}



// 哈夫曼编码结构体
struct HuffmanCoding {
	char key;// 英文字母
	string coding;// 对应的编码
};

// 方法：递归哈夫曼树，获取叶子结点的哈夫曼编码（规定左子树为0，右子树为1）
string getHuffmanCodingRecursion(const HuffmanTree& T, HuffmanCoding*& arr, int& index, string str = "") {
	if (!T->leftChild && !T->rightChild) {// 若是叶子结点
		arr[index].key = T->data.key;// 将叶子结点的字母和哈夫曼编码加入数组中
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

// 方法：获取哈夫曼树中各叶子结点对应的哈夫曼编码
HuffmanCoding* getHuffmanCoding(const HuffmanTree& T, int sz) {
	// 1.获取哈夫曼编码数组
	HuffmanCoding* arr = new HuffmanCoding[sz];
	int index = 0;
	getHuffmanCodingRecursion(T, arr, index);
	// 2.数组排序
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

	// 【1】哈夫曼树
	// （1）创建哈夫曼树
	HuffmanTree T1;
	Element arr1[] = { {'A', 5},{'B', 25},{'C', 40},{'D', 30},{'E', 10} };
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	createHuffmanTree(T1, arr1, sz1);// 创建哈夫曼树
	printHuffmanTree(T1);	
	//  110
	//	├─70
	//	│ ├─40
	//	│ │ ├─25, key:B
	//	│ │ └─15
	//	│ │   ├─10, key : E
	//	│ │   └─5, key : A
	//	│ └─30, key : D
	//	└─40, key : C
	cout << "=================" << endl;

	// （2）打印该树的哈夫曼编码
	HuffmanCoding* huffmanCoding1 = getHuffmanCoding(T1, sz1);// 获取哈夫曼编码
	for (int i = 0; i < sz1; i++) {
		cout << huffmanCoding1[i].key << ":" << huffmanCoding1[i].coding << endl;
	}
	//	A:1100
	//	B : 111
	//	C : 0
	//	D : 10
	//	E : 1101
	cout << "=================\n\n\n" << endl;




	// 【2】案例：获取各英文字母的哈夫曼编码
	// （1）创建哈夫曼树
	cout << "=======================================" << endl;
	HuffmanTree T2;
	Element arr2[] = { {'A', 8.19},{'B', 1.47},{'C', 3.83},{'D', 3.91},{'E', 12.25},
		{'F', 2.26},{'G', 1.71},{'H', 4.57},{'I', 7.10},{'J', 0.14},{'K', 0.41},{'L', 3.77},
		{'M', 3.34},{'N', 7.06},{'O', 7.26},{'P', 2.89},{'Q', 0.09},{'R', 6.85},{'S', 6.36},
		{'T', 9.41},{'U', 2.58},{'V', 1.09},{'W', 1.59},{'X', 0.21},{'Y', 1.58},{'Z', 0.08} };// 这是各个英文字母在日常中的使用频率
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);
	createHuffmanTree(T2, arr2, sz2);
	printHuffmanTree(T2);
	cout << "=======================================" << endl;

	// （2）获取哈夫曼编码
	HuffmanCoding* huffmanCoding2 = getHuffmanCoding(T2, sz2);
	for (int i = 0; i < sz2; i++) {
		cout << huffmanCoding2[i].key << ":" << huffmanCoding2[i].coding << endl;
	}


	return 0;
}