#include<iostream>
using namespace std;
#include<string>


// 链队
//
//
// 1.链队中包含：
//		队头指针：指向头节点
//		队尾指针：指向尾结点
//
//
// 2.注意事项：
//	由于链队需要队头、队尾两个指针，
//	因此不能再只用头结点指针表示整个链表了，
//	而是需要新定义一个结构体，存放链表的头指针和尾指针
//
//




//typedef struct Person {
//	string name;
//	int age;
//	string sex;
//}Element;
//
//
//typedef struct LNode {
//	Element data;
//	LNode* next = NULL;
//}LNode;
//
//
//typedef struct LinkQueue {
//	LNode* front = NULL;
//	LNode* rear = NULL;
//}LinkQueue;
//
//
//
//// 方法：初始化链队
//bool initQueue(LinkQueue& Q) {
//	Q.front = new LNode;
//	Q.front->next = NULL;
//	Q.rear = Q.front;
//	return true;
//}
//
//
//// 方法：销毁链表
//bool destroyQueue(LinkQueue& Q) {
//	Q.rear = NULL;
//	LNode* p;
//	while (Q.front) {
//		p = Q.front;
//		Q.front = Q.front->next;
//		delete p;
//	}
//	p = NULL;
//	return true;
//}
//
//
//// 方法：元素入队【增】
//bool enQueue(LinkQueue& Q, const Element& e) {
//	Q.rear->next = new LNode;
//	Q.rear = Q.rear->next;
//	Q.rear->data = e;
//	Q.rear->next = NULL;
//	return true;
//}
//
//
//// 方法：元素出队【删】
//bool deQueue(LinkQueue& Q, Element& e) {
//	if (Q.front == Q.rear) {
//		cout << "链队为空，无法出队" << endl;
//		return false;
//	}
//
//	LNode* p = Q.front->next;
//	if (p == Q.rear) {		// 若链队的首元结点就是其尾结点，
//		Q.rear = Q.front;	// 将尾指针指向头结点
//	}
//	Q.front->next = p->next;
//	e = p->data;
//	delete p;
//	p = NULL;
//	return true;
//}
//
//
//// 方法：读取队头元素【查】
//bool getFront(const LinkQueue& Q, Element& e) {
//	if (Q.front == Q.rear) {
//		cout << "链队为空，无法读取队头元素" << endl;
//		return false;
//	}
//
//	e = Q.front->next->data;
//	return true;
//}
//
//
//// 方法：返回数据元素的字符串信息
//string elementToString(const Element& e) {
//	return "{name=" + e.name +
//		", age=" + to_string(e.age) +
//		", sex=" + e.sex + "}";
//}
//
//
//// 方法：从队头到队尾打印队列的数据元素
//void printQueue(const LinkQueue& Q) {
//	if (Q.front == Q.rear) {
//		cout << "链队为空" << endl;
//		return;
//	}
//
//	LNode* p = Q.front->next;
//	int num = 1;
//	while (p) {
//		cout << "第" << num << "位：" << elementToString(p->data) << endl;
//		num++;
//		p = p->next;
//	}
//}
//
//
//
//
//int main() {
//
//	// (1)创建并初始化链队
//	LinkQueue Q;
//	initQueue(Q);
//	printQueue(Q);// 链队为空
//	cout << "==========================" << endl;
//
//
//	// (2)元素入队
//	enQueue(Q, Element{ "张三", 34, "男" });
//	enQueue(Q, Element{ "李四", 27, "女" });
//	enQueue(Q, Element{ "王五", 45, "男" });
//	enQueue(Q, Element{ "赵六", 55, "男" });
//	printQueue(Q);
//	cout << "==========================" << endl;
//	//第1位：{ name = 张三, age = 34, sex = 男 }
//	//第2位：{ name = 李四, age = 27, sex = 女 }
//	//第3位：{ name = 王五, age = 45, sex = 男 }
//	//第4位：{ name = 赵六, age = 55, sex = 男 }
//
//
//	// (3)元素出队
//	Element e1, e2;
//	deQueue(Q, e1);
//	deQueue(Q, e2);
//	cout << elementToString(e1) << endl;// {name=张三, age=34, sex=男}
//	cout << elementToString(e2) << endl;// {name=李四, age=27, sex=女}
//	cout << "==========================" << endl;
//	printQueue(Q);
//	cout << "==========================" << endl;
//	//第1位：{ name = 王五, age = 45, sex = 男 }
//	//第2位：{ name = 赵六, age = 55, sex = 男 }
//	
//
//	// (4)读取队头元素
//	Element e3;
//	getFront(Q, e3);
//	cout << elementToString(e3) << endl;
//	cout << "==========================" << endl;// {name=王五, age=45, sex=男}
//
//
//	return 0;
//}