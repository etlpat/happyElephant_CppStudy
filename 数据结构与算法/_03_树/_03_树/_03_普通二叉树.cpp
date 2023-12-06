//#include<iostream>
//using namespace std;
//#include<string>
//#include "_03_LinkQueue.h"



// ��ʽ�洢������
//
// (1)���������
//	�������Ľ�㣺���� ����Ԫ�ء�����ָ�롢�Һ���ָ��
//	�����á����������ڵ��ָ�롿������(����)����������
//
//
//
// (2)�������ı���
//	1.�����������->��->��
//	2.�����������->��->��
//	3.�����������->��->��
//	4.��α������Ӹ��ڵ�->Ҷ�ڵ㣬���ϵ�����������ÿ���д����ҷ���
//	
//	ע�⣺1.ǰ���ֱ������������򡢺��򣬶���˵�ĸ��ڵ�ķ���˳��ÿ�ֱ�������ȷ��Ψһһ�����С�
//			��֪ (��������+��������) ���� (��������+��������) ���� (��������+�������)������Ψһȷ��һ�Ŷ�����
//			��Ҫ�Ƶ�������������Ҫ��������
// 
//		  2.��α�������������ȱ�������Ҫͨ�������С�����ʵ��
//			�㷨�����ø��ڵ���ӣ�֮����ڵ���ӣ����Һ�����ӣ����ӳ��ӣ����ӵ�����������ӣ��Һ��ӳ��ӣ��Һ��ӵ�������������...
//			ԭ�����ڶ����Ƚ��ȳ������ʣ����Ա�֤�����Ӵ����Ǵ�ǳ��������ӵ�
//
//
// (3)�������Ĵ���
//	������Ҫ�������е�����������������
//	���ǣ�һ����ͨ���������в���Ψһȷ��һ�Ŷ���������ˣ�������������Ҫ����ȫ�������С�
//	����ȫ�������С��磺ABDH#K###E##CFI###G#J##	�����е�'#'��ʾNULL��
//	
//	��Ȼ����ȫ�������С���ȫ�������ж�������������������






