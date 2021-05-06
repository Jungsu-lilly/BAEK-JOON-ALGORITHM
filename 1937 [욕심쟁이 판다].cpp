#include <iostream>
#include <algorithm>
using namespace std;
int a[501][501]; // 대나무숲 지도
int dp[501][501], n; // n은 500 이하의 자연수
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 }; // 상, 좌, 하, 우

int Search(int x, int y) {
	if (dp[x][y] != 0) { // 이미 방문했다면
		return dp[x][y];
	}
	dp[x][y] = max(dp[x][y], 1);
	for (int i = 0; i < 4; i++) { // 상 좌 하 우 탐색
		int nextX = x + dx[i];
		int nextY = y + dy[i];

		if (nextX >= 1 && nextX <= n && nextY >= 1 && nextY <= n && a[nextX][nextY] > a[x][y]) {
			if (dp[nextX][nextY] != 0) { // 방문한 적이 있는 경우
				dp[x][y] = max(dp[x][y], dp[nextX][nextY] + 1);
			}
			else // 방문한 적이 없는 경우
				dp[x][y] = max ( dp[x][y] , Search(nextX, nextY) + 1);
		}
	}
	return dp[x][y];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			Search(i, j);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << "정답: " << ans << endl;
	return 0;
}