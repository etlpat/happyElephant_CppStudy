#include<iostream>
using namespace std;
#include<string>




// 案例：制作饮品
// 制作饮品大致流程为：煮水、冲泡、倒入杯中、加入辅料
// 利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶




//class AbstractDrinking// 抽象父类
//{
//public:
//	// 纯虚函数
//	virtual void Boil() = 0;// 煮水
//	virtual void Brew() = 0;// 冲泡
//	virtual void PourInCup() = 0;// 装杯
//	virtual void PutSth() = 0;// 加料
//
//	void makeDrink()// 制作饮品
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		PutSth();
//	}
//};
//
//
//class Coffee :public AbstractDrinking
//{
//public:
//	virtual void Boil() {
//		cout << "煮自来水" << endl;
//	}
//	virtual void Brew() {
//		cout << "冲泡咖啡" << endl;
//	}
//	virtual void PourInCup() {
//		cout << "倒入咖啡杯" << endl;
//	}
//	virtual void PutSth() {
//		cout << "加入糖" << endl;
//	}
//};
//
//
//class Tea :public AbstractDrinking
//{
//public:
//	virtual void Boil() {
//		cout << "煮矿泉水" << endl;
//	}
//	virtual void Brew() {
//		cout << "冲泡茶叶" << endl;
//	}
//	virtual void PourInCup() {
//		cout << "倒入茶杯" << endl;
//	}
//	virtual void PutSth() {
//		cout << "加入枸杞" << endl;
//	}
//};
//
//
//void DoWork(AbstractDrinking& d)// 多态制作饮品
//{
//	d.makeDrink();
//}
//
//
//int main()
//{
//	Coffee c;
//	Tea t;
//
//	c.makeDrink();// 调用继承自父类的制作饮品函数
//	t.makeDrink();
//
//	DoWork(c);// 多态制作饮品
//	DoWork(t);
//
//	return 0;
//}