#pragma once
#include<iostream>
using namespace std;
#include<string>



struct Element {
	char key;
	double value;// ����Ȩֵ
};


typedef struct TNode {
	Element data = {};
	TNode* leftChild = NULL;
	TNode* rightChild = NULL;

} *HuffmanTree;


// ɭ��(˫��)����ÿ��������������ɭ���е���
typedef struct LNode {
	TNode* tree = NULL;// ���ĸ��ڵ�ָ��
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