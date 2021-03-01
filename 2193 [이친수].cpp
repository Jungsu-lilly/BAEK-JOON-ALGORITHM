#include <iostream>
long long int a[91]; // 场磊府啊 1
long long int b[91]; // 场磊府啊 0
using namespace std;
int main(void) {
	int n;
	cin >> n;
	a[1] = 1; b[1] = 0;
	a[2] = 0; b[2] = 1;
	for (int i = 3; i <= n; i++) {
		a[i] = b[i - 1]; // 1
		b[i] = a[i - 1] + b[i - 1]; // 0
	}
	cout << a[n] + b[n] << endl;
	return 0;
}