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



// ��ʼ������Ϊͷָ�봴��ͷ��㣩
bool initList(LinkList& L);
bool initList(LinkList& L, double x);

// ͷ�巨����һ��Ԫ�ء�����
bool listHeadAdd(LinkList& L, const Element& element);

// ��ȡ����βָ�루����ָ�����һ������ָ�룩
LNode* getTailPointer(const LinkList& L);

// β�巨����һ��Ԫ�ء�����
bool listTailAdd(LinkList& L, const Element& element);

// ��λ����Ԫ�ء��������ڵ�i��λ�ò���Ԫ��element��
bool listInsert(LinkList& L, int i, const Element& element);

// ��ָ��λ�ò���Ԫ�ء�����
bool insertPriorNode(LNode* p, const Element& element);

// ɾ����ͷԪ�ء�ɾ����������ɾ���ݷ��ظ����ò�����
bool listHeadSub(LinkList& L, Element& element);

// ɾ����βԪ�ء�ɾ����������ɾ���ݷ��ظ����ò�����
bool listTailSub(LinkList& L, Element& element);

// ��λɾ��Ԫ�ء�ɾ����������ɾ���ݷ��ظ����ò�����
bool listDelete(LinkList& L, int i, Element& element);

// ɾ��������㡾ɾ��
bool deleteNode(LNode* p);

// ��λ����Ԫ�ء��顿������ָ��λ�õ�Ԫ�أ�
LNode* getElement(LinkList L, int i);

// ����Ԫ����Ϣ
string elementToString(const Element& element);

// ��ӡ˳���ȫ��Ԫ��
void printLinkList(const LinkList& L);

// (ͷ�巨)����������
LinkList createList_HeadInsert(double x, Element* arr, int length);

// (β�巨)����������
LinkList createList_TailInsert(double x, Element* arr, int length);