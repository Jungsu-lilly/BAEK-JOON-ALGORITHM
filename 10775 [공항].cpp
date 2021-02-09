#include <iostream>
#include <vector>
#define MAX 100001
using namespace std;
int arr[MAX];

int findParent(int num) {
	if (arr[num] < 0)
		return num;
	int parent = findParent(arr[num]);
	arr[num] = parent;
	return parent;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(arr, -1, sizeof(arr));
	int G, P; // 게이트 수, 비행기 수
	int count = 0;
	cin >> G >> P;
	
	int result = 0;
	bool dock = true;
	for (int i = 0; i < P; i++) {
		int temp;
		cin >> temp;
		
		if (!dock) continue;

		int openGate = findParent(temp);
	}

	return 0;
}