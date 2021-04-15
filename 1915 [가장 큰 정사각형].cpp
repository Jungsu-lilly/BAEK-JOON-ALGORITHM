#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int n, m;
int a[1001][1001];
int dp[1001][1001];

void Search(int x, int y) {
	if(a[x][y] == 1)
		dp[x][y] = min(dp[x - 1][y - 1], min(dp[x][y - 1], dp[x - 1][y])) + 1;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); string s;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			a[i][j] = s[j-1] - '0';
		}
		s.clear();
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			Search(i, j);
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ans = max(dp[i][j], ans);
		}
	}
	cout << ans * ans << endl;
	return 0;
}