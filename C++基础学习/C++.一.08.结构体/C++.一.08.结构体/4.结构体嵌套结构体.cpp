#include<iostream>
#include<string>
using namespace std;



// 结构体内可以嵌套结构体
// 如下，结构体Teacher中包含结构体Student


//struct Student
//{
//	string name;
//	string sex;
//};
//
//struct Teacher
//{
//	int id;
//	string name;
//	int age;
//	Student stu;
//};
//
//int main()
//{
//	Teacher t1 = { 114, "老王", 54, {"张三", "男"} };
//	cout << t1.stu.name << endl;// 张三
//	t1.stu.name = "李四";
//	cout << t1.stu.name << endl;// 李四
//
//	// t1.stu访问到学生结构体
//	// t1.stu.name访问到学生的名字
//
//	return 0;
//}

