#include <iostream>
#define MAX 2187
using namespace std;

int a[MAX][MAX];
int ans[3]; // -1 , 0, 1 로만 채워진 종이갯수

int div(int n, int r, int c) {

	if (n == 1)
		return a[r][c];
	
	int temp[9] = { 0, };
	temp[0] = div(n / 3, r, c);
	temp[1] = div(n / 3, r, c + n / 3);
	temp[2] = div(n / 3, r, c + 2 * n / 3);
	temp[3] = div(n / 3, r + n / 3, c);
	temp[4] = div(n / 3, r + n / 3, c + n / 3);
	temp[5] = div(n / 3, r + n / 3, c + 2 * n / 3);
	temp[6] = div(n / 3, r + 2 * n / 3, c);
	temp[7] = div(n / 3, r + 2 * n / 3, c + n / 3);
	temp[8] = div(n / 3, r + 2 * n / 3, c + 2 * n / 3);

	int k = temp[0]; bool val = true;

	for (int i = 0; i < 8; i++) {
		if (temp[i] != temp[i + 1]) {
			val = false;
			break;
		}
	}

	if (val == true) // 9개가 다 같은 경우
		return temp[0];
	else {
		for (int i = 0; i < 9; i++) {
			switch (temp[i]) {
			case -1: ans[0]++; break;
			case 0: ans[1]++; break;
			case 1: ans[2]++; break;
			}
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if (n<1 || n>MAX) return 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];	// 배열 채우기
	}
	
	div(n, 0, 0);
	for (int i = 0; i < 3; i++)
		cout << ans[i] << endl;

	return 0;
}