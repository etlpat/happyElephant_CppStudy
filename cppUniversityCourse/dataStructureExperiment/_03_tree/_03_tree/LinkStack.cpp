#include "LinkStack.h"


// 初始化栈
bool initStack(Stack& S) {
	S = new StackNode;
	S->next = NULL;
	return true;
}


// 方法：销毁链栈
bool destroyStack(Stack& S) {
	StackNode* p;
	while (S) {
		p = S;
		S = S->next;
		delete p;
	}
	return true;
}


// 元素入栈
bool push(Stack& S, TreeNode* tp) {
	StackNode* tmp = new StackNode;
	tmp->treePointer = tp;
	tmp->next = S->next;
	S->next = tmp;
	return true;
}


// 元素出栈
bool pop(Stack& S, TreeNode*& tp) {
	if (!S->next) {
	return false;
	}
	StackNode* tmp = S->next;
	tp = tmp->treePointer;
	S->next = tmp->next;
	delete tmp;
	return true;
}


bool isEmpty(const Stack& S) {
	return S->next == NULL;
}