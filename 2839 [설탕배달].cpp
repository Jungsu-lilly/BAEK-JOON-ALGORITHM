#include <iostream>
using namespace std;
int main(void) {
	int n;
	cin >> n;
	if (n < 3 || n>5000)
		return 0;
	int num = 0;
	for (int i = 0; i <= n / 5; i++) {
		int temp = n - 5 * i;
		if (temp % 3 == 0) {
			num = i + temp / 3;
		}
	}
	if (num == 0)
		cout << -1 << endl;
	else
		cout << num << endl;
	return 0;
}