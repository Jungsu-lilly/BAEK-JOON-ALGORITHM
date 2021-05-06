#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int time[1001], inDegree[1001], dp[1001];
vector<int> a[1001];
queue<int> q;

int main(void) {
	ios_base::sync_with_stdio(0);	cin.tie(0);	  cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k, des; // 건물 갯수, 건물 규칙 갯수
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
			cin >> time[i];
		for (int i = 0; i < k; i++) {
			int from, to;
			cin >> from;  cin >> to;
			a[from].push_back(to); // 인접노드 넣어줌.
			inDegree[to]++; // 진입차수 1증가시킴.
		}
		cin >> des; // 도착지점

		for (int i = 1; i <= n; i++) {
			if (inDegree[i] == 0) {
				q.push(i);
				dp[i] = time[i];
			}
		}
		
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			if (x == des)
				break;
			for (int i = 0; i < a[x].size(); i++) {
				int y = a[x][i];
				inDegree[y]--; // 인접노드의 진입차수 끊어줌.
				dp[y] = max(dp[y], dp[x] + time[y]);
				if(inDegree[y] == 0)
					q.push(y);
			}
		}
		while (!q.empty())
			q.pop();

		cout << "정답: " << dp[des] << endl << endl;

		// 변수들 초기화
		fill(time + 1, time + n + 1, 0);
		fill(inDegree + 1, inDegree + n + 1, 0);
		fill(dp + 1, dp + n + 1, 0);
		for (int i = 1; i <= n; i++) {
			if (time[i] != 0 || inDegree[i] != 0 || dp[i] != 0)
				cout << "오류 : " << i << endl;
			a[i].clear();
		}
	}

	return 0;
}