#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define MAX 100000
using namespace std;

vector<int> a[MAX];
int d[MAX], id, inDegree[MAX];
int group[MAX];
bool finished[MAX] = { false, };
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x)
{
	d[x] = ++id;
	int parent = d[x];
	s.push(x);

	for (int i = 0; i < a[x].size(); i++){
		int y = a[x][i]; // 이웃 노드
		if (d[y] == 0)
			parent = min(parent, dfs(y));
		else if (!finished[y]) // 처리중인 경우
			parent = min(parent, d[y]);
	}
	if (parent == d[x]) { // 부모 노드가 자신일 경우
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			scc.push_back(t);
			if (t == x)
				break;
		}
		sort(scc.begin(), scc.end()); // 오름차순 정렬
		SCC.push_back(scc);
	}
	return parent;
}

void ans1(int n) {
	int idx = 1;
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) { // 같은 scc인 노드들은 같은 그룹에
			int x = SCC[i][j];
			group[x] = idx;
		}
		idx++;
	}

	// group의 inDegree 를 세어줌
	for (int i = 0; i < n; i++) {
		int x = i; // 노드
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			if (group[x] != group[y]) // 다른 그룹인 경우 해당 group의 inDegree를 1로.
				inDegree[group[y]] = 1;
		}
	}

	int count = 0;
	int ans = 0;
	for (int i = 1; i <= idx-1; i++) {
		if (inDegree[i] == 0) {
			count++;
			ans = i;
		}
	}
	if (count == 1) { // 진입차수가 0인 그룹이 오직 한개 존재
		for (int i = 0; i < SCC[ans-1].size(); i++) {
			cout << SCC[ans-1][i] << endl;
		}
	}
	else { // 진입차수가 0인 그룹이 1개 이상일 때
		cout << "Confused" << endl;
	}
	cout << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	if (t > 11 || t < 0)
		return 0;
	while (t--) {
		// 각종 전역변수 초기화
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, false);
		fill(inDegree, inDegree + MAX, 0);
		fill(group, group + MAX, 0);
		id = 0;

		int n, m; // n:노드, m:간선
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			a[i].clear(); // a 초기화
		}

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
		}

		for (int i = 0; i < n; i++)
			if (d[i] == 0) dfs(i); // 방문하지 않은 정점에 대해서만 dfs수행
		ans1(n);
	}
}