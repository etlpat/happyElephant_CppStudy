#pragma once
#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 100


// ������Ϣ
struct VertexInfo {
	string name;
};

// ������Ľ��
struct EdgeNode {
	int vertexIndex = -1;// ����±�
	double weight = 0;// Ȩ
	EdgeNode* next = NULL;
};

// ����Ľ��
struct VertexNode {
	bool hasData = false;// ��ʾ��ǰ����Ƿ�Ϊ��
	VertexInfo data;
	EdgeNode* first = NULL;// ָ��������ָ��
};

// �ڽӱ�
struct AdjacencyList {
	VertexNode* vertexNodeArr;// ��������
	int vertexNum;// �����
	int edgeNum;// ����
};


// ���еĽ��
struct VNode {
	VertexInfo* vertrxPoint = NULL;
	VNode* next = NULL;
};

// ����
struct VertexQueue {
	VNode* front = NULL;
	VNode* rear = NULL;
};


bool initQueue(VertexQueue& Q);
bool isEmpty(const VertexQueue& Q);
bool enQueue(VertexQueue& Q, VertexInfo* vp);
bool deQueue(VertexQueue& Q, VertexInfo*& vp);
bool destroyQueue(VertexQueue& Q);