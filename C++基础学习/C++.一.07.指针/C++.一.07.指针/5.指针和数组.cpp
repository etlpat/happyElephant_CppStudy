#include<iostream>
using namespace std;



// ����������������Ԫ�ص�ַ����˿���ͨ��ָ���������

//// ���ӣ�����˫ָ�뷨�����鷴ת
//int main()
//{
//	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int* start = arr;
//	int* end = arr + sz - 1;
//	while (start < end) {
//		int tmp = *start;
//		*start = *end;
//		*end = tmp;
//		start++;
//		end--;
//	}
//	for (int i = 0; i < sz; i++) {
//		cout << arr[i] << " ";
//	}
//	system("pause");
//	return 0;
//}






//// �±����ò�����[]:
// 
// p[i]�ı��ʾ���*(p + i)
// pΪָ�룬��p[i]��ʾ��pΪ��ʼ��ַ�������±�Ϊi��Ԫ�أ��൱��*(p + i)


//int main()
//{
//	int arr[10] = { 0 };
//	for (int i = 0; i < 10; i++) {
//		cout << *(arr + i) << " ";// *(arr+i)��arr[i]Ч��һ��
//	}
//	cout << endl;
//
//
//	int* p = arr;
//	for (int i = 0; i < 10; i++) {
//		cout << p[i] << " ";//  p[i]��*(p+i)Ч��һ��
//	}
//
//	return 0;
//}


