//#include<iostream>
//using namespace std;
//#include<string>
//#define MAX_SIZE 1000


// ��ȫ������
//
// (1)����
//	��ȫ���������������һ���⣬������Ľ�㶼�����ģ��������һ��Ľ�㶼�ǿ�������е�
//	
// (2)��ȫ��������ʵ��
//	����ȫ�����������ң����ϵ��£��Ը��ڵ�Ϊ1��ʼ���
//	�����������±꣬����Ŷ�Ӧ��ŵĽ��
//	
// (3)��������
//	1.i�����ӣ�2 * i
//	2.i���Һ��ӣ�2 * i + 1
//	3.i�ĸ��ڵ㣺[i / 2]
//	4.i���ڵĲ�Σ�[log2 i] + 1
//	5.i�Ž���Ƿ�������?��2 * i <= n ?
//	6.i�Ž���Ƿ����Һ���?��2 * i + 1 <= n ?
//	7.i�Ƿ���Ҷ�ӽ��?��i > [n/2] ?





//// ����Ԫ��
// struct Element {
//	 char key;
// };
//
//
//// ���Ľ��
//struct TreeNode {
//	Element data;
//	bool isEmpty = true;// �жϸ�λ���Ƿ�Ϊ��
//};
//
//
//// ��ȫ������
//struct BiTree {
//	TreeNode* arr;
//	int length = 0;
//};
//
//
//// ��ʼ��������
//bool initBiTree(BiTree& T) {
//	T.arr = new TreeNode[MAX_SIZE];
//	T.length = 0;
//}