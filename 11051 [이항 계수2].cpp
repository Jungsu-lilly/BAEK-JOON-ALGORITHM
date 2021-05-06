#include <iostream>
using namespace std;
int a[1001][1001];
int main(void) {
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		a[0][i] = 1;
	}
	for (int i = 1; i <= n; i++)
		a[1][i] = i;

	for (int i = 2; i <= k; i++) {
		for (int j = i; j <= n; j++) {
			if (j == i) a[i][j] = 1;
			else {
				a[i][j] = a[i][j - 1] + a[i - 1][j - 1];
			}
			a[i][j] %= 10007;
		}
	}

	cout << a[k][n] << endl;
	return 0;
}