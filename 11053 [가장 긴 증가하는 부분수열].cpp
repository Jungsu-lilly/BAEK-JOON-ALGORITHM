#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000];
int dp[1000];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N; // 수열의 크기
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		int temp = 0;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				temp = max(temp, dp[j]);
			}
		}
		dp[i] = temp + 1;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}