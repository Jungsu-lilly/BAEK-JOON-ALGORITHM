#include <iostream>
using namespace std;
long long a[101];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t; // 테스트 케이스
	cin >> t;
	a[1] = 1;
	a[2] = 1;
	a[3] = 1;
	for (int i = 4; i <= 100; i++) {
		a[i] = a[i - 2] + a[i - 3];
	}
	while (t--) {
		int n;
		cin >> n;
		cout << a[n] << endl;
	}

	return 0;
}