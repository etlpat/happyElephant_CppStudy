#include<iostream>
using namespace std;
#include<string>



void func1(int& a) {
	cout << a << "," << &a << endl;
}

int& func2(int& b) {
	cout << b << "," << &b << endl;
	return b;
}

int main()
{
	int arr[][3] = { {1, 2}, {3, 4, 5}, 6, 7, 8, 9, 10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	cout << "row:" << sz << endl;
	for (int i = 0; i < sz; i++) {
		int sz1 = sizeof(arr[i]) / sizeof(arr[i][0]);
		cout << "col:" << sz1 << "\t";
		for (int j = 0; j < sz1; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
