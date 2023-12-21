#include<iostream>
using namespace std;
#include<string>


int binarySearch(const int* arr, int startIndex, int endIndex, const int target) {
	if (startIndex > endIndex) {
		return -1;
	}
	int mid = (startIndex + endIndex) / 2;
	if (arr[mid] == target) {
		return mid;
	}
	else if (arr[mid] > target) {
		return binarySearch(arr, startIndex, mid - 1, target);
	}
	else {
		return binarySearch(arr, mid + 1, endIndex, target);
	}
}




//int main() {
//	int arr[] = { 0,3,4,9,13,16,18,20,25,29,35,39,42,46,47,51,59,63,65,67,73,78,81,84,94,99 };
//	int endIndex = sizeof(arr) / sizeof(arr[0]) - 1;
//	int targetIndex;
//
//
//	// (1)查找一个存在的数据
//	int findNum = 39;
//	targetIndex = binarySearch(arr, 0, endIndex, findNum);
//	cout << findNum << "的下标：" << (targetIndex == -1 ? "不存在" : to_string(targetIndex)) << endl;
//	
//
//	// (2)查找一个不存在的数据
//	findNum = 77;
//	targetIndex = binarySearch(arr, 0, endIndex, findNum);
//	cout << findNum << "的下标：" << (targetIndex == -1 ? "不存在" : to_string(targetIndex)) << endl;
//
//
//	return 0;
//}