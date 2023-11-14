#include<iostream>
using namespace std;
#include<string>

#define MAX 1000


struct Person // 通讯录人员
{
	string name;
	string sex;
	int age;
	string phone;
	string addr;
};


struct AddrBook // 通讯录
{
	Person PerArr[MAX];
	int size;
};




void showMenu();
void personAdd(AddrBook* p);
void printAllPreson(const AddrBook* p);
void deletePerson(AddrBook* p);
void findPeople(const AddrBook* p);
void changePeople(AddrBook* p);
void clearAll(AddrBook* p);

