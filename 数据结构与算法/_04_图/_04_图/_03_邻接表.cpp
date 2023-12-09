#include<iostream>
using namespace std;
#include<string>


// ͼ���ڽӱ�
//
// (1)�ڽӱ�
//	�ڽӱ�(Adjacency List)���ڽӱ���һ��������������ϵĴ洢�ṹ
//		1.�ڽӱ�����飺����Ԫ�ذ����������ָ�����������Ž����Ϣ��ָ����ָ���Ԫ�صıߵ�����
//		2.�ڽӱ������ÿ����㶼������һ��������������ýڵ����ڵı߹��ɵ���������Ľ�������ڽ����±�ͱߵ�Ȩֵ
//
//
// (1)ͼ���ڽӱ�
//	1.��������飩
//		������������������� + �߱�ͷfirstEdgeָ��	
//
//	2.�ߵ�����
//		�߽����������ڶ����±� + �ߵ�Ȩֵ + nextָ��
//




//// ������Ϣ
//struct VertexInfo {
//	string name;
//};
//
//
//// �߽��
//struct EdgeNode {
//	int vertexIndex;// ���ڵĶ����±�
//	double weight = 0;// �ߵ�Ȩֵ
//	EdgeNode* next = NULL;
//};
//
//
//// �������
//typedef struct VertexNode {
//	VertexInfo data;
//	EdgeNode* firstEdge = NULL;
//}*AdjacencyList;// �ö�������飬��ʾ�ڽӱ�
//
//
//
//// ��������ȡ������ڽӱ��е��±�
//int indexOf(const AdjacencyList& adjacencyList, int sz, const string vertexName) {
//	for (int i = 0; i < sz; i++) {
//		if (adjacencyList[i].data.name == vertexName) {
//			return i;
//		}
//	}
//	return -1;
//}
//
//
//
//// ��������������ͼ�ڽӱ�
//// ������(�����������, ������, �ߵ����飬 �ߵĸ���) 
//AdjacencyList createDirectedVertexList(VertexInfo* vertexArr, int vertexSZ, string* directedEdge, int directedSZ) {
//	// 1.�����������Ϊ������Ϣ��ֵ
//	AdjacencyList adjacencyList = new VertexNode[vertexSZ];
//	for (int i = 0; i < vertexSZ; i++) {// ����������Ϣ����
//		adjacencyList[i].data = vertexArr[i];
//		adjacencyList[i].firstEdge = NULL;
//	}
//
//	// 2.Ϊ�������ӱߵ�����
//	string startPoint, endPoint;
//	int startIndex, endIndex;
//	EdgeNode* edgeNode;
//	for (int i = 0; i < directedSZ; i++) {// �������������
//		startPoint = directedEdge[i].substr(0, 1);// ��ȡ�ߵ����
//		endPoint = directedEdge[i].substr(1, 1);// ��ȡ�ߵ��յ�
//		startIndex = indexOf(adjacencyList, vertexSZ, startPoint);// ��ȡ������ڽӱ��е��±�
//		endIndex = indexOf(adjacencyList, vertexSZ, endPoint);// ��ȡ�յ����ڽӱ��е��±�
//		// �����߽��
//		edgeNode = new EdgeNode;
//		edgeNode->vertexIndex = endIndex;
//		edgeNode->weight = 0;// ���ﲻ�о�Ȩֵ
//		edgeNode->next = adjacencyList[startIndex].firstEdge;
//		adjacencyList[startIndex].firstEdge = edgeNode;
//	}
//	return adjacencyList;
//}
//
//
//
//// ��������������ͼ�ڽӱ�
//// ������(�����������, ������, �ߵ����飬 �ߵĸ���) 
//VertexNode* createUndirectedVertexList(VertexInfo* vertexArr, int vertexSZ, string* undirectedEdge, int undirectedSZ) {
//	//1.�����������Ϊ������Ϣ��ֵ
//	AdjacencyList adjacencyList = new VertexNode[vertexSZ];
//	for (int i = 0; i < vertexSZ; i++) {// ����������Ϣ����
//		adjacencyList[i].data = vertexArr[i];
//		adjacencyList[i].firstEdge = NULL;
//	}
//
//	// 2.Ϊ������ӱߵ�����
//	string leftPoint, rightPoint;
//	int leftIndex, rightIndex;
//	EdgeNode* edgeNode;
//	for (int i = 0; i < undirectedSZ; i++) {
//		leftPoint = undirectedEdge[i].substr(0, 1);// ��ȡ�ߵ��󶥵�
//		rightPoint = undirectedEdge[i].substr(1, 1);// ��ȡ�ߵ��Ҷ���
//		leftIndex = indexOf(adjacencyList, vertexSZ, leftPoint);// ��ȡ�󶥵����ڽӱ��е��±�
//		rightIndex = indexOf(adjacencyList, vertexSZ, rightPoint);// ��ȡ�Ҷ������ڽӱ��е��±�
//		// ��Ϊ�ߵ��󶥵���ӱ�
//		edgeNode = new EdgeNode;
//		edgeNode->vertexIndex = rightIndex;
//		edgeNode->weight = 0;
//		edgeNode->next = adjacencyList[leftIndex].firstEdge;
//		adjacencyList[leftIndex].firstEdge = edgeNode;
//		// ��Ϊ�ߵ��Ҷ�����ӱ�
//		edgeNode = new EdgeNode;
//		edgeNode->vertexIndex = leftIndex;
//		edgeNode->weight = 0;
//		edgeNode->next = adjacencyList[rightIndex].firstEdge;
//		adjacencyList[rightIndex].firstEdge = edgeNode;
//	}
//	return adjacencyList;
//}
//
//
//
//// ��������ӡ�ڽӱ�
//void printAdjacencyList(const AdjacencyList& L, int sz) {
//	for (int i = 0; i < sz; i++) {
//		cout << "index:" << i << ", key:" + L[i].data.name << " ";
//		EdgeNode* p = L[i].firstEdge;
//		while (p) {
//			cout << "->" << L[p->vertexIndex].data.name << "(i=" << p->vertexIndex << ")";
//			p = p->next;
//		}
//		cout << endl;
//	}
//}
//
//
//
//int main() {
//	// (1)���û�������
//	// ͼ�Ľ����Ϣ
//	VertexInfo vertexArr[] = { {"A"},{"B"},{"C"},{"D"},{"E"} };
//	int vertexSZ = sizeof(vertexArr) / sizeof(vertexArr[0]);
//	// ����ͼ�ı�
//	string directedEdge[] = { "AB", "AE", "BD", "CA", "DA", "EA", "EB", "EC", "ED" };
//	int directedSZ = sizeof(directedEdge) / sizeof(directedEdge[0]);
//	// ����ͼ�ı�
//	string undirectedEdge[] = { "AB", "AC", "AD", "AE", "BD", "CE" };
//	int undirectedSZ = sizeof(undirectedEdge) / sizeof(undirectedEdge[0]);
//
//
//
//	// (2)����ͼ���ڽӱ�
//	AdjacencyList directedAdjacencyList = createDirectedVertexList(vertexArr, vertexSZ, directedEdge, directedSZ);
//	cout << "����ͼ��" << endl;
//	printAdjacencyList(directedAdjacencyList, vertexSZ);
//	cout << "================================================" << endl;
//	//	����ͼ��
//	//	index:0, key:A ->E(i=4)->B(i=1)
//	//	index:1, key:B ->D(i=3)
//	//	index:2, key:C ->A(i=0)
//	//	index:3, key:D ->A(i=0)
//	//	index:4, key:E ->D(i=3)->C(i=2)->B(i=1)->A(i=0)
//
//
//	// (3)����ͼ���ڽӱ�
//	AdjacencyList undirectedAdjacencyList = createUndirectedVertexList(vertexArr, vertexSZ, undirectedEdge, undirectedSZ);
//	cout << "����ͼ��" << endl;
//	printAdjacencyList(undirectedAdjacencyList, vertexSZ);
//	//	����ͼ��
//	//	index:0, key:A ->E(i=4)->D(i=3)->C(i=2)->B(i=1)
//	//	index:1, key:B ->D(i=3)->A(i=0)
//	//	index:2, key:C ->E(i=4)->A(i=0)
//	//	index:3, key:D ->B(i=1)->A(i=0)
//	//	index:4, key:E ->C(i=2)->A(i=0)
//
//
//	return 0;
//}