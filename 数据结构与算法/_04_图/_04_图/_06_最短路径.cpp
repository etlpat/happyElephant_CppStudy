#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 100
#define MAX_DISTANCE 65535



// 最短路径
//
// (1)注意事项
//	最短路径：即带权(联通)图中全部顶点到某一指定顶点的最小路径
//	这里统一对无向带权图求最短路径，这些算法对有向图也生效
// 
// 
// (2)Dijkstra算法
//	·迪杰斯特拉算法：是用于在加权图中查找从源节点到其他所有节点的最短路径的算法。
//	·基本思想：从源节点开始，通过不断确定路径最短的节点，并更新还未确定的节点的距离值，最终找到从源节点到目标节点的最短路径。
//	·注意：迪杰斯特拉算法不能处理带有负权重的边。
//	·实现思路：
//		1.初始化：创建一个最短路径数组，该数组的每个元素都代表一个节点。元素内需要存放：当前节点到源节点的最短路径、当前节点在最短路径上的前驱节点等...
//				  将源节点的初始距离设置为0，将所有其他节点的初始距离设置为无穷大。 
//		2.迭代更新最短路径数组：每轮循环从数组中提取路径最短的节点，之后更新与该节点相邻的结点到源节点的最短路径。
//		3.终止条件：当获取到全部节点的最短路径后，算法结束。





// 顶点信息
struct VertexInfo {
	string name;
};

// 边信息
struct EdgeInfo {
	string name;
	double weight = 0;
};

// 边链表的结点
struct EdgeNode {
	int vertexIndex = -1;
	double weight = 0;
	EdgeNode* next = NULL;
};

// 结点表的结点
struct VertexNode {
	bool hasData = false;
	VertexInfo data;
	EdgeNode* first = NULL;
};

// 邻接表
struct AdjacencyList {
	VertexNode* vertexNodeArr;// 结点表数组
	int vertexNum;// 结点数
	int edgeNum;// 边数
};


// 方法：【查】获取结点在邻接表中的下标
int indexOf(const AdjacencyList* PAL, const string vertexName) {
	// i：邻接表中的实际下标	j：已遍历的顶点个数
	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
		if (PAL->vertexNodeArr[i].hasData) {
			if (PAL->vertexNodeArr[i].data.name == vertexName) {
				return i;
			}
			j++;
		}
	}
	return -1;
}


// 方法：【查】获取邻接表中下标对应的顶点名
string getVertexName(const AdjacencyList* PAL, int index) {
	if (index < 0 || index >= MAX_SIZE || !PAL->vertexNodeArr[index].hasData) {
		return "";
	}
	return  PAL->vertexNodeArr[index].data.name;
}


// 方法：创建无向图邻接表
AdjacencyList* createAdjacencyList(const VertexInfo* vertexArr, int vertexSZ, const EdgeInfo* edgeArr, int edgeSZ) {
	AdjacencyList* PAL = new AdjacencyList;
	PAL->vertexNum = vertexSZ;
	PAL->edgeNum = 2 * edgeSZ;
	PAL->vertexNodeArr = new VertexNode[MAX_SIZE];
	// 1.为顶点表添加信息
	for (int i = 0; i < vertexSZ; i++) {
		PAL->vertexNodeArr[i].data = vertexArr[i];
		PAL->vertexNodeArr[i].hasData = true;
		PAL->vertexNodeArr[i].first = NULL;
	}
	// 2.添加边链表
	int leftIndex, rightIndex;
	EdgeNode* edgeNode;
	for (int i = 0; i < edgeSZ; i++) {
		leftIndex = indexOf(PAL, edgeArr[i].name.substr(0, 1));
		rightIndex = indexOf(PAL, edgeArr[i].name.substr(1, 1));
		// 为左顶点添加边
		edgeNode = new EdgeNode;
		edgeNode->vertexIndex = rightIndex;
		edgeNode->weight = edgeArr[i].weight;
		edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
		PAL->vertexNodeArr[leftIndex].first = edgeNode;
		// 为右顶点添加边
		edgeNode = new EdgeNode;
		edgeNode->vertexIndex = leftIndex;
		edgeNode->weight = edgeArr[i].weight;
		edgeNode->next = PAL->vertexNodeArr[rightIndex].first;
		PAL->vertexNodeArr[rightIndex].first = edgeNode;
	}
	return PAL;
}


