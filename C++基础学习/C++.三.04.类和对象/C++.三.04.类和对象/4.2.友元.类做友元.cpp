#include<iostream>
using namespace std;
#include<string>




//// ������Ԫ
//
// ���䣺�������
//  �﷨��class ����;
//  �磺class MyClass��// ����MyClass��
//
// ������Ԫ
// �﷨��friend �������;
// �磺friend class MyClass;
// ע�⣺�����ϴ���д����2�У�MyClass�������2����Ԫ����MyClass��Ҳ�ɷ�����2��˽�г�Ա


 

//class Building
//{
//private:
//	friend class Person;// friend + ���������Person�����Building�����Ԫ
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
//class Person
//{
//public:
//	string name;
//	Building* pb;
//
//	Person() {// ��������
//		name = "xxx";
//		pb = new Building;// �ڶ�����������new ����
//	}
//
//	void visit() {
//		// Person����Building�����Ԫ�����Է������е�˽�б���
//		cout << pb->bedroom << ", ";
//		cout << pb->washroom << endl;
//	}
//};
//
//
//int main()
//{
//	Person p;
//	p.visit();// ����, ϴ�ּ�
//
//	return 0;
//}