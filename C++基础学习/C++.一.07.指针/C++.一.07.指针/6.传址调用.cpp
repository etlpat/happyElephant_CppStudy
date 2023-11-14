#include<iostream>
using namespace std;




//// 传址调用：
// 使用函数时，若将地址传给形参，可以实现在函数内修改主函数中的数据
// 解释：虽然形参是实参的临时拷贝，传值调用不能直接改变主函数中的数据，
//		 但若传入地址，可以在函数中通过地址访问并修改指定空间



//void swap(int *a, int *b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//int main()
//{
//	int a = 3, b = 4;
//	cout << a << " " << b << endl;// 3 4
//
//	swap(&a, &b);
//	cout << a << " " << b << endl;// 4 3
//
//
//	system("pause");
//	return 0;
//}