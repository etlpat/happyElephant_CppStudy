#include<iostream>
#include<string>
using namespace std;

#define stuNum 2
#define teaNum 2




// ����1��
// ����3����ʦ��ÿ����ʦָ��5��ѧ���������ʦ��ѧ���Ľṹ��
// ��ʦ�Ľṹ�壺����������Ա�����5��ѧ���Ľ�����
// ѧ���Ľṹ�壺����ѧ�����������Է���
// ��󴴽�������3����ʦ��ͨ��������ÿ����ʦ����������ѧ����ֵ������ӡ����ʦ�����Լ���ʦ������ѧ��������


//struct Student
//{
//	string name;
//	int score;
//};
//
//struct Teacher
//{
//	string name;
//	Student stuArr[stuNum];
//};
//
//Student* getStuData(Student* p)
//{
//	cout << "������ѧ��������";
//	cin >> p->name;
//	cout << "������ѧ��������";
//	cin >> p->score;
//	return p;
//}
//
//Teacher* getTeaData(Teacher* p)
//{
//	cout << "�������ʦ������";
//	cin >> p->name;
//	for (int i = 0; i < stuNum; i++) {
//		cout << i + 1 << "��ѧ����" << endl;
//		getStuData(p->stuArr + i);
//	}
//	return p;
//}
//
//void printTeaData(const Teacher* p)
//{
//	cout << "����������������������������������������" << endl;
//	cout << "��ʦ������" << p->name << endl;
//	for (int i = 0; i < stuNum; i++) {
//		cout << "ѧ��" << i + 1 << "��" << (p->stuArr)[i].name << "\t";
//		cout << "����Ϊ��" << (p->stuArr)[i].score << endl;
//	}
//}
//
//int main()
//{
//	Teacher teaArr[teaNum];
//	for (int i = 0; i < teaNum; i++) {
//		getTeaData(teaArr + i);
//	}
//	cout << "\n\n\n";
//	
//	for (int i = 0; i < teaNum; i++) {
//		printTeaData(teaArr + i);
//	}
//
//	system("pause");
//	return 0;
//}









// ����2��
// ���һ��Ա���ṹ�壬�������������䡢�Ա�Ա���������£�
// {"����",43,"��"},{"����",23,"��"},{"�ŷ�",53,"��"},{"����",42,"��"},{"����",46,"Ů"}
// ͨ��ð�������㷨���������е�Ա���������У�����ӡ


//struct Emp
//{
//	string name;
//	int age;
//	string sex;
//};
//
//void swap(Emp* pa, Emp* pb)
//{
//	Emp tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}
//
//void f(Emp* empArr, int sz)
//{
//	for (int i = 0; i < sz - 1; i++) {
//		int Flag = 1;
//		for (int j = 0; j < sz - 1 - i; j++) {
//			if (empArr[j].age > empArr[j + 1].age) {
//				swap(empArr + j, empArr + j + 1);
//				Flag = 0;
//			}
//		}
//		if (Flag) {
//			break;
//		}
//	}
//}
//
//void priInfo(Emp* arr, int sz)
//{
//	cout << "������������������������������������" << endl;
//	for (int i = 0; i < sz; i++) {
//		cout << arr[i].name << "��" << arr[i].age << "��" << arr[i].sex << endl;
//	}
//	cout << "������������������������������������" << endl;
//}
//
//int main()
//{
//	Emp empArr[5] = { {"����",43,"��"},{"����",23,"��"},{"�ŷ�",53,"��"},{"����",42,"��"},{"����",46,"Ů"} };
//	int sz = sizeof(empArr) / sizeof(empArr[0]);
//	
//	priInfo(empArr, sz);
//	f(empArr, sz);
//	cout << "\n\n\n";
//	priInfo(empArr, sz);
//
//	system("pause");
//	return 0;
//}



