#include<iostream>
using namespace std;
#include<string>




//// 访问权限：
// 类在设计时，可以把属性和行为放在不同的访问权限下，加以控制
//
// 成员的访问权限有三种：
// 1.public：	公共权限 （类的内外都可以访问，子类可以访问）
// 2.protected：保护权限 （类内可以访问，类外不可访问，子类可以访问）
// 3.private：	私有权限 （类内可以访问，类外不可访问，子类不可访问）
//
//
// 类中默认访问权限时私有权限



//class A
//{
//public:// 公共权限
//	int public_a;
//
//protected:// 保护权限
//	int protected_a;
//
//private:// 私有权限
//	int private_a;
//
//public:
//	void setValue(int num1, int num2, int num3) {
//		public_a = num1;
//		protected_a = num2;
//		private_a = num3;
//	}
//	void printValue() {
//		cout << "public_a:" << public_a << endl;
//		cout << "protected_a:" << protected_a << endl;
//		cout << "private_a:" << private_a << endl;
//	}
//};
//
//int main()
//{
//	A A1;
//	A1.public_a = 1;
//	//A1.protected_a = 2;// 报错，保护成员在类外不可访问
//	//A1.private_a = 3;// 报错，私有成员在类外不可访问
//
//	A1.setValue(1, 2, 3);// 可通过成员方法，在类内访问保护成员和私有成员
//	A1.printValue();// 1, 2, 3
//
//	return 0;
//}





