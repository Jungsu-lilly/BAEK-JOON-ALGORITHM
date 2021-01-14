#include<iostream>
using namespace std;

int sorted[8];

void merge(int a[],int m, int middle, int n)
{
	int i = m;
	int j = middle + 1;
	int k = m;

	while (i <= middle && j <= n) 
	{
		if (a[i] >= a[j]) {
			sorted[k] = a[j];
			j++;
		}
		else {	// a[i] 가 더 작은 경우
			sorted[k] = a[i];
			i++;
		}
		k++;
	}

	if (i > middle) {
		while (j <= n) {
			sorted[k] = a[j];
			j++; k++;
		}
	}
	else {
		while (i <= middle) {
			sorted[k] = a[i];
			i++; k++;
		}
	}

	for (int x = m; x <= n; x++) {
		a[x] = sorted[x];
	}

}

void mergeSort(int a[], int m, int n)
{
	if (m < n)
	{
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}


int main(void)
{
	int arr[8] = { 7,6,5,8,3,5,9,1 };
	mergeSort(arr, 0, 7);

	for (int i = 0; i < 8; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}