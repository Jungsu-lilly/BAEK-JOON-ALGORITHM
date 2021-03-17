#include <iostream>
#include <algorithm>
using namespace std;
int a[1000];
int dp[1000];
int dp2[1000];
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n; // 수열의 크기
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	// 증가하는 부분수열 크기 구하기.
	for (int i = 0; i < n; i++) {
		int temp = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				temp = max(temp, dp[j] + 1);
			}
		}
		dp[i] = temp;
	}

	for (int i = 0; i < n; i++)
		cout << dp[i] << " ";
	cout << endl;

	// (선택된 것)이후로 감소하는 부분순열 크기 구하기
	// 역으로 증가하는 증가수열을 구함.
	for (int i = n-1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = n-1; j > i; j--) {
			if (a[i] > a[j]) {
				dp2[i] = max(dp2[i], dp2[j] + 1);
			}
		}
	}
	int Max = 0;
	
	for (int i = 0; i < n; i++) {
		if (dp[i] + dp2[i] - 1 > Max) {
			Max = dp[i] + dp2[i] - 1;
		}
	}
	for (int i = 0; i < n; i++)
		cout << dp2[i] << " ";
	cout << endl;
	cout << Max << endl;
	return 0;

}