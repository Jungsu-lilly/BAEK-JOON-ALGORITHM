#include <iostream>
#include <string>
#include <vector>
#define MAX 500000
using namespace std;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string a;
	vector<char> ch;
	int n, k;
	cin >> n >> k;
	if (k < 1 || n < 2 || k >= MAX || n>MAX || k>=n) // 범위 오류
		return 0;
	cin >> a;

	int i = 0;
	while (i != a.size()) {
		while (k != 0 && !ch.empty() && ch.back() < a[i]) {
			ch.pop_back();
			k--; // 숫자 제거갯수 1감소
		}
		ch.push_back(a[i]);
		i++;
	}
	while (k--) {
		ch.pop_back();
	}

	for (int i = 0; i < ch.size(); i++)
		cout << ch[i];
	cout << endl;
	return 0;
}