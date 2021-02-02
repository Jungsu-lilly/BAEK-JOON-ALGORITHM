#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int n, l; // 물이 새는 갯수, 테이프 길이
	cin >> n >> l;
	if (n < 1 || n>1000 || l < 1 || l>1000) return 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x < 1 || x>1000) return 0;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	int num = 1; // 필요한 테이프 수

	int temp = a[0]; // 테이프 위치 갱신
	for (int i = 1; i <= n - 1; i++) {
		int dis = a[i] - temp;
		if (l < dis + 1) {
			temp = a[i]; // 테이프 붙이는곳 갱신
			num++;
		}
	}
	cout << num << endl;
	return 0;
}