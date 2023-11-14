#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 1000


// 顺序栈(SqStack)：存储结构为顺序表
//
// 注意：顺序栈的结构体中包含：
//	1.存放数据元素的数组首地址arr
//	2.栈顶元素的下标top
// （注意：若不习惯用top，也可以存放栈的元素个数length）



//typedef struct Person {
//	string name;
//	int age;
//	string sex;
//}Element;
//
//
//typedef struct SqStack {
//	Element* arr = NULL;// 数据元素数组的首地址
//	int top = -1;// 栈顶元素的下标
//}SqStack;
//
//
//
//// 方法：初始化栈
//bool initStack(SqStack& S) {
//	if (S.arr) {
//		cout << "栈的数组不为NULL，不能初始化" << endl;
//		return false;
//	}
//
//	S.arr = new Element[MAX_SIZE];// 分配堆区数组空间
//	S.top = -1;// 空栈，令栈顶元素下标为-1
//	return true;
//}
//
//
//// 方法：销毁栈
//bool destroyStack(SqStack& S) {
//	S.top = -1;
//	if (S.arr) {
//		delete[] S.arr;// 释放堆区数组空间
//		S.arr = NULL;
//	}
//	return true;
//}
//
//
//// 入栈【增】
//bool push(SqStack& S, const Element& e) {
//	if (S.top + 1 == MAX_SIZE) {
//		cout << "栈已满，不能入栈元素" << endl;
//		return false;
//	}
//
//	S.arr[++S.top] = e;
//	return true;
//}
//
//
//// 出栈【删】
//bool pop(SqStack& S, Element& e) {
//	if (S.top == -1) {
//		cout << "栈为空栈，不能出栈元素" << endl;
//		return false;
//	}
//
//	e = S.arr[S.top--];
//	return true;
//}
//
//
//// 读取栈顶元素【查】
//bool getTop(const SqStack& S, Element& e) {
//	if (S.top == -1) {
//		cout << "栈为空栈，不能读取栈顶元素" << endl;
//		return false;
//	}
//
//	e = S.arr[S.top];
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
//// 方法：从栈底到栈顶打印栈的数据元素
//void printStack(const SqStack& S) {
//	if (S.top == -1) {
//		cout << "栈为空" << endl;
//		return;
//	}
//
//	for (int i = 0; i <= S.top; i++) {
//		cout << "第" << i + 1 << "位：" << elementToString(S.arr[i]) << endl;
//	}
//}
//
//
//
//
//int main() {
//
//	// (1)创建并初始化栈
//	SqStack S;
//	initStack(S);
//	printStack(S);// 栈为空
//	cout << "==========================" << endl;
//
//
//	// (2)元素入栈
//	push(S, Element{ "张三", 34, "男" });
//	push(S, Element{ "李四", 27, "女" });
//	push(S, Element{ "王五", 45, "男" });
//	printStack(S);
//	cout << "==========================" << endl;
//	//第1位：{ name = 张三, age = 34, sex = 男 }
//	//第2位：{ name = 李四, age = 27, sex = 女 }
//	//第3位：{ name = 王五, age = 45, sex = 男 }
//
//
//	// (3)获取栈顶元素
//	Element e1;
//	getTop(S, e1);
//	cout << elementToString(e1) << endl;// {name=王五, age=45, sex=男}
//	cout << "==========================" << endl;
//
//
//	// (4)元素出栈
//	Element e2, e3, e4;
//	pop(S, e2);
//	pop(S, e3);
//	pop(S, e4);
//	cout << elementToString(e2) << endl;// {name=王五, age=45, sex=男}
//	cout << elementToString(e3) << endl;// {name=李四, age=27, sex=女}
//	cout << elementToString(e4) << endl;// {name=张三, age=34, sex=男}
//	cout << "==========================" << endl;
//	printStack(S);// 栈为空
//
//
//	return 0;
//}