//#include "_03_LinkQueue.h"
//
//
//// ��ʼ������
//bool initQueue(Queue& Q) {
//	Q.front = new QueueNode;
//	Q.front->next = NULL;
//	Q.rear = Q.front;
//	return true;
//}
//
//
//// ���
//bool enQueue(Queue& Q, TreeNode* pt) {
//	Q.rear->next = new QueueNode;
//	Q.rear = Q.rear->next;
//	Q.rear->treePointer = pt;
//	Q.rear->next = NULL;
//	return true;
//}
//
//
//// ����
//bool deQueue(Queue& Q, TreeNode*& pt) {
//	if (isEmpty(Q)) {
//		return false;
//	}
//	QueueNode* pn = Q.front->next;
//	if (Q.rear == pn) {// ��βָ��ָ�򼴽�ɾ������Ԫ���
//		Q.rear = Q.front;// ��ͷָ�븳��βָ��
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