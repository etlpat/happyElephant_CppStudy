#pragma once
#include<iostream>
using namespace std;
#include<string>



extern struct TreeNode;

typedef struct StackNode {
	TreeNode* treePointer = NULL;
	StackNode* next = NULL;
}*Stack;


bool initStack(Stack& S);
bool destroyStack(Stack& S);
bool push(Stack& S, TreeNode* tp);
bool pop(Stack& S, TreeNode*& tp);
bool isEmpty(const Stack& S);