#include<iostream>
using namespace std;



// 由于数组名就是首元素地址，因此可以通过指针访问数组

//// 例子：利用双指针法将数组反转
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* start = arr;
//	int* end = arr + sz - 1;
//	while (start < end) {
//		int tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//	for (int i = 0; i < sz; i++) {
//		cout << arr[i] << " ";
//	}
//	system("pause");
//	return 0;
//}






//// 下标引用操作符[]:
// 
// p[i]的本质就是*(p + i)
// p为指针，则p[i]表示以p为起始地址，访问下标为i的元素，相当于*(p + i)


//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++) {
//		cout << *(arr + i) << " ";// *(arr+i)和arr[i]效果一致
//	}
//	cout << endl;
//
//
//	int* p = arr;
//	for (int i = 0; i < 10; i++) {
//		cout << p[i] << " ";//  p[i]和*(p+i)效果一致
//	}
//
//	return 0;
//}


