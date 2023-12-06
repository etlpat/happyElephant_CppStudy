//#include<iostream>
//using namespace std;
//#include<string>
//#include "_03_LinkQueue.h"



// 链式存储二叉树
//
// (1)二叉树结点
//	二叉树的结点：包含 数据元素、左孩子指针、右孩子指针
//	我们用【二叉树根节点的指针】来代表(操纵)整个二叉树
//
//
//
// (2)二叉树的遍历
//	1.先序遍历：根->左->右
//	2.中序遍历：左->根->右
//	3.后序遍历：左->右->根
//	4.层次遍历：从根节点->叶节点，从上到下逐层遍历，每层中从左到右访问
//	
//	注意：1.前三种遍历的先序、中序、后序，都是说的根节点的访问顺序。每种遍历都能确定唯一一串序列。
//			已知 (中序序列+先序序列) 或者 (中序序列+后序序列) 或者 (中序序列+层次序列)，都能唯一确定一颗二叉树
//			想要推导二叉树，必须要中序序列
// 
//		  2.层次遍历：即广度优先遍历，需要通过【队列】辅助实现
//			算法：先让根节点入队，之后根节点出队，左右孩子入队；左孩子出队，左孩子的左右子树入队；右孩子出队，右孩子的左右子树出队...
//			原理：由于队列先进先出的性质，可以保证结点出队次序是从浅到深，逐层出队的
//
//
// (3)二叉树的创建
//	我们需要根据已有的数据来创建二叉树
//	但是，一串普通的先序序列不能唯一确定一颗二叉树。因此，创建二叉树需要【完全先序序列】
//	【完全先序序列】如：ABDH#K###E##CFI###G#J##	（其中的'#'表示NULL）
//	
//	当然，完全中序序列、完全后续序列都可以用来创建二叉树






