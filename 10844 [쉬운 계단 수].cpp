#include <iostream>
using namespace std;
long long a[101][10];
#define MAX 1000000000
int main(void) {
	int N;
	long long ans = 0;
	cin >> N;
	for (int i = 1; i <= 9; i++)
		a[1][i] = 1;
	for (int i = 2; i <= 100; i++) {
		a[i][1] += a[i - 1][0] % MAX;
		for (int j = 1; j <= 8; j++) {
			long long temp = a[i - 1][j] % MAX;
			a[i][j - 1] += temp;
			a[i][j + 1] += temp % MAX;
		}
		a[i][8] += a[i - 1][9];
	}
	for (int i = 0; i <= 9; i++) {
		ans += a[N][i];
	}
	cout << ans % MAX << endl;
	return 0;
}