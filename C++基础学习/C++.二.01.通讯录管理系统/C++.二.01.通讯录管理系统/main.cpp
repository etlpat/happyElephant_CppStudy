#include"head.h"

//// ͨѶ¼����ϵͳ
// ϵͳҪ��
// ͨѶ¼��������1000��ϵ�˵�����
// ��ϵ�ˣ������������Ա����䡢�绰����ͥסַ
// 
// ����Ҫ��ӡͨѶ¼�˵���������ͨѶ¼��Ϣ��
// 1.�����ϵ�ˣ����һ������ϵ��
// 2.��ʾ��ϵ�ˣ���ʾ������ϵ����Ϣ
// 3.ɾ����ϵ�ˣ���������ɾ����ϵ��
// 4.������ϵ�ˣ����������鿴ָ����ϵ����Ϣ
// 5.�޸���ϵ�ˣ��������������޸�ָ����ϵ��
// 6.�����ϵ�ˣ����������ϵ��
// 0.�˳�ͨѶ¼




int main()
{
	AddrBook AB;// ����ͨѶ¼
	AB.size = 0;// ��������ʼ��Ϊ0

	while (1) {
		showMenu();// ��ӡ�˵�����

		int select;
		cin >> select;

		switch (select) {// ���в���ѡ��
		case 1:
			personAdd(&AB);
			break;
		case 2:
			printAllPreson(&AB);
			break;
		case 3:
			deletePerson(&AB);
			break;
		case 4:
			findPeople(&AB);
			break;
		case 5:
			changePeople(&AB);
			break;
		case 6:
			clearAll(&AB);
			break;
		case 0:
			cout << "��ӭ�´�����" << endl;
			system("pause");
			return 0;
		default:
			cout << "��Ч����������������" << endl;
			break;
		}
		system("pause");
		system("cls");// ��������
	}

	return 0;
}
