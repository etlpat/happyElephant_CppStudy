#pragma once
#include<iostream>
using namespace std;
#include<string>



struct Element {
	char key;
	double value;// 结点的权值
};


typedef struct TNode {
	Element data = {};
	TNode* leftChild = NULL;
	TNode* rightChild = NULL;

} *HuffmanTree;


// 森林(双向)链表，每个结点的数据域都是森林中的树
typedef struct LNode {
	TNode* tree = NULL;// 树的根节点指针
	LNode* prior = NULL;
	LNode* next = NULL;
}*ForestLinkdeList;




bool initList(ForestLinkdeList& L);
bool isEmpty(const ForestLinkdeList& L);
bool isOnlyOne(const ForestLinkdeList& L);
bool addTail(ForestLinkdeList& L, TNode* tree);
bool addAll(ForestLinkdeList& L, Element* arr, int sz);
bool removeHead(ForestLinkdeList& L, TNode*& tree);
bool insertByOrder(ForestLinkdeList& L, TNode* tree);
bool destroy(ForestLinkdeList& L);