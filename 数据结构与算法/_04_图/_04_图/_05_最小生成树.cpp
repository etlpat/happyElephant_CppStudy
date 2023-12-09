#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 100
#define MAX_COST 65535


// ��С������
//
// (1)ע������
//	��Ȩͼ������С��������˵��
//	����ͳһ�������Ȩͼ����С����������Щ�㷨������ͼҲ��Ч
// 
// 
// 
// (2)��С�������㷨
//	��Kruskal(��³˹����)�㷨������û��ʵ�֣�
//	��Prim(����ķ)�㷨			
//	��Prim�㷨��ѡ��һ����ʼ�ڵ㣬������ΧȨֵ(����)��С�ıߣ����������Լ���������������δѡ�ڵ���뵽��С�������У�
//				֮���Ѿ��������С����������һ�����壬ѡ�񵽴���С������������С�Ľ�㣬������С�������������´������飬ֱ��ȫ����������С��������
//	��ע�⣺����������У���Ҫ����һ���������飬����Ÿ���㵽����С����������ʹ��ۣ������Ž�����Ӷ����¸����顣
//	��Prim�㷨���裺
//		1.��ʼ����ѡ��һ����ʼ�ڵ������ѡ�ڵ㼯�ϡ�
//		2.������������ѡ�ڵ㼯��������δѡ�ڵ㣬�ҳ�������������ѡ�ڵ㼯�ϵı���Ȩֵ(����)��С�ıߣ����������Լ���������������δѡ�ڵ���뵽��С����������ѡ�ڵ㼯���С�
//		3.������ʹ������飺�����¼���Ľڵ㣬��������������δѡ�ڵ����ʹ��ۡ����ͨ������½ڵ㵽��ĳ��δѡ�ڵ�ľ����ԭ���ľ���С����ô�͸���������롣
//		4.�ظ�����2��3��ֱ�����еĽڵ㶼��ѡ����С��������





