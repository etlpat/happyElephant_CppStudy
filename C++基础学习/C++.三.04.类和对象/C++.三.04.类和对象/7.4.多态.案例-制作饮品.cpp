#include<iostream>
using namespace std;
#include<string>




// ������������Ʒ
// ������Ʒ��������Ϊ����ˮ�����ݡ����뱭�С����븨��
// ���ö�̬����ʵ�ֱ��������ṩ����������Ʒ���࣬�ṩ�����������ȺͲ�Ҷ




//class AbstractDrinking// ������
//{
//public:
//	// ���麯��
//	virtual void Boil() = 0;// ��ˮ
//	virtual void Brew() = 0;// ����
//	virtual void PourInCup() = 0;// װ��
//	virtual void PutSth() = 0;// ����
//
//	void makeDrink()// ������Ʒ
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
//		cout << "������ˮ" << endl;
//	}
//	virtual void Brew() {
//		cout << "���ݿ���" << endl;
//	}
//	virtual void PourInCup() {
//		cout << "���뿧�ȱ�" << endl;
//	}
//	virtual void PutSth() {
//		cout << "������" << endl;
//	}
//};
//
//
//class Tea :public AbstractDrinking
//{
//public:
//	virtual void Boil() {
//		cout << "���Ȫˮ" << endl;
//	}
//	virtual void Brew() {
//		cout << "���ݲ�Ҷ" << endl;
//	}
//	virtual void PourInCup() {
//		cout << "����豭" << endl;
//	}
//	virtual void PutSth() {
//		cout << "�������" << endl;
//	}
//};
//
//
//void DoWork(AbstractDrinking& d)// ��̬������Ʒ
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
//	c.makeDrink();// ���ü̳��Ը����������Ʒ����
//	t.makeDrink();
//
//	DoWork(c);// ��̬������Ʒ
//	DoWork(t);
//
//	return 0;
//}