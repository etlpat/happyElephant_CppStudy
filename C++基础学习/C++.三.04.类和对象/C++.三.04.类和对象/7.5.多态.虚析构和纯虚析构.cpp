#include<iostream>
using namespace std;
#include<string>




//// �������ʹ�������
// ��̬ʹ��ʱ�������������������Կ��ٵ���������ô�øö���ĸ���ָ�����ͷ�ʱ�޷����õ�������������룬����ڴ�й©
// �����ʽ������������������Ϊ��������������
//
// 
// �������ʹ��������Ĺ��ԣ�
//		1.���ý������ָ���ͷ�������������
//		2.����Ҫ�о���ĺ���ʵ�֣���ʹ�Ǵ���ҲҪ����ʵ�֣�
// �������ʹ�������������
//		���ڴ������������ǳ����࣬�޷�ʵ��������
// 
// 
// �������﷨��
//		virtual ~����() { }
// ���������﷨�� 
//		virtual ~����() = 0; 
//		ע�⣺��������֮��Ҳ����������ʵ�֣�ԭ���������д��ڶ������ݣ���Ҫ�����������ͷţ�
//			  ����ʵ�֣�����::~����() { }  






//// ����ָ��������ʱ��������������е��������������������ж������ԣ��ڴ�й©
//class Animal
//{
//public:
//	Animal() {
//		cout << "Animal����" << endl;
//	}
//	~Animal() {
//		cout << "Animal����" << endl;
//	}
//
//	virtual void speak() {}
//};
//
//class Cat : public Animal
//{
//public:
//	string* p_name;
//	Cat(string str) {
//		cout << "Cat����" << endl;
//		p_name = new string(str);
//	}
//	~Cat() {
//		cout << "Cat����" << endl;
//		if (p_name) {
//			delete p_name;
//			p_name = NULL;
//		}
//	}
//
//	virtual void speak() {
//		cout << *p_name << "��������" << endl;
//	}
//};
//
//int main()
//{
//	// ���⣺���������ϣ�1.����Ը����麯����д 2.�����ָ�������ִ�������������Ƕ�̬
//
//	Animal* animal = new Cat("Tom");// Animal���죬Cat����
//	animal->speak();// Tom��������
//	delete animal;// Animal����
//	
//	// ����ָ��������ʱ��������������е��������������������ж������ԣ����ڴ�й©
//
//	return 0;
//}







//// ���������������ܹ�����������⣺
//
//// ��1����������
//class Animal1
//{
//public:
//	Animal1() {
//		cout << "Animal����" << endl;
//	}
//	virtual ~Animal1() {// ������
//		cout << "Animal������" << endl;
//	}
//	virtual void speak() {}
//};
//
//class Cat1 : public Animal1
//{
//public:
//	string* p_name;
//	Cat1(string str) {
//		cout << "Cat����" << endl;
//		p_name = new string(str);
//	}
//	~Cat1() {
//		cout << "Cat����" << endl;
//		if (p_name) {
//			delete p_name;
//			p_name = NULL;
//		}
//	}
//	virtual void speak() {
//		cout << *p_name << "��������" << endl;
//	}
//};
//
//void test1() {
//	Animal1* animal1 = new Cat1("Tom");
//	animal1->speak();
//	delete animal1;
//
//	//Animal����
//	//Cat����
//	//Tom��������
//	//Cat����// ���������������
//	//Animal������
//}
//
//
//
//// ��2����������
//class Animal2
//{
//public:
//	Animal2() {
//		cout << "Animal����" << endl;
//	}
//	virtual ~Animal2() = 0;// ��������
//	virtual void speak() {}
//};
//
//Animal2:: ~Animal2() {// ��������ҲҪ������ʵ�֣�ԭ���������д��ڶ������ݣ���Ҫ�����������ͷţ�
//	cout << "Animal��������" << endl;
//}
//
//class Cat2 : public Animal2
//{
//public:
//	string* p_name;
//	Cat2(string str) {
//		cout << "Cat����" << endl;
//		p_name = new string(str);
//	}
//	~Cat2() {
//		cout << "Cat����" << endl;
//		if (p_name) {
//			delete p_name;
//			p_name = NULL;
//		}
//	}
//	virtual void speak() {
//		cout << *p_name << "��������" << endl;
//	}
//};
//
//void test2() {
//	Animal2* animal2 = new Cat2("Tom");
//	animal2->speak();
//	delete animal2;
//
//	//Animal����
//	//Cat����
//	//Tom��������
//	//Cat����// ���������������
//	//Animal��������
//}
//
//
//
//int main()
//{
//	test1();
//	cout << endl;
//	test2();
//
//	return 0;
//}
