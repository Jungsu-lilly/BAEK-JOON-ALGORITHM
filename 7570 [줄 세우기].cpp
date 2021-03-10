#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;
int dp[MAX+1]; // 각 값의 인덱스 값을 저장.
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, ans = 0; //  N: 어린이 수 
	cin >> N;

	for (int i = 0; i < N; i++) {
		int x; 
		cin >> x;
		dp[x] = dp[x - 1] + 1;
		ans = max(ans, dp[x]);
	}
	cout << N - ans << endl;
	return 0;
}