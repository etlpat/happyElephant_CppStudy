#include<iostream>
using namespace std;
#include<string>


// ͼ���ڽӾ���
// 
// (0)�ڽӾ���
//	�ڽӾ���������ʾͼ�бߵĹ�ϵ�����бߣ���Ϊ1�����ޱߣ���Ϊ0
//	ע�⣺���Ǵ�Ȩ�ڽӾ���������Ԫ�ش��Ȩֵ������ͨ��·���áޱ�ʾ
//		  ���߱Ƚ��٣�����ֱ����һά�����űߵ���Ϣ��ϡ������˷ѿռ�
//
//
// (1)����ͼ
//	����ͼ�����ݽṹ��
//	struct UndirectedGraph {
//		Vertex* vertexArr;// ��Ŷ�����Ϣ������
//		int* edgeArr;// ����ͼ���ڽӱ�һά����(�����Ǿ��󣬲����Խ���)
//	}; 
//
//
// (2)����ͼ
// ����ͼ�����ݽṹ��
//	struct DirectedGraph {
//		Vertex* vertexArr;// ��Ŷ�����Ϣ������
//		int(*edgeArr)[10];// ����ͼ���ڽӱ���ά����
//	};
//
//
// (3)�ɴ����һ������������ͼ��
//	������ͼ���ٽ����ΪA��
//		A��·������Ϊ1���ڽӾ���
//		A^2������Ϊ2��·���ľ���
//		A^n������Ϊn��·���ľ���
//		A + A^2 + A^3 +...+ A^n��ͼ�Ŀɴ����





