#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v;
int arr[100], dp[501];

bool ascA(pair<int, int> x , pair<int, int> y) {
	return x.first < y.first; // 앞에꺼 오름차순 정렬
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end(), ascA);
	for (int i = 0; i < v.size(); i++) {
		arr[i] = v[i].second;
	}

	// LIS (가장 긴 증가하는 부분수열 구하기 //
	for (int i = 0; i < n; i++) {
		int x = arr[i];
		int temp = 0;
		for (int j = 1; j < x; j++) {
			if (dp[j] != 0) {
				temp = max(temp, dp[j]);
			}
		}
		dp[x] = temp + 1;
	}
	int len = 0;
	for (int i = 1; i <= 500; i++) {
		len = max(len, dp[i]);
	}
	cout << n - len << endl;
	return 0;
}