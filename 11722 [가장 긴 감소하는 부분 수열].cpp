#include<iostream>
#include <algorithm>
using namespace std;
int a[1000];
int dp[1000];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		dp[i] = max(1, dp[i]); // 첫 방문때는 1로 설정함.
		for (int j = i + 1; j < n; j++) {
			if (a[j] < a[i]) {
				dp[j] = max(dp[i] + 1,dp[j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		ans = max(dp[i], ans);
	}
	for (int i = 0; i < n; i++) {
		cout << dp[i] << " ";
	}cout << endl;
	cout << ans << endl;
	return 0;
}