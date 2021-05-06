#include <iostream>
#include <algorithm>
using namespace std;
int a[1001][1001];
int dp[1001][1001];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N, M; // За, ·Д
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			int Max = max(dp[i][j - 1], dp[i - 1][j]);
			Max = max(Max, dp[i - 1][j - 1]);
			dp[i][j] = Max + a[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[N][M] << endl;
	return 0;
}