// 方法：打印带权邻接表
void printAdjacencyList(const AdjacencyList* PAL) {
	cout << "结点数：" << PAL->vertexNum << "， 边数：" << PAL->edgeNum << endl;
	EdgeNode* p;
	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
		if (PAL->vertexNodeArr[i].hasData) {
			cout << "index:" << i << ", key:" + PAL->vertexNodeArr[i].data.name << " ";
			p = PAL->vertexNodeArr[i].first;
			while (p) {
				cout << "->" << PAL->vertexNodeArr[p->vertexIndex].data.name << "(" << p->weight << ")";
				p = p->next;
			}
			cout << endl;
			j++;
		}
	}
}



// Dijkstra算法中，存放最短路径信息的数组元素
struct shortestPathNode {
	int vertexIndex;// 当前结点下标
	bool isAdd;		// 是否被添加
	double shortestDistance;// (距离初始结点的)最短距离
	int preVertexIndex;// (最短路径上)前驱顶点的下标
};


// 方法：将最短路径表的内容打印出来
// 思路：利用栈的先进后出。先存入终点，然后依次存入其前驱，最后出栈的顺序就是从起点到终点的序列
void printShortestPathArr(const AdjacencyList* PAL, const shortestPathNode* shortestPathArr, int startIndex) {
	int* stack = new int[PAL->vertexNum];
	int stackSZ = 0, shortestPathArrIndex;
	cout << "起始顶点\"" << PAL->vertexNodeArr[shortestPathArr[startIndex].vertexIndex].data.name << "\"到各顶点的最短路径如下：" << endl;
	for (int i = 0; i < PAL->vertexNum; i++) {
		// 1.先将本轮的顶点下标入栈
		stack[0] = shortestPathArr[i].vertexIndex;
		stackSZ = 1;
		shortestPathArrIndex = i;
		// 2.若顶点的前驱下标不为-1，将前驱入栈，直到没有前驱为止
		while (shortestPathArr[shortestPathArrIndex].preVertexIndex != -1) {
			shortestPathArrIndex = shortestPathArr[shortestPathArrIndex].preVertexIndex;
			stack[stackSZ] = shortestPathArr[shortestPathArrIndex].vertexIndex;
			stackSZ++;
		}
		// 3.打印最短路径信息
		cout << "顶点\"" << getVertexName(PAL, shortestPathArr[i].vertexIndex) << 
			"\"， 路径长度：" << shortestPathArr[i].shortestDistance << "， 最短路径：";
		while (stackSZ--) {// 出栈顺序：起始顶点->本轮顶点
			cout << getVertexName(PAL, stack[stackSZ]);
		}
		cout << endl;
	}
	delete[] stack;
}


