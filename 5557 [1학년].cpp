#include <iostream>
using namespace std;
int a[101], n;
long long dp[101][21];
// dp[i][j] i: ÀÎµ¦½º, j: °ª(0~20)

void solve(int x) {
	if (x == n)
		return;
	for (int i = 0; i <= 20; i++) {
		if (dp[x - 1][i] != 0) {
			if (i + a[x] <= 20) {
				dp[x][i + a[x]] += dp[x - 1][i];
			}
			if (i - a[x] >= 0) {
				dp[x][i - a[x]] += dp[x - 1][i];
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n; // 3 ~ 100

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1][a[1]] = 1;
	
	for (int i = 2; i <= n; i++)
		solve(i);

	cout << dp[n - 1][a[n]];
	return 0;
}