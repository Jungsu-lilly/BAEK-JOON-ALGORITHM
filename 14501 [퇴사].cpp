#include <iostream>
#include <algorithm>
using namespace std;
int a[16][2];
int dp[16];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int t, p;
		cin >> t >> p;
		a[i][0] = t;  a[i][1] = p;
	}
	for (int i = 1; i <= N; i++) {
		if (a[i][0] != 1){
			dp[i] = max (dp[i - 1],dp[i]);
			if (i + a[i][0] - 1 > N)
				continue;
			dp[i + a[i][0] - 1] = max(dp[i-1] + a[i][1], dp[i + a[i][0] - 1]);
		}
		else {
			dp[i] = max(dp[i - 1] + a[i][1], dp[i]);
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
	cout << dp[N] << endl;
	return 0;
}