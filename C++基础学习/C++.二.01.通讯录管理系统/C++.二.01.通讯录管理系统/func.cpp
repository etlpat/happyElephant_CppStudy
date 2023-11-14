#include"head.h"


void showMenu()// 打印菜单
{
	cout << "*****************************" << endl;
	cout << "******  1、添加联系人  ******" << endl;
	cout << "******  2、显示联系人  ******" << endl;
	cout << "******  3、删除联系人  ******" << endl;
	cout << "******  4、查找联系人  ******" << endl;
	cout << "******  5、修改联系人  ******" << endl;
	cout << "******  6、清空联系人  ******" << endl;
	cout << "******  0、退出通讯录  ******" << endl;
	cout << "*****************************" << endl;
}


int isExist(const AddrBook* p, string name1)// 判断联系人是否存在,存在返回下标，否则返回-1
{
	for (int i = 0; i < p->size; i++) {
		if ((p->PerArr)[i].name == name1) {
			return i;
		}
	}
	return -1;
}


void addOne(AddrBook* p, int i)// 添加一个联系人到i下标处
{
	cout << "请输入联系人姓名：";
	cin >> (p->PerArr)[i].name;
	cout << "请输入联系人性别：";
	cin >> (p->PerArr)[i].sex;
	cout << "请输入联系人年龄：";
	cin >> (p->PerArr)[i].age;
	cout << "请输入联系人电话：";
	cin >> (p->PerArr)[i].phone;
	cout << "请输入联系人地址：";
	cin >> (p->PerArr)[i].addr;
}


void personAdd(AddrBook* p)// 添加联系人
{
	if (p->size == MAX) {
		cout << "通讯录已满，无法添加" << endl;
		return;
	}

	addOne(p, p->size);
	p->size += 1;
	cout << "添加成功" << endl;
}


void printAllPreson(const AddrBook* p)// 打印全部联系人
{
	cout << "—————————————————————————————————————————————————————————————————" << endl;
	if (p->size == 0) {
		cout << "暂无联系人" << endl;
	}
	else {
		for (int i = 0; i < p->size; i++) {
			cout << (p->PerArr)[i].name << "\t"
				<< (p->PerArr)[i].sex << "\t"
				<< (p->PerArr)[i].age << "\t"
				<< (p->PerArr)[i].phone << "\t"
				<< (p->PerArr)[i].addr << endl;
		}
	}
	cout << "—————————————————————————————————————————————————————————————————" << endl;
}


void deletePerson(AddrBook* p)// 按指定姓名删除联系人
{
	string name;
	cout << "请输入删除的联系人姓名：";
	cin >> name;

	int t = isExist(p, name);
	if (t == -1) {
		cout << "查无此人" << endl;
	}
	else {
		for (int i = t; i < p->size - 1; i++) {
			(p->PerArr)[i] = (p->PerArr)[i + 1];
		}
		p->size -= 1;
		cout << "删除成功" << endl;
	}
}


void findPeople(const AddrBook* p)// 查找指定姓名的联系人
{
	string name;
	cout << "请输入查找的联系人姓名：";
	cin >> name;

	int t = isExist(p, name);
	if (t == -1) {
		cout << "查无此人" << endl;
	}
	else {
		cout << "—————————————————————————————————————————————————————————————————" << endl;
		cout << (p->PerArr)[t].name << "\t"
			<< (p->PerArr)[t].sex << "\t"
			<< (p->PerArr)[t].age << "\t"
			<< (p->PerArr)[t].phone << "\t"
			<< (p->PerArr)[t].addr << endl;
		cout << "—————————————————————————————————————————————————————————————————" << endl;
	}
}


void changePeople(AddrBook* p)// 按照姓名修改联系人
{
	string name;
	cout << "请输入修改的联系人姓名：";
	cin >> name;

	int t = isExist(p, name);
	if (t == -1) {
		cout << "查无此人" << endl;
	}
	else {
		addOne(p, t);
		cout << "修改成功" << endl;
	}
}


void clearAll(AddrBook* p)// 清除全部联系人
{
	p->size = 0;
	cout << "联系人已清空" << endl;
}

