#include<iostream>
using namespace std;
#include<string>




// 案例：电脑组装
// 电脑主要组成部件为Cpu(用于计算calculate)，显卡VideoCard(用于显示display)，内存条Memory（用于存储storage）
// 将每个零解封装出抽象类，并提供不同厂商生产不同零件（Intel、Lenovo）
// 创建电脑类提供让电脑工作的函数，并且调用每个零件工作的接口
// 测试时组装三台不同的电脑进行工作




//class Cpu//  CPU抽象类
//{
//public:
//	virtual void calculate() = 0;
//};
//
//class VideoCard// 显卡抽象类
//{
//public:
//	virtual void display() = 0;
//};
//
//class Memory// 内存条抽象类
//{
//public:
//	virtual void storage() = 0;
//};
//
//
//
//class IntelCpu :public Cpu// 英特尔CPU类
//{
//public:
//	virtual void calculate() {
//		cout << "英特尔CPU计算" << endl;
//	}
//};
//
//class LenovoCpu :public Cpu// 联想CPU类
//{
//public:
//	virtual void calculate() {
//		cout << "联想CPU计算" << endl;
//	}
//};
//
//
//
//class IntelVideoCard :public VideoCard// 英特尔显卡类
//{
//public:
//	virtual void display() {
//		cout << "英特尔显卡显示" << endl;
//	}
//};
//
//class LenovoVideoCard :public VideoCard// 联想显卡类
//{
//public:
//	virtual void display() {
//		cout << "联想显卡显示" << endl;
//	}
//};
//
//
//
//class IntelMemory :public Memory// 英特尔内存条类
//{
//public:
//	virtual void storage() {
//		cout << "英特尔内存条存储" << endl;
//	}
//};
//
//class LenovoMemory :public Memory// 联想内存条类
//{
//public:
//	virtual void storage() {
//		cout << "联想内存条存储" << endl;
//	}
//};
//
//
//
//class Computer // 电脑类（利用一个类实现类对象的多态）
//{
//private:
//	Cpu* cpu;
//	VideoCard* videocard;
//	Memory* memory;
//
//public:
//	Computer(Cpu* c, VideoCard* v, Memory* m) {// 传入不同厂家的零件，用抽象父类接收子类
//		cpu = c;
//		videocard = v;
//		memory = m;
//	}
//
//	void run() {// 实现多态的函数
//		cpu->calculate();
//		videocard->display();
//		memory->storage();
//	}
//};
//
//
//
//int main()
//{
//	Cpu* ic = new IntelCpu;
//	Cpu* lc = new LenovoCpu;
//	VideoCard* iv = new IntelVideoCard;
//	VideoCard* lv = new LenovoVideoCard;
//	Memory* im = new IntelMemory;
//	Memory* lm = new LenovoMemory;
//
//	Computer* c1 = new Computer(ic, iv, im);
//	c1->run();
//	cout << "------------------------" << endl;
//
//	Computer* c2 = new Computer(lc, lv, lm);
//	c2->run();
//	cout << "------------------------" << endl;
//	
//	Computer* c3 = new Computer(ic, lv, im);
//	c3->run();
//
//
//	delete c1;
//	delete c2;
//	delete c3;
//	delete ic;
//	delete lc;
//	delete iv;
//	delete lv;
//	delete im;
//	delete lm;
//
//
//	return 0;
//}