#include <iostream>
using namespace std;



// 数组
// 1.数组中的每个元素都是相同数据类型
// 2.C++的数组，内存空间连续
// 3.n个元素的数组，下标是从0到n-1




// 一维数组的定义：
// 1.数据类型 数组名[数组长度];
//	（未赋初值，不自动补0）
// 
// 2.数据类型 数组名[数组长度] = { 元素1， 元素2... };
//	（剩余空间自动补0）
// 
// 3.数据类型 数组名[] = { 元素1， 元素2... };
//	（自动根据元素个数分配内存空间）


//int main()
//{
//	//数组的三种定义方法
//
//	int arr1[5];// 不给数组赋初值，不会自动补0
//	for (int i = 0; i < 5; i++) {
//		cout << arr1[i] << endl;
//	}
//
//	int arr2[5] = { 1, 2, 3 };// 剩余位置自动补0
//	for (int i = 0; i < 5; i++) {
//		cout << arr2[i] << endl;
//	}
//
//	int arr3[] = { 1, 2, 3 };// 数组会根据元素个数分配对应的空间
//	for (int i = 0; i < 3; i++) {
//		cout << arr3[i] << endl;
//	}
//
//
//	system("pause");
//	return 0;
//}






////// 【数组名】是【数组首元素地址】（两个特例）
// 
// 若定义数组 int arr[10];
// arr：数组名未首元素地址（基本所以情况）
// sizeof(arr)：整个数组
// &arr：整个数组的地址
//
// 
// 注意：数组名是常量，不可以进行赋值操作


//int main()
//{
//	int arr[10] = { 0 };
//
//	cout << sizeof(arr) << endl;// 40，sizeof(数组名)统计整个数组大小
//	cout << sizeof(arr)/sizeof(arr[0]) << endl;// 10，获取元素个数
//
//
//	// arr和&arr
//
//	cout << arr << endl;//		0000009436FDF538
//	cout << arr+1 << endl;//	0000009436FDF53C
//	cout << &arr << endl;//		0000009436FDF538
//	cout << &arr+1 << endl;//	0000009436FDF560
//
//	// 如上：arr表示数组首元素地址；&arr表示整个数组的地址
//	// 二者数值相同，但是跨度不同：arr跨度是一个元素，&arr跨度是整个数组
//
//
//	system("pause");
//	return 0;
//}



//// 练习1：找出数组中最大的数值
//int main()
//{
//	int arr[] = { 1, 14, 53, 64,67, 85, 653, 23, 4 };
//	int max = arr[0];
//	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
//		if (max < arr[i]) {
//			max = arr[i];
//		}
//	}
//	cout << max << endl;
//	system("pause");
//	return 0;
//}


//// 练习2：将数组中元素逆序存放到原数组中
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10,11 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int i, tmp;
//	for (i = 0; i < sz / 2; i++) {
//		tmp = arr[i];
//		arr[i] = arr[sz - 1 - i];
//		arr[sz - 1 - i] = tmp;
//	}
//
//	for (i = 0; i < sz; i++) {
//		cout << arr[i] << " ";
//	}
//
//	system("pause");
//	return 0;
//}