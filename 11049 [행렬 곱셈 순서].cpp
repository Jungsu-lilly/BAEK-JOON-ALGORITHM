#include <iostream>
#include <algorithm>
using namespace std;
int dp[501][501]; // dp[x][y] : �ε����� x~ y������ ��� �� ���ϴ� ������ ����.

class m { // ��� Ŭ����
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
	int n; // ����� ����
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i].r;
		cin >> a[i].c;
	}
	cout << func(1, n);
	return 0;
}