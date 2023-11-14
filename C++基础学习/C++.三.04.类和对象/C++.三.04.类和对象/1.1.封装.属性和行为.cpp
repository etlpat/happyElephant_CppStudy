#include<iostream>
using namespace std;
#include<string>




//// 类和对象
// C++面向对象的三大特性：封装、继承、多态
// C++认为万事万物皆为对象，对象上有其属性和行为
//
// 
// 类中的成员包括：属性和行为
// 属性：又叫成员属性、成员变量
// 行为：又叫成员函数、成员方法




//// 封装
// 封装：将属性和行为封装为一个整体，表现生活中的实物
//       将属性和行为加以控制
// 
//
//// 下面是一些基本语法： 
// 
// 1.创建类
// 语法：
//	class 类名
//	{ 
//	访问权限: 
//		属性 / 行为;
//		属性 / 行为;
//		...
//	};
// 
// 2.通过类创建对象：
// 语法：类名 对象名;
// 
// 3.使用对象的属性/行为
// 语法：对象名.属性
//		 对象名.行为




//// 示例1：
//// 设计一个圆类，包含求圆周长的行为
//
//#define pi 3.1415926
//
//class Circle
//{
//// 访问权限(公共权限)
//public:
//
//	// 属性(变量)：半径
//	double r;
//
//	// 行为(函数)：获得周长
//	double getZC()
//	{
//		return 2 * pi * r;
//	}
//};
//
//int main()
//{
//	// 实例化一个圆(通过类，创建一个对象)
//	Circle c1;
//	c1.r = 10;
//	double zc = c1.getZC();
//
//	cout << "半径为：" << c1.r << endl;
//	cout << "周长为：" << zc << endl;
//
//	return 0;
//}




//// 示例2：
//// 设计一个学生类，属性包含姓名学号，行为包含姓名、学号的赋值和打印操作
//
//class Student
//{
//// 公共权限
//public:
//
//	// 属性
//	string name;
//	string id;
//
//	// 行为
//	void setName(string name1) {
//		name = name1;
//	}
//	void setId(string id1) {
//		id = id1;
//	}
//	void showName() {
//		cout << "姓名为：" << name << endl;
//	}
//	void showId() {
//		cout << "学号为：" << id << endl;
//	}
//};
//
//int main()
//{
//	// 创建学生对象
//	Student s1;
//	s1.setName("张三");
//	s1.setId("114514");
//	s1.showName();
//	s1.showId();
//
//	return 0;
//}

