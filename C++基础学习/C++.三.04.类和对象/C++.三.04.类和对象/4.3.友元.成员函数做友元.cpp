#include<iostream>
using namespace std;
#include<string>




//// ��Ա��������Ԫ
// �﷨��friend ��Ա�������� ������� ������::��
// �磺friend void MyClass::func();
// ע�⣺�����ϴ���д����2�У�MyClass��ĳ�Ա����func������2����Ԫ
//
//
// ��Ա��������Ԫ������뻷����ͬ�������bug��ƽʱֱ����������Ԫ����




//class Building;
//
//
//class Person
//{
//private:
//	Building* pb;
//
//public:
//	Person() {
//		pb = new Building;
//	}
//
//	void visit(); // visit������������������ʵ��
//};
//
//
//class Building
//{
//private:
//	friend void Person::visit();// ��Ա��������Ԫ����Ա��������ʱ��������
//
//	string bedroom;
//	string washroom;
//
//public:
//	Building() :bedroom("����"), washroom("ϴ�ּ�")
//	{ }
//};
//
//
//void Person::visit() {// visit������ʵ�֣�����ʵ�ֳ�Ա����Ҫ��������
//	cout << pb->bedroom << endl;
//	cout << pb->washroom << endl;
//}
//
//
//int main()
//{
//	Person p;
//	p.visit();
//
//	return 0;
//}


