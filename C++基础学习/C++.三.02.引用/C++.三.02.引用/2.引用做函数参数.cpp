#include<iostream>
using namespace std;




//// 引用做函数参数
// 定义函数时，可以将形参定义为实参的引用
// 
// 作用：写函数时，除传址调用以外，又新增了一种利用形参修改实参的方法



//// 1.地址传递
//void swap1(int* a, int* b)
//{
//	int tmp = *a;
//	*a = *b;
//	*b = tmp;
//}
//
//// 2.引用传递
//void swap2(int& a, int& b)// 这里形参的a,b是实参a,b的引用(别名)（别名和原名可以相同）
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//int main()
//{
//	int a = 2;
//	int b = 3;
//
//	cout << a << ", " << b << endl;// 2, 3
//	swap1(&a, &b);
//	cout << a << ", " << b << endl;// 3, 2
//	swap2(a, b);
//	cout << a << ", " << b << endl;// 2, 3
//
//	// 如上，地址传参和引用传参，都可以在函数内部利用形参访问实参
//
//
//	return 0;
//}