//// 数据元素
// struct Element {
//	 char key;
// };
//
//
//// 树的结点
// typedef struct TreeNode {
//	 Element data;
//	 TreeNode* leftChild = NULL;
//	 TreeNode* rightChild = NULL;
// }*BiTree;// 用根结点的指针表示二叉树
//
//
//
//
////方法：根据完全先序序列创建二叉树
////注意：普通先序序列(ABDHKECFIGJ)不能确定一个二叉树，
////		但是完全先序序列(ABDH#K###E##CFI###G#J##)可以确定一个唯一的二叉树，其中#表示子树为空
////
////int createBiTree(BiTree& T, const string& str, int index = 0) {
//	// if (str[index] == '#') {// 完全先序序列中的'#'，代表子树为空
//	//	 T = NULL;
//	//	 return index + 1;// 每次读取完一个字符（确定了一个结点），index往后移一位
//	// }
//
//	// T = new TreeNode;
//	// T->data.key = str[index];
//	// index++;// 每次读取完一个字符（确定了一个结点），index往后移一位
//
//	// index = createBiTree(T->leftChild, str, index);
//	// index = createBiTree(T->rightChild, str, index);
//	// return index;
// //}
//
// // 将上面的代码优化后，如下：
// string createBiTree(BiTree& T, string str) {
//	 if (str[0] == '#') {
//		 T = NULL;
//		 return str.substr(1, str.length() - 1);
//	 }
//
//	 T = new TreeNode();
//	 T->data.key = str[0];
//	 str = createBiTree(T->leftChild, str.substr(1, str.length() - 1));
//	 str = createBiTree(T->rightChild, str);
//	 return str;
// }
// 
//
//
//
// // 方法：先序遍历二叉树
// string preOrderTraverse(const BiTree& T) {
//	 if (!T) {// 递归结束条件：树为空树
//		 return "";
//	 }
//	 string str = "";
//	 str += T->data.key;
//	 str += preOrderTraverse(T->leftChild);
//	 str += preOrderTraverse(T->rightChild);
//	 return str;
// }
//
//
// // 方法：中序遍历二叉树
// string inOrderTraverse(const BiTree& T) {
//	 if (!T) {
//		 return "";
//	 }
//	 string str = "";
//	 str += inOrderTraverse(T->leftChild);
//	 str += T->data.key;
//	 str += inOrderTraverse(T->rightChild);
//	 return str;
//}
//
//
// // 方法：后序遍历二叉树
// string postOrderTraverse(const BiTree& T) {
//	 if (!T) {
//		 return "";
//	 }
//	 string str = "";
//	 str += postOrderTraverse(T->leftChild);
//	 str += postOrderTraverse(T->rightChild);
//	 str += T->data.key;
//	 return str;
// }
//
//
// // 方法：层次遍历二叉（利用队列实现）
// string levelOrderTraverse(const BiTree& T) {
//	 if (!T) {
//		 return "";
//	 }
//	 Queue treeNodeQueue;// 创建队列
//	 initQueue(treeNodeQueue);
//	 enQueue(treeNodeQueue, T);// 根节点入队
//
//	 TreeNode* tmp = NULL;
//	 string str = "";
//	 while (!isEmpty(treeNodeQueue)) {
//		 deQueue(treeNodeQueue, tmp);// 出队
//		 str += tmp->data.key;
//		 if (tmp->leftChild) {// 左孩子入队
//			 enQueue(treeNodeQueue, tmp->leftChild);
//		 }
//		 if (tmp->rightChild) {// 右孩子入队
//			 enQueue(treeNodeQueue, tmp->rightChild);
//		 }
//	 }
//	 destroyQueue(treeNodeQueue);// 销毁队列
//	 return str;
// }
// 
//
// //// 方法：打印二叉树
// //// 注意：深度depth这个参数可以删去，用str.length()代替即可（这里为了代码的可读性而保留该参数）
// //void printBiTree(const BiTree& T, int depth = 0, string str = "") {
//	// if (!T) {
//	//	 cout << "#" << endl;// 若树为空，打印"#"
//	//	 return;
//	// }
//
//	// // (1)打印根结点数据
//	// cout << T->data.key << endl;// 初始打印位置：深度为depth
//
//	// // (2)打印右子树
//	// for (int i = 0; i < depth; i++) {// 打印depth个深度的间隔
//	//	 if (str[i] == '1') {
//	//		 cout << "│ ";// 若上一行是"├─"，则本行对应位置打印"│ "
//	//	 }
//	//	 else {
//	//		 cout << "  ";// 若上一行是"└─"，则本行对应位置打印"  "
//	//	 }
//	// }
//	// cout << "├─";// 打印后深度为depth+1
//	// printBiTree(T->rightChild, depth + 1, str + "1");// 由于右子树前为"├─"，传参str + "1"，让下一行对应位置打印"│ "
//
//	// // (3)打印左子树
//	// for (int i = 0; i < depth; i++) {
//	//	 if (str[i] == '1') {
//	//		 cout << "│ ";
//	//	 }
//	//	 else {
//	//		 cout << "  ";
//	//	 }
//	// }
//	// cout << "└─";
//	// printBiTree(T->leftChild, depth + 1, str + "0");// 由于左子树前为"└─"，传参str + "0"，让下一行对应位置打印"  "
// //}
//
//
// // 方法：打印二叉树
// // 上面代码简化后，得到以下代码
// void printBiTree(const BiTree& T, string str = "") {
//	 if (!T) {
//		 cout << "#" << endl;
//		 return;
//	 }
//	 cout << T->data.key << endl;
//	 cout << str << "├─";
//	 printBiTree(T->rightChild, str + "│ ");
//	 cout << str << "└─";
//	 printBiTree(T->leftChild, str + "  ");
// }
//
//
//
//
//
// int main() {
//	 BiTree T;
//	 createBiTree(T, "ABDH#K###E##CFI###G#J##");
//	 printBiTree(T);
//	//	A
//	//	├─C
//	//	│  ├─G
//	//	│  │ ├─J
//	//	│  │ │ ├─#
//	//	│  │ │ └─#
//	//	│  │ └─#
//	//	│  └─F
//	//	│		├─#
//	//	│      └─I
//	//	│			├─#
//	//	│			└─#
//	//	└─B
//	//		├─E
//	//		│ ├─#
//	//		│ └─#
//	//		└─D
//	//			├─#
//	//			└─H
//	//				├─K
//	//				│ ├─#
// 	//				│ └─#
// 	//				└─#
//
//
//	 cout << "先序序列：" << preOrderTraverse(T) << endl;
//	 cout << "中序序列：" << inOrderTraverse(T) << endl;
//	 cout << "后序序列：" << postOrderTraverse(T) << endl;
//	 cout << "层次遍历：" << levelOrderTraverse(T) << endl;
//	//先序序列：ABDHKECFIGJ
//	//中序序列：HKDBEAIFCGJ
//	//后序序列：KHDEBIFJGCA
//	//层次遍历：ABCDEFGHIJK
//
//	 return 0;
// }