#include <iostream>
using namespace std;



//// break语句
// 作用：用于跳出循环或switch语句
// break使用时机：
// 1.出现在switch条件语句中，作用是中止case并跳出switch
// 2.出现在循环语句中，跳出当前循环语句
// 3.出现在嵌套循环中，跳出所在的最内层循环







//// continue语句
// 作用：在循环语句中，跳过本次循环并继续执行下一次循环


//// 打印1到10中的奇数
//
//int main()
//{
//	int i;
//	for (i = 1; i <= 10; i++) {
//		if (i % 2 == 0)
//			continue;
//		cout << i << " ";
//	}
//
//	system("pause");
//	return 0;
//}







//// goto语句
// 功能：可无条件跳转语句
// 语法：goto 标记;
//		 标记: （注意标记后面是冒号）
// 用法：若标记的名称存在，执行goto语句是，会跳转到标记位置
//
// 
// 注意，该语法影响代码结构，平时不使用


//int main()
//{
//
//	cout << 1 << endl;
//
//	goto FLAG;
//
//	cout << 2 << endl;
//	cout << 3 << endl;
//
//	FLAG:
//
//	cout << 4 << endl;
//
//	return 0;
//}

