#include <iostream>
using namespace std;
int a[11];
int main(void) {
	int t; 
	cin >> t;
	a[1] = 1, a[2] = 2, a[3] = 4;
	for (int i = 4; i <= 10; i++) {
		a[i] = a[i - 1] + a[i - 2] + a[i - 3];
	}
	while (t--) {
		int n;
		cin >> n;
		if (n < 0 || n >= 11) return 0;
		cout << a[n] << endl;
	}
	return 0;
}