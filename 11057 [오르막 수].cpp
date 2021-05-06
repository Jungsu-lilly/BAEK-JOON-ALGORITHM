#include <iostream>
using namespace std;
long long dp[1001][10];
int main(void) {
	int n;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			dp[i][j] = (dp[i][j - 1] + dp[i - 1][j])%10007;
		}
	}
	
	for (int i = 0; i <= 9; i++) {
		ans += dp[n][i];
	}
	cout << ans % 10007<< endl;
	return 0;
}