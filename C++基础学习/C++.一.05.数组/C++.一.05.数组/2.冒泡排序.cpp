#include <iostream>
using namespace std;



////// ð�����򣨴�С��������Ϊ����
// 1.����n��Ԫ�ؾ�ѭ��n-1��
// 2.ÿ�˴�ǰ����ȶԽ���Ԫ�أ����ϴ�Ļ�������
// 3.��n��Ԫ�����һ�˽���n-1�Σ�֮��ÿ�˽���������һ�ݼ�



//int main()
//{
//	int arr[] = { 23, 175, 69, 8, 82, 1000, 46, 589, 23, 4, 478, 24, 65, 1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz - 1; i++) {// ѭ��sz-1��
//		int flag = 1;// �Ż�����
//		for (int j = 0; j < sz - 1 - i; j++) {// ÿ�˽���sz-1-i��
//			if (arr[j] > arr[j + 1]) {
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag) {// ��ĳ��δִ�н�����˵����������ɣ�flagΪ1��ֱ������ѭ��
//			break;
//		}
//	}
//	
//	for (int i = 0; i < sz; i++) {
//		cout << arr[i] << " ";
//	}
//
//	system("pause");
//	return 0;
//}