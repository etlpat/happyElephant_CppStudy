#include "graph.h"


// 方法：获取结点在邻接表中的下标
int indexOf(const AdjacencyList* ALPointer, const string vertexName) {
	// 循环结束条件：num(遍历的有效结点数)==节点个数/下标到达最大值 
	for (int i = 0, j = 0; j < ALPointer->vertexNum && i < MAX_SIZE; i++) {
		if (ALPointer->vertexNodeArr[i].hasData) {
			j++;
			if (ALPointer->vertexNodeArr[i].data.name == vertexName) {
				return i;
			}
		}
	}
	return -1;
}


// 方法：创建无向图的邻接表
AdjacencyList* createAdjacencyList(const VertexInfo* vertexArr, int vertexSZ, const string* edgeArr, int edgeSZ) {
	// 1.创建邻接表
	AdjacencyList* PAL = new AdjacencyList;
	PAL->vertexNum = vertexSZ;
	PAL->edgeNum = 2 * edgeSZ;
	PAL->vertexNodeArr = new VertexNode[MAX_SIZE];
	// 2.为邻接表的结点数据表赋值
	for (int i = 0; i < vertexSZ; i++) {
		PAL->vertexNodeArr[i].hasData = true;
		PAL->vertexNodeArr[i].data = vertexArr[i];
		PAL->vertexNodeArr[i].first = NULL;
	}
	// 3.为顶点添加边链表
	int leftIndex, rightIndex;
	EdgeNode* edgeNode;
	for (int i = 0; i < edgeSZ; i++) {
		leftIndex = indexOf(PAL, edgeArr[i].substr(0, 1));
		rightIndex = indexOf(PAL, edgeArr[i].substr(1, 1));
		// ①为边的左顶点添加边
		edgeNode = new EdgeNode;
		edgeNode->vertexIndex = rightIndex;
		edgeNode->weight = 1;
		edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
		PAL->vertexNodeArr[leftIndex].first = edgeNode;
		// ②为边的右顶点添加边
		edgeNode = new EdgeNode;
		edgeNode->vertexIndex = leftIndex;
		edgeNode->weight = 1;
		edgeNode->next = PAL->vertexNodeArr[rightIndex].first;
		PAL->vertexNodeArr[rightIndex].first = edgeNode;
	}
	return PAL;
}


// 方法：打印邻接表
void printAdjacencyList(const AdjacencyList* PAL) {
	cout << "结点数：" << PAL->vertexNum << "， 边数：" << PAL->edgeNum << endl;
	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
		if (PAL->vertexNodeArr[i].hasData) {
			cout << "index:" << i << ", key:" + PAL->vertexNodeArr[i].data.name << " ";// i表示真实下标
			EdgeNode* p = PAL->vertexNodeArr[i].first;
			while (p) {
				cout << "->" << PAL->vertexNodeArr[p->vertexIndex].data.name << "(i=" << p->vertexIndex << ")";
				p = p->next;
			}
			cout << endl;
			j++;// 已遍历的有效结点数++
		}
	}
}


// 方法：广度优先算法，通过队列遍历startIndex所在的连通分量，返回BFS遍历序列
string Breadth_First_Search(const AdjacencyList* PAL, int(*&flagArr)[2], int startIndex) {
	// 1.创建队列
	VertexQueue Q;
	initQueue(Q);
	enQueue(Q, &(PAL->vertexNodeArr[startIndex].data));// 初始节点入队
	for (int i = 0; i < PAL->vertexNum; i++) {
		if (flagArr[i][0] == startIndex) {
			flagArr[i][1] = 1;
			break;
		}
	}
	// 2.通过队列，进行图的广度优先遍历
	string str = "";
	VertexInfo* pv = NULL;
	EdgeNode* edgeNode = NULL;
	int index;
	while (!isEmpty(Q)) {
		// ①队头元素出队，并加入遍历序列
		deQueue(Q, pv);
		index = indexOf(PAL, pv->name);
		str += PAL->vertexNodeArr[index].data.name;
		// ②将出队元素相邻的(未遍历过的)顶点全部入队
		edgeNode = PAL->vertexNodeArr[index].first;
		while (edgeNode) {
			for (int i = 0; i < PAL->vertexNum; i++) {
				if (flagArr[i][0] == edgeNode->vertexIndex) {
					if (flagArr[i][1] == 0) {
						flagArr[i][1] = 1;
						enQueue(Q, &(PAL->vertexNodeArr[edgeNode->vertexIndex].data));
					}
					break;
				}
			}
			edgeNode = edgeNode->next;
		}
	}
	destroyQueue(Q);
	return str;
}


