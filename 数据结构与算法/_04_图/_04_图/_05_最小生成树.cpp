#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 100
#define MAX_COST 65535


// 最小生成树
//
// (1)注意事项
//	带权图才有最小生成树的说法
//	这里统一对无向带权图求最小生成树，这些算法对有向图也生效
// 
// 
// 
// (2)最小生成树算法
//	①Kruskal(克鲁斯卡尔)算法（这里没有实现）
//	②Prim(普里姆)算法			
//	·Prim算法：选择一个起始节点，搜索周围权值(代价)最小的边，将这条边以及与这条边相连的未选节点加入到最小生成树中，
//				之后将已经构造的最小生成树看作一个整体，选择到达最小生成树代价最小的结点，接入最小生成树，并更新代价数组，直到全部结点加入最小生成树。
//	·注意：在这个过程中，需要定义一个代价数组，来存放各结点到达最小生成树的最低代价，并随着结点的添加而更新该数组。
//	·Prim算法步骤：
//		1.初始化：选择一个起始节点加入已选节点集合。
//		2.对于所有与已选节点集合相连的未选节点，找出连接它们与已选节点集合的边中权值(代价)最小的边，将这条边以及与这条边相连的未选节点加入到最小生成树和已选节点集合中。
//		3.更新最低代价数组：对于新加入的节点，更新其所有相邻未选节点的最低代价。如果通过这个新节点到达某个未选节点的距离比原来的距离小，那么就更新这个距离。
//		4.重复步骤2和3，直到所有的节点都被选入最小生成树。





