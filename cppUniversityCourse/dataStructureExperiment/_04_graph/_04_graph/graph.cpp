#include "graph.h"


// ��������ȡ������ڽӱ��е��±�
int indexOf(const AdjacencyList* ALPointer, const string vertexName) {
	// ѭ������������num(��������Ч�����)==�ڵ����/�±굽�����ֵ 
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


// ��������������ͼ���ڽӱ�
AdjacencyList* createAdjacencyList(const VertexInfo* vertexArr, int vertexSZ, const string* edgeArr, int edgeSZ) {
	// 1.�����ڽӱ�
	AdjacencyList* PAL = new AdjacencyList;
	PAL->vertexNum = vertexSZ;
	PAL->edgeNum = 2 * edgeSZ;
	PAL->vertexNodeArr = new VertexNode[MAX_SIZE];
	// 2.Ϊ�ڽӱ�Ľ�����ݱ�ֵ
	for (int i = 0; i < vertexSZ; i++) {
		PAL->vertexNodeArr[i].hasData = true;
		PAL->vertexNodeArr[i].data = vertexArr[i];
		PAL->vertexNodeArr[i].first = NULL;
	}
	// 3.Ϊ������ӱ�����
	int leftIndex, rightIndex;
	EdgeNode* edgeNode;
	for (int i = 0; i < edgeSZ; i++) {
		leftIndex = indexOf(PAL, edgeArr[i].substr(0, 1));
		rightIndex = indexOf(PAL, edgeArr[i].substr(1, 1));
		// ��Ϊ�ߵ��󶥵���ӱ�
		edgeNode = new EdgeNode;
		edgeNode->vertexIndex = rightIndex;
		edgeNode->weight = 1;
		edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
		PAL->vertexNodeArr[leftIndex].first = edgeNode;
		// ��Ϊ�ߵ��Ҷ�����ӱ�
		edgeNode = new EdgeNode;
		edgeNode->vertexIndex = leftIndex;
		edgeNode->weight = 1;
		edgeNode->next = PAL->vertexNodeArr[rightIndex].first;
		PAL->vertexNodeArr[rightIndex].first = edgeNode;
	}
	return PAL;
}


// ��������ӡ�ڽӱ�
void printAdjacencyList(const AdjacencyList* PAL) {
	cout << "�������" << PAL->vertexNum << "�� ������" << PAL->edgeNum << endl;
	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
		if (PAL->vertexNodeArr[i].hasData) {
			cout << "index:" << i << ", key:" + PAL->vertexNodeArr[i].data.name << " ";// i��ʾ��ʵ�±�
			EdgeNode* p = PAL->vertexNodeArr[i].first;
			while (p) {
				cout << "->" << PAL->vertexNodeArr[p->vertexIndex].data.name << "(i=" << p->vertexIndex << ")";
				p = p->next;
			}
			cout << endl;
			j++;// �ѱ�������Ч�����++
		}
	}
}


