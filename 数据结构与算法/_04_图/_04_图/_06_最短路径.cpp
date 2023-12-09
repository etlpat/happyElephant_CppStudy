#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 100
#define MAX_DISTANCE 65535



// ���·��
//
// (1)ע������
//	���·��������Ȩ(��ͨ)ͼ��ȫ�����㵽ĳһָ���������С·��
//	����ͳһ�������Ȩͼ�����·������Щ�㷨������ͼҲ��Ч
// 
// 
// (2)Dijkstra�㷨
//	���Ͻ�˹�����㷨���������ڼ�Ȩͼ�в��Ҵ�Դ�ڵ㵽�������нڵ�����·�����㷨��
//	������˼�룺��Դ�ڵ㿪ʼ��ͨ������ȷ��·����̵Ľڵ㣬�����»�δȷ���Ľڵ�ľ���ֵ�������ҵ���Դ�ڵ㵽Ŀ��ڵ�����·����
//	��ע�⣺�Ͻ�˹�����㷨���ܴ�����и�Ȩ�صıߡ�
//	��ʵ��˼·��
//		1.��ʼ��������һ�����·�����飬�������ÿ��Ԫ�ض�����һ���ڵ㡣Ԫ������Ҫ��ţ���ǰ�ڵ㵽Դ�ڵ�����·������ǰ�ڵ������·���ϵ�ǰ���ڵ��...
//				  ��Դ�ڵ�ĳ�ʼ��������Ϊ0�������������ڵ�ĳ�ʼ��������Ϊ����� 
//		2.�����������·�����飺ÿ��ѭ������������ȡ·����̵Ľڵ㣬֮�������ýڵ����ڵĽ�㵽Դ�ڵ�����·����
//		3.��ֹ����������ȡ��ȫ���ڵ�����·�����㷨������





// ������Ϣ
struct VertexInfo {
	string name;
};

// ����Ϣ
struct EdgeInfo {
	string name;
	double weight = 0;
};

// ������Ľ��
struct EdgeNode {
	int vertexIndex = -1;
	double weight = 0;
	EdgeNode* next = NULL;
};

// ����Ľ��
struct VertexNode {
	bool hasData = false;
	VertexInfo data;
	EdgeNode* first = NULL;
};

// �ڽӱ�
struct AdjacencyList {
	VertexNode* vertexNodeArr;// ��������
	int vertexNum;// �����
	int edgeNum;// ����
};


