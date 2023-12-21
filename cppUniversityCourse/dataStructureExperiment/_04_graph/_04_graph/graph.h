#pragma once
#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 100


// 顶点信息
struct VertexInfo {
	string name;
};

// 边链表的结点
struct EdgeNode {
	int vertexIndex = -1;// 结点下标
	double weight = 0;// 权
	EdgeNode* next = NULL;
};

// 结点表的结点
struct VertexNode {
	bool hasData = false;// 表示当前结点是否为空
	VertexInfo data;
	EdgeNode* first = NULL;// 指向边链表的指针
};

// 邻接表
struct AdjacencyList {
	VertexNode* vertexNodeArr;// 结点表数组
	int vertexNum;// 结点数
	int edgeNum;// 边数
};


// 队列的结点
struct VNode {
	VertexInfo* vertrxPoint = NULL;
	VNode* next = NULL;
};

// 队列
struct VertexQueue {
	VNode* front = NULL;
	VNode* rear = NULL;
};


bool initQueue(VertexQueue& Q);
bool isEmpty(const VertexQueue& Q);
bool enQueue(VertexQueue& Q, VertexInfo* vp);
bool deQueue(VertexQueue& Q, VertexInfo*& vp);
bool destroyQueue(VertexQueue& Q);