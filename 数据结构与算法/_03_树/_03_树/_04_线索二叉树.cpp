#include<iostream>
using namespace std;
#include<string>



// 线索二叉树
// 
// (0)分类
//	线索二叉树，分为先序/中序/后序线索二叉树
//	这里，我们研究中序线索二叉树
//	中序线索二叉树，即结点的前驱是中序序列上的前驱，后继是中序序列上的后继
// 
// 
//
// (1)概念
//	若二叉树有n个结点，则共有2n个链域，以及n-1条边。所以，二叉树会有n+1个空链域
//	我们将二叉树线索化，将空的左孩子指针指向该结点的前驱，将空的右孩子指针指向该结点的后继。
//
//
// (2)二叉树的线索化
//	①添加tag区分线索
//		为了区分指针是不是线索，我们需要添加ltag、rtag
//		若ltag/rtag==0，则表示指针指向孩子；若ltag/rtag==1，则表示是线索
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
//	int ltag = 0;// 0表示是子树，1表示是线索
//	int rtag = 0;
//}*BiTree;
//
//
//
//// 方法：创建二叉树（根据完全先序序列）
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
//	// 为线索标签赋值，若左/右孩子为NULL，则之后对其线索化，将tag赋为1
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
//// 方法：中序遍历二叉树，并打印中序序列
//void inOrderTraverse(BiTree& T, int n = 0) {
//	if (T->ltag == 0) {
//		inOrderTraverse(T->lchild, 1);
//	}
//	cout << T->data.key;
//	if (T->rtag == 0) {
//		inOrderTraverse(T->rchild, 1);
//	}
//	if (n == 0) cout << endl;// 若是最外层函数，则打印换行
//}
//
//
//
//// 方法：二叉树(中序)线索化
//TNode* pre = NULL;// 【设置指向前驱的全局变量】
//void inThreading(BiTree& T, int start = 1) {
//	if (start == 1) {// 若是最外层函数，将前驱指针设为NULL
//		pre = NULL;
//	}
//	// 1.遍历左子树
//	if (T->ltag == 0) {// 注意：线索化时，遍历子树的判断条件必须是tag==0，不能用child==NULL(结点线索化后，会指向前驱/后继，不为NULL，可能死循环)
//		inThreading(T->lchild, 0);
//	}
//
//	// 2.操作根节点
//	// (1)为当前结点和前驱结点添加线索
//	else if (T->ltag == 1) {// 若当前结点ltag==1，将左孩子线索化（指向前驱结点）
//		T->lchild = pre;
//	}
//	if (pre && pre->rtag == 1) {// 若前驱结点rtag==1，将其右孩子线索化（指向当前结点）
//		pre->rchild = T;
//	}
//	// (2)将前驱结点设为当前结点
//	pre = T;
//	
//	// 3.遍历右子树（后继结点：右子树上结点/当前小左子树的根节点）
//	if (T->rtag == 0) {
//		inThreading(T->rchild, 0);
//	}
//}
//
//
//
//// 方法：寻找中序线索二叉树某结点的后继结点
//TNode* findSuccessorNode(TNode* p) {
//	if (p->rtag == 1) {// 若rtag==1，则右孩子是线索，指向后继结点
//		return p->rchild;
//	}
//	else {// 若rtag==0，则该节点的右子树的最左下角的结点就是其后继结点（原理：左根右）
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
//// 方法：根据线索，获取中序线索二叉树的中序遍历序列
//void printInOrderTraverse(BiTree& T) {
//	TNode* p = T;
//	while (p->ltag == 0) {// 获取序列首个结点
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
// // 方法：打印线索二叉树
//void printBiTree(const BiTree& T, string str = "", int num = 0) {
//	if (num == 1) {
//		cout << "#" << endl;
//		return;
//	}
//	// 打印数据
//	cout << T->data.key << "（ltag=" << T->ltag;
//	if (T->ltag == 1) {
//		cout << ",前驱:";
//		if (T->lchild)
//			cout << T->lchild->data.key;
//		else
//			cout << "NULL";
//	}
//	cout << " | rtag=" << T->rtag;
//	if (T->rtag == 1) {
//		cout << ",后继:";
//		if (T->rchild)
//			cout << T->rchild->data.key;
//		else
//			cout << "NULL";
//	}
//	cout << "）" << endl;
//	// 打印格式
//	cout << str << "├─";
//	if (T->rtag == 0) {
//		printBiTree(T->rchild, str + "│ ");
//	}
//	else {
//		printBiTree(T->rchild, str + "│ ", 1);
//	}
//	cout << str << "└─";
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
//	// 1.创建二叉树
//	string str = "ABDH###E#I##CFJ###G##";
//	BiTree T = NULL;
//	createBiTree(T, str);
//	printBiTree(T);
//	
//
//	// 2.中序线索化二叉树
//	cout << endl << endl << "线索化后的二叉树：" << endl;
//	inThreading(T);
//	printBiTree(T);
//
//
//	// 3.递归中序遍历二叉树
//	cout << endl << endl << "中序序列：" << endl;
//	inOrderTraverse(T);// HDBEIAJFCG
//
//	// 4.通过线索中序遍历二叉树
//	printInOrderTraverse(T);// HDBEIAJFCG
//
//
//	return 0;
//}
