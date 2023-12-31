#include <iostream>
using namespace std;



//// 一维数组传参：
// 若想把一维数组传入函数，传参时可以在形参部分放入【数组】或【指针】
// 
// 
// 注意：1.【函数的形参无论是数组还是指针，接收到的都是首地址】
//		 2.【无法在函数内部用sizeof计算数组的大小】
//			原因：形参是实参的临时拷贝，形参接收到的首地址只是一个普通指针，sizeof计算的结果是指针自身的大小(4或8)；同理对其进行&，跨度也只是一个元素，不再是整个数组


//// 语法如下：
//void fun1(int arr[])// 拿数组接收，可以不写大小
//{ }
//void fun2(int arr[10])// 拿数组接收，可以规定大小
//{ }
//void fun3(int* arr)// 拿指针接收
//{ }
//
//int main()
//{
//	int arr[10] = { 0 };
//	fun1(arr);
//	fun2(arr);
//	fun3(arr);
//
//	return 0;
//}




//void fun1(int* arr)
//{
//	// 将数组作为形参传入函数后，接收到的arr仅是指向首地址的普通的指针，不具有数组整体的性质
//	cout << sizeof(arr) << endl;// 4
//	cout << &arr << endl;//		007AFA08
//	cout << &arr + 1 << endl;//	007AFA0C
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	fun1(arr);
//
//	return 0;
//}










//// 二维数组传参
// 和一维数组传参同理，形参可以是【数组】或【指针】
// 形参接收到的是首元素地址，即第一行数组的地址
// 
//
// 注意：二维数组的首元素是一维数组，首元素地址是数组地址
//		 如int arr[3][4],则首元素地址是数组地址：int (*arr)[4]
//		 区分：int (*arr)[4],是数组指针； int *arr[4],是指针数组；原因：[]的优先级大于*


////// 语法如下：
//void Fun1(int arr[3][5])// 用数组接收
//{}
//void Fun2(int arr[][5])// 行可以省略，列不可省略
//{}
//void Fun3(int (*arr)[5])// 用指针接收（二维数组的首地址）
//{}
//
//int main()
//{
//	int arr[3][5] = {0};
//	Fun1(arr);
//	Fun2(arr);
//	Fun3(arr);
//
//	return 0;
//}
