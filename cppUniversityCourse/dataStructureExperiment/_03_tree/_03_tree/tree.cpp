#include "LinkStack.h"


// 数据元素
struct Element {
	char key;
};


// 树的结点
typedef struct TreeNode {
	Element data;
	TreeNode* leftChild = NULL;
	TreeNode* rightChild = NULL;
}*BiTree;// 用根结点的指针表示二叉树



//方法：根据完全先序序列创建二叉树
//注意：普通先序序列(ABDHKECFIGJ)不能确定一个二叉树，
//		但是完全先序序列(ABDH#K###E##CFI###G#J##)可以确定一个唯一的二叉树，其中#表示子树为空
int createBiTree(BiTree& T, const string& str, int index = 0) {
	if (str[index] == '#') {// 完全先序序列中的'#'，代表子树为空
		T = NULL;
		return index + 1;// 每次读取完一个字符（确定了一个结点），index往后移一位
	}

	T = new TreeNode;
	T->data.key = str[index];
	index++;// 每次读取完一个字符（确定了一个结点），index往后移一位

	index = createBiTree(T->leftChild, str, index);
	index = createBiTree(T->rightChild, str, index);
	return index;
}


// 方法：先序遍历二叉树
string preOrderTraverse(const BiTree& T) {
	if (!T) {// 递归结束条件：树为空树
		return "";
	}
	string str = "";
	str += T->data.key;
	str += preOrderTraverse(T->leftChild);
	str += preOrderTraverse(T->rightChild);
	return str;
}


// 方法：计算叶子数目(递归)
int getLeafNumberRecursion(const BiTree& T) {
	if (!T) {// 若根为空
		return 0;
	}
	else if (!(T->leftChild) && !(T->rightChild)) {// 若是叶节点
		return 1;
	}

	int num = 0;
	num += getLeafNumberRecursion(T->leftChild);
	num += getLeafNumberRecursion(T->rightChild);
	return num;
}


// 方法：计算叶子结点数目(非递归)(栈)
int getLeafNumber(const BiTree& T) {
	if (!T) {
		return 0;
	}
	Stack S;// 创建栈
	initStack(S);
	push(S, T);// 根节点入栈

	int num = 0;
	TreeNode* tp;
	while (!isEmpty(S)) {
		pop(S, tp);// 元素出栈
		if (!(tp->leftChild) && !(tp->rightChild)) {// 若是叶节点，num++
			num++;
		}
		else {
			if (tp->rightChild) {// 右孩子入栈
				push(S, tp->rightChild);
			}
			if (tp->leftChild) {// 左孩子入栈
				push(S, tp->leftChild);
			}
		}
	}
	return num;
}


// 方法：获取先序序列中第num个结点(递归)
int getNodeByPreOrderRecursion(const BiTree& T, int num, TreeNode& node) {
	if (!T || !num) {// 递归结束条件：树为空树或num为0
		return num;
	}
	if (num == 1) {
		node = *T;
	}
	num--;
	if (!num) {// 若num是0，直接返回
		return num;
	}
	num = getNodeByPreOrderRecursion(T->leftChild, num, node);
	if (!num) {// 若num是0，直接返回
		return num;
	}
	num = getNodeByPreOrderRecursion(T->rightChild, num, node);
	return num;
}


// 方法：获取先序序列中第num个结点(非递归)(栈)
bool getNodeByPreOrder(const BiTree& T, int num, TreeNode& node) {
	if (!T) {
		return false;
	}
	Stack S;// 创建栈
	initStack(S);
	push(S, T);// 根节点入栈

	TreeNode* tp;
	while (!isEmpty(S)) {
		pop(S, tp);// 元素出栈
		if (num == 1) {
			node = *tp;
			return true;
		}
		num--;// 每出栈一次，num--
		if (tp->rightChild) {// 右孩子入栈
			push(S, tp->rightChild);
		}
		if (tp->leftChild) {// 左孩子入栈
			push(S, tp->leftChild);
		}
	}
	return false;
}


// 方法：打印二叉树
void printBiTree(const BiTree& T, string str = "") {
	if (!T) {
		cout << "#" << endl;
		return;
	}
	cout << T->data.key << endl;
	cout << str << "├─";
	printBiTree(T->rightChild, str + "│ ");
	cout << str << "└─";
	printBiTree(T->leftChild, str + "  ");
}





int main() {
	BiTree T;
	createBiTree(T, "ABD##EH###CF#I##G##");
	printBiTree(T);
	cout << endl << "先序序列：" << preOrderTraverse(T) << endl << endl;


	// 获取叶节点格式
	cout << "递归 - 叶子数目为：" << getLeafNumberRecursion(T) << endl;
	cout << "非递归 - 叶子数目为：" << getLeafNumber(T) << endl << endl;


	// 获取第n个结点
	int num = 5;
	TreeNode node1, node2;
	getNodeByPreOrderRecursion(T, num, node1);
	getNodeByPreOrder(T, num, node2);
	cout << "递归 - 第" << num << "个结点为：" << node1.data.key << endl;
	cout << "非递归 - 第" << num << "个结点为：" << node2.data.key << endl;
	
	num = 8;
	getNodeByPreOrderRecursion(T, num, node1);
	getNodeByPreOrder(T, num, node2);
	cout << "递归 - 第" << num << "个结点为：" << node1.data.key << endl;
	cout << "非递归 - 第" << num << "个结点为：" << node2.data.key << endl;
	return 0;
}