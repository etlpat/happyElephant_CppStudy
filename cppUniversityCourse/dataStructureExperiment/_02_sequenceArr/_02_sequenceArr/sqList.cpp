#include<iostream>
using namespace std;
#include<string>
#define MAX_SIZE 100


// 数据元素
typedef struct Element {
	double value;
}Element;

// 顺序表
typedef struct SqList {
	Element arr[MAX_SIZE];// 存放数据元素的数组
	int length;// 顺序表当前长度
}SqList;


// 方法：初始化线性表
void initList(SqList& list) {
	list.length = 0;
}


// 方法：插入元素（在第index个位置插入元素element）
bool listInsert(SqList& list, int index, const Element& element) {
	if (list.length >= MAX_SIZE) {
		cout << "顺序表空间不足" << endl;
		return false;
	}
	if(index < 0 || index > list.length){// 允许插入下标范围：[0, list.length]
		cout << "插入位置超出下标范围" << endl;
		return false;
	}

	for (int i = list.length - 1; i >= index; i--) {// 把插入位置和后面的元素都往后挪1位
		list.arr[i + 1] = list.arr[i];
	}
	list.arr[index] = element;
	list.length++;
	return true;

}


// 方法：按位查找元素（返回指定下标元素）
Element getElement(const SqList& list, int index) {
	if (index < 0 || index > list.length - 1) {
		cout << "查找位置超出下标范围" << endl;
		return { 0 };
	}
	return list.arr[index];
}


// 方法：按照顺序插入元素
bool insertByOrder(SqList& list, double value) {
	if (list.length >= MAX_SIZE) {
		cout << "顺序表空间不足" << endl;
		return false;
	}

	Element e = { value };
	int i = 0;
	if (list.length != 0) {
		while (i < list.length && list.arr[i].value < value) {
			i++;
		}
	}
	return listInsert(list, i, e);
}


// 方法：删除表尾元素（从表尾减少一个元素，并将其返回给引用参数）
bool listSub(SqList& list, Element& element) {
	if (list.length <= 0) {
		cout << "当前为空表，无法返回元素" << endl;
		return false;
	}
	element = list.arr[list.length - 1];
	list.length--;
	return true;
}


// 方法：删除指定元素（删除指定下标的元素，并将其返回给引用参数）
bool listDelete(SqList& list, int index, Element& element) {// 时间复杂度：O(n)
	if (list.length <= 0) {
		cout << "当前为空表，无法返回元素" << endl;
		return false;
	}
	if (index < 0 || index > list.length - 1) {// 允许删除下标范围：[0, list.length-1]
		cout << "删除位置超出下标范围" << endl;
		return false;
	}

	element = list.arr[index];// 把指定下标元素的值赋给引用类型参数
	for (int i = index; i <= list.length - 2; i++) {
		list.arr[i] = list.arr[i + 1];
	}
	list.length--;
	return true;
}


// 方法：按值查找元素下标（查找指定属性元素的下标）
int locateElement(const SqList& list, const double value) {
	for (int i = 0; i < list.length; i++) {
		if (value == list.arr[i].value) {
			return i;
		}
	}
	cout << "元素不存在" << endl;
	return -1;
}


// 方法：返回元素信息
string elementToString(const Element& element) {
	return "value=" + to_string(element.value);
}


// 方法：打印顺序表全部元素
void printList(const SqList& list) {
	if (list.length == 0) {
		cout << "顺序表为空" << endl;
		return;
	}
	for (int i = 0; i < list.length; i++) {
		cout << "第" << i + 1 << "位：" << elementToString(list.arr[i]) << endl;
	}
}


int main() {
	SqList L;
	initList(L);

	insertByOrder(L, 44);
	insertByOrder(L, -10);
	insertByOrder(L, 26);
	insertByOrder(L, 467);
	insertByOrder(L, 6);
	insertByOrder(L, 1);
	insertByOrder(L, 61);
	insertByOrder(L, 7);
	
	printList(L);

	return 0;
}