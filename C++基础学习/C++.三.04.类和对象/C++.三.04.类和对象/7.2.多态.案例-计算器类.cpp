#include<iostream>
using namespace std;
#include<string>




// ��������������
// �ֱ�������ͨд���Ͷ�̬д������ƶ�������������������ļ�����
//
// ��̬�ô���
// 1.��֯�ṹ����
// 2.�ɶ���ǿ
// 3.������չά���Ը�





//class Calculator1// ��ͨд��
//{
//public:
//	double num1;
//	double num2;
//
//	Calculator1() :num1(0), num2(0) {}
//	Calculator1(double a, double b) :num1(a), num2(b) {}
//
//	double getResult(char ch) {
//		switch (ch)
//		{
//		case '+':
//			return num1 + num2;
//		case '-':
//			return num1 - num2;
//		case '*':
//			return num1 * num2;
//		case '/':
//			return num1 / num2;
//		default:
//			cout << "����Ƿ�������" << endl;
//		}
//	}
//};
//
//
//int main()
//{
//	// ��ͨд���ļ�����
//	Calculator1 c1(3, 2);
//	cout << c1.getResult('+') << endl;// 5
//	cout << c1.getResult('-') << endl;// 1
//	cout << c1.getResult('*') << endl;// 6
//	cout << c1.getResult('/') << endl;// 1.5
//
//
//	return 0;
//}






//// ʵ�ʿ������ᳫһ��ԭ�򣺿���ԭ��
//// ����չ���п��ţ����޸Ľ��йرգ���Ӵ���ʱ�����޸�֮ǰ��Դ�룬����ֱ�������չ��
//
//
//class AbstractCalculator// ������ĳ�����
//{
//public:
//	double num1;
//	double num2;
//
//	AbstractCalculator() :num1(0), num2(0) {}
//
//	virtual double getResult() { return 0; }
//};
//
//class jiaCalculator :public AbstractCalculator// �ӷ���������
//{
//public:
//	jiaCalculator(double a, double b) {
//		num1 = a;
//		num2 = b;
//	}
//
//	double getResult() {// �麯����д
//		return num1 + num2;
//	}
//};
//
//class jianCalculator :public AbstractCalculator// ������������
//{
//public:
//	jianCalculator(double a, double b) {
//		num1 = a;
//		num2 = b;
//	}
//
//	double getResult() {// �麯����д
//		return num1 - num2;
//	}
//};
//
//class chengCalculator :public AbstractCalculator// �˷���������
//{
//public:
//	chengCalculator(double a, double b) {
//		num1 = a;
//		num2 = b;
//	}
//
//	double getResult() {// �麯����д
//		return num1 * num2;
//	}
//};
//
//class chuCalculator :public AbstractCalculator// ������������
//{
//public:
//	chuCalculator(double a, double b) {
//		num1 = a;
//		num2 = b;
//	}
//
//	double getResult() {// �麯����д
//		return num1 / num2;
//	}
//};
//
//double Calculator2(AbstractCalculator& ac)// ʵ�ֶ�̬�ĺ���
//{
//	return ac.getResult();
//}
//
//
//
//int main()
//{
//	// ��̬д���ļ�����
//	jiaCalculator a(3,2);
//	cout << Calculator2(a) << endl;// 5
//
//	jianCalculator b(3,2);
//	cout << Calculator2(b) << endl;// 1
//
//	chengCalculator c(3,2);
//	cout << Calculator2(c) << endl;// 6
//
//	chuCalculator d(3,2);
//	cout << Calculator2(d) << endl;// 1.5
//
//
//	return 0;
//}


