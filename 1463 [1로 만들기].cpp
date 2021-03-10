#include <iostream>
#include <algorithm>
using namespace std;
int a[1000001];

int main(void) {
	int N, ans = 0; // N은 100만 이하의 자연수
	cin >> N;
	for (int i = 2; i <= N; i++) {
		a[i] = a[i - 1] + 1;
		if (i % 2 == 0) {
			a[i] = min(a[i / 2] + 1, a[i]);
		}
		if (i % 3 == 0) {
			a[i] = min(a[i / 3] + 1, a[i]);
		}
	}
	cout << a[N] << endl;
	return 0;
}