#include<iostream>
using namespace std;
#include<string>




//// const���γ�Ա����
//
// 1.��������
//	�﷨�����������б���const�������Ǹ�this��const��
//        �磺void func(...) const {...}
// 
//	ע�⣺1.�������ڲ������޸ĳ�Ա����
//			  ԭ��this��ָ�볣�������������const�������Ǹ�this��const��this���ͱ�Ϊconst MyClass* const this��ָ���ֵ�޷��޸ġ�
//		 		    ���ڳ�Ա���������еĳ�Ա������Ĭ�϶���ͨ��this->�����ã��Ӻ���const���޷��޸ĳ�Ա����
//		  2.��Ա��������ʱ����mutable�ؼ��֣��ڳ���������Ȼ�����޸�
//			  mutable adj.�ɱ��
// 
// 
// 
// 2.������
//	�﷨��const ���� ������;
//	ע�⣺1.������Ҳ�������޸ĳ�Ա���ԣ����޸Ĵ�mutable�ؼ��ֵĳ�Ա��
//        2.������ֻ�ܵ��ó����������ɵ�����ͨ��������Ϊ��ͨ�������޸����ԣ�




//class MyClass
//{
//public:
//	int a;
//	mutable int b;
//
//	void func() {
//		cout << "funcִ��" << endl;
//	}
//
//	void con_func() const {// ����const����������this
//		//a = 100;// �������������޷��޸ĳ�Ա������aĬ��Ϊthis->a��this��Ϊ����ָ�룬a��ֵ�޷��޸ģ�
//		b = 100;// �������п��޸Ĵ�mutable�ؼ������εı���
//		cout << "con_funcִ��" << endl;
//	}
//
//};
//
//
//int main()
//{
//	MyClass m1;
//	m1.func();
//	m1.con_func();
//
//
//	const MyClass m2;// ������
//
//	//m2.a = 10;// �����������޷��޸�����
//	//m2.func()// �����������޷�������ͨ��Ա����
//
//	m2.b = 10; // ��������޸Ĵ�mutable�ؼ������εı���
//	m2.con_func();// ������ֻ�ܵ��ó�����
//
//
//	return 0;
//}

