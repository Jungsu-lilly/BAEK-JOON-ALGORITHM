#include <iostream>
#include <vector>
using namespace std;
int dp[1025][1025];
int a[1025][1025];
vector<pair<int, int>> v;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		v.push_back(make_pair(x1, y1));
		v.push_back(make_pair(x2, y2));
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
		}
	}

	for (int i = 0; i < 2 * m; i+=2) {
		int x1 = v[i].first;
		int y1 = v[i].second;
		int x2 = v[i+1].first;
		int y2 = v[i+1].second;
		cout << dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y1 - 1] << '\n';
	}
	return 0;
}