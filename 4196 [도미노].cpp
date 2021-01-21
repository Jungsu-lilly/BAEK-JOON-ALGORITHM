#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#define MAX 100001
using namespace std;

vector<int> a[MAX];
int d[MAX], id;
bool finished[MAX];
vector<vector<int>> SCC;
stack<int> s;
int inDegree[MAX], group[MAX];

int dfs(int x)
{
	d[x] = ++id; // 각 노드에 고유한 번호를 붙임.
	int parent = d[x];
	s.push(x);
	
	for(int i =0;i<a[x].size();i++){
		int y = a[x][i];
		if (!d[y]) // 인접 노드가 방문되지 않은 경우
			parent= min(parent,dfs(y));
		else if (!finished[y]) // 인접 노드 방문됨, 처리하는 중일 경우
			parent = min(parent, d[y]);
	}

	if (parent == d[x]) { // 부무노드가 자신일 경우
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			scc.push_back(t);
			group[t] = SCC.size() + 1;
			if (t == x)break;
		}
		SCC.push_back(scc);
	}
	return parent;
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int test;
	cin >> test;

	while (test--) {
		SCC.clear();
		id = 0;
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, false);
		fill(inDegree, inDegree + MAX, 0);
		fill(group, group + MAX, 0);
		int n, m; // 노드, 간선
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			a[i].clear();
		}

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
		}
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0)
				dfs(i);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < a[i].size(); j++) {
				int y = a[i][j]; // 인접노드
				if (group[i] != group[y])
					inDegree[group[y]]++;
			}
		}
		int ans = 0;
		for (int i = 1; i <= SCC.size(); i++) {
			if (inDegree[i] == 0)
				ans++;
		}
		cout << ans << endl;
	}
	return 0;
}