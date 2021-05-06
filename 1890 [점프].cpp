#include <iostream>
using namespace std;
int a[101][101], n;
long long dp[101][101];
int dx[] = { 0,1 };
int dy[] = { 1,0 };

long long dfs(int x, int y) {

	if (dp[x][y] != 0) { // 첫 방문이 아닌 경우
		return dp[x][y];
	}

	// -------- 여기부턴 첫 방문인 경우 -------- // 
	if (a[x][y] == 0) {
		return dp[x][y];
	}

	int t = a[x][y];
	for (int i = 0; i <= 1; i++) {
		int nx = x + t * dx[i]; // 다음 X좌표
		int ny = y + t * dy[i]; // 다음 Y좌표
		if (nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
			dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}


int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);	cout.tie(0);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	dp[n][n] = 1;
	cout << dfs(1, 1);
/*	cout << endl;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}*/
	return 0;
}