#include<iostream>
using namespace std;
#include<string>
#include<math.h>



//// 案例1：
//// 设计立方体类(Cube)
//// 属性：包括长(m_L)、宽(m_W)、高(m_H)
//// 方法：包含求立方体的面积和体积
//// 分别用全局函数和成员函数判断两个立方体是否相等
//
//
//class Cube
//{
//private:
//	double n_L;
//	double n_W;
//	double n_H;
//
//public:
//	void setInfo(double a, double b, double c) {// 设置立方体信息
//		n_L = a;
//		n_W = b;
//		n_H = c;
//	}
//	
//	double* getInfo() {// 返回存放立方体信息的堆区数组
//		double* arr = new double[3];
//		arr[0] = n_L;
//		arr[1] = n_W;
//		arr[2] = n_H;
//		return arr;
//	}
//
//	double getV() {// 返回长方体体积
//		return  n_L * n_W * n_H;
//	}
//
//	double getS() {// 返回长方体面积
//		return 2 * n_L * n_W + 2 * n_W * n_H + 2 * n_L * n_H;
//	}
//
//	int isSame1(Cube& c1) {// 判断本立方体和传入的立方体对象是否相等，相等返回1，不等返回0
//		double* arr = c1.getInfo();
//		if (arr[0] == n_L && arr[1] == n_W && arr[2] == n_H) {
//			delete[] arr;
//			return 1;
//		}
//		else {
//			delete[] arr;
//			return 0;
//		}
//	}
//};
//
//
//// 判断两立方体是否相等，相等返回1，不等返回0
//int isSame2(Cube& c1, Cube& c2)// 函数参数推荐引用传参，省空间
//{
//	double* arr1 = c1.getInfo();
//	double* arr2 = c2.getInfo();
//	for (int i = 0; i < 3; i++) {
//		if (arr1[i] != arr2[i]) {
//			delete[] arr1;
//			delete[] arr2;
//			return 0;
//		}
//	}
//	delete[] arr1;
//	delete[] arr2;
//	return 1;
//}
//
//
//int main()
//{
//	// 创建立方体对象
//	Cube c1;
//	Cube c2;
//
//	// 设置立方体长宽高
//	c1.setInfo(1, 2, 3);
//	c2.setInfo(3, 2, 1);
//
//	// 打印立方体c1信息
//	cout << "c1信息：";
//	double* arr1 = c1.getInfo();
//	for (int i = 0; i < 3; i++) {
//		cout << arr1[i] << " ";
//	}
//	cout << endl;
//
//	// 获取立方体c1面积、体积
//	cout << "c1面积：" << c1.getS() << endl;
//	cout << "c1体积：" << c1.getV() << endl;
//
//	// 判断两立方体是否相等（全局函数和成员函数分别判断）
//	cout << (isSame2(c1, c2) ? "相等" : "不相等") << endl;
//	cout << (c1.isSame1(c2) ? "相等" : "不相等") << endl;
//	
//	// 释放堆区数组空间
//	delete[] arr1;
//
//	return 0;
//}








//// 案例2
//// 设计一个点类，属性包含xy坐标
//// 设计一个圆类，属性包含圆心和半径，并内置一个判断点和圆关系的成员方法
//
//
//class Point
//{
//private:
//	double x;
//	double y;
//
//public:
//	void setX(double a) { x = a; }
//	double getX() { return x; }
//	void setY(double a) { y = a; }
//	double getY() { return y; }
//};
//
//
//class Circle
//{
//private:
//	int r;// 半径
//	Point center;// 圆心（一个类对象可以做另一个类的成员）
//public:
//
//	void setR(double a) { r = a; }
//	double getR() { return r; }
//	void setCenter(Point& p) { center = p; }
//	Point getCenter() { return center; }
//
//	void PoiCirRelation(Point& a) {
//		double d = pow(a.getX() - center.getX(), 2) + pow(a.getY() - center.getY(), 2);
//		if (d > pow(r, 2))
//			cout << "点在圆外" << endl;
//		else if (d == pow(r, 2))
//			cout << "点在圆上" << endl;
//		else
//			cout << "点在圆内" << endl;
//	}
//};
//
//int main()
//{
//	Circle c;
//	Point center;
//	center.setX(3);
//	center.setY(4);
//	c.setCenter(center);
//	c.setR(5);
//
//	Point p;
//	p.setX(0);
//	p.setY(0);
//	c.PoiCirRelation(p);// 点在圆上
//
//	p.setX(1);
//	p.setY(1);
//	c.PoiCirRelation(p);// 点在圆内
//
//	p.setX(-1);
//	p.setY(-1);
//	c.PoiCirRelation(p);// 点在圆外
//	
//
//	return 0;
//}



