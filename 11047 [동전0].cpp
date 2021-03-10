#include <iostream>
using namespace std;
#define MAX 100000000
int main(void) {
	int n, k; // Á¾·ù, ÃÖÁ¾¾×¼ö
	cin >> n >> k;
	if (n < 1 || n>10 || k<0 || k>MAX)
		return -1;
	int* a = new int[n + 1];
	int idx = 1;
	cin >> a[1];
	if (a[1] != 1)return -1;

	for (int i = 2; i <= n; i++) {
		cin >> a[i];
		if (a[i] % a[i - 1] != 0)
			return -1;
	}

	int sum = 0; // ÀÜµ· °¹¼ö
	for (int i = n; i >= 1; i--) {
		sum += k / a[i];
		k %= a[i];
	}
	cout << sum << endl;

	return 0;
}