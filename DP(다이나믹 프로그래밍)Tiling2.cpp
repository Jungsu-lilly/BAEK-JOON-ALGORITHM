#include <iostream>
using namespace std;
long long int c[1000001][2];

long long int dp(int x)
{
	c[0][0] = 0;
	c[1][0] = 2;
	c[2][0] = 7;
	c[2][1] = 1;

	for (int i = 3; i <= x; i++) {
		c[i][1] = (c[i - 1][1] + c[i - 3][0]) % 1000000007;
		c[i][0] = (2 * c[i - 1][0] + 3 * c[i - 2][0] + 2 * c[i][1]) % 1000000007;
	}
	return c[x][0];
}

int main(void)
{
	int n;
	cin >> n;
	cout << dp(n) << endl;

	return 0;
}
