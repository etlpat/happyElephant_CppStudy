#include<iostream>
using namespace std;
#include<string>




// ������������װ
// ������Ҫ��ɲ���ΪCpu(���ڼ���calculate)���Կ�VideoCard(������ʾdisplay)���ڴ���Memory�����ڴ洢storage��
// ��ÿ������װ�������࣬���ṩ��ͬ����������ͬ�����Intel��Lenovo��
// �����������ṩ�õ��Թ����ĺ��������ҵ���ÿ����������Ľӿ�
// ����ʱ��װ��̨��ͬ�ĵ��Խ��й���




//class Cpu//  CPU������
//{
//public:
//	virtual void calculate() = 0;
//};
//
//class VideoCard// �Կ�������
//{
//public:
//	virtual void display() = 0;
//};
//
//class Memory// �ڴ���������
//{
//public:
//	virtual void storage() = 0;
//};
//
//
//
//class IntelCpu :public Cpu// Ӣ�ض�CPU��
//{
//public:
//	virtual void calculate() {
//		cout << "Ӣ�ض�CPU����" << endl;
//	}
//};
//
//class LenovoCpu :public Cpu// ����CPU��
//{
//public:
//	virtual void calculate() {
//		cout << "����CPU����" << endl;
//	}
//};
//
//
//
//class IntelVideoCard :public VideoCard// Ӣ�ض��Կ���
//{
//public:
//	virtual void display() {
//		cout << "Ӣ�ض��Կ���ʾ" << endl;
//	}
//};
//
//class LenovoVideoCard :public VideoCard// �����Կ���
//{
//public:
//	virtual void display() {
//		cout << "�����Կ���ʾ" << endl;
//	}
//};
//
//
//
//class IntelMemory :public Memory// Ӣ�ض��ڴ�����
//{
//public:
//	virtual void storage() {
//		cout << "Ӣ�ض��ڴ����洢" << endl;
//	}
//};
//
//class LenovoMemory :public Memory// �����ڴ�����
//{
//public:
//	virtual void storage() {
//		cout << "�����ڴ����洢" << endl;
//	}
//};
//
//
//
//class Computer // �����ࣨ����һ����ʵ�������Ķ�̬��
//{
//private:
//	Cpu* cpu;
//	VideoCard* videocard;
//	Memory* memory;
//
//public:
//	Computer(Cpu* c, VideoCard* v, Memory* m) {// ���벻ͬ���ҵ�������ó������������
//		cpu = c;
//		videocard = v;
//		memory = m;
//	}
//
//	void run() {// ʵ�ֶ�̬�ĺ���
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