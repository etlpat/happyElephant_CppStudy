#include <iostream>
using namespace std;





////// 1.if语句
// 
// if语句的三种形式：
// 单行格式if语句：if(条件){执行语句}
// 多行格式if语句：if(条件){执行语句1} else{执行语句2}
// 多条件的if语句：if(条件1){执行语句1} else if(条件2){执行语句2} else{执行语句3}
// 
// 除此之外，if语句允许嵌套使用
//
// 注意if判断条件后不要加分号，否则if判断失去意义


// 总体格式：
// if (条件1)
// {
//    执行语句1
// } 
// else if (条件2)
// {
//    执行语句2
// } 
// else
// {
//    执行语句3
// }


//int main()
//{
//	int num = 0, flag = 0;
//	cout << "请输入flag" << endl;
//	cin >> flag;
//
//	if (flag != 0){
//		cout << "请输入num" << endl;
//		cin >> num;
//		if (num < 0) {
//			cout << "num不可输入负值" << endl;
//		}
//		else if (num < 100) {
//			cout << "num低于100" << endl;
//		}
//		else {
//			cout << "num高于100" << endl;
//		}
//	}
//	else {
//		cout << "flag值为0" << endl;
//	}
//
//	system("pause");
//	return 0;
//}







////// 三目运算符
// 语法： 表达式1 ? 表达式2 : 表达式3
// 语义：若表达式1为真，执行表达式2，并返回表达式2(的值)；
//       若表达式1为假，执行表达式3，并返回表达式3(的值)；
//
// 注意：C++中，三目运算符返回的是表达式本身，若值返回一个变量，课继续为该变量赋值


//// 例子：获取两个数中的较大值
//
//int main()
//{
//	int a = 3, b = 2;
//	int c;
//	c = (a > b ? a : b);
//	cout << c << endl;
//
//
//	// C++中，三目运算符返回的是变量，可以继续赋值
//	(a < b ? a : b) = 100;//平时最好不要这么写
//	cout << "a=" << a << ", b=" << b << endl;// a=3, b=100（C++三目运算符返回变量本身）
//
//
//	system("pause");
//	return 0;
//}







////// switch case语句
// 作用：执行多条件分支语句
// 语法：
//	switch (表达式) // 这里的变量只能是整数或字符
//	{
//	case 结果1:
//		执行语句1;
//		break;
//	case 结果2:
//		执行语句2:
//		break;
//	......
//	default:
//		执行语句3;
//		break;
//	}
// 
//
// 注意：switch语句的执行逻辑是：跳入表达式所对应的结果，一直向下执行，直到遇到break或者全部执行完自动退出
//	     从上向下执行到末尾（包括default中的语句）
//
// switch缺点：判断是只能是整数或字符，不可以是一个区间
//       有点：结果清晰，执行效率高


//int main()
//{
//	int num = 0;
//	cout << "请输入你的评价(1到10分)：";
//	cin >> num;
//
//	switch (num)
//	{
//	case 10:
//		cout << "优秀" << endl;
//		break;
//	case 9:
//		cout << "优秀" << endl;
//		break;
//	case 8:
//		cout << "良好" << endl;
//		break;
//	case 7:
//		cout << "良好" << endl;
//		break;
//	case 6:
//		cout << "一般" << endl;
//		break;
//	case 5:
//		cout << "一般" << endl;
//		break;
//	default:
//		cout << "很烂" << endl;
//
//	}
//
//	system("pause");
//	return 0;
//}