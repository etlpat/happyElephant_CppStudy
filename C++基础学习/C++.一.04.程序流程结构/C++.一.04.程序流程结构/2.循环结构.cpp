#include <iostream>
#include <ctime>
using namespace std;




////// while循环
// 作用：满足循环条件时，执行循环语句
// 语法：while(循环条件){循环语句}


//// while循环打印10到1：
//
//int main()
//{
//	int i = 10;
//	while (i) {
//		cout << i << " ";
//		i--;
//	}
//
//	system("pause");
//	return 0;
//}



//// 1到100猜数字：
//
//int main()
//{
//	// 生成随机数
//	srand((unsigned int)time(NULL));//生成随机数种子，需要头文件<ctime>
//	int val = rand() % 100 + 1;// rand()生成随机数，%100以后得到0到99的值
//	
//	
//	int num = 0;
//	cout << "请猜0到100的数字：";
//	while (1) {
//		cin >> num;
//		if (num > val)
//			cout << "猜大了，请继续猜：";
//		else if (num < val)
//			cout << "猜小了，请继续猜；";
//		else {
//			cout << "猜对了，就是" << val << endl;
//			break;
//		}
//	}
//
//	system("pause");
//	return 0;
//}







////// do...while循环
// 作用：先执行一次循环，再判断循环条件，条件满足则继续循环
// 语法：do{循环语句}while(循环条件);
//
//  注意：while后面需要加分号


//// 输出0到9
//
//int main()
//{
//	int i = 0;
//	do {
//		cout << i << " ";
//		i++;
//	} while (i < 10);
//
//	system("pause");
//	return 0;
//}



//// 获得所以三位数中的水仙花数（如1^3+5^3+3^3=153）
//
//int main()
//{
//	int n = 100;
//	do {
//		if (pow(n / 100, 3) + pow(n % 100 / 10, 3) + pow(n % 10, 3) == n) {
//			cout << n << " ";
//		}
//		n++;
//	} while (n < 1000);
//
//	system("pause");
//	return 0;
//}







////// for循环
// 语法：for(起始表达式; 条件表达式; 末尾表达式){循环体}
// 执行顺序：1 -> 2 -> 循环体 -> 3 -> 2 ->循环体 -> 3 ...
//
// for循环语句中的表达式可以不写，如for(;;)也是合法的


//// 输出0到10
//
//int main()
//{
//	int i;
//	for (i = 0; i <= 10; i++) {
//		cout << i << " ";
//	}
//
//	return 0;
//}


////// 注意：C++语法允许早for的起始表达式1定义变量：
//// 如：for(int i = 0; i < 10; i++) { 循环体 }
//// 上面i相当于在循环内部定义，i的作用域仅在for循环内部
//
//int main()
//{
//	for (int i = 0; i < 10; i++) {
//		;
//	}
//	//i = 1;// 报错，i的作用域仅在循环内部
//	
//	return 0;
//}



//// 1到100，输出个位数不含7、十位数不为7、不为7的倍数的数字
//
//int main()
//{
//	int i;
//	for (i = 1; i <= 100; i++) {
//		if (i % 10 != 7 && i % 100 / 10 != 7 && i % 7 != 0)
//			cout << i << " ";
//	}
//
//	return 0;
//}







////// 嵌套循环
// 循环允许嵌套


//// 打印10*10的星号
//
//int main()
//{
//	int i, j;
//	for (i = 0; i < 10; i++) {
//		for (j = 0; j < 10; j++) {
//			cout << "* ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


//// 乘法口诀
//
//int main()
//{
//	int i, j;
//	for (i = 1; i < 10; i++) {
//		for (j = 1; j <= i; j++) {
//			cout << j << "*" << i << "=" << j * i << "\t";
//		}
//		cout << endl;
//	}
//	return 0;
//}


