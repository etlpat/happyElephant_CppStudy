#include<iostream>
using namespace std;
#include<string>


// 链栈(LiStack)：用链表实现的栈
//
// 实现：
//	以下把头结点处规定为栈顶
//	只能在头结点处进行增删，即可实现链栈




//typedef struct Person {
//	string name;
//	int age;
//	string sex;
//}Element;
//
//
//typedef struct LinkNode {
//	Element data;
//	LinkNode* next;
//}LinkNode, *LiStack;
//// 用头结点的指针，表示链栈
//
//
//// 方法：初始化链栈
//bool initLiStack(LiStack& S) {
//	S = new LinkNode;
//	S->next = NULL;
//	return true;
//}
//
//
//// 方法：销毁链栈
//bool destroyLiStack(LiStack& S) {
//	LinkNode* p;
//	while (S) {
//		p = S;
//		S = S->next;
//		delete p;
//	}
//	p = NULL;
//	S = NULL;
//	return true;
//}
//
//
//// 方法：入栈【增】
//bool push(LiStack& S, const Element& e) {
//	LinkNode* p = new LinkNode;
//	p->data = e;
//	p->next = S->next;
//	S->next = p;
//	return true;
//}
//
//
//// 方法：出栈【删】
//bool pop(LiStack& S, Element& e) {
//	if (!S->next) {
//		cout << "链栈为空，无法出栈" << endl;
//		return false;
//	}
//
//	LinkNode* p = S->next;
//	e = p->data;
//	S->next = p->next;
//	delete p;
//	p = NULL;
//	return true;
//}
//
//
//// 方法：读取栈顶元素【查】
//bool getTop(const LiStack& S, Element& e) {
//	if (!S->next) {
//		cout << "链栈为空，无法读取" << endl;
//		return false;
//	}
//
//	e = S->next->data;
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
//// 从栈底到栈底打印元素，并返回元素个数
//int stackDataList(const LiStack& S, bool isHead = true) {
//	int num = 0;
//	if (S->next) {
//		num = 1 + stackDataList(S->next, false);
//	}
//	if (!isHead) {
//		cout << "第" << num + 1 << "位：" << elementToString(S->data) << endl;
//	}
//	return num;
//}
//
//
//// 方法：从栈底到栈顶打印栈的数据元素
//void printStack(const LiStack& S) {
//	int length = stackDataList(S);
//	if (length == 0) {
//		cout << "链栈为空" << endl;
//	}
//	else {
//		cout << "栈中元素个数为：" << length << endl;
//	}
//}
//
//
//
//
//int main() {
//
//	// (1)创建并初始化链栈
//	LiStack S;
//	initLiStack(S);
//	printStack(S);// 链栈为空
//	cout << "==========================" << endl;
//
//
//	// (2)元素入栈
//	push(S, Element{ "张三", 34, "男" });
//	push(S, Element{ "李四", 27, "女" });
//	push(S, Element{ "王五", 45, "男" });
//	push(S, Element{ "赵六", 75, "男" });
//	printStack(S);
//	cout << "==========================" << endl;
//	//第1位：{ name = 张三, age = 34, sex = 男 }
//	//第2位：{ name = 李四, age = 27, sex = 女 }
//	//第3位：{ name = 王五, age = 45, sex = 男 }
//	//第4位：{ name = 赵六, age = 75, sex = 男 }
//	//栈中元素个数为：4
//
//
//	// (3)获取栈顶元素
//	Element e1;
//	getTop(S, e1);
//	cout << elementToString(e1) << endl;// {name=赵六, age=75, sex=男}
//	cout << "==========================" << endl;
//
//
//	// (4)元素出栈
//	Element e2, e3, e4, e5;
//	pop(S, e2);
//	pop(S, e3);
//	cout << elementToString(e2) << endl;// {name=赵六, age=75, sex=男}
//	cout << elementToString(e3) << endl;// {name=王五, age=45, sex=男}
//	cout << "==========================" << endl;
//	printStack(S);
//	//第1位：{ name = 张三, age = 34, sex = 男 }
//	//第2位：{ name = 李四, age = 27, sex = 女 }
//	//栈中元素个数为：2
//
//	pop(S, e4);
//	pop(S, e5);
//	cout << "==========================" << endl;
//	printStack(S);// 链栈为空
//
//
//	return 0;
//}