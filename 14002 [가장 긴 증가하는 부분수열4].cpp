#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int a[1001], dp[1001];
stack<int> S;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n; //  ������ ũ��
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		int temp = dp[i]; // temp�� 0�������� �����Ѵ�.
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j]) {
				temp = max(dp[j], temp);
			}
		}
		dp[i] = temp + 1;
		ans = max(ans, dp[i]);
	}

	int idx = 0;
	cout << ans << endl;
	for (int i = n; i >= 1; i--) {
		if (dp[i] == ans) {
			idx = i; // idx�� ans�� �ε��� ���� ����
			S.push(a[i]);
			ans--;
			break;
		}
	}

	for (int i = idx -1; i >= 1; i--) {
		if (ans == 0)
			break;
		if (dp[i] == ans) {
			S.push(a[i]);
			ans--;
		}
	}

	while (!S.empty()) {
		cout << S.top() << " ";
		S.pop();
	}
	return 0;
}