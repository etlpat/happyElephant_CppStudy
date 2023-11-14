#include"head.h"


void showMenu()// ��ӡ�˵�
{
	cout << "*****************************" << endl;
	cout << "******  1�������ϵ��  ******" << endl;
	cout << "******  2����ʾ��ϵ��  ******" << endl;
	cout << "******  3��ɾ����ϵ��  ******" << endl;
	cout << "******  4��������ϵ��  ******" << endl;
	cout << "******  5���޸���ϵ��  ******" << endl;
	cout << "******  6�������ϵ��  ******" << endl;
	cout << "******  0���˳�ͨѶ¼  ******" << endl;
	cout << "*****************************" << endl;
}


int isExist(const AddrBook* p, string name1)// �ж���ϵ���Ƿ����,���ڷ����±꣬���򷵻�-1
{
	for (int i = 0; i < p->size; i++) {
		if ((p->PerArr)[i].name == name1) {
			return i;
		}
	}
	return -1;
}


void addOne(AddrBook* p, int i)// ���һ����ϵ�˵�i�±괦
{
	cout << "��������ϵ��������";
	cin >> (p->PerArr)[i].name;
	cout << "��������ϵ���Ա�";
	cin >> (p->PerArr)[i].sex;
	cout << "��������ϵ�����䣺";
	cin >> (p->PerArr)[i].age;
	cout << "��������ϵ�˵绰��";
	cin >> (p->PerArr)[i].phone;
	cout << "��������ϵ�˵�ַ��";
	cin >> (p->PerArr)[i].addr;
}


void personAdd(AddrBook* p)// �����ϵ��
{
	if (p->size == MAX) {
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}

	addOne(p, p->size);
	p->size += 1;
	cout << "��ӳɹ�" << endl;
}


void printAllPreson(const AddrBook* p)// ��ӡȫ����ϵ��
{
	cout << "����������������������������������������������������������������������������������������������������������������������������������" << endl;
	if (p->size == 0) {
		cout << "������ϵ��" << endl;
	}
	else {
		for (int i = 0; i < p->size; i++) {
			cout << (p->PerArr)[i].name << "\t"
				<< (p->PerArr)[i].sex << "\t"
				<< (p->PerArr)[i].age << "\t"
				<< (p->PerArr)[i].phone << "\t"
				<< (p->PerArr)[i].addr << endl;
		}
	}
	cout << "����������������������������������������������������������������������������������������������������������������������������������" << endl;
}


void deletePerson(AddrBook* p)// ��ָ������ɾ����ϵ��
{
	string name;
	cout << "������ɾ������ϵ��������";
	cin >> name;

	int t = isExist(p, name);
	if (t == -1) {
		cout << "���޴���" << endl;
	}
	else {
		for (int i = t; i < p->size - 1; i++) {
			(p->PerArr)[i] = (p->PerArr)[i + 1];
		}
		p->size -= 1;
		cout << "ɾ���ɹ�" << endl;
	}
}


void findPeople(const AddrBook* p)// ����ָ����������ϵ��
{
	string name;
	cout << "��������ҵ���ϵ��������";
	cin >> name;

	int t = isExist(p, name);
	if (t == -1) {
		cout << "���޴���" << endl;
	}
	else {
		cout << "����������������������������������������������������������������������������������������������������������������������������������" << endl;
		cout << (p->PerArr)[t].name << "\t"
			<< (p->PerArr)[t].sex << "\t"
			<< (p->PerArr)[t].age << "\t"
			<< (p->PerArr)[t].phone << "\t"
			<< (p->PerArr)[t].addr << endl;
		cout << "����������������������������������������������������������������������������������������������������������������������������������" << endl;
	}
}


void changePeople(AddrBook* p)// ���������޸���ϵ��
{
	string name;
	cout << "�������޸ĵ���ϵ��������";
	cin >> name;

	int t = isExist(p, name);
	if (t == -1) {
		cout << "���޴���" << endl;
	}
	else {
		addOne(p, t);
		cout << "�޸ĳɹ�" << endl;
	}
}


void clearAll(AddrBook* p)// ���ȫ����ϵ��
{
	p->size = 0;
	cout << "��ϵ�������" << endl;
}

