#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

vector<int> a[MAX];
vector<vector<int>> SCC;
stack<int> s;
int d[MAX], id;
bool finished[MAX];

int dfs(int x)
{
	d[x] = ++id;
	int parent = d[x];
	s.push(x);
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i]; // 인접노드
		// 아직 방문하지 않은 인접노드인 경우
		if (d[y] == 0)
			parent = min(parent, dfs(y));
		// 인접노드가 방문은 했지만 아직 처리중인 경우
		else if (!finished[y])
			parent = min(parent, d[y]);
	}

	if (d[x] == parent) { // 자기 자신이 부모 노드인 경우
		vector<int> scc;
		finished[x] = true;
		while (true) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			if (t == x)
				break;
			finished[t] = true;
		}
		sort(scc.begin(), scc.end()); // 오름차순으로 정렬
		SCC.push_back(scc);
	}
	return parent;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int v, e;
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
	}

	for (int i = 1; i <= v; i++) { // dfs는 정점의 개수만큼 일어난다.
		if (d[i] == 0) // 방문하지 않은 노드에 한해서만
			dfs(i);
	}

	sort(SCC.begin(), SCC.end());
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << " ";
		}
		cout << -1 << endl;
	}
	return 0;
}