#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[10001];
int dp[10001];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	dp[1] = a[1];
	dp[2] = max(dp[1] + a[2], a[2]);
	dp[3] = max(a[1] + a[3], a[2] + a[3]);
	dp[3] = max(dp[3], a[1] + a[2]);
	for (int i = 4; i <= n; i++) {
		int temp = max(dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]);
		temp = max(temp, dp[i - 1]);
		dp[i] = temp;
	}
	for (int i = 1; i <= n; i++)
		cout << dp[i] << " ";
	return 0;
}