#include<iostream>
#include<string>
using namespace std;

#define stuNum 2
#define teaNum 2




// 案例1：
// 共有3名老师，每名老师指导5个学生，设计老师和学生的结构体
// 老师的结构体：包含姓名成员、存放5个学生的结数组
// 学生的结构体：包含学生姓名、考试分数
// 最后创建数组存放3名老师，通过函数给每个老师及其所带的学生赋值，并打印出老师数据以及老师所带的学生的数据


//struct Student
//{
//	string name;
//	int score;
//};
//
//struct Teacher
//{
//	string name;
//	Student stuArr[stuNum];
//};
//
//Student* getStuData(Student* p)
//{
//	cout << "请输入学生姓名：";
//	cin >> p->name;
//	cout << "请输入学生分数：";
//	cin >> p->score;
//	return p;
//}
//
//Teacher* getTeaData(Teacher* p)
//{
//	cout << "请输入教师姓名：";
//	cin >> p->name;
//	for (int i = 0; i < stuNum; i++) {
//		cout << i + 1 << "号学生：" << endl;
//		getStuData(p->stuArr + i);
//	}
//	return p;
//}
//
//void printTeaData(const Teacher* p)
//{
//	cout << "————————————————————" << endl;
//	cout << "教师姓名：" << p->name << endl;
//	for (int i = 0; i < stuNum; i++) {
//		cout << "学生" << i + 1 << "：" << (p->stuArr)[i].name << "\t";
//		cout << "分数为：" << (p->stuArr)[i].score << endl;
//	}
//}
//
//int main()
//{
//	Teacher teaArr[teaNum];
//	for (int i = 0; i < teaNum; i++) {
//		getTeaData(teaArr + i);
//	}
//	cout << "\n\n\n";
//	
//	for (int i = 0; i < teaNum; i++) {
//		printTeaData(teaArr + i);
//	}
//
//	system("pause");
//	return 0;
//}









// 案例2：
// 设计一个员工结构体，包括姓名、年龄、性别，员工数据如下：
// {"刘备",43,"男"},{"关羽",23,"男"},{"张飞",53,"男"},{"赵云",42,"男"},{"貂蝉",46,"女"}
// 通过冒泡排序算法，将数组中的员工升序排列，最后打印


//struct Emp
//{
//	string name;
//	int age;
//	string sex;
//};
//
//void swap(Emp* pa, Emp* pb)
//{
//	Emp tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//void f(Emp* empArr, int sz)
//{
//	for (int i = 0; i < sz - 1; i++) {
//		int Flag = 1;
//		for (int j = 0; j < sz - 1 - i; j++) {
//			if (empArr[j].age > empArr[j + 1].age) {
//				swap(empArr + j, empArr + j + 1);
//				Flag = 0;
//			}
//		}
//		if (Flag) {
//			break;
//		}
//	}
//}
//
//void priInfo(Emp* arr, int sz)
//{
//	cout << "——————————————————" << endl;
//	for (int i = 0; i < sz; i++) {
//		cout << arr[i].name << "，" << arr[i].age << "，" << arr[i].sex << endl;
//	}
//	cout << "——————————————————" << endl;
//}
//
//int main()
//{
//	Emp empArr[5] = { {"刘备",43,"男"},{"关羽",23,"男"},{"张飞",53,"男"},{"赵云",42,"男"},{"貂蝉",46,"女"} };
//	int sz = sizeof(empArr) / sizeof(empArr[0]);
//	
//	priInfo(empArr, sz);
//	f(empArr, sz);
//	cout << "\n\n\n";
//	priInfo(empArr, sz);
//
//	system("pause");
//	return 0;
//}



