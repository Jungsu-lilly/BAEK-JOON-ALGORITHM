#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[500];
vector<int> dp[500];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, temp = 0; // 정수 삼각형 크기
	cin >> n;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i+1; j++) {
			cin >> temp;
			a[i].push_back(temp);
		}
	}
	dp[0].push_back(a[0][0]);
	for (int i = 1; i < n; i++) {
		dp[i].push_back(dp[i - 1][0] + a[i][0]);
		for (int j = 1; j < i; j++) {
			dp[i].push_back(max(dp[i - 1][j - 1] + a[i][j], dp[i - 1][j] + a[i][j]));
		}
		dp[i].push_back(dp[i - 1][i - 1] + a[i][i]);
	}
	int ans = dp[n - 1][0];
	for (int i = 1; i < n; i++) {
		if (ans < dp[n-1][i])
			ans = dp[n-1][i];
	}
	cout << ans << endl;
	return 0;
}