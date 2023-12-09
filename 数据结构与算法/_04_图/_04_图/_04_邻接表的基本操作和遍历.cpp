#include "_04_VertexQueue.h"
#define MAX_SIZE 100


// ͼ�ı���
//
// (1)ע������
//	����ͳһʵ������ͼ�Ļ��������ͱ���
//	��Щ�㷨�󲿷ֶ�����ͼҲͨ��
//
//
// (2)ͼ�ı���
//	1.ͼ�ı��������������㷨
//		�ٹ�����ȱ�����Breadth_First_Search == BFS��	
//		��������ȱ�����Depth_First_Search == DFS��
//		ע�⣺�����ǹ�����Ȼ���������ȣ�����Ҫ��¼����Ƿ񱻷��ʹ���
//			  ���ｨ�鵥������һ������flagArr������Ԫ�ر�ʾ��Ӧ����Ƿ񱻷��ʹ�
//	
//	2.BFS���������������
//		�����������㷨���������Ĳ�������㷨�����ȷ����ڽ��Ľ�㣬֮���ٷ������Ľ�㡣
//		����˳���ȷ���ָ�������ΧһȦ�Ľ�㣬֮�������Ȧ�Ľ�㣬���ڵ���һ���ķ��ʡ�
//		�㷨�������£������С�
//			1.��Դ�ڵ���Ϊ�ѷ��ʣ���������ӵ������С�
//			2.�Ӷ��е�ͷ��ȡ��һ���ڵ㣬Ȼ��������δ���ʵ����ڽڵ���Ϊ�ѷ��ʣ�����������ӵ����е�β����
//			3.�ظ�����2��ֱ������Ϊ�ա�
//		Ӧ�ó�����������������������ҵ����·������Ҫ�������нڵ�ĳ�����
//
//	3.DFS���������������
//		���������������������ȸ������㷨�����ȷ�ĳһ��·���ϵĽ�㣬����·��ȫ����������ٷ�������·���Ľ��
//		����˳���ȱ���һ��·����ֱ������������·������Ľ�㣬�ٴ���Ҷ����������������֧·��
//		�㷨�������£����ݹ顿
//			1.��Դ�ڵ���Ϊ�ѷ��ʡ�
//			2.�ݹ�ط���Դ�ڵ������δ���ʵ����ڽڵ㣬����ÿ��δ���ʵ����ڽڵ�ݹ��ظ��˹��̡�
//			3.��ĳ��·��û�и����δ���ʵ����ڽڵ�ʱ���򱾲�ݹ�������ص��ϲ�ݹ��ظ�����2��ֱ�����нڵ㶼�����ʡ�
//		Ӧ�ó������������������������Ҫ����һ��·������Լ����������ĳ�����





