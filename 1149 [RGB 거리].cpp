#include <iostream>
#include <algorithm>
using namespace std;
int a[1000][3];
int dp[1000][3];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];

	for (int i = 1; i < n; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + a[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + a[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + a[i][2];
	}
	ans = dp[n-1][0];
	for (int i = 1; i <= 2 ; i++) {
		if (dp[n-1][i] < ans)
			ans = dp[n-1][i];
	}
	cout << ans << endl;
	return 0;
}