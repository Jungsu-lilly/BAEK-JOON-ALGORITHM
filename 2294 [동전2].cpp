#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
int dp[10001];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	for (unsigned int i = 0; i < a.size(); i++) {
		int c = a[i];
		if (c > 10000) continue;
		for (int j = c; j <= k; j += c) {
			if (dp[j] != 0) // 이미 방문했을 경우
				dp[j] = min(dp[j], j / c);
			else { // 방문하지 않은 경우
				dp[j] = j / c;
			}
		}
	}

	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= i / 2; j++) {
			if(dp[i] != 0 && dp[j] != 0 && dp[i-j] != 0)
				dp[i] = min(dp[i], dp[j] + dp[i - j]);
			else if(dp[j] != 0 && dp[i - j] != 0)
				dp[i] =  dp[j] + dp[i - j];
		}
	}

	if (dp[k] != 0)
		cout << dp[k] << endl;
	else
		cout << -1 << endl;

	return 0;
}