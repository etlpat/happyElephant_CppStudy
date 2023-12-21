#include<iostream>
using namespace std;
#include<string>


 struct Element {
	 char name;
	 int key;
 };

 typedef struct TreeNode {
	 Element data;
	 TreeNode* leftChild = NULL;
	 TreeNode* rightChild = NULL;
 }*BiTree;


// 方法：创建二叉树
int createBiTree(BiTree& T, const Element* treeNodeArr, int index = 0) {
	 if (treeNodeArr[index].name == '#') {
		 T = NULL;
		 return index + 1;
	 }
	 T = new TreeNode;
	 T->data.name = treeNodeArr[index].name;
	 T->data.key = treeNodeArr[index].key;
	 index++;
	 index = createBiTree(T->leftChild, treeNodeArr, index);
	 index = createBiTree(T->rightChild, treeNodeArr, index);
	 return index;
 }
 

 // 方法：中序遍历二叉树
 string inOrderTraverse(const BiTree& T, bool isFirst = true) {
	 if (!T) {
		 return "";
	 }
	 string str = "";
	 str += inOrderTraverse(T->leftChild, false);
	 str += T->data.name;
	 str += ":" + to_string(T->data.key) + " ";
	 str += inOrderTraverse(T->rightChild, false);
	 return isFirst ? str.substr(0, str.length() - 1) : str;
}


 // 方法：打印二叉树
 void printBiTree(const BiTree& T, string str = "") {
	 if (!T) {
		 cout << "#" << endl;
		 return;
	 }
	 cout << T->data.name << ":" << T->data.key << endl;
	 if (T->leftChild || T->rightChild) {
		 cout << str << "├─";
		 printBiTree(T->rightChild, str + "│ ");
		 cout << str << "└─";
		 printBiTree(T->leftChild, str + "  ");
	 }
 }



 //int main() {
	// // (1)二叉排序树的基本数据
	// Element treeArr[] = { {'A',50},{'B',36},{'D',25},{'H',8},{'#',0},{'K',17},{'#',0},{'#',0},{'#',0},{'E',42},{'#',0},
	//	 {'#',0},{'C',82},{'F',73},{'I',62},{'#',0},{'#',0},{'#',0},{'G',91},{'#',0},{'J',126},{'#',0},{'#',0} };


	// // (2)创建二叉排序树
	// BiTree T;
	// createBiTree(T, treeArr);
	// printBiTree(T);
	// cout << "=====================\n\n";


	// // (3)遍历二叉排序树，获取其关键字序列
	// string str = inOrderTraverse(T);
	// cout << str << endl;


	// return 0;
 //}