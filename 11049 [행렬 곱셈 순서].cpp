#include <iostream>
#include <algorithm>
using namespace std;
int dp[501][501]; // dp[x][y] : 인덱스가 x~ y까지의 행렬 중 원하는 정답을 보관.

class m { // 행렬 클래스
public:
	int r;
	int c;
};
m a[501];

int func(int x, int y) {

	if (x == y) return 0;

	if (dp[x][y] != 0)
		return dp[x][y];

	int temp = INT_MAX;
	for (int k = x; k < y; k++) {
		temp = min(temp, func(x,k) + func(k+1,y) + a[x].r*a[k].c*a[y].c);
	}
	return dp[x][y] = temp;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; // 행렬의 갯수
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i].r;
		cin >> a[i].c;
	}
	cout << func(1, n);
	return 0;
}