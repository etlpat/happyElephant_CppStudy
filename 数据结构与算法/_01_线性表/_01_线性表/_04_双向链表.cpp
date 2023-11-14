#include<iostream>
using namespace std;
#include<string>




// (循环)双向链表（double linked list）
// 
//	双向链表的结点包括两个指针，指针prior指向前驱结点，指针next指向后继结点
//	循环：头结点的前驱为尾结点，尾结点的后继为头结点






// 数据元素
typedef struct Student {
	string name;
	int age;
	string sex;
}Element;


// 双向链表结点
typedef struct DulNode {
	Element data;
	DulNode* prior;// 前驱指针
	DulNode* next;// 后继指针
}DulNode, *DulLinkList;
// 用typedef将DulNode*定义为DulLinkList，方便用头指针表示整个双向链表



// 方法：初始化双向链表（为头指针创建头结点）
bool initDulLinkList(DulLinkList& L) {
	L = new DulNode;
	L->prior = L;
	L->next = L;
	return true;
}


// 方法：在表头增加一个元素【增】
bool dulListHeadAdd(DulLinkList& L, const Element e) {
	DulNode* p = new DulNode;
	p->data = e;
	p->prior = L;
	p->next = L->next;
	L->next->prior = p;
	L->next = p;
	return true;
}


// 方法：在表尾增加一个元素【增】
bool dulListTailAdd(DulLinkList& L, const Element e) {
	DulNode* p = new DulNode;
	p->data = e;
	p->prior = L->prior;
	p->next = L;
	L->prior->next = p;
	L->prior = p;
	return true;
}


// 方法：在第i个位置插入元素【增】
bool dulListInsert(DulLinkList& L, int i, const Element e) {
	if (i <= 0) {
		cout << "插入位置无效" << endl;
		return false;
	}

	DulNode* p = L;
	while (--i && p->next != L) {// 使p指向第i-1个结点
		p = p->next;
	}
	if (i != 0) {
		cout << "插入位置无效" << endl;
		return false;
	}

	DulNode* newNodePoint = new DulNode;
	newNodePoint->data = e;
	newNodePoint->prior = p;
	newNodePoint->next = p->next;
	p->next->prior = newNodePoint;
	p->next = newNodePoint;
	return true;
}


// 方法：从表头删除一个元素（并将被删数据返回给引用参数）【删】
bool dulListHeadDelete(DulLinkList& L, Element& e) {
	if (L->next == L) {
		cout << "双向链表为空，无法删除元素" << endl;
		return false;
	}

	DulNode* p = L->next;
	e = p->data;
	L->next = p->next;
	L->next->prior = L;
	delete p;
	return true;
}


// 方法：从表尾删除一个元素（并将被删数据返回给引用参数）【删】
bool dulListTailDelete(DulLinkList& L, Element& e) {
	if (L->next == L) {
		cout << "双向链表为空，无法删除元素" << endl;
		return false;
	}

	DulNode* p = L->prior;
	e = p->data;
	L->prior = p->prior;
	L->prior->next = L;
	delete p;
	return true;
}


// 方法：删除指定元素（并将被删数据返回给引用参数）【删】
bool dulListDelete(DulLinkList& L, int i, Element& e) {
	if (i <= 0) {
		cout << "删除位置无效" << endl;
		return false;
	}
	if (L->next == L) {
		cout << "双向链表为空，无法删除元素" << endl;
		return false;
	}

	DulNode* p = L->next;
	while (--i && p->next != L) {// 使p指向第i个结点
		p = p->next;
	}
	if (i != 0) {
		cout << "删除位置无效" << endl;
		return false;
	}

	e = p->data;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return true;
}


// 方法：返回指定位置的元素数据(的指针)【查】
Element* getElement(const DulLinkList& L, int i) {
	if (i <= 0) {
		cout << "查找位置无效" << endl;
		return NULL;
	}
	if (L->next == L) {
		cout << "双向链表为空" << endl;
		return NULL;
	}

	DulNode* p = L->next;
	while (--i && p->next != L) {// 使p指向第i个结点
		p = p->next;
	}
	if (i != 0) {
		cout << "查找位置无效" << endl;
		return NULL;
	}
	return &(p->data);
}


// 方法：按关键字查找元素【查】
Element* getElementForName(const DulLinkList& L, string name) {
	if (L->next == L) {
		cout << "双向链表为空" << endl;
		return NULL;
	}

	DulNode* p = L->next;
	while (p != L) {
		if (p->data.name == name) {
			return &(p->data);
		}
		p = p->next;
	}
	cout << "查找关键字元素不存在" << endl;
	return NULL;
}


// 方法：返回元素的信息
string elementToString(const Element& element) {
	return "{name=" + element.name +
		", age=" + to_string(element.age) +
		", sex=" + element.sex + "}";
}


// 方法：打印双向链表的全部元素
void printDulLinkList(const DulLinkList& L) {
	if (L->next == L) {
		cout << "双向链表为空" << endl;
		return;
	}

	DulNode* p = L->next;
	int i = 1;
	while (p != L) {
		cout << "第" << i << "位：" << elementToString(p->data) << endl;
		p = p->next;
		i++;
	}
}




