#include<iostream>
using namespace std;
#include<string>




//// ���μ̳�
// �������������̳�ͬһ�����࣬����ĳ����ͬʱ�̳������������ࡣ
// �������ּ̳з�ʽ����Ϊ���μ̳�/��ʯ�̳�
//
// ���μ̳����⣺
// ��B C�̳���A����D�̳���B C��
// ���ϣ�D�ͼ̳�������A�����ݣ�ռ�����ݿռ䣬���Ҳ���������
//
// 
// 
// �������������̳С�
// ��������ʱ���ڼ̳з�ʽ֮ǰ������virtual�ؼ��֣��ɽ�����̳С���ʱ�����Ϊ�����
// ��̳У�����Ӹ���̳е����������ָ�룬ָ��������
// ע�⣺������ֻ����һ�ݣ���ͬ����ͨ����̳еõ��������ָ�룬��ָ��ͬһ��������
// 
// 
// ��̳��﷨��class ���� :virtual public ���� {...};
// ��B��C��̳�A����B��C�̳е�������ͬһ��ռ䣻��D�̳���B��C��DҲֻ��̳е�ͬһ��ռ�




class Animal
{
public:
	int age;
};


// ��������
class Yang1 :public Animal
{ };
// ��������
class Tuo1 :public Animal
{ };
// ����������
class YangTuo1 :public Yang1, public Tuo1
{ };


// ������̳н�����μ̳е����⣺
// virtual�ؼ��֣�ʹ���Ϊ��̳�
// Animal��Ϊ�����
class Yang2 :virtual public Animal// ��̳У�Yang2��Tuo2�̳е���Animal������ͬһ��ռ�
{ };
class Tuo2 :virtual public Animal
{ };
class YangTuo2 :public Yang2, public Tuo2
{ };


int main()
{
	YangTuo1 yt1;
	//yt1.age = 18;// ��������������ͬ����������Ҫ������������
	yt1.Yang1::age = 18;
	yt1.Tuo1::age = 28;
	cout << yt1.Yang1::age << ", " << yt1.Tuo1::age << endl;// 18, 28
	// �������ַ�ʽ������ɶ����ԣ���ռ�������ڴ�


	// ͨ����̳У�ʹ��Yang2��Tuo2�е�age��ͬһ��ռ䣬YangTuo2�̳е���Ҳ����һ��ռ�
	YangTuo2 yt2;
	yt2.Yang2::age = 18;
	yt2.Tuo2::age = 28;
	yt2.age = 38;// ���ڴ����������м̳е�ͬһ��ռ䣬���Բ���������
	cout << yt2.Yang2::age << ", " << yt2.Tuo2::age << ", " << yt2.age << endl;// 38, 38, 38���൱�ڶԿռ丳ֵ�����Σ�

	
	return 0;
}
