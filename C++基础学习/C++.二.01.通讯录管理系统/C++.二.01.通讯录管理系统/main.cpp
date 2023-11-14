#include"head.h"

//// 通讯录管理系统
// 系统要求：
// 通讯录：可容纳1000联系人的数组
// 联系人：包括姓名、性别、年龄、电话、家庭住址
// 
// 首先要打印通讯录菜单，如下是通讯录信息：
// 1.添加联系人：添加一个新联系人
// 2.显示联系人：显示所有联系人信息
// 3.删除联系人：按照姓名删除联系人
// 4.查找联系人：按照姓名查看指定联系人信息
// 5.修改联系人：按照姓名重新修改指定联系人
// 6.清空联系人：清空所以联系人
// 0.退出通讯录




int main()
{
	AddrBook AB;// 创建通讯录
	AB.size = 0;// 将人数初始化为0

	while (1) {
		showMenu();// 打印菜单界面

		int select;
		cin >> select;

		switch (select) {// 进行操作选择
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
			cout << "欢迎下次再来" << endl;
			system("pause");
			return 0;
		default:
			cout << "无效操作，请重新输入" << endl;
			break;
		}
		system("pause");
		system("cls");// 清屏操作
	}

	return 0;
}
