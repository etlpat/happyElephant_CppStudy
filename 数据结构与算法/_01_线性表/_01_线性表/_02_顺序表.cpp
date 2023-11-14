#include<iostream>
using namespace std;
#include<string>

#define MAX_SIZE 100


// 顺序表（sequence list）
//
// (1)定义 
//	顺序表，即用顺序存储(数组)的方式实现线性表
//	
// (2)顺序表特点
//	1.随机访问（可以直接访问指定下标的元素），O(1)时间内可找到第i个元素
//	2.存储密度高，每个结点只存储数据元素
//	3.拓展容量不方便
//	4.插入、删除不方便，需要移动大量元素
//
//
// 
// (3)顺序表实现
//	以下为顺序表的实现
//	注意：本次利用栈区数组实现线性表，在创建SqList结构体同时开辟栈区空间
//	建议：定义SqList结构体时，结构体中存放Element*类型的数组首地址，在调用initList初始化时，为数组new堆区空间






//// 数据元素
//typedef struct Student {
//	string name;
//	int age;
//	string sex;
//}Element;
//
//
//// 顺序表
//typedef struct SqList {
//	Element arr[MAX_SIZE];// 存放数据元素的数组
//	int length;// 顺序表当前长度
//}SqList;
//
//
//
//
//// 方法：初始化线性表
//void initList(SqList& list) {
//	list.length = 0;
//}
//
//
//// 方法：增加元素（在表尾增加一个元素）
//bool listAdd(SqList& list, const Element& element) {
//	if (list.length >= MAX_SIZE) {
//		cout << "顺序表空间不足" << endl;
//		return false;
//	}
//	list.arr[list.length] = element;
//	list.length++;
//	return true;
//}
//
//
//// 方法：插入元素（在第index个位置插入元素element）
////	时间复杂度：O(n)
//bool listInsert(SqList& list, int index, const Element& element) {
//	if (list.length >= MAX_SIZE) {
//		cout << "顺序表空间不足" << endl;
//		return false;
//	}
//	if(index < 0 || index > list.length){// 允许插入下标范围：[0, list.length]
//		cout << "插入位置超出下标范围" << endl;
//		return false;
//	}
//
//	for (int i = list.length - 1; i >= index; i--) {// 把插入位置和后面的元素都往后挪1位
//		list.arr[i + 1] = list.arr[i];
//	}
//	list.arr[index] = element;
//	list.length++;
//	return true;
//
//}
//
//
//// 方法：删除表尾元素（从表尾减少一个元素，并将其返回给引用参数）
//bool listSub(SqList& list, Element& element) {
//	if (list.length <= 0) {
//		cout << "当前为空表，无法返回元素" << endl;
//		return false;
//	}
//	element = list.arr[list.length - 1];
//	list.length--;
//	return true;
//}
//
//
//// 方法：删除指定元素（删除指定下标的元素，并将其返回给引用参数）
//bool listDelete(SqList& list, int index, Element& element) {// 时间复杂度：O(n)
//	if (list.length <= 0) {
//		cout << "当前为空表，无法返回元素" << endl;
//		return false;
//	}
//	if (index < 0 || index > list.length - 1) {// 允许删除下标范围：[0, list.length-1]
//		cout << "删除位置超出下标范围" << endl;
//		return false;
//	}
//
//	element = list.arr[index];// 把指定下标元素的值赋给引用类型参数
//	for (int i = index; i <= list.length - 2; i++) {
//		list.arr[i] = list.arr[i + 1];
//	}
//	list.length--;
//	return true;
//}
//
//
//// 方法：按位查找元素（返回指定下标元素）
//Element getElement(const SqList& list, int index) {
//	if (index < 0 || index > list.length - 1) {
//		cout << "查找位置超出下标范围" << endl;
//		return { NULL, 0, NULL };
//	}
//	return list.arr[index];
//}
//
//
//// 方法：按值查找元素下标（查找指定属性元素的下标）
//int locateElement(const SqList& list, const string& name) {
//	for (int i = 0; i < list.length; i++) {
//		if (name == list.arr[i].name) {
//			return i;
//		}
//	}
//	cout << "元素不存在" << endl;
//	return -1;
//}
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
//void printList(const SqList& list) {
//	if (list.length == 0) {
//		cout << "顺序表为空" << endl;
//		return;
//	}
//	for (int i = 0; i < list.length; i++) {
//		cout << "第" << i+1 << "位：" << elementToString(list.arr[i]) << endl;
//	}
//}
//
//
//
//
//
//int main() {
//	//  1.创建线性表
//	SqList list1;
//
//
//	// 2.初始化线性表
//	initList(list1);
//	printList(list1);// 顺序表为空
//	cout << endl;
//
//
//
//	// 3.增加元素
//	Element e1 = { "张三", 12, "男" };
//	Element e2 = { "李四", 14, "女" };
//	Element e3 = { "王五", 15, "男" };
//	listAdd(list1, e1);
//	listAdd(list1, e2);
//	listAdd(list1, e3);
//	printList(list1);
//	cout << endl;
//	//	第1位：{ name = 张三, age = 12, sex = 男 }
//	//	第2位：{ name = 李四, age = 14, sex = 女 }
//	//	第3位：{ name = 王五, age = 15, sex = 男 }
//
//
//	// 4.插入(指定下标)元素
//	Element e4 = { "小明", 44, "男" };
//	Element e5 = { "小红", 54, "女" };
//	Element eTest1;
//	listInsert(list1, 3, e4);
//	listInsert(list1, 1, e5);
//	listInsert(list1, 100, eTest1);// 插入位置超出下标范围
//	cout << "===============" << endl;
//	printList(list1);
//	cout << endl;
//	//	第1位：{ name = 张三, age = 12, sex = 男 }
//	//	第2位：{ name = 小红, age = 54, sex = 女 }
//	//	第3位：{ name = 李四, age = 14, sex = 女 }
//	//	第4位：{ name = 王五, age = 15, sex = 男 }
//	//	第5位：{ name = 小明, age = 44, sex = 男 }
//
//
//
//	// 5.按位(下标)查找元素
//	Element ret1 = getElement(list1, 2);
//	cout << elementToString(ret1) << endl << endl;// {name=李四, age=14, sex=女}
//
//	// 6.按值(姓名)查找元素下标
//	cout << locateElement(list1, "小红") << endl;// 1
//	cout << locateElement(list1, "烫烫烫") << endl << endl;// 元素不存在，-1
//
//
//
//	// 7.减少(表尾)元素
//	Element e6;
//	listSub(list1, e6);
//	cout << "===============" << endl;
//	cout << elementToString(e6) << endl;// {name=小明, age=44, sex=男}
//	cout << "===============" << endl;
//	printList(list1);
//	cout << endl;
//	//	第1位：{ name = 张三, age = 12, sex = 男 }
//	//	第2位：{ name = 小红, age = 54, sex = 女 }
//	//	第3位：{ name = 李四, age = 14, sex = 女 }
//	//	第4位：{ name = 王五, age = 15, sex = 男 }
//
//
//	// 8.删除(指定下标)元素
//	Element e7, e8, eTest2;
//	listDelete(list1, 1, e7);
//	listDelete(list1, 0, e8);
//	listDelete(list1, 100, eTest2);// 删除位置超出下标范围
//	cout << "===============" << endl;
//	cout << elementToString(e7) << endl;// {name=小红, age=54, sex=女}
//	cout << elementToString(e8) << endl;// {name=张三, age=12, sex=男}
//	cout << "===============" << endl;
//	printList(list1);
//	cout << endl;
//	//	第1位：{ name = 李四, age = 14, sex = 女 }
//	//	第2位：{ name = 王五, age = 15, sex = 男 }
//
//
//	return 0;
//}