#include<iostream>
#include<string>
using namespace std;



//// 利用const修饰结构体中的数据
// 作用：防止误操作 
// 原因：结构体传参，若值传递，则须开辟一大块空间存放结构体的临时拷贝，所以一般用地址传参。
//	     使用地址传参时，若函数不需要改动结构体内容，为了防止误操作，建议加const修饰。
//
// 
// 注意：对于函数参数中的指针p，我们一般用const修饰为常量指针
//		 即 const Stu* p（指针指向的值不可修改）
// 
// P.S.形参写为const Stu* const p也可以，不过大多数情况常量指针已经够用了，所以一般写为const Stu* p



//struct Stu
//{
//	string name;
//	int age;
//	string sex;
//};
//
//void printStu(const Stu* s)// 用const修饰指针，防止误操作
//{
//	cout << s->name << " " << s->age << " " << s->sex << endl;
//}
//
//int main()
//{
//	Stu s1 = { "张三", 18, "男" };
//	printStu(&s1);
//
//	return 0;
//}