// ��������������㷨��ͨ�����б���startIndex���ڵ���ͨ����������BFS��������
string Breadth_First_Search(const AdjacencyList* PAL, int(*&flagArr)[2], int startIndex) {
	// 1.��������
	VertexQueue Q;
	initQueue(Q);
	enQueue(Q, &(PAL->vertexNodeArr[startIndex].data));// ��ʼ�ڵ����
	for (int i = 0; i < PAL->vertexNum; i++) {
		if (flagArr[i][0] == startIndex) {
			flagArr[i][1] = 1;
			break;
		}
	}
	// 2.ͨ�����У�����ͼ�Ĺ�����ȱ���
	string str = "";
	VertexInfo* pv = NULL;
	EdgeNode* edgeNode = NULL;
	int index;
	while (!isEmpty(Q)) {
		// �ٶ�ͷԪ�س��ӣ��������������
		deQueue(Q, pv);
		index = indexOf(PAL, pv->name);
		str += PAL->vertexNodeArr[index].data.name;
		// �ڽ�����Ԫ�����ڵ�(δ��������)����ȫ�����
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


// ������������ȱ�����ͼ����ͨ��������
int getConnectedComponentNum_BFS(const AdjacencyList* PAL) {
	// 1.����flagArr��ά���飬ÿ��Ԫ�ر�ʾ��{�����±�, �Ƿ񱻱�����}
	int(*flagArr)[2] = new int[PAL->vertexNum][2];
	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
		if (PAL->vertexNodeArr[i].hasData) {
			flagArr[j][0] = i;
			flagArr[j][1] = 0;
			j++;
		}
	}
	// 2.�Զ�����й�����ȱ���
	int startIndex = -1, count = 0;
	while (true) {
		for (int i = 0; i < PAL->vertexNum; i++) {// ��startIndex��Ϊ�׸�δ�������Ľ���±�
			if (flagArr[i][1] == 0) {
				startIndex = flagArr[i][0];
				break;
			}
			if (i == PAL->vertexNum - 1) {
				startIndex = -1;// �����н�㶼������������startIndex��Ϊ-1
			}
		}
		if (startIndex == -1) {
			break;
		}
		count++;
		cout << "��ͨ����" << count << "��" << Breadth_First_Search(PAL, flagArr, startIndex) << endl;
	}
	return count;
}


// ��������������㷨��ͨ���ݹ����startIndex���ڵ���ͨ����������DFS��������
string Depth_First_Search(const AdjacencyList* PAL, int(*&flagArr)[2], int startIndex, string str = "") {
	// 1.��ȡ��ǰ�������ݣ�������flag��Ϊ1
	str += PAL->vertexNodeArr[startIndex].data.name;
	for (int i = 0; i < PAL->vertexNum; i++) {
		if (flagArr[i][0] == startIndex) {
			flagArr[i][1] = 1;
			break;
		}
	}
	// 2.�Զ������ӵı߽���������ȱ���
	EdgeNode* edgeNode = PAL->vertexNodeArr[startIndex].first;
	while (edgeNode) {
		for (int i = 0; i < PAL->vertexNum; i++) {
			if (flagArr[i][0] == edgeNode->vertexIndex) {// ���ȱ�����һ������ͨ��ȫ�����㣬�ٱ�������ı�
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


// ������������ȱ������ж�������Ƿ���ͬһ��ͨ������
bool isInSameConnectedComponent_DFS(const AdjacencyList* PAL, string startVertex1, string startVertex2) {
	int firstIndex = indexOf(PAL, startVertex1);
	int secondIndex = indexOf(PAL, startVertex2);
	if (firstIndex == -1 || secondIndex == -1) {
		return "";
	}
	int(*flagArr)[2] = new int[PAL->vertexNum][2];// ����flagArr����
	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
		if (PAL->vertexNodeArr[i].hasData) {
			flagArr[j][0] = i;
			flagArr[j][1] = 0;
			j++;
		}
	}
	string str = Depth_First_Search(PAL, flagArr, firstIndex);
	cout << startVertex1 << "���ڵ���ͨ�����ǣ�" << str << endl;
	for (int i = 0; i < str.length(); i++) {
		if (startVertex2 == str.substr(i, 1)) {
			return true;
		}
	}
	return false;
}




int main() {
	// (1)�������ͨͼ�Ļ�����Ϣ
	// ��ͼ�Ķ���
	VertexInfo vertexArr[] = { {"A"},{"B"},{"C"},{"D"},{"E"},{"F"},{"G"},{"H"},{"I"},{"J"},{"K"} };
	int vertexSZ = sizeof(vertexArr) / sizeof(vertexArr[0]);
	// ��ͼ�ı�
	string edgeArr[] = { "AB", "CD", "AE", "BF", "FC", "CG", "GD", "DH", "FG", "GH", "IJ", "JK", "KI" };
	int edgeSZ = sizeof(edgeArr) / sizeof(edgeArr[0]);


	// (2)�����ڽӱ�
	AdjacencyList* PAL  = createAdjacencyList(vertexArr, vertexSZ, edgeArr, edgeSZ);
	printAdjacencyList(PAL);
	cout << "============================================\n\n\n";
	

	// (3)��ȡͼ����ͨ��������
	int num = getConnectedComponentNum_BFS(PAL);
	cout << "ͼ����ͨ��������Ϊ��" << num << endl;
	cout << "============================================\n\n\n";


	// (4)�ж����������Ƿ���·������
	bool flag = isInSameConnectedComponent_DFS(PAL, "A", "E");
	cout << "A��E���б�������" << (flag == 1 ? "YES" : "NO") << endl << endl;
	flag = isInSameConnectedComponent_DFS(PAL, "I", "A");
	cout << "I��A���б�������" << (flag == 1 ? "YES" : "NO") << endl;


	return 0;
}