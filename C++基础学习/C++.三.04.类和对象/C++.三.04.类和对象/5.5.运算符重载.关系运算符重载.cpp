#include<iostream>
using namespace std;
#include<string>




//// ��ϵ���������
// ���ã����ع�ϵ������������������Զ������Ͷ�����жԱȲ���
// ���� == != > < ����������ȶԶ���ָ�����ԣ����ز���ֵ
//
// 
// �﷨��
//	��Ա==������bool operator==(Person& p) {...}
//  ��Ա!=������bool operator!=(Person& p) {...}
//	ȫ�֡�������ϵ�����ͬ��




//class Person
//{
//public:
//	string name;
//	int age;
//
//	Person(string str, int n) :name(str), age(n)
//	{}
//
//	bool operator==(Person& p) {// ==��ϵ�����������
//		if (name == p.name && age == p.age)
//			return 1;
//		return 0;
//	}
//
//	bool operator!=(Person& p) {// !=��ϵ�����������
//		if (name != p.name || age != p.age)
//			return 1;
//		return 0;
//	}
//};
//
//
//int main()
//{
//	Person p1("����", 18);
//	Person p2("����", 18);
//	Person p3("����", 25);
//
//	cout << (p1 == p2) << endl;// 1
//	cout << (p1 != p2) << endl;// 0
//	cout << (p1 == p3) << endl;// 0
//	cout << (p1 != p3) << endl;// 1
//
//
//	return 0;
//}