// 方法：广度优先遍历求图的连通分量个数
int getConnectedComponentNum_BFS(const AdjacencyList* PAL) {
	// 1.创建flagArr二维数组，每个元素表示：{顶点下标, 是否被遍历过}
	int(*flagArr)[2] = new int[PAL->vertexNum][2];
	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
		if (PAL->vertexNodeArr[i].hasData) {
			flagArr[j][0] = i;
			flagArr[j][1] = 0;
			j++;
		}
	}
	// 2.对顶点进行广度优先遍历
	int startIndex = -1, count = 0;
	while (true) {
		for (int i = 0; i < PAL->vertexNum; i++) {// 将startIndex设为首个未被遍历的结点下标
			if (flagArr[i][1] == 0) {
				startIndex = flagArr[i][0];
				break;
			}
			if (i == PAL->vertexNum - 1) {
				startIndex = -1;// 若所有结点都被遍历过，将startIndex设为-1
			}
		}
		if (startIndex == -1) {
			break;
		}
		count++;
		cout << "连通分量" << count << "：" << Breadth_First_Search(PAL, flagArr, startIndex) << endl;
	}
	return count;
}


// 方法：深度优先算法，通过递归遍历startIndex所在的连通分量，返回DFS遍历序列
string Depth_First_Search(const AdjacencyList* PAL, int(*&flagArr)[2], int startIndex, string str = "") {
	// 1.获取当前结点的数据，并将其flag标为1
	str += PAL->vertexNodeArr[startIndex].data.name;
	for (int i = 0; i < PAL->vertexNum; i++) {
		if (flagArr[i][0] == startIndex) {
			flagArr[i][1] = 1;
			break;
		}
	}
	// 2.对顶点连接的边进行深度优先遍历
	EdgeNode* edgeNode = PAL->vertexNodeArr[startIndex].first;
	while (edgeNode) {
		for (int i = 0; i < PAL->vertexNum; i++) {
			if (flagArr[i][0] == edgeNode->vertexIndex) {// 优先遍历完一条边联通的全部顶点，再遍历后面的边
				if (flagArr[i][1] == 0) {
					str = Depth_First_Search(PAL, flagArr, edgeNode->vertexIndex, str);
				}
				break;
			}
		}
		edgeNode = edgeNode->next;
	}
	return str;
}


// 方法：深度优先遍历，判断两结点是否在同一连通分量中
bool isInSameConnectedComponent_DFS(const AdjacencyList* PAL, string startVertex1, string startVertex2) {
	int firstIndex = indexOf(PAL, startVertex1);
	int secondIndex = indexOf(PAL, startVertex2);
	if (firstIndex == -1 || secondIndex == -1) {
		return "";
	}
	int(*flagArr)[2] = new int[PAL->vertexNum][2];// 创建flagArr数组
	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
		if (PAL->vertexNodeArr[i].hasData) {
			flagArr[j][0] = i;
			flagArr[j][1] = 0;
			j++;
		}
	}
	string str = Depth_First_Search(PAL, flagArr, firstIndex);
	cout << startVertex1 << "所在的联通分量是：" << str << endl;
	for (int i = 0; i < str.length(); i++) {
		if (startVertex2 == str.substr(i, 1)) {
			return true;
		}
	}
	return false;
}




int main() {
	// (1)无向非联通图的基础信息
	// ①图的顶点
	VertexInfo vertexArr[] = { {"A"},{"B"},{"C"},{"D"},{"E"},{"F"},{"G"},{"H"},{"I"},{"J"},{"K"} };
	int vertexSZ = sizeof(vertexArr) / sizeof(vertexArr[0]);
	// ②图的边
	string edgeArr[] = { "AB", "CD", "AE", "BF", "FC", "CG", "GD", "DH", "FG", "GH", "IJ", "JK", "KI" };
	int edgeSZ = sizeof(edgeArr) / sizeof(edgeArr[0]);


	// (2)创建邻接表
	AdjacencyList* PAL  = createAdjacencyList(vertexArr, vertexSZ, edgeArr, edgeSZ);
	printAdjacencyList(PAL);
	cout << "============================================\n\n\n";
	

	// (3)获取图的连通分量个数
	int num = getConnectedComponentNum_BFS(PAL);
	cout << "图的连通分量个数为：" << num << endl;
	cout << "============================================\n\n\n";


	// (4)判断两个结点间是否有路径相连
	bool flag = isInSameConnectedComponent_DFS(PAL, "A", "E");
	cout << "A、E是有边相连？" << (flag == 1 ? "YES" : "NO") << endl << endl;
	flag = isInSameConnectedComponent_DFS(PAL, "I", "A");
	cout << "I、A是有边相连？" << (flag == 1 ? "YES" : "NO") << endl;


	return 0;
}