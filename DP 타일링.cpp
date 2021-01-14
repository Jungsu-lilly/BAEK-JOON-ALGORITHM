#include <iostream>
using namespace std;

int d[1000001];
int c[1000001][2];

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (d[x] != 0)
		return d[x];

	return d[x] = dp(x - 1) + dp(x - 2);
}

int Tile(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 2;
	if (d[x] != 0)
		return d[x];
	return d[x] = (Tile(x - 1) + Tile(x - 2))%10007;
}

int Tile2(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 3;
	if (x == 3) return 5;
	if (d[x] != 0)
		return d[x];
	return d[x] = (Tile2(x - 1) + 2 * Tile2(x - 2)) % 10007;
}


int Tile3(int x)
{
	if (x == 0)return 1;
	if (x == 1) return 0;
	if (x == 2) return 3;
	if (d[x] != 0) return d[x];

	int result = 3 * Tile3(x - 2);
	for (int i = 3; i <= x; i++) {
		if (i % 2 == 0) {
			result += 2 * Tile3(x - i);
		}
	}
	return d[x] = result;
}


long long Tile4(int x)
{
	if (x == 0) return 1;
	if (x == 1) return 2;
	if (x==2) return 7;
	if (d[x] != 0) return d[x];

	long long result = 2 * Tile4(x - 1) + 3 * Tile4(x - 2);
	for (int i = 3; i <= x; i++) {
		result += (2 * Tile4(x - i))% 1000000007;
		if (x - i == 0)
			break;
	}
	return d[x] = result % 1000000007;
}

int main(void)
{
	int n;
	cin >> n;
	cout << Tile3(n) << endl;
	return 0;
}