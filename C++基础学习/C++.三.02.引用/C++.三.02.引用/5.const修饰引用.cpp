#include<iostream>
using namespace std;




//// const��������
// ���ã��ں����β��б��У�������const�����βΣ���ֹ�����
// �÷���const int& b = a;������ͨ������b�ı�a���ڴ棩
//		��ԭ���ǽ� int* const b ����Ϊ const int* const b��
//
//
// �ʣ��������ô���void func(const int& a)��ֵ����void func(int a)�����߶�����ͨ���β��޸�ʵ�Σ����ߵ�������ʲô��
// ��ֵ������Ҫ����һ��ʵ�εĸ�����ռ�ô����ռ䣻���ô��εı����Ǵ���ָ�볣�����̶�ռ4�ֽڡ�



//void printNum(const int& num)
//{
//	cout << num << endl;
//}
//
//int main()
//{
//	int a = 10;
//	printNum(a);
//
//	return 0;
//}








//// const���õ�����д����
// C++��������д����const int& ref = 10;
// ��д��������ʱת��Ϊ��int tmp = 10; const int& ref = tmp;
//                       ϵͳΪ10������һ����ʱ�ռ䣬����ref��Ϊ�ÿռ������
//
//
// int& ref��������ֻ�ܽ��ձ���
// const int& ref�������ÿ��Խ��ճ��������



//int main()
//{
//	//int& ref = 10;// �������ñ������һ������ռ�
//
//	// ������������д��������
//	const int& ref = 10;
//	// ����const֮�󣬱������������޸ģ�int tmp = 10; const int& ref = tmp;
//}