#include<iostream>
using namespace std;
#include<string>



// 插入排序
// 思路：每次将紧挨着有序区的无序区中的第一个元素插入到有序区，并使有序区有序
void insertionSort(double* arr, int sz) {
	double tmp;
	for (int i = 0; i < sz - 1; i++) {// 循环sz-1次，每次为有序区添加一个元素
		for (int j = i + 1; j >= 1; j--) {// j为有序区i后面的第一个无序区中的元素
			if (arr[j - 1] > arr[j]) {
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
			else {// 由于有序区元素本来就有序，所以只要前一个元素<=插入的元素，直接break
				break;
			}
		}
	}
}


// 简单选择排序
// 思路：每次循环遍历无序区，并找到无序区中最小的元素，将其与无序区的首元素互换，从而拓展有序区
void simpleSelectionSort(double* arr, int sz) {
	double tmp;
	int minIndex;
	for (int i = 0; i < sz - 1; i++) {// n个元素，进行sz-1次选择排序
		minIndex = i;// 指向无序区的第一个元素
		for (int j = i; j < sz; j++) {// 遍历无序区，找到最小的元素
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		// 找到最小元素后，将无序区的首个元素与最小元素交换
		tmp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
}



// 快排
// 思路：每次都取一个基准元素，来划分数组，将小于基准的放到基准左边，将大于基准的放到基准右边，结束后，基准的位置就确定了
//		 之后，递归对基准的左右两侧子序列进行该操作即可。
void quickSort(double* arr, int sz) {
	if (sz <= 1) {
		return;
	}
	double standard = arr[0];// 将首元素定为基准元素
	int leftIndex = 0, rightIndex = sz - 1;
	while (leftIndex < rightIndex) {
		// 把右面的小元素换到左边
		while (leftIndex < rightIndex && arr[rightIndex] >= standard) {// 基准元素右边>=基准元素
			rightIndex--;
		}
		arr[leftIndex] = arr[rightIndex];
		// 把左面的小元素换到右面
		while (leftIndex < rightIndex && arr[leftIndex] < standard) {// 基准元素左边<基准元素
			leftIndex++;
		}
		arr[rightIndex] = arr[leftIndex];
	}
	arr[leftIndex] = standard;
	quickSort(arr, leftIndex);
	quickSort(arr + leftIndex + 1, sz - leftIndex - 1);
}





//int main() {
//	double arr[] = { 6,4,7,1,9,3,0,7,1,4,5,8,5,2 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//
//
//	//insertionSort(arr, sz);
//	//simpleSelectionSort(arr, sz);
//	quickSort(arr, sz);
//
//
//	for (int i = 0; i < sz; i++) {
//		cout << arr[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}