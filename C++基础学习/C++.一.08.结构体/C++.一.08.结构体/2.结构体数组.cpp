#include<iostream>
#include<string>
using namespace std;



//// 结构体数组：元素都是结构体的数组
// 
// 结构体数组也是数组，遵循数组的一切原则：
// 如：数组名是首元素地址
//	   元素未填满，其余位置自动补0
// 
// 
// 语法：(与创建数组的语法相同)
// 1.struct 结构体类型名 数组名[元素个数] = { 元素列表 };
// 2.结构体类型名 数组名[元素个数] = { 元素列表 };// struct可省略


//struct Stu
//{
//	string name;
//	int age;
//	string sex;
//};
//
//int main()
//{
//	Stu arr[10] = { {"张三",18,"男"} };// 剩余位置自动补0
//	arr[1].name = "李四";
//	arr[1].age = 12;
//	arr[1].sex = "女";
//
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
//		cout << arr[i].name << " " << arr[i].age << " " << arr[i].sex << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}
