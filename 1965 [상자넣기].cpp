#include <iostream>
#include <algorithm>
using namespace std;
int dp[1001];
int a[1001];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		dp[i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		int m = 0;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) {
				m = max(m, dp[j]);
			}
		}
		dp[i] = m + 1;
	}
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;

	return 0;
}