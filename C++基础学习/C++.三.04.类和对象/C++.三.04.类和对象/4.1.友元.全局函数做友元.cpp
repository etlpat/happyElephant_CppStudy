#include<iostream>
using namespace std;
#include<string>




//// ��Ԫ
// �ڳ������Щ˽������Ҳ���������һЩ���⺯��������з��ʣ�����Ҫ��Ԫ����
// ��Ԫ��Ŀ�ģ���һ�����������࣬������һ�����е�˽�г�Ա
// ��Ԫ�ؼ��֣�friend
//
//
// ��Ԫ������ʵ��
// 1.ȫ�ֺ�������Ԫ��	friend void func(...);
// 2.������Ԫ��			friend class MyClass;
// 3.��Ա��������Ԫ��	friend void MyClass::func(...);
//
//
// �ܽ᣺
// 1.����д���Ĺ�ͬ�﷨��friend ����
// 2.��Ԫ����������λ�ڹ��á�˽�С������������λ���޹ؽ�Ҫ
 


//// ȫ�ֺ�������Ԫ��
// �﷨��friend �������� 
// �磺friend void func();
// ע�⣺�뽫ȫ�ֺ�����Ϊ�����Ԫ��ֻҪ�������﷨д�����м��ɣ�������������˽��Ȩ�޶����ԣ�
// 
// �������﷨д�����У�ȫ�ֺ������������Ԫ����ȫ�ֺ���Ҳ���Է������е�˽�г�Ա��������Ա





//class Building
//{
//private:
//	friend void func(Building* p);// friend + ����������func����Building�����Ԫ
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
//void func(Building* p) {
//	// �ú�����Building�����Ԫ�����Է������е�˽�г�Ա
//	cout << p->bedroom << endl;// ����
//	cout << p->washroom << endl;// ϴ�ּ�
//}
//
//
//int main()
//{
//	Building b;
//	func(&b);
//
//	return 0;
//}