int main() {

	// (1)定义并初始化双向链表
	DulLinkList L = NULL;
	initDulLinkList(L);
	printDulLinkList(L);// 双向链表为空
	cout << "==============================" << endl;


	// (2)头插法/尾插法
	dulListTailAdd(L, Element{ "张三", 18, "男" });
	dulListTailAdd(L, Element{ "李四", 26, "女" });
	dulListTailAdd(L, Element{ "王五", 37, "男" });
	dulListHeadAdd(L, Element{ "赵六", 31, "女" });
	dulListHeadAdd(L, Element{ "孙七", 55, "男" });
	printDulLinkList(L);
	cout << "==============================" << endl;
	//第1位：{name=孙七, age=55, sex=男}
	//第2位：{name=赵六, age=31, sex=女}
	//第3位：{name=张三, age=18, sex=男}
	//第4位：{name=李四, age=26, sex=女}
	//第5位：{name=王五, age=37, sex=男}


	// (3)在指定位置插入元素 
	dulListInsert(L, 0, Element{ "小明", 7, "男" });// 插入位置无效
	dulListInsert(L, 1, Element{ "小红", 9, "女" });
	dulListInsert(L, 5, Element{ "小夫", 8, "男" });
	dulListInsert(L, 8, Element{ "小玉", 6, "女" });
	dulListInsert(L, 10, Element{ "小诺", 8, "男" });// 插入位置无效
	printDulLinkList(L);
	cout << "==============================" << endl;
	//第1位：{ name = 小红, age = 9, sex = 女 }
	//第2位：{ name = 孙七, age = 55, sex = 男 }
	//第3位：{ name = 赵六, age = 31, sex = 女 }
	//第4位：{ name = 张三, age = 18, sex = 男 }
	//第5位：{ name = 小夫, age = 8, sex = 男 }
	//第6位：{ name = 李四, age = 26, sex = 女 }
	//第7位：{ name = 王五, age = 37, sex = 男 }
	//第8位：{ name = 小玉, age = 6, sex = 女 }


	// (4)查找指定位置的元素
	getElement(L, 0);// 查找位置无效
	cout << elementToString(*getElement(L, 1)) << endl;// {name=小红, age=9, sex=女}
	cout << elementToString(*getElement(L, 3)) << endl;// {name=赵六, age=31, sex=女}
	cout << elementToString(*getElement(L, 6)) << endl;// {name=李四, age=26, sex=女}
	cout << elementToString(*getElement(L, 8)) << endl;// {name=小玉, age=6, sex=女}
	getElement(L, 9);// 查找位置无效
	cout << "==============================" << endl;


	// (5)查找指定关键字的元素
	getElementForName(L, "迪奥");// 查找关键字元素不存在
	getElementForName(L, "铁牛");// 查找关键字元素不存在
	cout << elementToString(*getElementForName(L, "张三")) << endl;// {name=张三, age=18, sex=男}
	cout << elementToString(*getElementForName(L, "小红")) << endl;// {name=小红, age=9, sex=女}
	cout << elementToString(*getElementForName(L, "小玉")) << endl;// {name=小玉, age=6, sex=女}
	cout << "==============================" << endl;


	// (6)删除指定位置的元素
	Element e1, e2, e3, e4, e5;
	dulListDelete(L, 0, e1);// 删除位置无效
	dulListDelete(L, 1, e2);
	dulListDelete(L, 4, e3);
	dulListDelete(L, 6, e4);
	dulListDelete(L, 6, e5);// 删除位置无效
	printDulLinkList(L);
	cout << "==============================" << endl;
	cout << elementToString(e2) << endl;// {name=小红, age=9, sex=女}
	cout << elementToString(e3) << endl;// {name=小夫, age=8, sex=男}
	cout << elementToString(e4) << endl;// {name=小玉, age=6, sex=女}
	cout << "==============================" << endl;
	//第1位：{ name = 孙七, age = 55, sex = 男 }
	//第2位：{ name = 赵六, age = 31, sex = 女 }
	//第3位：{ name = 张三, age = 18, sex = 男 }
	//第4位：{ name = 李四, age = 26, sex = 女 }
	//第5位：{ name = 王五, age = 37, sex = 男 }


	// (7)删除头/尾元素
	Element e6, e7, e8, e9;
	dulListHeadDelete(L, e6);
	dulListTailDelete(L, e7);
	dulListHeadDelete(L, e8);
	dulListTailDelete(L, e9);
	printDulLinkList(L);// 第1位：{name=张三, age=18, sex=男}
	cout << "==============================" << endl;
	cout << elementToString(e6) << endl;// {name=孙七, age=55, sex=男}
	cout << elementToString(e7) << endl;// {name=王五, age=37, sex=男}
	cout << elementToString(e8) << endl;// {name=赵六, age=31, sex=女}
	cout << elementToString(e9) << endl;// {name=李四, age=26, sex=女}
	cout << "==============================" << endl;


	return 0;
}