// 方法：Dijkstra算法求最短路径
// 该算法通过操作一个shortestPathArr(最短路径数组)，来获取各顶点到指定顶点的最短路径以及前驱顶点
bool ShortestPath_Dijkstra(const AdjacencyList* PAL, const string startVertex) {
	int startIndex = indexOf(PAL, startVertex);
	if (startIndex == -1) {
		return false;
	}
	// 1.创建最短路径信息数组
	shortestPathNode* shortestPathArr = new shortestPathNode[PAL->vertexNum];
	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
		if (startIndex == i) {
			// 将邻接表的起始顶点下标，改为最短路径表shortestPathArr中对应的下标
			startIndex = j;
		}
		if (PAL->vertexNodeArr[i].hasData) {
			shortestPathArr[j].vertexIndex = i;
			shortestPathArr[j].isAdd = false;
			shortestPathArr[j].shortestDistance = MAX_DISTANCE;
			shortestPathArr[j].preVertexIndex = -1;
			j++;
		}
	}

	// 2.不断循环更新最短路径表，直到获取每个顶点距离初始顶点的最短路径
	//	注意：最终获得的最短路径信息，都存放在shortestPathArr中
	double shortestDistance;
	int shortestDistanceIndex;
	EdgeNode* edgeNode;
	for (int i = 0; i < PAL->vertexNum; i++) {
		// ①获取本轮还未被添加的最短路径的顶点
		shortestDistance = MAX_DISTANCE;
		for (int j = 0; j < PAL->vertexNum; j++) {// 找出本轮中未被添加且距离最短的顶点
			if (!shortestPathArr[j].isAdd && shortestPathArr[j].shortestDistance < shortestDistance) {
				shortestDistance = shortestPathArr[j].shortestDistance;
				shortestDistanceIndex = j;
			}
		}
		if (shortestDistance == MAX_DISTANCE) {// 若最短路径表中还没有记录顶点，则记录初始结点
			shortestPathArr[startIndex].shortestDistance = 0;
			shortestDistanceIndex = startIndex;
		}

		// ②将本轮中路径最短的顶点的isAdd属性设为true
		shortestPathArr[shortestDistanceIndex].isAdd = true;

		// ③更新与该顶点相邻的未被添加的顶点（更新邻居顶点的最短路径和前驱）
		edgeNode = PAL->vertexNodeArr[shortestPathArr[shortestDistanceIndex].vertexIndex].first;
		while (edgeNode) {
			for (int j = 0; j < PAL->vertexNum; j++) {
				if (edgeNode->vertexIndex == shortestPathArr[j].vertexIndex) {// 找到边结点对应的shortestPathArr元素
					if (!shortestPathArr[j].isAdd && // 若该边顶点未被添加 且 (初始顶点经过本次添加的顶点到达当前边结点的最短路径 < 边结点之前的最短路径)
						shortestPathArr[shortestDistanceIndex].shortestDistance + edgeNode->weight < shortestPathArr[j].shortestDistance) {
						// 更新边结点的最短路径和前驱
						shortestPathArr[j].shortestDistance = shortestPathArr[shortestDistanceIndex].shortestDistance + edgeNode->weight;
						shortestPathArr[j].preVertexIndex = shortestPathArr[shortestDistanceIndex].vertexIndex;// 前驱变为本轮添加的最短路径顶点
					}
					break;
				}
			}
			edgeNode = edgeNode->next;
		}
	}

	// 3.打印最短路径信息
	printShortestPathArr(PAL, shortestPathArr, startIndex);
	delete[] shortestPathArr;
	return true;
}




int main() {
	// (1)图的基本信息
	VertexInfo vertexArr[] = { {"A"},{"B"},{"C"},{"D"},{"E"},{"F"},{"G"},{"H"},{"I"} };
	int vertexSZ = sizeof(vertexArr) / sizeof(vertexArr[0]);
	EdgeInfo edgeArr[] = { {"AB",1},{"AC",5},{"BC",3},{"BD",7},{"BE",5},{"CE",1},{"CF",7},
		{"DE",2},{"EF",3},{"DG",3},{"EG",6},{"EH",9},{"FH",5},{"GH",2},{"GI",7},{"HI",4} };
	int edgeSZ = sizeof(edgeArr) / sizeof(edgeArr[0]);


	// (2)创建邻接表
	AdjacencyList* PAL = createAdjacencyList(vertexArr, vertexSZ, edgeArr, edgeSZ);
	printAdjacencyList(PAL);
	cout << "=============================================\n\n";


	// (3)Dijkstra算法求图的最短路径
	// 各顶点到A的最短路径
	ShortestPath_Dijkstra(PAL, "A");
	cout << "\n=============================================\n";
	// 各顶点到E的最短路径
	ShortestPath_Dijkstra(PAL, "E");

	return 0;
}