//// ������Ϣ
//struct VertexInfo {
//	string name;
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
//int indexOf(const AdjacencyList* ALPointer, const string vertexName) {
//	// ѭ������������num(��������Ч�����)==�ڵ����/�±굽�����ֵ 
//	for (int index = 0, num = 0; num < ALPointer->vertexNum && index < MAX_SIZE; index++) {
//		if (ALPointer->vertexNodeArr[index].hasData) {// ����ǰ�±��Ӧ�Ľ����Ч
//			num++;// num��¼�Ѿ���������Ч������
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
//// ����������������������ͼ���ڽӱ�
//// ������(�����������, ������, �ߵ����飬 �ߵĸ���) 
//AdjacencyList* createAdjacencyList(const VertexInfo* vertexArr, int vertexSZ, const string* edgeArr, int edgeSZ) {
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
//		leftIndex = indexOf(PAL, edgeArr[i].substr(0, 1));// �ߵ��󶥵��±�
//		rightIndex = indexOf(PAL, edgeArr[i].substr(1, 1));// �ߵ��Ҷ����±�
//		// ��Ϊ�ߵ��󶥵���ӱ�
//		edgeNode = new EdgeNode;
//		edgeNode->vertexIndex = rightIndex;
//		edgeNode->weight = 1;
//		edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
//		PAL->vertexNodeArr[leftIndex].first = edgeNode;
//		// ��Ϊ�ߵ��Ҷ�����ӱ�
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
//
//// ��������������������
//bool addEdge(AdjacencyList* PAL, string edge) {
//	int leftIndex = indexOf(PAL, edge.substr(0, 1));// �ߵ��󶥵��±�
//	int rightIndex = indexOf(PAL, edge.substr(1, 1));// �ߵ��Ҷ����±�
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
//	edgeNode->weight = 1;
//	edgeNode->next = PAL->vertexNodeArr[leftIndex].first;
//	PAL->vertexNodeArr[leftIndex].first = edgeNode;
//	// ��Ϊ�ߵ��Ҷ�����ӱ�
//	edgeNode = new EdgeNode;
//	edgeNode->vertexIndex = leftIndex;
//	edgeNode->weight = 1;
//	edgeNode->next = PAL->vertexNodeArr[rightIndex].first;
//	PAL->vertexNodeArr[rightIndex].first = edgeNode;
//
//	PAL->edgeNum += 2;// ����+=2
//	return true;
//}
//
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
//
//// ����������������������㷨��ͨ�����б���startIndex���ڵ���ͨ����
//// ����BFS��������
//string Breadth_First_Search(const AdjacencyList* PAL, int(*&flagArr)[2], int startIndex) {
//	// ��������
//	VertexQueue Q;
//	initQueue(Q);
//	for (int i = 0; i < PAL->vertexNum; i++) {
//		if (flagArr[i][0] == startIndex) {// ���ʱ��������flag��Ϊ1
//			flagArr[i][1] = 1;
//			break;
//		}
//	}
//	enQueue(Q, &(PAL->vertexNodeArr[startIndex].data));// ��ָ���ĳ�ʼ������
//
//	// ͨ�����У�����ͼ�Ĺ�����ȱ���
//	string str = "";
//	VertexInfo* pv = NULL;
//	EdgeNode* edgeNode = NULL;
//	int index;
//	while (!isEmpty(Q)) {
//		// �ٶ�ͷԪ�س��ӣ��������������
//		deQueue(Q, pv);
//		index = indexOf(PAL, pv->name);
//		str += PAL->vertexNodeArr[index].data.name;
//
//		// �ڽ�����Ԫ�����ڵ�(δ��������)����ȫ����ӣ�ע�⣺���ʱҪ�������flag��Ϊ1��
//		edgeNode = PAL->vertexNodeArr[index].first;
//		while (edgeNode) {
//			for (int i = 0; i < PAL->vertexNum; i++) {// ����flagArr
//				if (flagArr[i][0] == edgeNode->vertexIndex) {// ����ǰ�ߵĽ��δ�����������ý�����
//					if (flagArr[i][1] == 0) {
//						flagArr[i][1] = 1;// ��ӣ���flag��Ϊ1
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
//// (����)�������������������ڽӱ��˳�򣬹�����ȱ���ͼ��ȫ����ͨ����
//// ����BFS��������
//string BFS(const AdjacencyList* PAL) {
//	// 1.����flagArr��ά���飬ÿ��Ԫ�ر�ʾ��{�����±�, �Ƿ񱻱�����}
//	int(*flagArr)[2] = new int[PAL->vertexNum][2];
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
//		if (PAL->vertexNodeArr[i].hasData) {
//			flagArr[j][0] = i;// �����Ч������±�
//			flagArr[j][1] = 0;// 0��ʾ����δ������
//			j++;
//		}
//	}
//	// 2.�Զ�����й�����ȱ���
//	string str = "";
//	int startIndex = -1;
//	while (true) {
//		for (int i = 0; i < PAL->vertexNum; i++) {// ��startIndex��Ϊ�׸�δ�������Ľ���±�
//			if (flagArr[i][1] == 0) {
//				startIndex = flagArr[i][0];
//				break;
//			}
//			if (i == PAL->vertexNum - 1) {
//				startIndex = -1;// �����н�㶼������������startIndex��Ϊ-1
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
//// (����)���������������Դ��붥�����ڵ���ͨ�������й�����ȱ���
//// ����BFS��������
//string BFS(const AdjacencyList* PAL, string startVertex) {
//	int startIndex = indexOf(PAL, startVertex);
//	if (startIndex == -1) {
//		return "";
//	}
//	int(*flagArr)[2] = new int[PAL->vertexNum][2];// ����flagArr����
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
//// ����������������������㷨��ͨ���ݹ����startIndex���ڵ���ͨ����
//// ����DFS��������
//string Depth_First_Search(const AdjacencyList* PAL, int(*&flagArr)[2], int startIndex, string str = "") {
//	// 1.��ȡ��ǰ�������ݣ�������flag��Ϊ1
//	str += PAL->vertexNodeArr[startIndex].data.name;
//	for (int i = 0; i < PAL->vertexNum; i++) {
//		if (flagArr[i][0] == startIndex) {
//			flagArr[i][1] = 1;// ����ǰ���flag��Ϊ1
//			break;
//		}
//	}
//	// 2.�Զ������ӵı߽���������ȱ���
//	EdgeNode* edgeNode = PAL->vertexNodeArr[startIndex].first;
//	while (edgeNode) {// �������������ȱ�����һ������ͨ��ȫ�����㣬�ٱ�������ıߣ�
//		for (int i = 0; i < PAL->vertexNum; i++) {
//			if (flagArr[i][0] == edgeNode->vertexIndex) {
//				if (flagArr[i][1] == 0) {// ����δ������������Ըñ߽���������ȱ���
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
//// (����)�������������������ڽӱ��˳��������ȱ���ͼ��ȫ����ͨ����
//// ����DFS��������
//string DFS(const AdjacencyList* PAL) {
//	// 1.����flagArr���飬��¼�����Ƿ񱻱���
//	int(*flagArr)[2] = new int[PAL->vertexNum][2];
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
//		if (PAL->vertexNodeArr[i].hasData) {
//			flagArr[j][0] = i;// �����±�
//			flagArr[j][1] = 0;// �Ƿ񱻱���
//			j++;
//		}
//	}
//	// 2.�Զ������������ȱ���
//	string str = "";
//	int startIndex = -1;
//	while (true) {
//		for (int i = 0; i < PAL->vertexNum; i++) {// ��startIndex��Ϊ�׸�δ�������Ľ���±�
//			if (flagArr[i][1] == 0) {
//				startIndex = flagArr[i][0];
//				break;
//			}
//			if (i == PAL->vertexNum - 1) {
//				startIndex = -1;// �����н�㶼������������startIndex��Ϊ-1
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
//// (����)���������������Դ��붥�����ڵ���ͨ��������������ȱ���
//// ����DFS��������
//string DFS(const AdjacencyList* PAL, string startVertex) {
//	int startIndex = indexOf(PAL, startVertex);
//	if (startIndex == -1) {
//		return "";
//	}
//	int(*flagArr)[2] = new int[PAL->vertexNum][2];// ����flagArr����
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
//// ��������ӡ�ڽӱ�
//void printAdjacencyList(const AdjacencyList* PAL) {
//	cout << "�������" << PAL->vertexNum << "�� ������" << PAL->edgeNum << endl;
//	for (int i = 0, j = 0; j < PAL->vertexNum && i < MAX_SIZE; i++) {
//		if (PAL->vertexNodeArr[i].hasData) {
//			cout << "index:" << i << ", key:" + PAL->vertexNodeArr[i].data.name << " ";// i��ʾ��ʵ�±�
//			EdgeNode* p = PAL->vertexNodeArr[i].first;
//			while (p) {
//				cout << "->" << PAL->vertexNodeArr[p->vertexIndex].data.name << "(i=" << p->vertexIndex << ")";
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
//
//
//int main() {
//	// ��1��ͼ�Ļ�����Ϣ
//	// ͼ�Ľ����Ϣ
//	VertexInfo vertexArr[] = { {"A"},{"B"},{"C"},{"D"},{"E"} };
//	int vertexSZ = sizeof(vertexArr) / sizeof(vertexArr[0]);
//	// ����ͼ�ı�
//	string edgeArr[] = { "AB", "AC", "AD", "AE", "BD", "CE" };
//	int edgeSZ = sizeof(edgeArr) / sizeof(edgeArr[0]);
//
//
//
//	// ��2����������ͼ���ڽӱ�
//	AdjacencyList* PAL = createAdjacencyList(vertexArr, vertexSZ, edgeArr, edgeSZ);
//	printAdjacencyList(PAL);
//	cout << "===================================\n\n";
//
//
//
//	// ��3���ڽӱ�Ļ�������
//	// ��ɾ�����㣨����ȫ���ߣ�
//	if (deleteVertex(PAL, "A") && deleteVertex(PAL, "D")) {
//		cout << "����ɾ���ɹ�����" << endl;
//		printAdjacencyList(PAL);
//	}
//	cout << "===================================\n\n";
//
//	// ����Ӷ��㣨�������λ��
//	VertexInfo v1 = { "F" };
//	if (addVertex(PAL, v1)) {
//		cout << "������ӳɹ�����" << endl;
//		printAdjacencyList(PAL);
//	}
//	cout << "===================================\n\n";
//
//	// ����ӱ�
//	if (addEdge(PAL, "FB") && addEdge(PAL, "FE")) {
//		cout << "����ӳɹ�����" << endl;
//		printAdjacencyList(PAL);
//	}
//	cout << "===================================\n\n";
//
//	// ��ɾ����
//	if (deleteEdge(PAL, "CE")) {
//		cout << "��ɾ���ɹ�����" << endl;
//		printAdjacencyList(PAL);
//	}
//	cout << "===================================\n\n";
//
//
//
//
//	// ��4������ͼ�ı�������
//	VertexInfo vertexArr2[] = { {"A"},{"B"},{"C"},{"D"},{"E"},{"F"},{"G"},{"H"},{"I"},{"J"},{"K"} };
//	int vertexSZ2 = sizeof(vertexArr2) / sizeof(vertexArr2[0]);
//	string edgeArr2[] = { "AB", "CD", "AE", "BF", "FC", "CG", "GD", "DH", "FG", "GH", "IJ", "JK", "KI" };
//	int edgeSZ2 = sizeof(edgeArr2) / sizeof(edgeArr2[0]);
//	// ע�⣺��ͼΪ����ͨͼ������������ͨ����
//	PAL = createAdjacencyList(vertexArr2, vertexSZ2, edgeArr2, edgeSZ2);
//	printAdjacencyList(PAL);
//	
//	cout << "****************************\n\n";
//	cout << "��������ͨͼ�Ĺ������(BFS)���У�" << BFS(PAL) << endl;
//	cout << "BΪ��ʼ�����BFS���У�" << BFS(PAL, "B") << endl;
//	cout << "DΪ��ʼ�����BFS���У�" << BFS(PAL, "D") << endl;
//	cout << "��������ͨͼ���������(DFS)���У�" << DFS(PAL) << endl;
//	cout << "BΪ��ʼ�����DFS���У�" << DFS(PAL, "B") << endl;
//	cout << "DΪ��ʼ�����DFS���У�" << DFS(PAL, "D") << endl;
//
//	return 0;
//}