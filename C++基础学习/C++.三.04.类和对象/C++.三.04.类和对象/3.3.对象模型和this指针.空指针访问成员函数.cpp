#include<iostream>
using namespace std;
#include<string>




//// ��ָ����ʳ�Ա����
// C++�п�ָ��Ҳ�ǿ��Ե��ó�Ա�����ģ�����Ҫע����û���õ�thisָ��
// ����õ�thisָ�룬��Ҫ�����жϱ�֤����Ľ�׳��
//
//
// ע�⣺
// ��Ա�����У����еĳ�Ա����Ĭ�϶���(this->��Ա����)����ʽ��ֻ����(this->)����ʾ
// �����Ա������ a Ĭ��Ϊ this->a��
// ��ʱ����thisΪ��ָ�룬�������������Ҫ�����ж���䣬this�ǿ�ָ�룬ֱ��return




//class MyClass
//{
//public:
//	int a;
//	int b;
//	
//	void printClassName() {
//		cout << "MyClass" << endl;
//	}
//
//	void printA() {
//		cout << a << endl;// ����� a Ĭ��Ϊ this->a ����ʽ
//	}
//
//	void printB() {
//		if (!this) {// �ж϶����ָ���Ƿ�Ϊ��ָ��
//			return;
//		}
//		cout << b << endl;// ����� b Ĭ��Ϊ this->b ����ʽ
//	}
//
//
//
//};
//
//
//int main()
//{
//	MyClass* p = NULL;
//
//	// ��ָ��Ҳ�ɵ��ó�Ա����
//	p->printClassName();// MyClass
//
//	//p->printA();// �������
//
//	p->printB();
//
//
//	return 0;
//}