//// 顶点信息
//struct VertexInfo {
//	string name;
//};
//
//// 边信息
//struct EdgeInfo {
//	string name;
//	double weight = 0;// 权
//};
//
//// 边链表的结点
//struct EdgeNode {
//	int vertexIndex = -1;// 结点下标
//	double weight = 0;// 权
//	EdgeNode* next = NULL;
//};
//
//// 结点表的结点
//struct VertexNode {
//	bool hasData = false;// 表示当前结点是否为空
//	VertexInfo data;
//	EdgeNode* first = NULL;// 指向边链表的指针
//};
//
//// 邻接表
//struct AdjacencyList {
//	VertexNode* vertexNodeArr;// 结点表数组
//	int vertexNum;// 结点数
//	int edgeNum;// 边数
//};
//
//
//
//// 方法：【查】获取结点在邻接表中的下标
//int indexOf(const AdjacencyList* PAL, const string vertexName) {
//	// 循环结束条件：num(遍历的有效结点数)==节点个数/下标到达最大值 
//	for (int index = 0, num = 0; num < PAL->vertexNum && index < MAX_SIZE; index++) {
//		if (PAL->vertexNodeArr[index].hasData) {// 若当前下标对应的结点有效
//			num++;// num记录已经遍历的有效结点个数
//			if (PAL->vertexNodeArr[index].data.name == vertexName) {
//				return index;
//			}
//		}
//	}
//	return -1;
//}
//
//
//// 方法：初始化邻接表
//bool initAdjacencyList(AdjacencyList*& PAL) {
//	PAL = new AdjacencyList;
//	PAL->vertexNum = 0;
//	PAL->edgeNum = 0;
//	PAL->vertexNodeArr = new VertexNode[MAX_SIZE];
//	return true;
//}
//
//
//// 方法：【创建】创建无向图的邻接表
//// 参数：(结点数据数组, 结点个数, 边的数组， 边的个数) 
//AdjacencyList* createAdjacencyList(const VertexInfo* vertexArr, int vertexSZ, const EdgeInfo* edgeArr, int edgeSZ) {
//	// 1.创建邻接表
//	AdjacencyList* PAL = new AdjacencyList;
//	PAL->vertexNum = vertexSZ;
//	PAL->edgeNum = 2 * edgeSZ;
//	PAL->vertexNodeArr = new VertexNode[MAX_SIZE];
//
//	// 2.为邻接表的结点数据表赋值
//	for (int i = 0; i < vertexSZ; i++) {
//		PAL->vertexNodeArr[i].hasData = true;
//		PAL->vertexNodeArr[i].data = vertexArr[i];
//		PAL->vertexNodeArr[i].first = NULL;
//	}
//
//	// 3.为顶点添加边链表
//	int leftIndex, rightIndex;
//	EdgeNode* edgeNode;
//	for (int i = 0; i < edgeSZ; i++) {
//		leftIndex = indexOf(PAL, edgeArr[i].name.substr(0, 1));// 边的左顶点下标
//		rightIndex = indexOf(PAL, edgeArr[i].name.substr(1, 1));// 边的右顶点下标
//		// ①为边的左顶点添加边
//		edgeNode = new EdgeNode;
//		edgeNode->vertexIndex = rightIndex;
//		edgeNode->weight = edgeArr[i].weight;
//		edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
//		PAL->vertexNodeArr[leftIndex].first = edgeNode;
//		// ②为边的右顶点添加边
//		edgeNode = new EdgeNode;
//		edgeNode->vertexIndex = leftIndex;
//		edgeNode->weight = edgeArr[i].weight;
//		edgeNode->next = PAL->vertexNodeArr[rightIndex].first;
//		PAL->vertexNodeArr[rightIndex].first = edgeNode;
//	}
//	return PAL;
//}
//
//
//// 方法：【增】添加结点
//bool addVertex(AdjacencyList* PAL, const VertexInfo& vertex) {
//	if (PAL->vertexNum == MAX_SIZE) {// 若表满，返回false
//		cout << "结点表已满" << endl;
//		return false;
//	}
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {// 若定点名重复，返回false
//		if (PAL->vertexNodeArr[i].hasData) {
//			if (PAL->vertexNodeArr[i].data.name == vertex.name) {
//				cout << "结点重名" << endl;
//				return false;
//			}
//			j++;// 已遍历的有效结点数
//		}
//	}
//	int i = 0;
//	while (PAL->vertexNodeArr[i].hasData) {
//		// 将i设为首个数据为空的下标
//		i++;
//	}
//	PAL->vertexNodeArr[i].data = vertex;
//	PAL->vertexNodeArr[i].hasData = true;
//	PAL->vertexNodeArr[i].first = NULL;
//
//	PAL->vertexNum++;// 结点数++
//	return true;
//}
//
//
//// 方法：【增】插入结点到指定下标
//bool insertVertex(AdjacencyList* PAL, const VertexInfo& vertex, int index) {
//	if (PAL->vertexNodeArr[index].hasData) {
//		return false;
//	}
//	PAL->vertexNodeArr[index].hasData = true;
//	PAL->vertexNodeArr[index].data = vertex;
//	PAL->vertexNodeArr[index].first = NULL;
//	PAL->vertexNum++;
//	return true;
//}
//
//
//// 方法：【增】添加无向边
//bool addEdge(AdjacencyList* PAL, const EdgeInfo& edge) {
//	int leftIndex = indexOf(PAL, edge.name.substr(0, 1));// 边的左顶点下标
//	int rightIndex = indexOf(PAL, edge.name.substr(1, 1));// 边的右顶点下标
//
//	if (leftIndex == -1 || rightIndex == -1) {// 若结点不存在，则返回false
//		cout << "结点不存在" << endl;
//		return false;
//	}
//	EdgeNode* edgeNode = PAL->vertexNodeArr[leftIndex].first;
//	while (edgeNode) {
//		if (edgeNode->vertexIndex == rightIndex) {// 若边重复，则返回false;
//			cout << "边重复" << endl;
//			return false;
//		}
//		edgeNode = edgeNode->next;
//	}
//
//	// ①为边的左顶点添加边
//	edgeNode = new EdgeNode;
//	edgeNode->vertexIndex = rightIndex;
//	edgeNode->weight = edge.weight;
//	edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
//	PAL->vertexNodeArr[leftIndex].first = edgeNode;
//	// ②为边的右顶点添加边
//	edgeNode = new EdgeNode;
//	edgeNode->vertexIndex = leftIndex;
//	edgeNode->weight = edge.weight;
//	edgeNode->next = PAL->vertexNodeArr[rightIndex].first;
//	PAL->vertexNodeArr[rightIndex].first = edgeNode;
//
//	PAL->edgeNum += 2;// 边数+=2
//	return true;
//}
//
//
//// 方法：【删】删除结点（及其全部边）
//bool deleteVertex(AdjacencyList* PAL, string vertexName) {
//	int deleteIndex = indexOf(PAL, vertexName);
//	if (deleteIndex == -1 || !PAL->vertexNodeArr[deleteIndex].hasData) {// 若删除节点不存在，返回false
//		cout << "结点不存在" << endl;
//		return false;
//	}
//
//	// ①删除与该节点关联的全部边
//	EdgeNode* thisEdgeNode, * otherEdgeNode, * tmp;
//	while (PAL->vertexNodeArr[deleteIndex].first) {// 若first边结点不为空
//		// 1.thisEdgeNode表示要删除的本结点上的边
//		thisEdgeNode = PAL->vertexNodeArr[deleteIndex].first;
//		PAL->vertexNodeArr[deleteIndex].first = thisEdgeNode->next;
//		// 2.otherEdgeNode表示要删除的其它结点上的边（若this为"AB"，则other为"BA"）
//		otherEdgeNode = PAL->vertexNodeArr[thisEdgeNode->vertexIndex].first;
//		// 删除otherEdgeNode
//		if (otherEdgeNode->vertexIndex == deleteIndex) {// 若otherEdgeNode就是其顶点的first，直接删除first
//			PAL->vertexNodeArr[thisEdgeNode->vertexIndex].first = otherEdgeNode->next;
//			delete otherEdgeNode;
//		}
//		else {
//			tmp = otherEdgeNode;
//			while (tmp->next->vertexIndex != deleteIndex) {// 将tmp设为要删除的边结点的前一个结点
//				tmp = tmp->next;
//			}
//			otherEdgeNode = tmp->next;
//			tmp->next = otherEdgeNode->next;
//			delete otherEdgeNode;
//		}
//		// 删除thisEdgeNode
//		delete thisEdgeNode;
//		PAL->edgeNum -= 2;// 每循环一次，边数-=2
//	}
//	// ②将当前结点设为空
//	PAL->vertexNodeArr[deleteIndex].data = {};
//	PAL->vertexNodeArr[deleteIndex].hasData = false;
//
//	PAL->vertexNum--;// 结点数--
//	return true;
//}
//
//
//// 方法：【删】删除边
//bool deleteEdge(AdjacencyList* PAL, string edge) {
//	int leftIndex = indexOf(PAL, edge.substr(0, 1));// 边的左顶点下标
//	int rightIndex = indexOf(PAL, edge.substr(1, 1));// 边的右顶点下标
//
//	if (leftIndex == -1 || rightIndex == -1) {// 若边不存在，返回false
//		cout << "边不存在" << endl;
//		return false;
//	}
//
//	EdgeNode* edgeNode, * tmp;
//	// ①删除左节点的边
//	edgeNode = PAL->vertexNodeArr[leftIndex].first;
//	if (edgeNode->vertexIndex == rightIndex) {// 若要删除的结点是first结点
//		PAL->vertexNodeArr[leftIndex].first = edgeNode->next;
//		delete edgeNode;
//	}
//	else {
//		tmp = edgeNode;
//		while (tmp->next && tmp->next->vertexIndex != rightIndex) {// 将tmp设为要删除的边结点的前一个结点
//			tmp = tmp->next;
//		}
//		if (!tmp->next) {// 若遍历到最后，tmp的下一个都不为rightIndex，返回false
//			cout << "边不存在" << endl;
//			return false;
//		}
//		edgeNode = tmp->next;
//		tmp->next = edgeNode->next;
//		delete edgeNode;
//	}
//	// ②删除右节点的边
//	edgeNode = PAL->vertexNodeArr[rightIndex].first;
//	if (edgeNode->vertexIndex == leftIndex) {
//		PAL->vertexNodeArr[rightIndex].first = edgeNode->next;
//		delete edgeNode;
//	}
//	else {
//		tmp = edgeNode;
//		while (tmp->next->vertexIndex != leftIndex) {
//			tmp = tmp->next;
//		}
//		edgeNode = tmp->next;
//		tmp->next = edgeNode->next;
//		delete edgeNode;
//	}
//
//	PAL->edgeNum -= 2;
//	return true;
//}
//
//
//// 方法：打印邻接表
//void printAdjacencyList(const AdjacencyList* PAL) {
//	cout << "结点数：" << PAL->vertexNum << "， 边数：" << PAL->edgeNum << endl;
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
//		if (PAL->vertexNodeArr[i].hasData) {
//			cout << "index:" << i << ", key:" + PAL->vertexNodeArr[i].data.name << " ";// i表示真实下标
//			EdgeNode* p = PAL->vertexNodeArr[i].first;
//			while (p) {
//				cout << "->" << PAL->vertexNodeArr[p->vertexIndex].data.name << "(" << p->weight << ")";
//				p = p->next;
//			}
//			cout << endl;
//			j++;// 已遍历的有效结点数++
//		}
//	}
//}
//
//
//
//// Prim算法中，最低代价表的结点
//typedef struct LowCostNode {
//	// 代价：正数->表示结点连接到图的最低代价；0->表示结点已经连到图上；MAX_COST->结点与图没有直接的边相连(定义MAX_COST为65535，表示路程无穷远)
//	int vertexIndex;	// 对应顶点的下标 
//	bool isAdd = false;	// 是否已经添加到最小生成树
//	double lowCast;		// 该顶点加入最小生成树的最低代价（权）
//	int lowCastEdgeIndex;// 最低代价的边的另一端的顶点下标
//};
//
//// 方法：Prim算法求最小生成树
//AdjacencyList* getMiniSpanTree_Prim(const AdjacencyList* PAL) {
//	// 1.创建最低代价表
//	LowCostNode* lowCostArr = new LowCostNode[PAL->vertexNum];
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
//		if (PAL->vertexNodeArr[i].hasData) {
//			lowCostArr[j].vertexIndex = i;
//			lowCostArr[j].isAdd = false;
//			lowCostArr[j].lowCast = MAX_COST;// 将最小代价设为最大
//			j++;
//		}
//	}
//
//	// 2.创建最小生成树
//	AdjacencyList* miniSpanTree;
//	initAdjacencyList(miniSpanTree);
//
//	// 3.为最小生成树添加边和顶点（每次加入代价最小的边和顶点）
//	double leastCost;
//	int leastCostIndex;
//	EdgeNode* edgeNode;
//	string edge;
//	for (int i = 0; i < PAL->vertexNum; i++) {
//		// ①获取本轮未被添加的最小代价的顶点
//		leastCost = MAX_COST;// 每轮将最低代价设为MAX_COST
//		for (int j = 0; j < PAL->vertexNum; j++) {// 遍历代价表
//			if (!lowCostArr[j].isAdd && lowCostArr[j].lowCast < leastCost) {
//				leastCost = lowCostArr[j].lowCast;// 获取最小代价
//				leastCostIndex = j;// 获取最小代价对应的lowCostArrs元素下标
//			}
//		}
//		if (leastCost == MAX_COST) {// 若遍历后，最小代价还是MAX_COST，说明最小生成树还没有添加顶点
//			leastCostIndex = 0;// 默认首次添加0
//		}
//
//		// ②将最小代价的顶点和边添加到最小生成树中
//		insertVertex(miniSpanTree, PAL->vertexNodeArr[lowCostArr[leastCostIndex].vertexIndex].data, lowCostArr[leastCostIndex].vertexIndex);
//		if (leastCost != MAX_COST) {// 首次只添加顶点，不添加边
//			edge = PAL->vertexNodeArr[lowCostArr[leastCostIndex].vertexIndex].data.name + PAL->vertexNodeArr[lowCostArr[leastCostIndex].lowCastEdgeIndex].data.name;
//			addEdge(miniSpanTree, { edge, lowCostArr[leastCostIndex].lowCast });
//		}
//		lowCostArr[leastCostIndex].isAdd = true;
//
//		// ③更新代价表（生成树添加新顶点后，某些顶点到生成树的代价会更小）
//		edgeNode = PAL->vertexNodeArr[lowCostArr[leastCostIndex].vertexIndex].first;
//		while (edgeNode) {// 更新与本次加入的顶点相连的顶点的最低代价
//			for (int j = 0; j < PAL->vertexNum; j++) {// 遍历lowCostArr，获取当前边的顶点在lowCostArr中的位置
//				if (edgeNode->vertexIndex == lowCostArr[j].vertexIndex) {
//					// 更新边结点的代价
//					if (!lowCostArr[j].isAdd && edgeNode->weight < lowCostArr[j].lowCast) {// 若该边未被添加且该边的权值小于顶点之前的最低代价
//						lowCostArr[j].lowCast = edgeNode->weight;// 更新顶点的最低代价
//						lowCostArr[j].lowCastEdgeIndex = leastCostIndex;//	更新最低代价的边
//					}
//					break;
//				}
//			}
//			edgeNode = edgeNode->next;
//		}
//	}
//	delete[] lowCostArr;
//	return miniSpanTree;
//}
//
//
//
//
//
//int main() {
//	// (1)创建邻接表
//	VertexInfo vertexArr[] = { {"A"},{"B"},{"C"},{"D"},{"E"},{"F"} };
//	int vertexSZ = sizeof(vertexArr) / sizeof(vertexArr[0]);
//	EdgeInfo edgeArr[] = { {"AB", 6},{"AC", 5},{"AD", 1},{"BD", 5},{"BE", 3},{"CD", 4},{"CF", 2},{"DE", 6},{"DF", 4},{"EF", 6} };
//	int edgeSZ = sizeof(edgeArr) / sizeof(edgeArr[0]);
//	AdjacencyList* PAL = createAdjacencyList(vertexArr, vertexSZ, edgeArr, edgeSZ);
//	printAdjacencyList(PAL);
//	cout << "===================================\n\n";
//
//
//	// (2)获取最小生成树
//	AdjacencyList* PAL_MiniSpanTree = getMiniSpanTree_Prim(PAL);
//	printAdjacencyList(PAL_MiniSpanTree);
//	cout << "===================================\n\n";
//
//
//	return 0;
//}