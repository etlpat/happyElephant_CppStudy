#include<iostream>
using namespace std;
#include<string>




// 单链表（linked list）
//
// (1)结点
//	单链表的每个结点包含：数据域(存放数据元素) 和 指针域(存放下个结点的指针)
// 
// 
// (2)头指针、头结点、首元结点
//	头指针：指向头结点的指针，整个单链表从头指针开始
//	头结点：首元结点前附设的一个结点，用于存储附加信息，或不存储信息	
//	首元结点：存放第一个元素的结点，是头结点的后继
// 
// 
// (3)设置头结点的好处
//	1.便于数据处理
//		头结点后继是首元结点，则保证链表对第一个元素的处理和其它数据元素相同，不用特殊处理
//	2.便于非空表和空表的统一处理
//		无论链表是否为空，都存在头结点






//// 数据元素
//typedef struct Student {
//	string name;
//	int age;
//	string sex;
//}Element;
//
// 
//// 链表结点
//typedef struct LNode {
//	Element data;// 数据域
//	LNode* next;// 指针域
//}LNode, *LinkList;
//// 这里用typedef将LNode*定义为LinkList
//
//
//
//
//// 方法：初始化链表（为头指针创建头结点）
//bool initList(LinkList& L) {// 参数传入头指针
//	L = new LNode;// new头结点
//	L->next = NULL;
//	return true;
//}
//
//
//// 方法：头插法增加一个元素【增】
//bool listHeadAdd(LinkList& L, const Element& element) {
//	LNode* p = new LNode;
//	p->data = element;
//	p->next = L->next;
//	L->next = p;
//	return true;
//}
//
//
//// 方法：获取链表尾指针（返回指向最后一个结点的指针）
//LNode* getTailPointer(const LinkList& L) {
//	LNode* p = L;
//	while (p->next) {// 最终p指向尾结点
//		p = p->next;
//	}
//	return p;
//}
//
//
//// 方法：尾插法增加一个元素【增】
//bool listTailAdd(LinkList& L, const Element& element) {
//	LNode* p = new LNode;
//	p->data = element;
//	p->next = NULL;
//	getTailPointer(L)->next = p;
//	return true;
//}
//
//
//// 方法：按位插入元素【增】（在第i个位置插入元素element）
//bool listInsert(LinkList& L, int i, const Element& element) {
//	if (i < 1) {
//		cout << "插入位置无效" << endl;
//		return false;
//	}
//
//	LNode* p1 = L;
//	// 让p1指向第i-1个元素结点 （共n个元素，则可插入范围是[1, n+1]）
//	while (p1 && --i) {// --i可使p1指向第i-1个元素
//		p1 = p1->next;
//	}
//	if (!p1) {// 插入第i位置，i结点可为NULL，但i-1结点必须存在
//		cout << "插入位置超出元素范围" << endl;
//		return false;
//	}
//
//	LNode* p2 = new LNode;
//	p2->data = element;
//	p2->next = p1->next;
//	p1->next = p2;
//	return true;
//}
//
//
//// 方法：在指定结点前插入一个元素【增】
//// 思路：e.g.若有链表结点x->y->z，想要在y前插入一个e结点
////		 由于单链表只能访问后继，无法访问到前驱
////		 我们可以逆转思路，在y后面又插入一个y'，然后把前面的y改成e
////		 ①(x->y->z)  ②(x->y->y'->z)  ③(x->e->y'->z)
//// 时间复杂度：O(1)，好
//bool insertPriorNode(LNode* p, const Element& element) {
//	if (!p) {
//		cout << "传入无效结点" << endl;
//		return false;
//	}
//	LNode* p1 = new LNode;
//	p1->data = p->data;// 在p结点后面再插入一个p结点的拷贝p1
//	p1->next = p->next;
//	p->next = p1;
//	p->data = element;// 把p结点的数据赋为element
//	return true;
//}
//
//
//
//// 方法：删除表头元素【删】（并将被删数据返回给引用参数）
//bool listHeadSub(LinkList& L, Element& element) {
//	if (!L->next) {
//		cout << "链表为空，无法删除元素" << endl;
//		return false;
//	}
//	LNode* q = L->next;
//	element = q->data;
//	L->next = q->next;
//	delete q;
//	return true;
//}
//
//
//// 方法：删除表尾元素【删】（并将被删数据返回给引用参数）
//bool listTailSub(LinkList& L, Element& element) {
//	if (!L->next) {
//		cout << "链表为空，无法删除元素" << endl;
//		return false;
//	}
//	LNode* p = L;
//	while (p->next->next) {// p最终为尾结点的前驱
//		p = p->next;
//	}
//	LNode* q = p->next;
//	element = q->data;
//	p->next = NULL;
//	delete q;
//	return 0;
//}
//
//
//// 方法：按位删除元素【删】（并将被删数据返回给引用参数）
//bool listDelete(LinkList& L, int i, Element& element) {
//	if (!L->next) {
//		cout << "链表为空，无法删除元素" << endl;
//		return false;
//	}
//	if (i < 1) {
//		cout << "删除位置无效" << endl;
//		return false;
//	}
//
//	LNode* p = L;
//	// 让p指向第i-1个元素结点 （共n个元素，则可插入范围是[1, n]）
//	while (p->next && --i) {
//		p = p->next;
//	}
//	if (!p->next) {// 删除第i位置，i-1和i结点都必须存在（对比按位插入代码）
//		cout << "删除位置超出元素范围" << endl;
//		return false;
//	}
//
//	LNode* q = p->next;// q为要删除的第i个元素
//	element = q->data;
//	p->next = q->next;
//	delete q;
//	return true;
//}
//
//
//// 方法：删除给定结点【删】
//// 思路：由于单链表不能直接获得给定结点p的前驱，
////		 因此逆转思路：先把后继的值赋给p，再把p的后继删除即可
////		 删除p：(x->p->y) (x->y'->y) (x->y')
//// 注意：若p为尾结点，指向NULL，无法拷贝删除后继，因此这种情况无法使用
//bool deleteNode(LNode* p) {
//	if (!p) {
//		cout << "结点为空，无法删除" << endl;
//		return false;
//	}
//	if (!p->next) {
//		cout << "若后继结点为NULL，本方法无法使用" << endl;
//		return false;
//	}
//	LNode* q = p->next;
//	p->data = q->data;// 将p后继的值赋给p
//	p->next = q->next;// 删除p的后继
//	delete q;
//	return true;
//}
//
//
//
//// 方法：按位查找元素【查】（返回指定位置的元素）
//LNode* getElement(LinkList L, int i) {
//	if (i < 1) {
//		cout << "查找位置无效" << endl;
//		return NULL;
//	}
//
//	LNode* p = L;
//	while (p && i--)// i--可以让p指向第i个元素
//	{
//		p = p->next;
//	}
//	if (!p) {
//		cout << "查找位置超出界限" << endl;
//		return NULL;
//	}
//	return p;
//}
//
//
//// 方法：按值(关键字)查找元素【查】
//LNode* locateElement(LinkList L, string name) {
//	LNode* p = L->next;
//	while (p) {
//		if (p->data.name == name) {
//			return p;
//		}
//		p = p->next;
//	}
//
//	cout << "所找关键字元素不存在" << endl;
//	return NULL;
//}
//
//
//
//// 方法：返回元素信息
//string elementToString(const Element& element) {
//	return "{name=" + element.name +
//		", age=" + to_string(element.age) +
//		", sex=" + element.sex + "}";
//}
//
//
//// 方法：打印顺序表全部元素
//void printLinkList(const LinkList& L) {
//	if (!L || !L->next) {
//		cout << "链表为空" << endl;
//		return;
//	}
//	LNode* p = L->next;// 首元结点
//	int i = 1;
//	while (p) {
//		cout << "第" << i << "位：" << elementToString(p->data) << endl;
//		p = p->next;
//		i++;
//	}
//}
//
//
//
//// 方法：(头插法)建立单链表（即将传入的数组转化为单链表）
//LinkList createList_HeadInsert(Element* arr, int length) {
//	if (!arr || length < 0) {
//		cout << "传入异常数据" << endl;
//		return NULL;
//	}
//
//	LinkList L = NULL;
//	initList(L);// 创建头结点
//	LNode* tmp = NULL;
//	for (int i = length - 1; i >= 0; i--) {// 头插：在表头倒叙存储数组元素
//		tmp = new LNode;
//		tmp->data = arr[i];
//		tmp->next = L->next;
//		L->next = tmp;
//	}
//	return L;
//}
//
//
//// 方法：(尾插法)建立单链表（即将传入的数组转化为单链表）
//LinkList createList_TailInsert(Element* arr, int length) {
//	if (!arr || length < 0) {
//		cout << "传入异常数据" << endl;
//		return NULL;
//	}
//
//	LinkList L = NULL;
//	initList(L);// 创建头结点
//	LNode* pTail = L;// 保存尾指针
//	for (int i = 0; i < length; i++) {// 尾插：在表尾顺序存储数组元素
//		pTail->next = new LNode;
//		pTail = pTail->next;
//		pTail->data = arr[i];
//	}
//	pTail->next = NULL;
//	return L;
//}
//
//
//
//
//
//int main() {
//	// 1.创建链表
//	//（这里的L实际上是链表的头指针，用来表示链表）
//	LinkList L = NULL;
//
//	// 2.初始化单链表
//	initList(L);
//	printLinkList(L);// 链表为空
//
//
//
//	// 3.头/尾插法为链表添加元素
//	Element e1 = { "张三", 22, "男" };
//	Element e2 = { "李四", 33, "女" };
//	Element e3 = { "王五", 44, "男" };
//	listHeadAdd(L, e2);
//	listHeadAdd(L, e1);
//	listTailAdd(L, e3);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	//	第1位：{ name = 张三, age = 22, sex = 男 }
//	//	第2位：{ name = 李四, age = 33, sex = 女 }
//	//	第3位：{ name = 王五, age = 44, sex = 男 }
//
//
//	// 4.在指定位置插入结点元素
//	Element e4 = { "小明", 14, "男" };
//	Element e5 = { "小红", 15, "女" };
//	listInsert(L, 2, e4);
//	listInsert(L, 5, e5);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	//	第1位：{ name = 张三, age = 22, sex = 男 }
//	//	第2位：{ name = 小明, age = 14, sex = 男 }
//	//	第3位：{ name = 李四, age = 33, sex = 女 }
//	//	第4位：{ name = 王五, age = 44, sex = 男 }
//	//	第5位：{ name = 小红, age = 15, sex = 女 }
//
//
//	// 5.在指定结点前插入一个前驱（新内容）
//	Element e6 = { "孔子", 88, "男" };
//	insertPriorNode(L->next->next->next, e6);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	//	第1位：{ name = 张三, age = 22, sex = 男 }
//	//	第2位：{ name = 小明, age = 14, sex = 男 }
//	//	第3位：{ name = 孔子, age = 88, sex = 男 }
//	//	第4位：{ name = 李四, age = 33, sex = 女 }
//	//	第5位：{ name = 王五, age = 44, sex = 男 }
//	//	第6位：{ name = 小红, age = 15, sex = 女 }
//
//
//
//	// 6.按位查找元素
//	LNode* p1 = getElement(L, 3);
//	LNode* p2 = getElement(L, 4);
//	LNode* p3 = getElement(L, 0);// 查找位置无效
//	LNode* p4 = getElement(L, 7);// 查找位置超出界限
//	cout << "\n================" << endl;
//	cout << elementToString(p1->data) << endl;
//	cout << elementToString(p2->data) << endl;
//	cout << p3 << endl;
//	cout << p4 << endl;
//	//	{name = 孔子, age = 88, sex = 男}
//	//	{name = 李四, age = 33, sex = 女}
//	//	0000000000000000
//	//	0000000000000000
//
//
//	// 7.按关键字查找元素
//	LNode* p5 = locateElement(L, "王五");
//	LNode* p6 = locateElement(L, "烫烫烫");// 所找关键字元素不存在
//	cout << "\n================" << endl;
//	cout << elementToString(p5->data) << endl;
//	cout << p6 << endl;
//	//	{name = 王五, age = 44, sex = 男}
//	//	0000000000000000
//
//
//
//	// 8.删除(并返回)指定位置的元素
//	Element ret1;
//	Element ret2;
//	listDelete(L, 2, ret1);
//	listDelete(L, 5, ret2);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	cout << "================" << endl;
//	cout << elementToString(ret1) << endl;
//	cout << elementToString(ret2) << endl;
//	//	第1位：{ name = 张三, age = 22, sex = 男 }
//	//	第2位：{ name = 孔子, age = 88, sex = 男 }
//	//	第3位：{ name = 李四, age = 33, sex = 女 }
//	//	第4位：{ name = 王五, age = 44, sex = 男 }
//	//	================
//	//	{name = 小明, age = 14, sex = 男}
//	//	{name = 小红, age = 15, sex = 女}
//
//
//	// 9.删除并返回头/尾元素
//	Element ret3;
//	Element ret4;
//	listHeadSub(L, ret3);
//	listTailSub(L, ret4);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	cout << "================" << endl;
//	cout << elementToString(ret3) << endl;
//	cout << elementToString(ret4) << endl;
//	//	第1位：{ name = 孔子, age = 88, sex = 男 }
//	//	第2位：{ name = 李四, age = 33, sex = 女 }
//	//	================
//	//	{name = 张三, age = 22, sex = 男}
//	//	{name = 王五, age = 44, sex = 男}
//
//
//	// 10.删除指定结点
//	deleteNode(L->next);
//	cout << "\n================" << endl;
//	printLinkList(L);
//	//	第1位：{name=李四, age=33, sex=女}
//
//
//
//
//	// 11.头插法将数组转化为链表
//	cout << "\n================" << endl;
//	Element arr[] = {{"张三", 11, "男"}, {"李四", 15, "女"}, 
//		{"王五", 21, "男"}, {"赵六", 37, "男"}, {"孙七", 51, "女"}};
//	int length = sizeof(arr) / sizeof(arr[0]);
//	LinkList L1 = createList_HeadInsert(arr, length);
//	printLinkList(L1);
//	//	第1位：{ name = 张三, age = 11, sex = 男 }
//	//	第2位：{ name = 李四, age = 15, sex = 女 }
//	//	第3位：{ name = 王五, age = 21, sex = 男 }
//	//	第4位：{ name = 赵六, age = 37, sex = 男 }
//	//	第5位：{ name = 孙七, age = 51, sex = 女 }
//
//
//	// 12.尾插法将数组转化为链表
//	cout << "\n================" << endl;
//	LinkList L2 = createList_TailInsert(arr, length);
//	//	第1位：{ name = 张三, age = 11, sex = 男 }
//	//	第2位：{ name = 李四, age = 15, sex = 女 }
//	//	第3位：{ name = 王五, age = 21, sex = 男 }
//	//	第4位：{ name = 赵六, age = 37, sex = 男 }
//	//	第5位：{ name = 孙七, age = 51, sex = 女 }
//	printLinkList(L2);
//
//
//	return 0;
//}