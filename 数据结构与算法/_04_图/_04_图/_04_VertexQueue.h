#pragma once
#include<iostream>
using namespace std;
#include<string>



extern struct VertexInfo;


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