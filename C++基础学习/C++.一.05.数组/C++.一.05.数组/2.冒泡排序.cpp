#include <iostream>
using namespace std;



////// 冒泡排序（从小到大排序为例）
// 1.若对n个元素就循环n-1趟
// 2.每趟从前到后比对交换元素，将较大的换到后面
// 3.若n个元素则第一趟交换n-1次，之后每趟交换次数逐一递减



//int main()
//{
//	int arr[] = { 23, 175, 69, 8, 82, 1000, 46, 589, 23, 4, 478, 24, 65, 1 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0; i < sz - 1; i++) {// 循环sz-1趟
//		int flag = 1;// 优化代码
//		for (int j = 0; j < sz - 1 - i; j++) {// 每趟交换sz-1-i次
//			if (arr[j] > arr[j + 1]) {
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (flag) {// 若某趟未执行交换，说明排序已完成，flag为1，直接跳出循环
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