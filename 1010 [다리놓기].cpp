#include <iostream>
#include <algorithm>
using namespace std;
int main(void) {
	int t;
	cin >> t; // �׽�Ʈ ���̽� ��
	while (t--) {
		int n, m;
		long long ans = 1;
		cin >> n >> m;
		int x = min(n, m - n);
		for (int i = 0; i < x; i++)
			ans *= m - i;
		for (int i = 1; i <= x; i++)
			ans /= i;
		cout << ans << endl;
	}
	return 0;
}