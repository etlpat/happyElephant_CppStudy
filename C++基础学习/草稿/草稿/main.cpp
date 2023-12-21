#include<iostream>
using namespace std;
#include<string>



// ��������
// ˼·��ÿ�ν����������������������еĵ�һ��Ԫ�ز��뵽����������ʹ����������
void insertionSort(double* arr, int sz) {
	double tmp;
	for (int i = 0; i < sz - 1; i++) {// ѭ��sz-1�Σ�ÿ��Ϊ���������һ��Ԫ��
		for (int j = i + 1; j >= 1; j--) {// jΪ������i����ĵ�һ���������е�Ԫ��
			if (arr[j - 1] > arr[j]) {
				tmp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = tmp;
			}
			else {// ����������Ԫ�ر�������������ֻҪǰһ��Ԫ��<=�����Ԫ�أ�ֱ��break
				break;
			}
		}
	}
}


// ��ѡ������
// ˼·��ÿ��ѭ�����������������ҵ�����������С��Ԫ�أ�����������������Ԫ�ػ������Ӷ���չ������
void simpleSelectionSort(double* arr, int sz) {
	double tmp;
	int minIndex;
	for (int i = 0; i < sz - 1; i++) {// n��Ԫ�أ�����sz-1��ѡ������
		minIndex = i;// ָ���������ĵ�һ��Ԫ��
		for (int j = i; j < sz; j++) {// �������������ҵ���С��Ԫ��
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		// �ҵ���СԪ�غ󣬽����������׸�Ԫ������СԪ�ؽ���
		tmp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
}



// ����
// ˼·��ÿ�ζ�ȡһ����׼Ԫ�أ����������飬��С�ڻ�׼�ķŵ���׼��ߣ������ڻ�׼�ķŵ���׼�ұߣ������󣬻�׼��λ�þ�ȷ����
//		 ֮�󣬵ݹ�Ի�׼���������������н��иò������ɡ�
void quickSort(double* arr, int sz) {
	if (sz <= 1) {
		return;
	}
	double standard = arr[0];// ����Ԫ�ض�Ϊ��׼Ԫ��
	int leftIndex = 0, rightIndex = sz - 1;
	while (leftIndex < rightIndex) {
		// �������СԪ�ػ������
		while (leftIndex < rightIndex && arr[rightIndex] >= standard) {// ��׼Ԫ���ұ�>=��׼Ԫ��
			rightIndex--;
		}
		arr[leftIndex] = arr[rightIndex];
		// �������СԪ�ػ�������
		while (leftIndex < rightIndex && arr[leftIndex] < standard) {// ��׼Ԫ�����<��׼Ԫ��
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