#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		vector<int> v(n+1);
		vector<int> sum(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> v[i];
			if (i == 0) {
				sum[i] = v[i];
			}
			else
				sum[i] = sum[i - 1] + v[i];
		}

		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		for (int gap = 1; gap < n; gap++) { // 갭 변동 ( 1 ~ (n-1) )
			for (int start = 1; start + gap <= n; start++) { // 시작점 변동
 				int end = start + gap; //  도착점을 특정. end > start
				dp[start][end] = INT_MAX;
				for (int mid = start; mid < end; mid++) { // 중간점 변동
					if (dp[start][end] > dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1]) {
						dp[start][end] = dp[start][mid] + dp[mid + 1][end] + sum[end] - sum[start - 1];
					}
				}
			}
		}
		for (int i = 1; i <= n-1; i++) {
			for (int j = 1; j <= n; j++) {
				cout << dp[i][j] << '\t';
			}
			cout << endl;
		}
		cout << dp[1][n] << '\n';
	}
	return 0;
}