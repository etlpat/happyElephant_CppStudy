#include<iostream>
using namespace std;
#include<string>




////  ���麯���ͳ�����
// �ڶ�̬�У�ͨ���������麯����ʵ���Ǻ�������ģ�������Ҫ���ǵ���������д������
// ��˿��Խ��麯����Ϊ�����麯����
// 
// 
// ���麯���﷨��virtual �������� ������ (�����б�) = 0;
// ���������˴��麯���������Ҳ��Ϊ�������ࡿ
//
// �������ص㣺
// 1.�޷�ʵ��������
// 2.���������д�������еĴ��麯��������Ҳ���ڳ�����




//class Base
//{
//	// �����д��麯�����ͱ���Ϊ�����ࣨ�޷�ʵ��������
//public:
//	// ���麯��
//	virtual void func() = 0;
//};
//
//
//class Son1 : public Base
//{
//public:
//	void func() { cout << "��̬Son1" << endl; }
//};
//class Son2 : public Base
//{
//public:
//	void func() { cout << "��̬Son2" << endl; }
//};
//void do_func(Base& b) {// ʵ�ֶ�̬
//	b.func();
//}
//
//
//int main()
//{
//	//Base b; // �����������޷�ʵ���� 
//	//new Base;
//
//	Son1 s1;
//	Son2 s2;
//	do_func(s1);// ��̬Son1
//	do_func(s2);// ��̬Son2
//
//
//	return 0;
//}