//#include "_03_LinkQueue.h"
//
//
//// 初始化队列
//bool initQueue(Queue& Q) {
//	Q.front = new QueueNode;
//	Q.front->next = NULL;
//	Q.rear = Q.front;
//	return true;
//}
//
//
//// 入队
//bool enQueue(Queue& Q, TreeNode* pt) {
//	Q.rear->next = new QueueNode;
//	Q.rear = Q.rear->next;
//	Q.rear->treePointer = pt;
//	Q.rear->next = NULL;
//	return true;
//}
//
//
//// 出队
//bool deQueue(Queue& Q, TreeNode*& pt) {
//	if (isEmpty(Q)) {
//		return false;
//	}
//	QueueNode* pn = Q.front->next;
//	if (Q.rear == pn) {// 若尾指针指向即将删除的首元结点
//		Q.rear = Q.front;// 将头指针赋给尾指针
//	}
//	Q.front->next = pn->next;
//	pt = pn->treePointer;
//	delete pn;
//	return true;
//}
//
//
//bool isEmpty(const Queue& Q) {
//	return Q.front == Q.rear;
//}
//
//
//bool destroyQueue(Queue& Q) {
//	Q.rear = NULL;
//	QueueNode* p;
//	while (Q.front) {
//	p = Q.front;
//	Q.front = Q.front->next;
//	delete p;
//	}
//	p = NULL;
//	return true;
//}