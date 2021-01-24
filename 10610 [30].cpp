#include <iostream>
#include <string>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string n;
	cin >> n;
	int num[10] = { 0, };
	int count = 0; int sum =0;
	int len = n.size(); // 숫자 길이
	for (int i = 0; i < len; i++) {
		num[n[i] - '0'] += 1;
		sum += n[i] - '0';
	}
	if (sum % 3 == 0 && num[0] != 0) {
		for (int i = 9; i >= 0; i--) {
			for (int j = 0; j < num[i]; j++) {
				cout << i;
			}
		}
	}
	else
		cout << -1;

	return 0;
}