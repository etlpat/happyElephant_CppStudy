#include<iostream>
#include<string>
using namespace std;




//// 结构体
// 结构体属于用户自定义的数据类型，允许用户存储不同的数据类型



//// 结构体的定义
// 
// 语法：
//	struct tag			//struct:结构体关键字  tag:结构体标签    struct tag:结构体类型
//	{
//		member - list;	//成员列表;
//	}variable - list;	//变量列表;（在这里可以创建全局变量）但是写代码尽量不用全局变量
//
// 
// 语法简单记为：struct 结构体名 { 结构体成员列表 };
// 注意：定义结构体时，最后要加分号


//struct Student
//{
//	// 成员列表
//	string name;
//	int age;
//	string sex;
//};

//// 以上结构体相当于一个数据类型，类型名是struct Student（C++中可简写为Student）







//// 创建结构体类型的变量
// 语法：
// 1.struct 结构体名 变量名 = { 成员1, 成员2... };
// 2.定义结构体时在末尾创建(全局)变量
// 3.结构体名 变量名 = { 成员1, 成员2... };
// 
// 注意：如上第3条，C++创建结构体变量时，【struct关键字可以省略】


//struct Student
//{
//	string name;
//	int age;
//	string sex;
//}s2;// 这里创建的是全局变量
//
//int main()
//{
//	// 创建结构体变量
//	struct Student s1 = { "张三", 18, "男" };
//	cout << "姓名：" << s1.name << "，年龄：" << s1.age << "，性别：" << s1.sex << endl;
//
//
//	// s2为结构体后面创建的变量
//	s2.name = "李四";// 注意：string型的字符串可以直接赋值，char arr[20]字符数组不可直接赋值
//	s2.age = 28;
//	s2.sex = "女";
//	cout << "姓名：" << s2.name << "，年龄：" << s2.age << "，性别：" << s2.sex << endl;
//
//
//	// C++创建结构体变量时，可不加struct关键字
//	Student s3 = { "王五", 33, "男" };
//	cout << "姓名：" << s3.name << "，年龄：" << s3.age << "，性别：" << s3.sex << endl;
//
//
//	system("pause");
//	return 0;
//}







//// 结构体成员访问
// 我们可以通过(.)或者(->)操作符来访问结构体变量的成员
// 语法：
// 结构体变量.成员名
// 结构体指针->成员名


//struct Student
//{
//	string name;
//	string sex;
//};
//
//
//int main()
//{
//	Student s = { "张三", "女" };
//	cout << s.name << endl;// 张三
//	s.name = "李四";
//	cout << s.name << endl;// 李四
//
//
//	Student* ps = &s;// 创建结构体指针
//	cout << ps->sex << endl;// 女
//	ps->sex = "男";
//	cout << ps->sex << endl;// 男
//
//
//	return 0;
//}

