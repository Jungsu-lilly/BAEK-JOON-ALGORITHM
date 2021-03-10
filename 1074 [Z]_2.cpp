#include <iostream>
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, r, c;
	cin >> n >> r >> c;
	int res = 0;
	int len = pow(2, n - 1);

	int x = r; // За
	int y = c; // ї­
	for (int i = 0; i < n;i++) {
		if (x < len && y < len) {
			res += 0;
		}
		else if (x < len && y >= len) {
			res += len*len;
		}
		else if (x >= len && y < len) {
			res += len * len * 2;
		}
		else if (x >= len && y >= len) {
			res += len * len * 3;
		}
		x = x % len;
		y = y % len;
		len = len / 2;
	}
	cout << res << endl;
	return 0;
}