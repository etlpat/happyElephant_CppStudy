#include<iostream>
using namespace std;
#include<string>




//// �������������
// Ŀ�ģ�����Զ�����������͵�����
// ȫ�ֺ���ʵ���﷨��ostream& operator<<(ostream& cout, const MyClass& m)
//
// 
// cout����׼������Ķ���������ostream���������
// ע�⣺
//  1.������ cout<<����ֵ �ķ�ʽ������ڲ����б��б����cout����Ҫ����Ķ������
//		�����ڳ�Ա��������Ҫ�����������Ϊ����������޷��ж�cout��<<����໹���Ҳࡣ���Բ����ó�Ա��������<<��
//  2.cout������ȫ��ֻ����һ��������ͨ�����ô���
//  3.����<<������ʽ���ã����Ա��뷵��cout������
//
//
// 
// �������������������Ϊ��Ա������ֻ����ȫ����ʵ�֡�����Ҫ����˽�����ԣ���Ҫ��operator<<������Ϊ�����Ԫ




//class MyClass
//{
//private:
//	friend ostream& operator<<(ostream& cout, const MyClass& m);// ��������������غ�������Ϊ�����Ԫ
//	int a;
//	int b;
//
//public:
//	MyClass() :a(0), b(0)
//	{}
//	MyClass(int a1, int b1) :a(a1), b(b1)
//	{}
//};
//
//
//// ȫ�ֺ����������������
//ostream& operator<<(ostream& cout, const MyClass& m) {// ������operator<<(cout,m),��Ϊcout<<m
//	// ע�⣺cout�Ǳ�׼������Ķ���ȫ��ֻ����һ��������ͨ�����ô���
//	cout << m.a << ", " << m.b;
//	return cout;
//	// ���뷵��cout����������ʽ������������� <<
//}
//
//
//int main()
//{
//	MyClass m(10, 20);
//	
//	// ͨ���������ص�<<�������
//	cout << m << endl;// 10, 20
//
//	// ͨ��ȫ�ֺ����������
//	operator<<(cout, m);// 10, 20
//
//
//	return 0;
//}