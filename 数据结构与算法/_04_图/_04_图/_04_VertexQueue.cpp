#include "_04_VertexQueue.h"


bool initQueue(VertexQueue& Q) {
	Q.front = new VNode;
	Q.front->vertrxPoint = NULL;
	Q.front->next = NULL;
	Q.rear = Q.front;
	return true;
}


bool isEmpty(const VertexQueue& Q) {
	return Q.front == Q.rear;
}


bool enQueue(VertexQueue& Q, VertexInfo* vp) {
	Q.rear->next = new VNode;
	Q.rear = Q.rear->next;
	Q.rear->vertrxPoint = vp;
	Q.rear->next = NULL;
	return true;
}


bool deQueue(VertexQueue& Q, VertexInfo*& vp) {
	if (isEmpty(Q)) {
		return false;
	}
	VNode* tmp = Q.front->next;
	if (tmp == Q.rear) {
		Q.rear = Q.front;
	}
	Q.front->next = tmp->next;
	vp = tmp->vertrxPoint;
	delete tmp;
	return true;
}


bool destroyQueue(VertexQueue& Q) {
	while (Q.front) {
		Q.rear = Q.front;
		Q.front = Q.front->next;
		delete Q.rear;
	}
	Q.rear = NULL;
	return true;
}