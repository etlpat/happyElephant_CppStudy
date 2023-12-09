#pragma once
#include<iostream>
using namespace std;
#include<string>



extern struct VertexInfo;


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