#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> v[501];
int time[501];
int result[501];
int inDegree[501];
int n;

void topologySort() { // topology Sort
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			result[i] = time[i];
			q.push(i);
		}
	}

	for (int i = 0; i < n; i++) { // 정렬이 정확히 수행되려면 n개의 노드 방문
		int x = q.front();
		q.pop();
		for (int j = 0; j < v[x].size(); j++) {
			int y = v[x][j];
			result[y] = max(result[x] + time[y], result[y]);
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}

	for (int i = 1; i <= n; i++)
		cout << result[i] << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n; // 건물의 종류 수
	for (int i = 1; i <= n; i++) {
		int m;
		cin >> m;
		time[i] = m; // 걸리는 시간
		while (1)
		{
			int x; // 먼져 지어져야 하는 건물 번호
			cin >> x;
			if (x == -1)
				break;
			v[x].push_back(i);
			inDegree[i] += 1;

		}
	}
	topologySort();

	return 0;
}