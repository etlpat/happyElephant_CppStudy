#include "_04_VertexQueue.h"
#define MAX_SIZE 100


// 图的遍历
//
// (1)注意事项
//	这里统一实现无向图的基本操作和遍历
//	这些算法大部分对有向图也通用
//
//
// (2)图的遍历
//	1.图的遍历有以下两种算法
//		①广度优先遍历（Breadth_First_Search == BFS）	
//		②深度优先遍历（Depth_First_Search == DFS）
//		注意：无论是广度优先还是深度优先，都需要记录结点是否被访问过，
//			  这里建议单独创建一个数组flagArr，数组元素表示对应结点是否被访问过
//	
//	2.BFS（广度优先搜索）
//		概念：广度优先算法类似于树的层序遍历算法，优先访问邻近的结点，之后再访问外层的结点。
//		遍历顺序：先访问指定结点周围一圈的结点，之后访问外圈的结点，由内到外一层层的访问。
//		算法步骤如下：【队列】
//			1.将源节点标记为已访问，并将其添加到队列中。
//			2.从队列的头部取出一个节点，然后将其所有未访问的相邻节点标记为已访问，并将它们添加到队列的尾部。
//			3.重复步骤2，直到队列为空。
//		应用场景：广度优先搜索适用于找到最短路径或需要访问所有节点的场景。
//
//	3.DFS（深度优先搜索）
//		概念：深度优先类似于树的先根遍历算法，优先访某一条路径上的结点，这条路径全部访问完后再访问其它路径的结点
//		遍历顺序：先遍历一条路径，直到遍历完这条路径最深处的结点，再从树叶到树根遍历其它分支路径
//		算法步骤如下：【递归】
//			1.将源节点标记为已访问。
//			2.递归地访问源节点的所有未访问的相邻节点，并对每个未访问的相邻节点递归重复此过程。
//			3.当某条路径没有更多的未访问的相邻节点时，则本层递归结束，回到上层递归重复步骤2，直到所有节点都被访问。
//		应用场景：深度优先搜索适用于需要查找一条路径或解决约束满足问题的场景。





