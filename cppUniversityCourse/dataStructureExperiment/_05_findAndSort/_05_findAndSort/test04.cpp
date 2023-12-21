#include<iostream>
using namespace std;


void adjustPositiveAndNegative(int* leftPoint, int* rightPoint) {
	leftPoint--;
	rightPoint++;
	while (leftPoint + 1 < rightPoint - 1) {
		while (*(++leftPoint) >= 0);
		while (*(--rightPoint) < 0);
		*(leftPoint) = *(leftPoint) ^ *(rightPoint);
		*(rightPoint) = *(rightPoint) ^ *(leftPoint);
		*(leftPoint) = *(rightPoint) ^ *(leftPoint);
	}
}


int main() {
	int arr[] = { 1, -2, -3, 4, -5, 6, -7, -8, -9, 10, 11, -22, 33, 44, -55, -66, 77, 88, -99, 100, 100, 100, 100 };
	int sz = sizeof(arr) / sizeof(arr[0]);


	cout << "ÅÅÐòÇ°£º";
	for (int i = 0; i < sz; i++) { cout << arr[i] << " "; }
	cout << endl;
	

	adjustPositiveAndNegative(arr, arr + sz - 1);
	cout << "ÅÅÐòºó£º";
	for (int i = 0; i < sz; i++) { cout << arr[i] << " "; }
	cout << endl;

	return 0;
}