#include<iostream>
using namespace std;
#include<string>




//// 成员属性设置为私有
// 在实际生产中，【一般将所有成员属性都设置为私有】
// 属性全为私有，在主函数中就只能通过成员函数间接访问属性
// 
// 优点：1.可以自己控制属性的读写权限
//		   （属性本身是私有，通过设置公共的接口函数控制属性的读写）
//		 2.对于写，可以检查数据的有效性
//		   （在set接口中，加入if判断，即可识别用户的输入是否有效）



//class Preson
//{
//private:// 将属性的权限设置为私有
//	
//	string name;// 可读可写
//	int age = 0;// 只读	（这里设默认值为0）
//	string sex;	// 只写
//
//public:
//	void setName(string name1) {// name可写
//		name = name1;
//	}
//	string getName() {// name可读
//		return name;
//	}
//	int getAge() {// age只读
//		return age;
//	}
//	void setSex(string sex1) {// sex只写，并判断性别的有效性
//		if (sex1 == "男" || sex1 == "女") {
//			sex = sex1;
//		}
//		else {
//			cout << "输入性别有误" << endl;
//		}
//	}
//};
//
//
//int main()
//{
//	Preson p1;// 由于属性私有，只能通过成员方法访问属性
//
//	// 姓名可读可写
//	p1.setName("张三");
//	cout << p1.getName() << endl;
//
//	// 年龄只读
//	cout << p1.getAge() << endl;
//
//	// 性别只写
//	p1.setSex("1234");// 输入性别有误
//	p1.setSex("男");
//
//
//	return 0;
// }