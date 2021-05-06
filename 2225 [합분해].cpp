#include <iostream>
using namespace std;
int dp[201][201];
#define MAX 1000000000;

int main(void) {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++) {
		dp[i][1] = 1;
	}
	for (int i = 1; i <= k; i++)
	{
		dp[0][i] = 1;
	}
	for (int i = 1; i <= k; i++)
		dp[1][i] = i;


	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= k; j++) {
			for (int l = 0; l <= i; l++) {
				dp[i][j] += dp[i - l][j - 1];
				dp[i][j] %= MAX;
			}
		}
	}

	cout << dp[n][k] << endl;
	return 0;
}