#include<iostream>
using namespace std;
#include<string>




//// �������������
// ͨ�����ص����������ʵ�ֶ��������͵ĵ���
// ע�⣺���������Ҫ��Ϊǰ��++ �� ����++
//
// 
// ++�����߼���
//	  1.ǰ��++��ǰ��++������ʽ���ã�������غ�����Ҫ���ض��������
//	  2.����++������++��������ʽ���ã����ֱ�ӷ���ֵ����ǰ�Ķ���Ŀ��������ɷ������ã���Ϊ���˺�����������ڵĿռ䱻�ͷţ�
// ע�⣺����++�������б�ĩβ������� intռλ������Ϊ�˺�ǰ��++�����������أ�
// 
//
// 
// ǰ��++�����﷨��
//	 ��Ա������MyClass& operator++() {...}
//   ȫ�ֺ�����MyClass& operator++(MyClass& m) {...}
// ����++�����﷨��
//	 ��Ա������MyClass operator++(int) {...} // intռλ���� ���ڲ����б�ĩβ
//   ȫ�ֺ�����MyClass operator++(MyClass& m, int) {...}




//class MyClass
//{
//private:
//	friend ostream& operator<<(ostream& cout, const MyClass& m);// ��Ԫ��<<�����غ���
//	//friend MyClass& operator++(MyClass& m);// ��Ԫ��ǰ��++�����غ���
//	//friend MyClass operator++(MyClass& m, int);// ��Ԫ������++�����غ���
//
//	int a;
//	int b;
//
//public:
//	MyClass() :a(0), b(0)
//	{}
//	MyClass(int a1, int b1) :a(a1), b(b1)
//	{}
//
//	// ǰ��++�����غ���
//	MyClass& operator++() {
//		a++;
//		b++;
//		return *this;// ����ǰ��++֧����ʽ���ã��ʷ�������
//	}
//
//	MyClass operator++(int) {// ע�⣺����++�������б�ĩβ������� intռλ����Ϊ�˺�ǰ��++�����������أ�
//		MyClass tmp = *this;
//		a++;
//		b++;
//		return tmp;// ����++��֧����ʽ���ã���������ֵ����ǰ�Ķ���Ŀ���
//		//�����ɷ������ã���Ϊ���˺�����tmp���ڵĿռ䱻�ͷţ�
//	}
//};
//
//
//// ����<<�����
//ostream& operator<<(ostream& cout, const MyClass& m) {
//	cout << m.a << ", " << m.b;
//	return cout;
//}
//
//
////// ȫ�ֺ�������ǰ��++
////MyClass& operator++(MyClass& m) {
////	m.a++;
////	m.b++;
////	return m;
////}
////
////// ȫ�ֺ������غ���++
////MyClass operator++(MyClass& m, int) {// ע�⣺intռλ����Ҫ���ڲ����б�ĩβ
////	MyClass tmp = m;
////	m.a++;
////	m.b++;
////	return tmp;
////}
//
//
//int main()
//{
//	int a = 1;
//	cout << ++(++a) << endl;// 3��ǰ��++������ʽ����
//	//cout << (a++)++ << endl;// ��������++��������ʽ����
//
//
//	MyClass m(10, 20);
//	cout << m << endl;// 10, 20
//
//	cout << ++m << endl;// 11, 21
//	cout << m++ << endl;// 11, 21
//	cout << m << endl;// 12, 22
//
//
//	return 0;
//}