#include<iostream>
using namespace std;
#include<string>




//// struct��class������
// 
// ��C++�У�struct��class���������ڣ�
// 1.Ĭ�Ϸ���Ȩ�޲�ͬ��class��ԱĬ��Ȩ��Ϊ˽�У�struct��ԱĬ��Ȩ��Ϊ����
// 2.�̳з�ʽ��ͬ��class���Ե��̳кͶ�̳У�structֻ�ܵ��̳�
// 
// ����Ȩ������
//	struct��Ĭ��Ȩ��Ϊ����(public)
//	class�� Ĭ��Ȩ��Ϊ˽��(private)
// 
// 
// ע�⣺C++�У��ṹ����Ҳ����д����,����C���Բ��С�
// ��C++�У��󲿷�ʱ��struct��class��д����ʽû��̫������




//// Ĭ�Ϸ���Ȩ������
//
//struct Stu1
//{
//	string name;// Ĭ��Ȩ�ޣ�����
//
//	void printName() {
//		cout << name << endl;
//	}
//};
//
//class Stu2
//{
//	string name;// Ĭ��Ȩ�ޣ�˽��
//
//	void printName() {
//		cout << name << endl;
//	}
//};
//
//
//int main()
//{
//	Stu1 s1;
//	Stu2 s2;
//
//	// �ṹ���ԱĬ��Ȩ��Ϊ����
//	s1.name = "����";
//	s1.printName();
//
//	// ��ĳ�ԱĬ��Ȩ��Ϊ˽��
//	//s2.name = "����";// ����˽�г�Ա���ɷ���
//	//s2.printName();// ����˽�г�Ա���ɷ���
//
//
//	return 0;
//}