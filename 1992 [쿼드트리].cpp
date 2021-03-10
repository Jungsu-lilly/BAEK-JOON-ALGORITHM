#include <iostream>
#include <string>
#include <math.h>
#define MAX 64
using namespace std;
int a[MAX][MAX];
int idx = 0;

string div(int n, int r, int c) {
	if (n == 2) {
		int a1 = 0, a2 = 0, a3 = 0, a4 = 0;
		a1 = a[r][c]; a2 = a[r][c + 1];
		a3 = a[r + 1][c]; a4 = a[r + 1][c + 1];

		if (a1 == a2 && a2 == a3 && a3 == a4) {
			return to_string(a1);
		}
		else
			return "(" + to_string(a1) + to_string(a2) + to_string(a3) + to_string(a4) + ")";
	}
	string s1 = div(n / 2, r, c);
	string s2 = div(n / 2, r, c + n / 2);
	string s3 = div(n / 2, r + n / 2, c);
	string s4 = div(n / 2, r + n / 2, c + n / 2);
	if (s1 == s2 && s2 == s3 && s3 == s4 && s1.length() == 1) { // s1, s2, s3, s4가 같으면
		return s1;
	}
	else
		return "(" + s1 + s2 + s3 + s4 + ")";
}

int main(void) {
	ios_base::sync_with_stdio(0); cout.tie(0); cin.tie(0);

	int n; // 2의 제곱수
	string s = "";
	cin >> n;
	if (n < 1 || n>64)
		return 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			a[i][j] = s[j]-'0';
	} // 2차원 배열 완성
	cout << div(n, 0, 0) << endl;
	return 0;
}