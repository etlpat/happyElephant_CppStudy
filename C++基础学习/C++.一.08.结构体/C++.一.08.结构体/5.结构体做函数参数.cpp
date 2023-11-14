#include<iostream>
#include<string>
using namespace std;




//// 结构体作为参数向函数中传递
// 传递方式有两种：
// 1.值传递
// 2.地址传递
//
// 注意：形参是实参的临时拷贝，值传递时，会在内存中开辟一块结构体大小的空间，若结构体过大，系统开销大，导致性能下降
//		 所以为了节省空间，在结构体传参时一般使用地址传参。




//struct Student
//{
//	string name;
//	int age;
//	string sex;
//};
//
//void printStudent(Student s)
//{
//	cout << s.name << " " << s.age << " " << s.sex << endl;
//}
//
//Student* clearStudent(Student* p)
//{
//	p->name = "\0";
//	p->age = 0;
//	p->sex = "\0";
//	return p;
//}
//
//int main()
//{
//	Student s1 = { "张三", 18, "男" };
//	printStudent(s1);
//	clearStudent(&s1);
//	printStudent(s1);
//
//	return 0;
//}

