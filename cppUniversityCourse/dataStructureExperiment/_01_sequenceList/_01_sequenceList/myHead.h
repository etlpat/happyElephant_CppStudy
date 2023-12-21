#pragma once
#include<iostream>
using namespace std;
#include<string>
#include<math.h>


typedef struct Element{
	int index;
	double num;
}Element;


typedef struct LNode {
	Element data;
	LNode* next;
}*LinkList;



// 初始化链表（为头指针创建头结点）
bool initList(LinkList& L);
bool initList(LinkList& L, double x);

// 头插法增加一个元素【增】
bool listHeadAdd(LinkList& L, const Element& element);

// 获取链表尾指针（返回指向最后一个结点的指针）
LNode* getTailPointer(const LinkList& L);

// 尾插法增加一个元素【增】
bool listTailAdd(LinkList& L, const Element& element);

// 按位插入元素【增】（在第i个位置插入元素element）
bool listInsert(LinkList& L, int i, const Element& element);

// 在指定位置插入元素【增】
bool insertPriorNode(LNode* p, const Element& element);

// 删除表头元素【删】（并将被删数据返回给引用参数）
bool listHeadSub(LinkList& L, Element& element);

// 删除表尾元素【删】（并将被删数据返回给引用参数）
bool listTailSub(LinkList& L, Element& element);

// 按位删除元素【删】（并将被删数据返回给引用参数）
bool listDelete(LinkList& L, int i, Element& element);

// 删除给定结点【删】
bool deleteNode(LNode* p);

// 按位查找元素【查】（返回指定位置的元素）
LNode* getElement(LinkList L, int i);

// 返回元素信息
string elementToString(const Element& element);

// 打印顺序表全部元素
void printLinkList(const LinkList& L);

// (头插法)建立单链表
LinkList createList_HeadInsert(double x, Element* arr, int length);

// (尾插法)建立单链表
LinkList createList_TailInsert(double x, Element* arr, int length);