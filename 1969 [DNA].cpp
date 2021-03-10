#include <iostream>
#include <string>
#define MAX 1001
using namespace std;
string a[MAX];
string b;
int num[4]; // A, C, G, T

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; // dna수, 문자열 길이
	int distance = 0; // 해밍 거리
	cin >> n >> m;
	if (n < 1 || n>1000 || m < 1 || m>50)
		return 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < m; i++) { // 열
		for (int j = 1; j <= n; j++) { // 행
			char ch = a[j][i];
			switch (ch){
			case 'A':
				num[0]++; break;
			case 'C':
				num[1]++; break;
			case 'G':
				num[2]++; break;
			case 'T':
				num[3]++; break;
			}
		}
		int result = num[0]; int idx = 0;
		for (int k = 0; k < 3; k++) {
			if (result < num[k + 1]){
				result = num[k + 1];
				idx = k + 1;
			}
		}
		distance += n - result;
		switch (idx) {
		case 0:
			b += "A"; break;
		case 1:
			b += "C"; break;
		case 2:
			b += "G"; break;
		case 3:
			b += "T"; break;
		}
		for (int l = 0; l < 4; l++)
			num[l] = 0; // num  배열 초기화
	}
	cout << b << endl;
	cout << distance << endl;
	return 0;
}