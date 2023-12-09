#include<iostream>
using namespace std;
#include<string>


// 图的邻接矩阵
// 
// (0)邻接矩阵
//	邻接矩阵，用来表示图中边的关系，若有边，则为1，若无边，则为0
//	注意：若是带权邻接矩阵，则矩阵的元素存放权值，不连通的路径用∞表示
//		  若边比较少，建议直接用一维数组存放边的信息，稀疏矩阵浪费空间
//
//
// (1)无向图
//	无向图的数据结构：
//	struct UndirectedGraph {
//		Vertex* vertexArr;// 存放顶点信息的数组
//		int* edgeArr;// 无向图的邻接表：一维数组(下三角矩阵，不含对角线)
//	}; 
//
//
// (2)有向图
// 有向图的数据结构：
//	struct DirectedGraph {
//		Vertex* vertexArr;// 存放顶点信息的数组
//		int(*edgeArr)[10];// 有向图的邻接表：二维数组
//	};
//
//
// (3)可达矩阵（一般是描述有向图）
//	若有向图的临界矩阵为A：
//		A：路径长度为1的邻接矩阵
//		A^2：长度为2的路径的矩阵
//		A^n：长度为n的路径的矩阵
//		A + A^2 + A^3 +...+ A^n：图的可达矩阵





//// 定义定点数
//#define VERTEX_NUM 5
//
//
//// 表示图的顶点
//struct Vertex {
//	string key;// 顶点的名字
//	int index;// 顶点在邻接表中的下标（可以不添加该参数）
//};
//
//
//// 无向图
//struct UndirectedGraph {
//	Vertex* vertexArr = NULL;// 存放顶点信息的数组
//	int* edgeArr = NULL;// 无向图的邻接表：一维数组下三角矩阵
//};
//
//
//// 有向图
//struct DirectedGraph {
//	Vertex* vertexArr = NULL;// 存放顶点信息的数组
//	int(*edgeArr)[VERTEX_NUM] = NULL;// 有向图的邻接表：二维数组
//};
//
//
//
//// 方法：初始化无向图
//bool initUndirectedGraph(UndirectedGraph& ug) {
//	ug.vertexArr = new Vertex[VERTEX_NUM];
//	int sum = 0;
//	for (int i = VERTEX_NUM - 1; i > 0; i--) {// 获取一维数组的大小
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
//// 方法：初始化有向图
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
//// 方法：寻找结点对应的二维邻接矩阵下标
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
//// 方法：传入二维数组的下标，返回其所对应的【一维下三角矩阵】的下标
//int getTriangleIndex(int i, int j) {
//	if (i == j) {// 若i==j，则边为自环，返回-1（简单图无自环）
//		return -1;
//	}
//	if (i < j) {// 若i<j，表示在上三角位置
//		// 无向图的二维数组邻接矩阵对称，这里统一（i、j互换）转化为下三角处理
//		int tmp = i;
//		i = j;
//		j = tmp;
//	}
//	int sum = 0;// 这里的算法画图理解
//	while (--i) {
//		sum += i;
//	}
//	return sum + j;
//}
//
//
//// 方法：创建无向图
//bool createUndirectedGraph(UndirectedGraph& ug, Vertex* arr, string* undirectedGraphEdge, int edgeSZ) {
//	// 添加结点信息
//	for (int i = 0; i < VERTEX_NUM; i++) {
//		ug.vertexArr[i].key = arr[i].key;
//		ug.vertexArr[i].index = arr[i].index;
//	}
//	// 为邻接表添加边的信息
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
//// 方法：创建有向图
//bool createDirectedGraph(DirectedGraph& dg, Vertex* arr, string* directedGraphEdge, int edgeSz) {
//	// 添加结点信息
//	for (int i = 0; i < VERTEX_NUM; i++) {
//		dg.vertexArr[i].key = arr[i].key;
//		dg.vertexArr[i].index = arr[i].index;
//	}
//	// 为邻接表添加边信息
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
//// 方法：打印无向图的邻接矩阵
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
//// 方法：打印有向图的邻接矩阵
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
//	// (1)设置基础数据
//	// 有向/无向图的顶点
//	Vertex arr[] = { {"A", 0},{"B", 1},{"C", 2},{"D", 3},{"E", 4} };
//	// 无向图的边
//	string undirectedGraphEdge[] = { "AB", "AC", "AD", "AE", "BD", "CE" };
//	int undirectedSZ = sizeof(undirectedGraphEdge) / sizeof(undirectedGraphEdge[0]);
//	// 有向图的边
//	string directedGraphEdge[] = { "AB", "AE", "BD", "CA", "DA", "EC" };
//	int directedSZ = sizeof(directedGraphEdge) / sizeof(directedGraphEdge[0]);
//
//	
//	// (2)创建无向图
//	UndirectedGraph ug;
//	initUndirectedGraph(ug);
//	createUndirectedGraph(ug, arr, undirectedGraphEdge, undirectedSZ);
//	cout << "无向图下三角矩阵：" << endl;
//	printUndirectedGraphEdge(ug);
//	cout << "===================" << endl;
//
//
//	// (3)创建有向图
//	DirectedGraph dg;
//	initDirectedGraph(dg);
//	createDirectedGraph(dg, arr, directedGraphEdge, directedSZ);
//	cout << "有向图二维数组矩阵：" << endl;
//	printDirectedGraphEdge(dg);
//
//
//	return 0;
//}