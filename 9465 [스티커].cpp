#include <iostream>
#include <algorithm>
using namespace std;
int a[2][100001];
int dp[2][100001];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t, ans = 0; // 테스트 케이스
	cin >> t;

	while (t--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> a[0][i];
		for (int i = 1; i <= n; i++)
			cin >> a[1][i];
		dp[0][1] = a[0][1];
		dp[1][1] = a[1][1];
		dp[0][2] = dp[1][1] + a[0][2];
		dp[1][2] = dp[0][1] + a[1][2];
		
		for (int i = 3; i <= n; i++) {
			for (int j = 0; j < 2; j++) {
				dp[j][i] = max(dp[!j][i - 1] + a[j][i], max(dp[0][i - 2], dp[1][i - 2]) + a[j][i]);
			}
		}
		ans = max(dp[0][n], dp[1][n]);
		cout << ans << endl;
	}
	return 0;
}