//// ���嶨����
//#define VERTEX_NUM 5
//
//
//// ��ʾͼ�Ķ���
//struct Vertex {
//	string key;// ���������
//	int index;// �������ڽӱ��е��±꣨���Բ���Ӹò�����
//};
//
//
//// ����ͼ
//struct UndirectedGraph {
//	Vertex* vertexArr = NULL;// ��Ŷ�����Ϣ������
//	int* edgeArr = NULL;// ����ͼ���ڽӱ�һά���������Ǿ���
//};
//
//
//// ����ͼ
//struct DirectedGraph {
//	Vertex* vertexArr = NULL;// ��Ŷ�����Ϣ������
//	int(*edgeArr)[VERTEX_NUM] = NULL;// ����ͼ���ڽӱ���ά����
//};
//
//
//
//// ��������ʼ������ͼ
//bool initUndirectedGraph(UndirectedGraph& ug) {
//	ug.vertexArr = new Vertex[VERTEX_NUM];
//	int sum = 0;
//	for (int i = VERTEX_NUM - 1; i > 0; i--) {// ��ȡһά����Ĵ�С
//		sum += i;
//	}
//	ug.edgeArr = new int[sum];
//	for (int i = 0; i < sum; i++) {
//		ug.edgeArr[i] = 0;
//	}
//	return true;
//}
//
//
//// ��������ʼ������ͼ
//bool initDirectedGraph(DirectedGraph& dg) {
//	dg.vertexArr = new Vertex[VERTEX_NUM];
//	dg.edgeArr = new int[VERTEX_NUM][VERTEX_NUM];
//	for (int i = 0; i < VERTEX_NUM; i++) {
//		for (int j = 0; j < VERTEX_NUM; j++) {
//			dg.edgeArr[i][j] = 0;
//		}
//	}
//	return true;
//}
//
//
//// ������Ѱ�ҽ���Ӧ�Ķ�ά�ڽӾ����±�
//int getNodeIndex(Vertex* arr, string key) {
//	for (int i = 0; i < VERTEX_NUM; i++) {
//		if (arr[i].key == key) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//
//// �����������ά������±꣬����������Ӧ�ġ�һά�����Ǿ��󡿵��±�
//int getTriangleIndex(int i, int j) {
//	if (i == j) {// ��i==j�����Ϊ�Ի�������-1����ͼ���Ի���
//		return -1;
//	}
//	if (i < j) {// ��i<j����ʾ��������λ��
//		// ����ͼ�Ķ�ά�����ڽӾ���Գƣ�����ͳһ��i��j������ת��Ϊ�����Ǵ���
//		int tmp = i;
//		i = j;
//		j = tmp;
//	}
//	int sum = 0;// ������㷨��ͼ���
//	while (--i) {
//		sum += i;
//	}
//	return sum + j;
//}
//
//
//// ��������������ͼ
//bool createUndirectedGraph(UndirectedGraph& ug, Vertex* arr, string* undirectedGraphEdge, int edgeSZ) {
//	// ��ӽ����Ϣ
//	for (int i = 0; i < VERTEX_NUM; i++) {
//		ug.vertexArr[i].key = arr[i].key;
//		ug.vertexArr[i].index = arr[i].index;
//	}
//	// Ϊ�ڽӱ���ӱߵ���Ϣ
//	string key1, key2;
//	for (int i = 0; i < edgeSZ; i++) {
//		key1 = undirectedGraphEdge[i].substr(0, 1);
//		key2 = undirectedGraphEdge[i].substr(1, 1);
//		ug.edgeArr[getTriangleIndex(getNodeIndex(arr, key1), getNodeIndex(arr, key2))] = 1;
//	}
//	return true;
//}
//
//
//// ��������������ͼ
//bool createDirectedGraph(DirectedGraph& dg, Vertex* arr, string* directedGraphEdge, int edgeSz) {
//	// ��ӽ����Ϣ
//	for (int i = 0; i < VERTEX_NUM; i++) {
//		dg.vertexArr[i].key = arr[i].key;
//		dg.vertexArr[i].index = arr[i].index;
//	}
//	// Ϊ�ڽӱ���ӱ���Ϣ
//	string key1, key2;
//	for (int i = 0; i < edgeSz; i++) {
//		key1 = directedGraphEdge[i].substr(0, 1);
//		key2 = directedGraphEdge[i].substr(1, 1);
//		dg.edgeArr[getNodeIndex(arr, key1)][getNodeIndex(arr, key2)] = 1;
//	}
//	return true;
//}
//
//
//// ��������ӡ����ͼ���ڽӾ���
//void printUndirectedGraphEdge(const UndirectedGraph& ug) {
//	int sum = 0;
//	for (int i = 1; i < VERTEX_NUM; i++) {
//		sum += i - 1;
//		for (int j = 0; j < i; j++) {
//			cout << ug.edgeArr[sum + j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//
//// ��������ӡ����ͼ���ڽӾ���
//void printDirectedGraphEdge(const DirectedGraph& dg) {
//	for (int i = 0; i < VERTEX_NUM; i++) {
//		for (int j = 0; j < VERTEX_NUM; j++) {
//			cout << dg.edgeArr[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//
//
//
//
//
//int main() {
//	// (1)���û�������
//	// ����/����ͼ�Ķ���
//	Vertex arr[] = { {"A", 0},{"B", 1},{"C", 2},{"D", 3},{"E", 4} };
//	// ����ͼ�ı�
//	string undirectedGraphEdge[] = { "AB", "AC", "AD", "AE", "BD", "CE" };
//	int undirectedSZ = sizeof(undirectedGraphEdge) / sizeof(undirectedGraphEdge[0]);
//	// ����ͼ�ı�
//	string directedGraphEdge[] = { "AB", "AE", "BD", "CA", "DA", "EC" };
//	int directedSZ = sizeof(directedGraphEdge) / sizeof(directedGraphEdge[0]);
//
//	
//	// (2)��������ͼ
//	UndirectedGraph ug;
//	initUndirectedGraph(ug);
//	createUndirectedGraph(ug, arr, undirectedGraphEdge, undirectedSZ);
//	cout << "����ͼ�����Ǿ���" << endl;
//	printUndirectedGraphEdge(ug);
//	cout << "===================" << endl;
//
//
//	// (3)��������ͼ
//	DirectedGraph dg;
//	initDirectedGraph(dg);
//	createDirectedGraph(dg, arr, directedGraphEdge, directedSZ);
//	cout << "����ͼ��ά�������" << endl;
//	printDirectedGraphEdge(dg);
//
//
//	return 0;
//}