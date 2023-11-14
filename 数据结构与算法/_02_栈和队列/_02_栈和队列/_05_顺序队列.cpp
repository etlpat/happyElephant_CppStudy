#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 5


// 顺序队列
//
//
// 1.顺序队列中包含：
//		1.存放数据元素的数组
//		2.队头下标(指向队头元素)
//		3.队尾下标(指向队尾元素的下一个位置)
// 
// 
// 2.思路
//	队列：使用的是【循环数组】，队列的元素存放在[对头下标, 队尾下标)区间，0下标未必是队头
// 		增：(队尾下标++) % MAN_SIZE
//		删：(对头下标++) % MAN_SIZE
//		空队列：队头下标 == 队尾下标
//		满队列：(队尾下标 + 1) % MAX_SIZE == 队头下标
//	注意：以上的队尾下标，实际是队尾元素的下一个位置
//
//
// 3.注意事项
//	这里满队列的元素个数为MAX_SIZE - 1，因为必须空一个位置，
//	用 (rear+1)%MAX_SIZE == front 表示队列已满
//	空一个位置的原因是：若不保留一个位置，队满时 rear == front，无法区分对空和队满
//
// 
// 4.其他方案
//	1.可以在队列中添加length表示元素个数，这样就不用留一个位置区分是否队满了
//	2.可以用rear直接表示队尾元素，而不是队尾元素的下一个位置。这样初始化时rear必须为length-1，而不是0
//	......





//typedef struct Person {
//	string name;
//	int age;
//	string sex;
//}Element;
//
//
//typedef struct SqQueue {
//	Element* arr = NULL;// 数据元素数组的首地址
//	int front = 0;// 队头指针
//	int rear = 0;// 队尾指针
//}SqQueue;
//
//
//
//// 方法：初始化队列
//bool initQueue(SqQueue& Q) {
//	if (Q.arr) {
//		cout << "顺序队列数组不为NULL，无法初始化" << endl;
//		return false;
//	}
//
//	Q.arr = new Element[MAX_SIZE];
//	Q.front = 0;
//	Q.rear = 0;
//	return true;
//}
//
//
//// 方法：销毁队列
//bool destroyQueue(SqQueue& Q) {
//	Q.front = 0;
//	Q.rear = 0;
//	if (Q.arr) {
//		delete[] Q.arr;
//		Q.arr = NULL;
//	}
//	return true;
//}
//
//
//// 方法：元素入队【增】
//bool enQueue(SqQueue& Q, const Element& e) {
//	if ((Q.rear + 1) % MAX_SIZE == Q.front) {
//		cout << "队列已满，无法入队" << endl;
//		return false;
//	}
//
//	Q.arr[Q.rear] = e;
//	Q.rear = (Q.rear + 1) % MAX_SIZE;
//	return true;
//}
//
//
//// 方法：元素出队【删】
//bool deQueue(SqQueue& Q, Element& e) {
//	if (Q.front == Q.rear) {
//		cout << "队列为空，无法出队" << endl;
//		return false;
//	}
//
//	e = Q.arr[Q.front];
//	Q.front = (Q.front + 1) % MAX_SIZE;
//	return true;
//}
//
//
//// 方法：读取队头元素【查】
//bool getFront(const SqQueue& Q, Element& e) {
//	if (Q.front == Q.rear) {
//		cout << "队列为空，无法读取队头元素" << endl;
//		return false;
//	}
//
//	e = Q.arr[Q.front];
//	return true;
//}
//
//
//// 方法：获取队列元素个数
//int getLength(const SqQueue& Q) {
//	return Q.front <= Q.rear ? Q.rear - Q.front : Q.rear - Q.front + MAX_SIZE;
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
//void printQueue(const SqQueue& Q) {
//	if (Q.front == Q.rear) {
//		cout << "顺序队列为空" << endl;
//		return;
//	}
//
//	int i = Q.front;
//	int num = 1;
//	while (i != Q.rear) {
//		cout << "第" << num << "位(下标为" << i << ")：" << elementToString(Q.arr[i]) << endl;
//		num++;
//		i = (i + 1) % MAX_SIZE;
//	}
//}
//
//
//
//
//int main() {
//
//	// (1)创建并初始化顺序队列
//	SqQueue Q;
//	initQueue(Q);
//	printQueue(Q);
//	cout << "==========================" << endl;
//
//
//	// (2)元素入队
//	enQueue(Q, Element{ "张三", 34, "男" });
//	enQueue(Q, Element{ "李四", 27, "女" });
//	enQueue(Q, Element{ "王五", 45, "男" });
//	enQueue(Q, Element{ "赵六", 55, "男" });
//	enQueue(Q, Element{ "孙七", 75, "女" });// 队列已满，无法入队
//	printQueue(Q);
//	cout << "队列元素个数为：" << getLength(Q) << endl;
//	cout << "==========================" << endl;
//	//第1位(下标为0)： { name = 张三, age = 34, sex = 男 }
//	//第2位(下标为1)： { name = 李四, age = 27, sex = 女 }
//	//第3位(下标为2)： { name = 王五, age = 45, sex = 男 }
//	//第4位(下标为3)： { name = 赵六, age = 55, sex = 男 }
//	//队列元素个数为：4
//
//
//	// (4)元素出队
//	Element e1, e2, e3;
//	deQueue(Q, e1);
//	deQueue(Q, e2);
//	deQueue(Q, e3);
//	cout << elementToString(e1) << endl;// {name=张三, age=34, sex=男}
//	cout << elementToString(e2) << endl;// {name=李四, age=27, sex=女}
//	cout << elementToString(e3) << endl;// {name=王五, age=45, sex=男}
//	cout << "==========================" << endl;
//	printQueue(Q);
//	cout << "队列元素个数为：" << getLength(Q) << endl;
//	cout << "==========================" << endl;
//	//第1位(下标为3)：{name=赵六, age=55, sex=男}
//	//队列元素个数为：1
//
//
//	// (5)检查顺序队列的循环数组
//	enQueue(Q, Element{ "小明", 7, "男" });
//	enQueue(Q, Element{ "小红", 9, "女" });
//	enQueue(Q, Element{ "大壮", 8, "男" });
//	printQueue(Q);
//	cout << "队列元素个数为：" << getLength(Q) << endl;
//	cout << "==========================" << endl;
//	//第1位(下标为3)： { name = 赵六, age = 55, sex = 男 }
//	//第2位(下标为4)： { name = 小明, age = 7, sex = 男 }
//	//第3位(下标为0)： { name = 小红, age = 9, sex = 女 }
//	//第4位(下标为1)： { name = 大壮, age = 8, sex = 男 }
//	//队列元素个数为：4
//	
//
//	// (5)读取队头元素
//	Element e4;
//	getFront(Q, e4);
//	cout << elementToString(e4) << endl;// {name=赵六, age=55, sex=男}
//	cout << "==========================" << endl;
//
//
//	return 0;
//}