//// 顶点信息
//struct VertexInfo {
//	string name;
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
//int indexOf(const AdjacencyList* ALPointer, const string vertexName) {
//	// 循环结束条件：num(遍历的有效结点数)==节点个数/下标到达最大值 
//	for (int index = 0, num = 0; num < ALPointer->vertexNum && index < MAX_SIZE; index++) {
//		if (ALPointer->vertexNodeArr[index].hasData) {// 若当前下标对应的结点有效
//			num++;// num记录已经遍历的有效结点个数
//			if (ALPointer->vertexNodeArr[index].data.name == vertexName) {
//				return index;
//			}
//		}
//	}
//	return -1;
//}
//
//
//
//// 方法：【创建】创建无向图的邻接表
//// 参数：(结点数据数组, 结点个数, 边的数组， 边的个数) 
//AdjacencyList* createAdjacencyList(const VertexInfo* vertexArr, int vertexSZ, const string* edgeArr, int edgeSZ) {
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
//		leftIndex = indexOf(PAL, edgeArr[i].substr(0, 1));// 边的左顶点下标
//		rightIndex = indexOf(PAL, edgeArr[i].substr(1, 1));// 边的右顶点下标
//		// ①为边的左顶点添加边
//		edgeNode = new EdgeNode;
//		edgeNode->vertexIndex = rightIndex;
//		edgeNode->weight = 1;
//		edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
//		PAL->vertexNodeArr[leftIndex].first = edgeNode;
//		// ②为边的右顶点添加边
//		edgeNode = new EdgeNode;
//		edgeNode->vertexIndex = leftIndex;
//		edgeNode->weight = 1;
//		edgeNode->next = PAL->vertexNodeArr[rightIndex].first;
//		PAL->vertexNodeArr[rightIndex].first = edgeNode;
//	}
//	return PAL;
//}
//
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
//
//// 方法：【增】添加无向边
//bool addEdge(AdjacencyList* PAL, string edge) {
//	int leftIndex = indexOf(PAL, edge.substr(0, 1));// 边的左顶点下标
//	int rightIndex = indexOf(PAL, edge.substr(1, 1));// 边的右顶点下标
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
//	edgeNode->weight = 1;
//	edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
//	PAL->vertexNodeArr[leftIndex].first = edgeNode;
//	// ②为边的右顶点添加边
//	edgeNode = new EdgeNode;
//	edgeNode->vertexIndex = leftIndex;
//	edgeNode->weight = 1;
//	edgeNode->next = PAL->vertexNodeArr[rightIndex].first;
//	PAL->vertexNodeArr[rightIndex].first = edgeNode;
//
//	PAL->edgeNum += 2;// 边数+=2
//	return true;
//}
//
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
//
//// 方法：【遍历】广度优先算法，通过队列遍历startIndex所在的连通分量
//// 返回BFS遍历序列
//string Breadth_First_Search(const AdjacencyList* PAL, int(*&flagArr)[2], int startIndex) {
//	// 创建队列
//	VertexQueue Q;
//	initQueue(Q);
//	for (int i = 0; i < PAL->vertexNum; i++) {
//		if (flagArr[i][0] == startIndex) {// 入队时，将结点的flag设为1
//			flagArr[i][1] = 1;
//			break;
//		}
//	}
//	enQueue(Q, &(PAL->vertexNodeArr[startIndex].data));// 将指定的初始结点入队
//
//	// 通过队列，进行图的广度优先遍历
//	string str = "";
//	VertexInfo* pv = NULL;
//	EdgeNode* edgeNode = NULL;
//	int index;
//	while (!isEmpty(Q)) {
//		// ①队头元素出队，并加入遍历序列
//		deQueue(Q, pv);
//		index = indexOf(PAL, pv->name);
//		str += PAL->vertexNodeArr[index].data.name;
//
//		// ②将出队元素相邻的(未遍历过的)顶点全部入队（注意：入队时要将顶点的flag设为1）
//		edgeNode = PAL->vertexNodeArr[index].first;
//		while (edgeNode) {
//			for (int i = 0; i < PAL->vertexNum; i++) {// 遍历flagArr
//				if (flagArr[i][0] == edgeNode->vertexIndex) {// 若当前边的结点未遍历过，将该结点入队
//					if (flagArr[i][1] == 0) {
//						flagArr[i][1] = 1;// 入队，则将flag设为1
//						enQueue(Q, &(PAL->vertexNodeArr[edgeNode->vertexIndex].data));
//					}
//					break;
//				}
//			}
//			edgeNode = edgeNode->next;
//		}
//	}
//	destroyQueue(Q);
//	return str;
//}
//
//
//
//// (重载)方法：【遍历】按照邻接表的顺序，广度优先遍历图的全部连通分量
//// 返回BFS遍历序列
//string BFS(const AdjacencyList* PAL) {
//	// 1.创建flagArr二维数组，每个元素表示：{顶点下标, 是否被遍历过}
//	int(*flagArr)[2] = new int[PAL->vertexNum][2];
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
//		if (PAL->vertexNodeArr[i].hasData) {
//			flagArr[j][0] = i;// 存放有效顶点的下标
//			flagArr[j][1] = 0;// 0表示顶点未被遍历
//			j++;
//		}
//	}
//	// 2.对顶点进行广度优先遍历
//	string str = "";
//	int startIndex = -1;
//	while (true) {
//		for (int i = 0; i < PAL->vertexNum; i++) {// 将startIndex设为首个未被遍历的结点下标
//			if (flagArr[i][1] == 0) {
//				startIndex = flagArr[i][0];
//				break;
//			}
//			if (i == PAL->vertexNum - 1) {
//				startIndex = -1;// 若所有结点都被遍历过，将startIndex设为-1
//			}
//		}
//		if (startIndex == -1) {
//			break;
//		}
//		str += Breadth_First_Search(PAL, flagArr, startIndex);
//	}
//	return str;
//}
//
//
//
//// (重载)方法：【遍历】对传入顶点所在的连通分量进行广度优先遍历
//// 返回BFS遍历序列
//string BFS(const AdjacencyList* PAL, string startVertex) {
//	int startIndex = indexOf(PAL, startVertex);
//	if (startIndex == -1) {
//		return "";
//	}
//	int(*flagArr)[2] = new int[PAL->vertexNum][2];// 创建flagArr数组
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
//		if (PAL->vertexNodeArr[i].hasData) {
//			flagArr[j][0] = i;
//			flagArr[j][1] = 0;
//			j++;
//		}
//	}
//	return Breadth_First_Search(PAL, flagArr, startIndex);
//}
//
//
//
//// 方法：【遍历】深度优先算法，通过递归遍历startIndex所在的连通分量
//// 返回DFS遍历序列
//string Depth_First_Search(const AdjacencyList* PAL, int(*&flagArr)[2], int startIndex, string str = "") {
//	// 1.获取当前结点的数据，并将其flag标为1
//	str += PAL->vertexNodeArr[startIndex].data.name;
//	for (int i = 0; i < PAL->vertexNum; i++) {
//		if (flagArr[i][0] == startIndex) {
//			flagArr[i][1] = 1;// 将当前结点flag设为1
//			break;
//		}
//	}
//	// 2.对顶点连接的边进行深度优先遍历
//	EdgeNode* edgeNode = PAL->vertexNodeArr[startIndex].first;
//	while (edgeNode) {// 遍历边链表（优先遍历完一条边联通的全部顶点，再遍历后面的边）
//		for (int i = 0; i < PAL->vertexNum; i++) {
//			if (flagArr[i][0] == edgeNode->vertexIndex) {
//				if (flagArr[i][1] == 0) {// 若边未被遍历过，则对该边进行深度优先遍历
//					str = Depth_First_Search(PAL, flagArr, edgeNode->vertexIndex, str);
//				}
//				break;
//			}
//		}
//		edgeNode = edgeNode->next;
//	}
//	return str;
//}
//
//
//
//// (重载)方法：【遍历】按照邻接表的顺序，深度优先遍历图的全部连通分量
//// 返回DFS遍历序列
//string DFS(const AdjacencyList* PAL) {
//	// 1.创建flagArr数组，记录顶点是否被遍历
//	int(*flagArr)[2] = new int[PAL->vertexNum][2];
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
//		if (PAL->vertexNodeArr[i].hasData) {
//			flagArr[j][0] = i;// 顶点下标
//			flagArr[j][1] = 0;// 是否被遍历
//			j++;
//		}
//	}
//	// 2.对顶点进行深度优先遍历
//	string str = "";
//	int startIndex = -1;
//	while (true) {
//		for (int i = 0; i < PAL->vertexNum; i++) {// 将startIndex设为首个未被遍历的结点下标
//			if (flagArr[i][1] == 0) {
//				startIndex = flagArr[i][0];
//				break;
//			}
//			if (i == PAL->vertexNum - 1) {
//				startIndex = -1;// 若所有结点都被遍历过，将startIndex设为-1
//			}
//		}
//		if (startIndex == -1) {
//			break;
//		}
//		str += Depth_First_Search(PAL, flagArr, startIndex);
//	}
//	return str;
//}
//
//
//
//// (重载)方法：【遍历】对传入顶点所在的连通分量进行深度优先遍历
//// 返回DFS遍历序列
//string DFS(const AdjacencyList* PAL, string startVertex) {
//	int startIndex = indexOf(PAL, startVertex);
//	if (startIndex == -1) {
//		return "";
//	}
//	int(*flagArr)[2] = new int[PAL->vertexNum][2];// 创建flagArr数组
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
//		if (PAL->vertexNodeArr[i].hasData) {
//			flagArr[j][0] = i;
//			flagArr[j][1] = 0;
//			j++;
//		}
//	}
//	return Depth_First_Search(PAL, flagArr, startIndex);
//}
//
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
//				cout << "->" << PAL->vertexNodeArr[p->vertexIndex].data.name << "(i=" << p->vertexIndex << ")";
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
//
//
//int main() {
//	// 【1】图的基础信息
//	// 图的结点信息
//	VertexInfo vertexArr[] = { {"A"},{"B"},{"C"},{"D"},{"E"} };
//	int vertexSZ = sizeof(vertexArr) / sizeof(vertexArr[0]);
//	// 无向图的边
//	string edgeArr[] = { "AB", "AC", "AD", "AE", "BD", "CE" };
//	int edgeSZ = sizeof(edgeArr) / sizeof(edgeArr[0]);
//
//
//
//	// 【2】创建无向图的邻接表
//	AdjacencyList* PAL = createAdjacencyList(vertexArr, vertexSZ, edgeArr, edgeSZ);
//	printAdjacencyList(PAL);
//	cout << "===================================\n\n";
//
//
//
//	// 【3】邻接表的基本操作
//	// ①删除顶点（及其全部边）
//	if (deleteVertex(PAL, "A") && deleteVertex(PAL, "D")) {
//		cout << "顶点删除成功！：" << endl;
//		printAdjacencyList(PAL);
//	}
//	cout << "===================================\n\n";
//
//	// ②添加顶点（优先填补空位）
//	VertexInfo v1 = { "F" };
//	if (addVertex(PAL, v1)) {
//		cout << "顶点添加成功！：" << endl;
//		printAdjacencyList(PAL);
//	}
//	cout << "===================================\n\n";
//
//	// ③添加边
//	if (addEdge(PAL, "FB") && addEdge(PAL, "FE")) {
//		cout << "边添加成功！：" << endl;
//		printAdjacencyList(PAL);
//	}
//	cout << "===================================\n\n";
//
//	// ④删除边
//	if (deleteEdge(PAL, "CE")) {
//		cout << "边删除成功！：" << endl;
//		printAdjacencyList(PAL);
//	}
//	cout << "===================================\n\n";
//
//
//
//
//	// 【4】无向图的遍历操作
//	VertexInfo vertexArr2[] = { {"A"},{"B"},{"C"},{"D"},{"E"},{"F"},{"G"},{"H"},{"I"},{"J"},{"K"} };
//	int vertexSZ2 = sizeof(vertexArr2) / sizeof(vertexArr2[0]);
//	string edgeArr2[] = { "AB", "CD", "AE", "BF", "FC", "CG", "GD", "DH", "FG", "GH", "IJ", "JK", "KI" };
//	int edgeSZ2 = sizeof(edgeArr2) / sizeof(edgeArr2[0]);
//	// 注意：该图为非连通图，包含两个连通分量
//	PAL = createAdjacencyList(vertexArr2, vertexSZ2, edgeArr2, edgeSZ2);
//	printAdjacencyList(PAL);
//	
//	cout << "****************************\n\n";
//	cout << "整个非连通图的广度优先(BFS)序列：" << BFS(PAL) << endl;
//	cout << "B为起始顶点的BFS序列：" << BFS(PAL, "B") << endl;
//	cout << "D为起始顶点的BFS序列：" << BFS(PAL, "D") << endl;
//	cout << "整个非连通图的深度优先(DFS)序列：" << DFS(PAL) << endl;
//	cout << "B为起始顶点的DFS序列：" << DFS(PAL, "B") << endl;
//	cout << "D为起始顶点的DFS序列：" << DFS(PAL, "D") << endl;
//
//	return 0;
//}