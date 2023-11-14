#include<iostream>
using namespace std;
#include<string>




//// 菱形继承
// 概念：两个派生类继承同一个基类，又有某个类同时继承这两个派生类。
// 以上这种继承方式被称为菱形继承/钻石继承
//
// 菱形继承问题：
// 若B C继承了A，而D继承了B C。
// 如上，D就继承了两份A的数据，占用两份空间，并且产生二义性
//
// 
// 
// 解决方法：【虚继承】
// 定义子类时，在继承方式之前，加上virtual关键字，可进行虚继承。此时基类称为虚基类
// 虚继承，子类从父类继承到的是虚基类指针，指向虚基类表
// 注意：虚基类表只存在一份，不同子类通过虚继承得到的虚基类指针，都指向同一个虚基类表
// 
// 
// 虚继承语法：class 子类 :virtual public 父类 {...};
// 若B、C虚继承A，则B、C继承的数据在同一块空间；而D继承了B、C，D也只会继承到同一块空间




class Animal
{
public:
	int age;
};


// 定义羊类
class Yang1 :public Animal
{ };
// 定义驼类
class Tuo1 :public Animal
{ };
// 定义羊驼类
class YangTuo1 :public Yang1, public Tuo1
{ };


// 利用虚继承解决菱形继承的问题：
// virtual关键字，使类变为虚继承
// Animal变为虚基类
class Yang2 :virtual public Animal// 虚继承，Yang2和Tuo2继承到的Animal对象是同一块空间
{ };
class Tuo2 :virtual public Animal
{ };
class YangTuo2 :public Yang2, public Tuo2
{ };


int main()
{
	YangTuo1 yt1;
	//yt1.age = 18;// 报错，两父类中有同名变量，需要加作用域区分
	yt1.Yang1::age = 18;
	yt1.Tuo1::age = 28;
	cout << yt1.Yang1::age << ", " << yt1.Tuo1::age << endl;// 18, 28
	// 如上这种方式，会造成二义性，并占用两份内存


	// 通过虚继承，使得Yang2、Tuo2中的age是同一块空间，YangTuo2继承到的也是这一块空间
	YangTuo2 yt2;
	yt2.Yang2::age = 18;
	yt2.Tuo2::age = 28;
	yt2.age = 38;// 由于从两个父类中继承到同一块空间，可以不加作用域
	cout << yt2.Yang2::age << ", " << yt2.Tuo2::age << ", " << yt2.age << endl;// 38, 38, 38（相当于对空间赋值了三次）

	
	return 0;
}