// ���������顿��ȡ������ڽӱ��е��±�
int indexOf(const AdjacencyList* PAL, const string vertexName) {
	// i���ڽӱ��е�ʵ���±�	j���ѱ����Ķ������
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


// ���������顿��ȡ�ڽӱ����±��Ӧ�Ķ�����
string getVertexName(const AdjacencyList* PAL, int index) {
	if (index < 0 || index >= MAX_SIZE || !PAL->vertexNodeArr[index].hasData) {
		return "";
	}
	return  PAL->vertexNodeArr[index].data.name;
}


// ��������������ͼ�ڽӱ�
AdjacencyList* createAdjacencyList(const VertexInfo* vertexArr, int vertexSZ, const EdgeInfo* edgeArr, int edgeSZ) {
	AdjacencyList* PAL = new AdjacencyList;
	PAL->vertexNum = vertexSZ;
	PAL->edgeNum = 2 * edgeSZ;
	PAL->vertexNodeArr = new VertexNode[MAX_SIZE];
	// 1.Ϊ����������Ϣ
	for (int i = 0; i < vertexSZ; i++) {
		PAL->vertexNodeArr[i].data = vertexArr[i];
		PAL->vertexNodeArr[i].hasData = true;
		PAL->vertexNodeArr[i].first = NULL;
	}
	// 2.��ӱ�����
	int leftIndex, rightIndex;
	EdgeNode* edgeNode;
	for (int i = 0; i < edgeSZ; i++) {
		leftIndex = indexOf(PAL, edgeArr[i].name.substr(0, 1));
		rightIndex = indexOf(PAL, edgeArr[i].name.substr(1, 1));
		// Ϊ�󶥵���ӱ�
		edgeNode = new EdgeNode;
		edgeNode->vertexIndex = rightIndex;
		edgeNode->weight = edgeArr[i].weight;
		edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
		PAL->vertexNodeArr[leftIndex].first = edgeNode;
		// Ϊ�Ҷ�����ӱ�
		edgeNode = new EdgeNode;
		edgeNode->vertexIndex = leftIndex;
		edgeNode->weight = edgeArr[i].weight;
		edgeNode->next = PAL->vertexNodeArr[rightIndex].first;
		PAL->vertexNodeArr[rightIndex].first = edgeNode;
	}
	return PAL;
}


// ��������ӡ��Ȩ�ڽӱ�
void printAdjacencyList(const AdjacencyList* PAL) {
	cout << "�������" << PAL->vertexNum << "�� ������" << PAL->edgeNum << endl;
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



// Dijkstra�㷨�У�������·����Ϣ������Ԫ��
struct shortestPathNode {
	int vertexIndex;// ��ǰ����±�
	bool isAdd;		// �Ƿ����
	double shortestDistance;// (�����ʼ����)��̾���
	int preVertexIndex;// (���·����)ǰ��������±�
};


// �����������·��������ݴ�ӡ����
// ˼·������ջ���Ƚ�������ȴ����յ㣬Ȼ�����δ�����ǰ��������ջ��˳����Ǵ���㵽�յ������
void printShortestPathArr(const AdjacencyList* PAL, const shortestPathNode* shortestPathArr, int startIndex) {
	int* stack = new int[PAL->vertexNum];
	int stackSZ = 0, shortestPathArrIndex;
	cout << "��ʼ����\"" << PAL->vertexNodeArr[shortestPathArr[startIndex].vertexIndex].data.name << "\"������������·�����£�" << endl;
	for (int i = 0; i < PAL->vertexNum; i++) {
		// 1.�Ƚ����ֵĶ����±���ջ
		stack[0] = shortestPathArr[i].vertexIndex;
		stackSZ = 1;
		shortestPathArrIndex = i;
		// 2.�������ǰ���±겻Ϊ-1����ǰ����ջ��ֱ��û��ǰ��Ϊֹ
		while (shortestPathArr[shortestPathArrIndex].preVertexIndex != -1) {
			shortestPathArrIndex = shortestPathArr[shortestPathArrIndex].preVertexIndex;
			stack[stackSZ] = shortestPathArr[shortestPathArrIndex].vertexIndex;
			stackSZ++;
		}
		// 3.��ӡ���·����Ϣ
		cout << "����\"" << getVertexName(PAL, shortestPathArr[i].vertexIndex) << 
			"\"�� ·�����ȣ�" << shortestPathArr[i].shortestDistance << "�� ���·����";
		while (stackSZ--) {// ��ջ˳����ʼ����->���ֶ���
			cout << getVertexName(PAL, stack[stackSZ]);
		}
		cout << endl;
	}
	delete[] stack;
}


// ������Dijkstra�㷨�����·��
// ���㷨ͨ������һ��shortestPathArr(���·������)������ȡ�����㵽ָ����������·���Լ�ǰ������
bool ShortestPath_Dijkstra(const AdjacencyList* PAL, const string startVertex) {
	int startIndex = indexOf(PAL, startVertex);
	if (startIndex == -1) {
		return false;
	}
	// 1.�������·����Ϣ����
	shortestPathNode* shortestPathArr = new shortestPathNode[PAL->vertexNum];
	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
		if (startIndex == i) {
			// ���ڽӱ����ʼ�����±꣬��Ϊ���·����shortestPathArr�ж�Ӧ���±�
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

	// 2.����ѭ���������·����ֱ����ȡÿ����������ʼ��������·��
	//	ע�⣺���ջ�õ����·����Ϣ���������shortestPathArr��
	double shortestDistance;
	int shortestDistanceIndex;
	EdgeNode* edgeNode;
	for (int i = 0; i < PAL->vertexNum; i++) {
		// �ٻ�ȡ���ֻ�δ����ӵ����·���Ķ���
		shortestDistance = MAX_DISTANCE;
		for (int j = 0; j < PAL->vertexNum; j++) {// �ҳ�������δ������Ҿ�����̵Ķ���
			if (!shortestPathArr[j].isAdd && shortestPathArr[j].shortestDistance < shortestDistance) {
				shortestDistance = shortestPathArr[j].shortestDistance;
				shortestDistanceIndex = j;
			}
		}
		if (shortestDistance == MAX_DISTANCE) {// �����·�����л�û�м�¼���㣬���¼��ʼ���
			shortestPathArr[startIndex].shortestDistance = 0;
			shortestDistanceIndex = startIndex;
		}

		// �ڽ�������·����̵Ķ����isAdd������Ϊtrue
		shortestPathArr[shortestDistanceIndex].isAdd = true;

		// �۸�����ö������ڵ�δ����ӵĶ��㣨�����ھӶ�������·����ǰ����
		edgeNode = PAL->vertexNodeArr[shortestPathArr[shortestDistanceIndex].vertexIndex].first;
		while (edgeNode) {
			for (int j = 0; j < PAL->vertexNum; j++) {
				if (edgeNode->vertexIndex == shortestPathArr[j].vertexIndex) {// �ҵ��߽���Ӧ��shortestPathArrԪ��
					if (!shortestPathArr[j].isAdd && // ���ñ߶���δ����� �� (��ʼ���㾭��������ӵĶ��㵽�ﵱǰ�߽������·�� < �߽��֮ǰ�����·��)
						shortestPathArr[shortestDistanceIndex].shortestDistance + edgeNode->weight < shortestPathArr[j].shortestDistance) {
						// ���±߽������·����ǰ��
						shortestPathArr[j].shortestDistance = shortestPathArr[shortestDistanceIndex].shortestDistance + edgeNode->weight;
						shortestPathArr[j].preVertexIndex = shortestPathArr[shortestDistanceIndex].vertexIndex;// ǰ����Ϊ������ӵ����·������
					}
					break;
				}
			}
			edgeNode = edgeNode->next;
		}
	}

	// 3.��ӡ���·����Ϣ
	printShortestPathArr(PAL, shortestPathArr, startIndex);
	delete[] shortestPathArr;
	return true;
}




int main() {
	// (1)ͼ�Ļ�����Ϣ
	VertexInfo vertexArr[] = { {"A"},{"B"},{"C"},{"D"},{"E"},{"F"},{"G"},{"H"},{"I"} };
	int vertexSZ = sizeof(vertexArr) / sizeof(vertexArr[0]);
	EdgeInfo edgeArr[] = { {"AB",1},{"AC",5},{"BC",3},{"BD",7},{"BE",5},{"CE",1},{"CF",7},
		{"DE",2},{"EF",3},{"DG",3},{"EG",6},{"EH",9},{"FH",5},{"GH",2},{"GI",7},{"HI",4} };
	int edgeSZ = sizeof(edgeArr) / sizeof(edgeArr[0]);


	// (2)�����ڽӱ�
	AdjacencyList* PAL = createAdjacencyList(vertexArr, vertexSZ, edgeArr, edgeSZ);
	printAdjacencyList(PAL);
	cout << "=============================================\n\n";


	// (3)Dijkstra�㷨��ͼ�����·��
	// �����㵽A�����·��
	ShortestPath_Dijkstra(PAL, "A");
	cout << "\n=============================================\n";
	// �����㵽E�����·��
	ShortestPath_Dijkstra(PAL, "E");

	return 0;
}