#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;
string s[2];
int dp[1002][1002];
vector<pair<int, int>> v[1002];
stack<pair<int, int>> S;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i <= 1; i++) {
		cin >> s[i];
	}
	int s1Length = s[0].length();
	int s2Length = s[1].length();

	for (int i = 1; i <= s2Length; i++) { // i : s2의 인덱스
		char s2 = s[1][i - 1];
		for (int j = 1; j <= s1Length; j++) { // j : s1의 인덱스
			char s1 = s[0][j - 1];

			if (s2 == s1) { // 두 단어가 같은 경우
				dp[i][j] = dp[i - 1][j - 1] + 1;
				v[dp[i][j]].push_back(make_pair(i, j));
			}
			else  // 두 단어가 다른 경우
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int ans = dp[s2Length][s1Length];
	cout << ans << endl;

	if (ans == 0)
		return 0;

	int idx1 = v[ans][0].first; // s2 인덱스
	int idx2 = v[ans][0].second; // s1 인덱스
	S.push(make_pair(idx1, idx2));
	for (int i = ans - 1; i >= 1; i--) {
		for (int j = 0; j < v[i].size(); j++) {
			if (idx1 > v[i][j].first && idx2 > v[i][j].second) {
				idx1 = v[i][j].first; idx2 = v[i][j].second;
				S.push(make_pair(idx1, idx2));
				break;
			}
		}
	}
	while (!S.empty()) {
		cout << s[1][S.top().first -1];
		S.pop();
	}
	return 0;
}