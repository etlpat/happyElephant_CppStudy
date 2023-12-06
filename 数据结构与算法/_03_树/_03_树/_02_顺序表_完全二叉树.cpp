//#include<iostream>
//using namespace std;
//#include<string>
//#define MAX_SIZE 1000


// 完全二叉树
//
// (1)概念
//	完全二叉树：除了最后一层外，其它层的结点都是满的，而且最后一层的结点都是靠左边排列的
//	
// (2)完全二叉树的实现
//	对完全二叉树从左到右，从上到下，以根节点为1开始标号
//	我们用数组下标，来存放对应编号的结点
//	
// (3)基本操作
//	1.i的左孩子：2 * i
//	2.i的右孩子：2 * i + 1
//	3.i的父节点：[i / 2]
//	4.i所在的层次：[log2 i] + 1
//	5.i号结点是否有左孩子?：2 * i <= n ?
//	6.i号结点是否有右孩子?：2 * i + 1 <= n ?
//	7.i是否是叶子结点?：i > [n/2] ?





//// 数据元素
// struct Element {
//	 char key;
// };
//
//
//// 树的结点
//struct TreeNode {
//	Element data;
//	bool isEmpty = true;// 判断该位置是否为空
//};
//
//
//// 完全二叉树
//struct BiTree {
//	TreeNode* arr;
//	int length = 0;
//};
//
//
//// 初始化二叉树
//bool initBiTree(BiTree& T) {
//	T.arr = new TreeNode[MAX_SIZE];
//	T.length = 0;
//}