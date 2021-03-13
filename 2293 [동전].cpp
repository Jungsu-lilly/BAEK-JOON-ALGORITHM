#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
int dp[10001];
bool asc(int a, int b) { // 오름차순으로 정렬
	return a < b;
}
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	sort(a.begin(), a.end(), asc);
	for (unsigned int i = 0; i < a.size(); i++) {
		int x = a[i];
		for (int j = 1; j <= k; j++) {
			if (x > j)continue;
			dp[j] += dp[j - x];
		}
	}
	cout << dp[k] << endl;
	return 0;
}