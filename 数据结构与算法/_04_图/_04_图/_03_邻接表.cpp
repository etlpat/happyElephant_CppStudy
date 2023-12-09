#include<iostream>
using namespace std;
#include<string>


// 图的邻接表
//
// (1)邻接表
//	邻接表(Adjacency List)：邻接表是一种数组和链表相结合的存储结构
//		1.邻接表的数组：数组元素包含数据域和指针域，数据域存放结点信息，指针域指向该元素的边的链表
//		2.邻接表的链表：每个结点都连接着一个链表，链表是与该节点相邻的边构成的链表，链表的结点存放相邻结点的下标和边的权值
//
//
// (1)图的邻接表
//	1.顶点表（数组）
//		顶点结点包含：顶点数据 + 边表头firstEdge指针	
//
//	2.边的链表
//		边结点包含：相邻顶点下标 + 边的权值 + next指针
//




//// 顶点信息
//struct VertexInfo {
//	string name;
//};
//
//
//// 边结点
//struct EdgeNode {
//	int vertexIndex;// 相邻的顶点下标
//	double weight = 0;// 边的权值
//	EdgeNode* next = NULL;
//};
//
//
//// 顶点表结点
//typedef struct VertexNode {
//	VertexInfo data;
//	EdgeNode* firstEdge = NULL;
//}*AdjacencyList;// 用顶点表数组，表示邻接表
//
//
//
//// 方法：获取结点在邻接表中的下标
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
//// 方法：创建有向图邻接表
//// 参数：(结点数据数组, 结点个数, 边的数组， 边的个数) 
//AdjacencyList createDirectedVertexList(VertexInfo* vertexArr, int vertexSZ, string* directedEdge, int directedSZ) {
//	// 1.创建顶点表，并为顶点信息赋值
//	AdjacencyList adjacencyList = new VertexNode[vertexSZ];
//	for (int i = 0; i < vertexSZ; i++) {// 遍历顶点信息数组
//		adjacencyList[i].data = vertexArr[i];
//		adjacencyList[i].firstEdge = NULL;
//	}
//
//	// 2.为顶点表添加边的链表
//	string startPoint, endPoint;
//	int startIndex, endIndex;
//	EdgeNode* edgeNode;
//	for (int i = 0; i < directedSZ; i++) {// 遍历有向边数组
//		startPoint = directedEdge[i].substr(0, 1);// 获取边的起点
//		endPoint = directedEdge[i].substr(1, 1);// 获取边的终点
//		startIndex = indexOf(adjacencyList, vertexSZ, startPoint);// 获取起点在邻接表中的下标
//		endIndex = indexOf(adjacencyList, vertexSZ, endPoint);// 获取终点在邻接表中的下标
//		// 创建边结点
//		edgeNode = new EdgeNode;
//		edgeNode->vertexIndex = endIndex;
//		edgeNode->weight = 0;// 这里不研究权值
//		edgeNode->next = adjacencyList[startIndex].firstEdge;
//		adjacencyList[startIndex].firstEdge = edgeNode;
//	}
//	return adjacencyList;
//}
//
//
//
//// 方法：创建无向图邻接表
//// 参数：(结点数据数组, 结点个数, 边的数组， 边的个数) 
//VertexNode* createUndirectedVertexList(VertexInfo* vertexArr, int vertexSZ, string* undirectedEdge, int undirectedSZ) {
//	//1.创建顶点表，并为顶点信息赋值
//	AdjacencyList adjacencyList = new VertexNode[vertexSZ];
//	for (int i = 0; i < vertexSZ; i++) {// 遍历顶点信息数组
//		adjacencyList[i].data = vertexArr[i];
//		adjacencyList[i].firstEdge = NULL;
//	}
//
//	// 2.为顶点添加边的链表
//	string leftPoint, rightPoint;
//	int leftIndex, rightIndex;
//	EdgeNode* edgeNode;
//	for (int i = 0; i < undirectedSZ; i++) {
//		leftPoint = undirectedEdge[i].substr(0, 1);// 获取边的左顶点
//		rightPoint = undirectedEdge[i].substr(1, 1);// 获取边的右顶点
//		leftIndex = indexOf(adjacencyList, vertexSZ, leftPoint);// 获取左顶点在邻接表中的下标
//		rightIndex = indexOf(adjacencyList, vertexSZ, rightPoint);// 获取右顶点在邻接表中的下标
//		// ①为边的左顶点添加边
//		edgeNode = new EdgeNode;
//		edgeNode->vertexIndex = rightIndex;
//		edgeNode->weight = 0;
//		edgeNode->next = adjacencyList[leftIndex].firstEdge;
//		adjacencyList[leftIndex].firstEdge = edgeNode;
//		// ②为边的右顶点添加边
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
//// 方法：打印邻接表
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
//	// (1)设置基础数据
//	// 图的结点信息
//	VertexInfo vertexArr[] = { {"A"},{"B"},{"C"},{"D"},{"E"} };
//	int vertexSZ = sizeof(vertexArr) / sizeof(vertexArr[0]);
//	// 有向图的边
//	string directedEdge[] = { "AB", "AE", "BD", "CA", "DA", "EA", "EB", "EC", "ED" };
//	int directedSZ = sizeof(directedEdge) / sizeof(directedEdge[0]);
//	// 无向图的边
//	string undirectedEdge[] = { "AB", "AC", "AD", "AE", "BD", "CE" };
//	int undirectedSZ = sizeof(undirectedEdge) / sizeof(undirectedEdge[0]);
//
//
//
//	// (2)有向图的邻接表
//	AdjacencyList directedAdjacencyList = createDirectedVertexList(vertexArr, vertexSZ, directedEdge, directedSZ);
//	cout << "有向图：" << endl;
//	printAdjacencyList(directedAdjacencyList, vertexSZ);
//	cout << "================================================" << endl;
//	//	有向图：
//	//	index:0, key:A ->E(i=4)->B(i=1)
//	//	index:1, key:B ->D(i=3)
//	//	index:2, key:C ->A(i=0)
//	//	index:3, key:D ->A(i=0)
//	//	index:4, key:E ->D(i=3)->C(i=2)->B(i=1)->A(i=0)
//
//
//	// (3)无向图的邻接表
//	AdjacencyList undirectedAdjacencyList = createUndirectedVertexList(vertexArr, vertexSZ, undirectedEdge, undirectedSZ);
//	cout << "无向图：" << endl;
//	printAdjacencyList(undirectedAdjacencyList, vertexSZ);
//	//	无向图：
//	//	index:0, key:A ->E(i=4)->D(i=3)->C(i=2)->B(i=1)
//	//	index:1, key:B ->D(i=3)->A(i=0)
//	//	index:2, key:C ->E(i=4)->A(i=0)
//	//	index:3, key:D ->B(i=1)->A(i=0)
//	//	index:4, key:E ->C(i=2)->A(i=0)
//
//
//	return 0;
//}