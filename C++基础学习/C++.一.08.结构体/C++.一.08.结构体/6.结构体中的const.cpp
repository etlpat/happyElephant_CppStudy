#include<iostream>
#include<string>
using namespace std;



//// ����const���νṹ���е�����
// ���ã���ֹ����� 
// ԭ�򣺽ṹ�崫�Σ���ֵ���ݣ����뿪��һ���ռ��Žṹ�����ʱ����������һ���õ�ַ���Ρ�
//	     ʹ�õ�ַ����ʱ������������Ҫ�Ķ��ṹ�����ݣ�Ϊ�˷�ֹ������������const���Ρ�
//
// 
// ע�⣺���ں��������е�ָ��p������һ����const����Ϊ����ָ��
//		 �� const Stu* p��ָ��ָ���ֵ�����޸ģ�
// 
// P.S.�β�дΪconst Stu* const pҲ���ԣ�����������������ָ���Ѿ������ˣ�����һ��дΪconst Stu* p



//struct Stu
//{
//	string name;
//	int age;
//	string sex;
//};
//
//void printStu(const Stu* s)// ��const����ָ�룬��ֹ�����
//{
//	cout << s->name << " " << s->age << " " << s->sex << endl;
//}
//
//int main()
//{
//	Stu s1 = { "����", 18, "��" };
//	printStu(&s1);
//
//	return 0;
//}