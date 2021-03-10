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
		int y = a[x][i]; // �̿� ���
		if (d[y] == 0)
			parent = min(parent, dfs(y));
		else if (!finished[y]) // ó������ ���
			parent = min(parent, d[y]);
	}
	if (parent == d[x]) { // �θ� ��尡 �ڽ��� ���
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			scc.push_back(t);
			if (t == x)
				break;
		}
		sort(scc.begin(), scc.end()); // �������� ����
		SCC.push_back(scc);
	}
	return parent;
}

void ans1(int n) {
	int idx = 1;
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) { // ���� scc�� ������ ���� �׷쿡
			int x = SCC[i][j];
			group[x] = idx;
		}
		idx++;
	}

	// group�� inDegree �� ������
	for (int i = 0; i < n; i++) {
		int x = i; // ���
		for (int j = 0; j < a[x].size(); j++) {
			int y = a[x][j];
			if (group[x] != group[y]) // �ٸ� �׷��� ��� �ش� group�� inDegree�� 1��.
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
	if (count == 1) { // ���������� 0�� �׷��� ���� �Ѱ� ����
		for (int i = 0; i < SCC[ans-1].size(); i++) {
			cout << SCC[ans-1][i] << endl;
		}
	}
	else { // ���������� 0�� �׷��� 1�� �̻��� ��
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
		// ���� �������� �ʱ�ȭ
		SCC.clear();
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, false);
		fill(inDegree, inDegree + MAX, 0);
		fill(group, group + MAX, 0);
		id = 0;

		int n, m; // n:���, m:����
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			a[i].clear(); // a �ʱ�ȭ
		}

		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			a[x].push_back(y);
		}

		for (int i = 0; i < n; i++)
			if (d[i] == 0) dfs(i); // �湮���� ���� ������ ���ؼ��� dfs����
		ans1(n);
	}
}