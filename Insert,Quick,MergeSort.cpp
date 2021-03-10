#include <iostream>
using namespace std;

void InsertionSort(int* arr, int len)
{

	for (int i = 1; i < len; i++)	{

		int j = i;
		while (j>=1)
		{
			if (arr[j - 1] > arr[j]) 
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
			j--;
		}
	}
}

void QuickSort(int*arr, int start, int end) // 오름차순으로 정렬
{
	if (start >= end) {
		return;
	}

	int key = start; // 피벗값
	int i = start + 1; 
	int j = end;
	int temp;

	while (i <= j)
	{  // 엇갈릴 때까지 반복
		while (arr[i] <= arr[key]) {
			i++; // i는 피벗값보다 큰값을 탐색함
		}
		while (arr[j] >= arr[key]&& j>start) {
			j--; // j는 피벗값보다 작은값을 탐색함
		}

		if (i > j) {	// 현재 엇갈린 상태면
			temp = arr[j];
			arr[j] = arr[key];
			arr[key] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	QuickSort(arr, start, j - 1);
	QuickSort(arr, j + 1, end);
}


void QuickSort2(int*arr, int start, int end) // 내림차순으로 정렬
{
	if (start >= end) {
		return;
	}

	int key = start; // 피벗값
	int i = start + 1;
	int j = end;
	int temp;

	while (i <= j)
	{  // 엇갈릴 때까지 반복
		while (arr[i] >= arr[key]) {
			i++; // i는 피벗값보다 작은값을 탐색함
		}
		while (arr[j] <= arr[key] && j > start) {
			j--; // j는 피벗값보다 큰값을 탐색함
		}

		if (i > j) {	// 현재 엇갈린 상태면
			temp = arr[j];
			arr[j] = arr[key];
			arr[key] = temp;
		}
		else {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}

	QuickSort2(arr, start, j - 1);
	QuickSort2(arr, j + 1, end);
}


int sorted[8];
void merge(int arr[], int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	// 작은 순서대로 배열에 삽입
	while (i <= middle && j <= n)
	{
		if (arr[i] <= arr[j]) {
			sorted[k] = arr[i];
			i++;
		}
		else {
			sorted[k] = arr[j];
			j++;
		}
		k++;
	}

	// 남은 데이터도 삽입
	if (i > middle) {
		while (j <= n)
		{
			sorted[k] = arr[j];
			j++;
			k++;
		}
	}
	else if (j > n) {
		while (i <= middle)
		{
			sorted[k] = arr[i];
			i++;
			k++;
		}
	}

	for (int i = m; i <= n; i++) {
		arr[i] = sorted[i];
	}

}


void mergeSort(int arr[], int m, int n)
{
	if (m < n) {
		int middle = (m + n) / 2;
		mergeSort(arr, m, middle);
		mergeSort(arr, middle+1, n);
		merge(arr, m, middle, n);
	}
}


void printArr(int* arr, int len) {
	
	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}


int main(void) 
{
	int arr[8] = { 7,6,5,8,3,5,9,1 };
	mergeSort(arr, 0, 7);

	for (int i = 0; i < 8; i++)
		cout << sorted[i] << " ";

	cout << endl;
	return 0;
}
