#include <iostream>
#include <algorithm>
using namespace std;
int a[300]; // 계단 점수
int dp[300];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n; // 계단의 갯수
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 10000 || a[i] < 1) return 0;
	}
	dp[0] = a[0];
	dp[1] = max(a[0], a[0] + a[1]);
	dp[2] = max(a[0] + a[2], a[1] + a[2]);

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 2] + a[i], dp[i - 3] + a[i - 1] + a[i]);
	}
	cout << dp[n-1] << endl;
	return 0;
}