//// ������Ϣ
//struct VertexInfo {
//	string name;
//};
//
//// ����Ϣ
//struct EdgeInfo {
//	string name;
//	double weight = 0;// Ȩ
//};
//
//// ������Ľ��
//struct EdgeNode {
//	int vertexIndex = -1;// ����±�
//	double weight = 0;// Ȩ
//	EdgeNode* next = NULL;
//};
//
//// ����Ľ��
//struct VertexNode {
//	bool hasData = false;// ��ʾ��ǰ����Ƿ�Ϊ��
//	VertexInfo data;
//	EdgeNode* first = NULL;// ָ��������ָ��
//};
//
//// �ڽӱ�
//struct AdjacencyList {
//	VertexNode* vertexNodeArr;// ��������
//	int vertexNum;// �����
//	int edgeNum;// ����
//};
//
//
//
//// ���������顿��ȡ������ڽӱ��е��±�
//int indexOf(const AdjacencyList* PAL, const string vertexName) {
//	// ѭ������������num(��������Ч�����)==�ڵ����/�±굽�����ֵ 
//	for (int index = 0, num = 0; num < PAL->vertexNum && index < MAX_SIZE; index++) {
//		if (PAL->vertexNodeArr[index].hasData) {// ����ǰ�±��Ӧ�Ľ����Ч
//			num++;// num��¼�Ѿ���������Ч������
//			if (PAL->vertexNodeArr[index].data.name == vertexName) {
//				return index;
//			}
//		}
//	}
//	return -1;
//}
//
//
//// ��������ʼ���ڽӱ�
//bool initAdjacencyList(AdjacencyList*& PAL) {
//	PAL = new AdjacencyList;
//	PAL->vertexNum = 0;
//	PAL->edgeNum = 0;
//	PAL->vertexNodeArr = new VertexNode[MAX_SIZE];
//	return true;
//}
//
//
//// ����������������������ͼ���ڽӱ�
//// ������(�����������, ������, �ߵ����飬 �ߵĸ���) 
//AdjacencyList* createAdjacencyList(const VertexInfo* vertexArr, int vertexSZ, const EdgeInfo* edgeArr, int edgeSZ) {
//	// 1.�����ڽӱ�
//	AdjacencyList* PAL = new AdjacencyList;
//	PAL->vertexNum = vertexSZ;
//	PAL->edgeNum = 2 * edgeSZ;
//	PAL->vertexNodeArr = new VertexNode[MAX_SIZE];
//
//	// 2.Ϊ�ڽӱ�Ľ�����ݱ�ֵ
//	for (int i = 0; i < vertexSZ; i++) {
//		PAL->vertexNodeArr[i].hasData = true;
//		PAL->vertexNodeArr[i].data = vertexArr[i];
//		PAL->vertexNodeArr[i].first = NULL;
//	}
//
//	// 3.Ϊ������ӱ�����
//	int leftIndex, rightIndex;
//	EdgeNode* edgeNode;
//	for (int i = 0; i < edgeSZ; i++) {
//		leftIndex = indexOf(PAL, edgeArr[i].name.substr(0, 1));// �ߵ��󶥵��±�
//		rightIndex = indexOf(PAL, edgeArr[i].name.substr(1, 1));// �ߵ��Ҷ����±�
//		// ��Ϊ�ߵ��󶥵���ӱ�
//		edgeNode = new EdgeNode;
//		edgeNode->vertexIndex = rightIndex;
//		edgeNode->weight = edgeArr[i].weight;
//		edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
//		PAL->vertexNodeArr[leftIndex].first = edgeNode;
//		// ��Ϊ�ߵ��Ҷ�����ӱ�
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
//// ��������������ӽ��
//bool addVertex(AdjacencyList* PAL, const VertexInfo& vertex) {
//	if (PAL->vertexNum == MAX_SIZE) {// ������������false
//		cout << "��������" << endl;
//		return false;
//	}
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {// ���������ظ�������false
//		if (PAL->vertexNodeArr[i].hasData) {
//			if (PAL->vertexNodeArr[i].data.name == vertex.name) {
//				cout << "�������" << endl;
//				return false;
//			}
//			j++;// �ѱ�������Ч�����
//		}
//	}
//	int i = 0;
//	while (PAL->vertexNodeArr[i].hasData) {
//		// ��i��Ϊ�׸�����Ϊ�յ��±�
//		i++;
//	}
//	PAL->vertexNodeArr[i].data = vertex;
//	PAL->vertexNodeArr[i].hasData = true;
//	PAL->vertexNodeArr[i].first = NULL;
//
//	PAL->vertexNum++;// �����++
//	return true;
//}
//
//
//// �����������������㵽ָ���±�
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
//// ��������������������
//bool addEdge(AdjacencyList* PAL, const EdgeInfo& edge) {
//	int leftIndex = indexOf(PAL, edge.name.substr(0, 1));// �ߵ��󶥵��±�
//	int rightIndex = indexOf(PAL, edge.name.substr(1, 1));// �ߵ��Ҷ����±�
//
//	if (leftIndex == -1 || rightIndex == -1) {// ����㲻���ڣ��򷵻�false
//		cout << "��㲻����" << endl;
//		return false;
//	}
//	EdgeNode* edgeNode = PAL->vertexNodeArr[leftIndex].first;
//	while (edgeNode) {
//		if (edgeNode->vertexIndex == rightIndex) {// �����ظ����򷵻�false;
//			cout << "���ظ�" << endl;
//			return false;
//		}
//		edgeNode = edgeNode->next;
//	}
//
//	// ��Ϊ�ߵ��󶥵���ӱ�
//	edgeNode = new EdgeNode;
//	edgeNode->vertexIndex = rightIndex;
//	edgeNode->weight = edge.weight;
//	edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
//	PAL->vertexNodeArr[leftIndex].first = edgeNode;
//	// ��Ϊ�ߵ��Ҷ�����ӱ�
//	edgeNode = new EdgeNode;
//	edgeNode->vertexIndex = leftIndex;
//	edgeNode->weight = edge.weight;
//	edgeNode->next = PAL->vertexNodeArr[rightIndex].first;
//	PAL->vertexNodeArr[rightIndex].first = edgeNode;
//
//	PAL->edgeNum += 2;// ����+=2
//	return true;
//}
//
//
//// ��������ɾ��ɾ����㣨����ȫ���ߣ�
//bool deleteVertex(AdjacencyList* PAL, string vertexName) {
//	int deleteIndex = indexOf(PAL, vertexName);
//	if (deleteIndex == -1 || !PAL->vertexNodeArr[deleteIndex].hasData) {// ��ɾ���ڵ㲻���ڣ�����false
//		cout << "��㲻����" << endl;
//		return false;
//	}
//
//	// ��ɾ����ýڵ������ȫ����
//	EdgeNode* thisEdgeNode, * otherEdgeNode, * tmp;
//	while (PAL->vertexNodeArr[deleteIndex].first) {// ��first�߽�㲻Ϊ��
//		// 1.thisEdgeNode��ʾҪɾ���ı�����ϵı�
//		thisEdgeNode = PAL->vertexNodeArr[deleteIndex].first;
//		PAL->vertexNodeArr[deleteIndex].first = thisEdgeNode->next;
//		// 2.otherEdgeNode��ʾҪɾ������������ϵıߣ���thisΪ"AB"����otherΪ"BA"��
//		otherEdgeNode = PAL->vertexNodeArr[thisEdgeNode->vertexIndex].first;
//		// ɾ��otherEdgeNode
//		if (otherEdgeNode->vertexIndex == deleteIndex) {// ��otherEdgeNode�����䶥���first��ֱ��ɾ��first
//			PAL->vertexNodeArr[thisEdgeNode->vertexIndex].first = otherEdgeNode->next;
//			delete otherEdgeNode;
//		}
//		else {
//			tmp = otherEdgeNode;
//			while (tmp->next->vertexIndex != deleteIndex) {// ��tmp��ΪҪɾ���ı߽���ǰһ�����
//				tmp = tmp->next;
//			}
//			otherEdgeNode = tmp->next;
//			tmp->next = otherEdgeNode->next;
//			delete otherEdgeNode;
//		}
//		// ɾ��thisEdgeNode
//		delete thisEdgeNode;
//		PAL->edgeNum -= 2;// ÿѭ��һ�Σ�����-=2
//	}
//	// �ڽ���ǰ�����Ϊ��
//	PAL->vertexNodeArr[deleteIndex].data = {};
//	PAL->vertexNodeArr[deleteIndex].hasData = false;
//
//	PAL->vertexNum--;// �����--
//	return true;
//}
//
//
//// ��������ɾ��ɾ����
//bool deleteEdge(AdjacencyList* PAL, string edge) {
//	int leftIndex = indexOf(PAL, edge.substr(0, 1));// �ߵ��󶥵��±�
//	int rightIndex = indexOf(PAL, edge.substr(1, 1));// �ߵ��Ҷ����±�
//
//	if (leftIndex == -1 || rightIndex == -1) {// ���߲����ڣ�����false
//		cout << "�߲�����" << endl;
//		return false;
//	}
//
//	EdgeNode* edgeNode, * tmp;
//	// ��ɾ����ڵ�ı�
//	edgeNode = PAL->vertexNodeArr[leftIndex].first;
//	if (edgeNode->vertexIndex == rightIndex) {// ��Ҫɾ���Ľ����first���
//		PAL->vertexNodeArr[leftIndex].first = edgeNode->next;
//		delete edgeNode;
//	}
//	else {
//		tmp = edgeNode;
//		while (tmp->next && tmp->next->vertexIndex != rightIndex) {// ��tmp��ΪҪɾ���ı߽���ǰһ�����
//			tmp = tmp->next;
//		}
//		if (!tmp->next) {// �����������tmp����һ������ΪrightIndex������false
//			cout << "�߲�����" << endl;
//			return false;
//		}
//		edgeNode = tmp->next;
//		tmp->next = edgeNode->next;
//		delete edgeNode;
//	}
//	// ��ɾ���ҽڵ�ı�
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
//// ��������ӡ�ڽӱ�
//void printAdjacencyList(const AdjacencyList* PAL) {
//	cout << "�������" << PAL->vertexNum << "�� ������" << PAL->edgeNum << endl;
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
//		if (PAL->vertexNodeArr[i].hasData) {
//			cout << "index:" << i << ", key:" + PAL->vertexNodeArr[i].data.name << " ";// i��ʾ��ʵ�±�
//			EdgeNode* p = PAL->vertexNodeArr[i].first;
//			while (p) {
//				cout << "->" << PAL->vertexNodeArr[p->vertexIndex].data.name << "(" << p->weight << ")";
//				p = p->next;
//			}
//			cout << endl;
//			j++;// �ѱ�������Ч�����++
//		}
//	}
//}
//
//
//
//// Prim�㷨�У���ʹ��۱�Ľ��
//typedef struct LowCostNode {
//	// ���ۣ�����->��ʾ������ӵ�ͼ����ʹ��ۣ�0->��ʾ����Ѿ�����ͼ�ϣ�MAX_COST->�����ͼû��ֱ�ӵı�����(����MAX_COSTΪ65535����ʾ·������Զ)
//	int vertexIndex;	// ��Ӧ������±� 
//	bool isAdd = false;	// �Ƿ��Ѿ���ӵ���С������
//	double lowCast;		// �ö��������С����������ʹ��ۣ�Ȩ��
//	int lowCastEdgeIndex;// ��ʹ��۵ıߵ���һ�˵Ķ����±�
//};
//
//// ������Prim�㷨����С������
//AdjacencyList* getMiniSpanTree_Prim(const AdjacencyList* PAL) {
//	// 1.������ʹ��۱�
//	LowCostNode* lowCostArr = new LowCostNode[PAL->vertexNum];
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
//		if (PAL->vertexNodeArr[i].hasData) {
//			lowCostArr[j].vertexIndex = i;
//			lowCostArr[j].isAdd = false;
//			lowCostArr[j].lowCast = MAX_COST;// ����С������Ϊ���
//			j++;
//		}
//	}
//
//	// 2.������С������
//	AdjacencyList* miniSpanTree;
//	initAdjacencyList(miniSpanTree);
//
//	// 3.Ϊ��С��������ӱߺͶ��㣨ÿ�μ��������С�ıߺͶ��㣩
//	double leastCost;
//	int leastCostIndex;
//	EdgeNode* edgeNode;
//	string edge;
//	for (int i = 0; i < PAL->vertexNum; i++) {
//		// �ٻ�ȡ����δ����ӵ���С���۵Ķ���
//		leastCost = MAX_COST;// ÿ�ֽ���ʹ�����ΪMAX_COST
//		for (int j = 0; j < PAL->vertexNum; j++) {// �������۱�
//			if (!lowCostArr[j].isAdd && lowCostArr[j].lowCast < leastCost) {
//				leastCost = lowCostArr[j].lowCast;// ��ȡ��С����
//				leastCostIndex = j;// ��ȡ��С���۶�Ӧ��lowCostArrsԪ���±�
//			}
//		}
//		if (leastCost == MAX_COST) {// ����������С���ۻ���MAX_COST��˵����С��������û����Ӷ���
//			leastCostIndex = 0;// Ĭ���״����0
//		}
//
//		// �ڽ���С���۵Ķ���ͱ���ӵ���С��������
//		insertVertex(miniSpanTree, PAL->vertexNodeArr[lowCostArr[leastCostIndex].vertexIndex].data, lowCostArr[leastCostIndex].vertexIndex);
//		if (leastCost != MAX_COST) {// �״�ֻ��Ӷ��㣬����ӱ�
//			edge = PAL->vertexNodeArr[lowCostArr[leastCostIndex].vertexIndex].data.name + PAL->vertexNodeArr[lowCostArr[leastCostIndex].lowCastEdgeIndex].data.name;
//			addEdge(miniSpanTree, { edge, lowCostArr[leastCostIndex].lowCast });
//		}
//		lowCostArr[leastCostIndex].isAdd = true;
//
//		// �۸��´��۱�����������¶����ĳЩ���㵽�������Ĵ��ۻ��С��
//		edgeNode = PAL->vertexNodeArr[lowCostArr[leastCostIndex].vertexIndex].first;
//		while (edgeNode) {// �����뱾�μ���Ķ��������Ķ������ʹ���
//			for (int j = 0; j < PAL->vertexNum; j++) {// ����lowCostArr����ȡ��ǰ�ߵĶ�����lowCostArr�е�λ��
//				if (edgeNode->vertexIndex == lowCostArr[j].vertexIndex) {
//					// ���±߽��Ĵ���
//					if (!lowCostArr[j].isAdd && edgeNode->weight < lowCostArr[j].lowCast) {// ���ñ�δ������Ҹñߵ�ȨֵС�ڶ���֮ǰ����ʹ���
//						lowCostArr[j].lowCast = edgeNode->weight;// ���¶������ʹ���
//						lowCostArr[j].lowCastEdgeIndex = leastCostIndex;//	������ʹ��۵ı�
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
//	// (1)�����ڽӱ�
//	VertexInfo vertexArr[] = { {"A"},{"B"},{"C"},{"D"},{"E"},{"F"} };
//	int vertexSZ = sizeof(vertexArr) / sizeof(vertexArr[0]);
//	EdgeInfo edgeArr[] = { {"AB", 6},{"AC", 5},{"AD", 1},{"BD", 5},{"BE", 3},{"CD", 4},{"CF", 2},{"DE", 6},{"DF", 4},{"EF", 6} };
//	int edgeSZ = sizeof(edgeArr) / sizeof(edgeArr[0]);
//	AdjacencyList* PAL = createAdjacencyList(vertexArr, vertexSZ, edgeArr, edgeSZ);
//	printAdjacencyList(PAL);
//	cout << "===================================\n\n";
//
//
//	// (2)��ȡ��С������
//	AdjacencyList* PAL_MiniSpanTree = getMiniSpanTree_Prim(PAL);
//	printAdjacencyList(PAL_MiniSpanTree);
//	cout << "===================================\n\n";
//
//
//	return 0;
//}