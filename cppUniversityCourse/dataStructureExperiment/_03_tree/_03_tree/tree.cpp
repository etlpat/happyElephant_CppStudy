#include "LinkStack.h"


// ����Ԫ��
struct Element {
	char key;
};


// ���Ľ��
typedef struct TreeNode {
	Element data;
	TreeNode* leftChild = NULL;
	TreeNode* rightChild = NULL;
}*BiTree;// �ø�����ָ���ʾ������



//������������ȫ�������д���������
//ע�⣺��ͨ��������(ABDHKECFIGJ)����ȷ��һ����������
//		������ȫ��������(ABDH#K###E##CFI###G#J##)����ȷ��һ��Ψһ�Ķ�����������#��ʾ����Ϊ��
int createBiTree(BiTree& T, const string& str, int index = 0) {
	if (str[index] == '#') {// ��ȫ���������е�'#'����������Ϊ��
		T = NULL;
		return index + 1;// ÿ�ζ�ȡ��һ���ַ���ȷ����һ����㣩��index������һλ
	}

	T = new TreeNode;
	T->data.key = str[index];
	index++;// ÿ�ζ�ȡ��һ���ַ���ȷ����һ����㣩��index������һλ

	index = createBiTree(T->leftChild, str, index);
	index = createBiTree(T->rightChild, str, index);
	return index;
}


// �������������������
string preOrderTraverse(const BiTree& T) {
	if (!T) {// �ݹ������������Ϊ����
		return "";
	}
	string str = "";
	str += T->data.key;
	str += preOrderTraverse(T->leftChild);
	str += preOrderTraverse(T->rightChild);
	return str;
}


// ����������Ҷ����Ŀ(�ݹ�)
int getLeafNumberRecursion(const BiTree& T) {
	if (!T) {// ����Ϊ��
		return 0;
	}
	else if (!(T->leftChild) && !(T->rightChild)) {// ����Ҷ�ڵ�
		return 1;
	}

	int num = 0;
	num += getLeafNumberRecursion(T->leftChild);
	num += getLeafNumberRecursion(T->rightChild);
	return num;
}


// ����������Ҷ�ӽ����Ŀ(�ǵݹ�)(ջ)
int getLeafNumber(const BiTree& T) {
	if (!T) {
		return 0;
	}
	Stack S;// ����ջ
	initStack(S);
	push(S, T);// ���ڵ���ջ

	int num = 0;
	TreeNode* tp;
	while (!isEmpty(S)) {
		pop(S, tp);// Ԫ�س�ջ
		if (!(tp->leftChild) && !(tp->rightChild)) {// ����Ҷ�ڵ㣬num++
			num++;
		}
		else {
			if (tp->rightChild) {// �Һ�����ջ
				push(S, tp->rightChild);
			}
			if (tp->leftChild) {// ������ջ
				push(S, tp->leftChild);
			}
		}
	}
	return num;
}


// ��������ȡ���������е�num�����(�ݹ�)
int getNodeByPreOrderRecursion(const BiTree& T, int num, TreeNode& node) {
	if (!T || !num) {// �ݹ������������Ϊ������numΪ0
		return num;
	}
	if (num == 1) {
		node = *T;
	}
	num--;
	if (!num) {// ��num��0��ֱ�ӷ���
		return num;
	}
	num = getNodeByPreOrderRecursion(T->leftChild, num, node);
	if (!num) {// ��num��0��ֱ�ӷ���
		return num;
	}
	num = getNodeByPreOrderRecursion(T->rightChild, num, node);
	return num;
}


// ��������ȡ���������е�num�����(�ǵݹ�)(ջ)
bool getNodeByPreOrder(const BiTree& T, int num, TreeNode& node) {
	if (!T) {
		return false;
	}
	Stack S;// ����ջ
	initStack(S);
	push(S, T);// ���ڵ���ջ

	TreeNode* tp;
	while (!isEmpty(S)) {
		pop(S, tp);// Ԫ�س�ջ
		if (num == 1) {
			node = *tp;
			return true;
		}
		num--;// ÿ��ջһ�Σ�num--
		if (tp->rightChild) {// �Һ�����ջ
			push(S, tp->rightChild);
		}
		if (tp->leftChild) {// ������ջ
			push(S, tp->leftChild);
		}
	}
	return false;
}


// ��������ӡ������
void printBiTree(const BiTree& T, string str = "") {
	if (!T) {
		cout << "#" << endl;
		return;
	}
	cout << T->data.key << endl;
	cout << str << "����";
	printBiTree(T->rightChild, str + "�� ");
	cout << str << "����";
	printBiTree(T->leftChild, str + "  ");
}





int main() {
	BiTree T;
	createBiTree(T, "ABD##EH###CF#I##G##");
	printBiTree(T);
	cout << endl << "�������У�" << preOrderTraverse(T) << endl << endl;


	// ��ȡҶ�ڵ��ʽ
	cout << "�ݹ� - Ҷ����ĿΪ��" << getLeafNumberRecursion(T) << endl;
	cout << "�ǵݹ� - Ҷ����ĿΪ��" << getLeafNumber(T) << endl << endl;


	// ��ȡ��n�����
	int num = 5;
	TreeNode node1, node2;
	getNodeByPreOrderRecursion(T, num, node1);
	getNodeByPreOrder(T, num, node2);
	cout << "�ݹ� - ��" << num << "�����Ϊ��" << node1.data.key << endl;
	cout << "�ǵݹ� - ��" << num << "�����Ϊ��" << node2.data.key << endl;
	
	num = 8;
	getNodeByPreOrderRecursion(T, num, node1);
	getNodeByPreOrder(T, num, node2);
	cout << "�ݹ� - ��" << num << "�����Ϊ��" << node1.data.key << endl;
	cout << "�ǵݹ� - ��" << num << "�����Ϊ��" << node2.data.key << endl;
	return 0;
}