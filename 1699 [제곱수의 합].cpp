#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int dp[100001];
int main(void) {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		dp[i] = i;
		for (int j = 1; j*j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);

	}
	for (int i = 1; i <= N; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
	cout << dp[N] << endl;
	return 0;
}