//// ����Ԫ��
// struct Element {
//	 char key;
// };
//
//
//// ���Ľ��
// typedef struct TreeNode {
//	 Element data;
//	 TreeNode* leftChild = NULL;
//	 TreeNode* rightChild = NULL;
// }*BiTree;// �ø�����ָ���ʾ������
//
//
//
//
////������������ȫ�������д���������
////ע�⣺��ͨ��������(ABDHKECFIGJ)����ȷ��һ����������
////		������ȫ��������(ABDH#K###E##CFI###G#J##)����ȷ��һ��Ψһ�Ķ�����������#��ʾ����Ϊ��
////
////int createBiTree(BiTree& T, const string& str, int index = 0) {
//	// if (str[index] == '#') {// ��ȫ���������е�'#'����������Ϊ��
//	//	 T = NULL;
//	//	 return index + 1;// ÿ�ζ�ȡ��һ���ַ���ȷ����һ����㣩��index������һλ
//	// }
//
//	// T = new TreeNode;
//	// T->data.key = str[index];
//	// index++;// ÿ�ζ�ȡ��һ���ַ���ȷ����һ����㣩��index������һλ
//
//	// index = createBiTree(T->leftChild, str, index);
//	// index = createBiTree(T->rightChild, str, index);
//	// return index;
// //}
//
// // ������Ĵ����Ż������£�
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
// // �������������������
// string preOrderTraverse(const BiTree& T) {
//	 if (!T) {// �ݹ������������Ϊ����
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
// // �������������������
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
// // �������������������
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
// // ��������α������棨���ö���ʵ�֣�
// string levelOrderTraverse(const BiTree& T) {
//	 if (!T) {
//		 return "";
//	 }
//	 Queue treeNodeQueue;// ��������
//	 initQueue(treeNodeQueue);
//	 enQueue(treeNodeQueue, T);// ���ڵ����
//
//	 TreeNode* tmp = NULL;
//	 string str = "";
//	 while (!isEmpty(treeNodeQueue)) {
//		 deQueue(treeNodeQueue, tmp);// ����
//		 str += tmp->data.key;
//		 if (tmp->leftChild) {// �������
//			 enQueue(treeNodeQueue, tmp->leftChild);
//		 }
//		 if (tmp->rightChild) {// �Һ������
//			 enQueue(treeNodeQueue, tmp->rightChild);
//		 }
//	 }
//	 destroyQueue(treeNodeQueue);// ���ٶ���
//	 return str;
// }
// 
//
// //// ��������ӡ������
// //// ע�⣺���depth�����������ɾȥ����str.length()���漴�ɣ�����Ϊ�˴���Ŀɶ��Զ������ò�����
// //void printBiTree(const BiTree& T, int depth = 0, string str = "") {
//	// if (!T) {
//	//	 cout << "#" << endl;// ����Ϊ�գ���ӡ"#"
//	//	 return;
//	// }
//
//	// // (1)��ӡ���������
//	// cout << T->data.key << endl;// ��ʼ��ӡλ�ã����Ϊdepth
//
//	// // (2)��ӡ������
//	// for (int i = 0; i < depth; i++) {// ��ӡdepth����ȵļ��
//	//	 if (str[i] == '1') {
//	//		 cout << "�� ";// ����һ����"����"�����ж�Ӧλ�ô�ӡ"�� "
//	//	 }
//	//	 else {
//	//		 cout << "  ";// ����һ����"����"�����ж�Ӧλ�ô�ӡ"  "
//	//	 }
//	// }
//	// cout << "����";// ��ӡ�����Ϊdepth+1
//	// printBiTree(T->rightChild, depth + 1, str + "1");// ����������ǰΪ"����"������str + "1"������һ�ж�Ӧλ�ô�ӡ"�� "
//
//	// // (3)��ӡ������
//	// for (int i = 0; i < depth; i++) {
//	//	 if (str[i] == '1') {
//	//		 cout << "�� ";
//	//	 }
//	//	 else {
//	//		 cout << "  ";
//	//	 }
//	// }
//	// cout << "����";
//	// printBiTree(T->leftChild, depth + 1, str + "0");// ����������ǰΪ"����"������str + "0"������һ�ж�Ӧλ�ô�ӡ"  "
// //}
//
//
// // ��������ӡ������
// // �������򻯺󣬵õ����´���
// void printBiTree(const BiTree& T, string str = "") {
//	 if (!T) {
//		 cout << "#" << endl;
//		 return;
//	 }
//	 cout << T->data.key << endl;
//	 cout << str << "����";
//	 printBiTree(T->rightChild, str + "�� ");
//	 cout << str << "����";
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
//	//	����C
//	//	��  ����G
//	//	��  �� ����J
//	//	��  �� �� ����#
//	//	��  �� �� ����#
//	//	��  �� ����#
//	//	��  ����F
//	//	��		����#
//	//	��      ����I
//	//	��			����#
//	//	��			����#
//	//	����B
//	//		����E
//	//		�� ����#
//	//		�� ����#
//	//		����D
//	//			����#
//	//			����H
//	//				����K
//	//				�� ����#
// 	//				�� ����#
// 	//				����#
//
//
//	 cout << "�������У�" << preOrderTraverse(T) << endl;
//	 cout << "�������У�" << inOrderTraverse(T) << endl;
//	 cout << "�������У�" << postOrderTraverse(T) << endl;
//	 cout << "��α�����" << levelOrderTraverse(T) << endl;
//	//�������У�ABDHKECFIGJ
//	//�������У�HKDBEAIFCGJ
//	//�������У�KHDEBIFJGCA
//	//��α�����ABCDEFGHIJK
//
//	 return 0;
// }