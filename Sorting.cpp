#include <iostream>
using namespace std;

void lab01(void) // 임의의 세 수를 오른차순으로 정렬.
{
	int a, b, c;
	cin >> a >> b >> c;
	int min = 1;
	int max = 1000000;
	if (a > max || b > max || c > max || a < min || b < min || c < min) {
		cout << "값의 범위를 넘었습니다." << endl;
		return;
	}

	int arr[3] = { a,b,c };

	if (arr[0] >= arr[1]) {
		int temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}

	if (arr[1] >= arr[2]) {
		int temp = arr[1];
		arr[1] = arr[2];
		arr[2] = temp;

		if (arr[0] >= arr[1]) {
			int temp = arr[0];
			arr[0] = arr[1];
			arr[1] = temp;
		}
	} 

//	cout << "정렬 완료" << endl;
	for (int i = 0; i < 3; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
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
		while (arr[j] >= arr[key] && j > start) {
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



void lab02()
{
	int n;
	int arr[1001];
	cin >> n;

	if (n < 1 || n > 1000)
	{
		cout << "범위오류" << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		
		if (c > 1000 || c < -1000)
			return;

		arr[i] = c;
	}

	QuickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}


void lab03() {
	int min = 1;
	int max = 1000000;
	int arr[1000001];

	int n;
	cin >> n;
	if (n<min || n>max) {
		cout << "범위 오류!" << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		if (c<-max || c>max) {
			cout << "범위오류!" << endl;
		}
		arr[i] = c;
	}

	QuickSort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}


int main(void) {

	lab03();
	return 0;
}
