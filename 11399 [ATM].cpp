#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int n; // »ç¶÷ ¼ö
	cin >> n;
	if (n < 1 || n>1000) return -1;

	int* a = new int[n + 1];
	int* b = new int[n + 1];
	int idx = 1;
	a[0] = -1;
	b[0] = 0;
	int m = n;
	while (m--) {
		cin >> a[idx];
		if (a[idx] < 1 || a[idx]>1000)
			return -1;
		idx++;
	}
	sort(a,a+n+1);
	for (int i = 1; i <= n; i++) {
		b[i] = b[i-1] + a[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
		sum += b[i];
	cout << sum << endl;

	return 0;
}