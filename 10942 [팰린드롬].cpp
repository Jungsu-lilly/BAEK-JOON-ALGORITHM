#include <iostream>
#include <vector>
using namespace std;
int a[2001];
vector<pair<int, int>> v;
int dp[2001][2001];
// dp[i][j] : i ~ j 까지 팰린드롬?

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; // 수열의 크기 1~2000
	int m; // 질문의 갯수 1~ 100,0000
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	cin >> m;
	for (int i = 1; i <= m; i++) {
		int s, e; // 시작점, 끝점
		cin >> s >> e;
		v.push_back(make_pair(s, e));
	}

	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
		if (a[i] == a[i + 1]) {
			dp[i][i + 1] = 1;
		}
		else
			dp[i][i + 1] = 0;
	}

	// n>= 3 부터 돌아가는 for문
	for (int gap = 2; gap <= n - 1; gap++) {
		for (int start = 1; start <= n - gap; start++) {
			int end = start + gap;
			if (a[start] == a[end] && dp[start + 1][end - 1] == 1) {
				dp[start][end] = 1;
			}
		}
	}

	for (int i = 1; i <= m; i++) {
		cout << dp[v[i - 1].first][v[i - 1].second] << endl;
	}
	return 0;
}