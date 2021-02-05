#include <iostream>
#include <vector>
using namespace std;
int main(void) {
	int n, sum = 0;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	int Size = a.size();
	if (n == 1) {
		cout << sum << endl;
	}
	else if (n >= 2) {
		for (int i = Size - 2; i >= 0; i--) {
			if (a[i] >= a[i + 1]) {
				int temp = a[i] - a[i + 1]; // Â÷ÀÌ
				sum += temp + 1;
				a[i] -= temp + 1;
			}
		}
		cout << sum << endl;
	}
	return 0;
}