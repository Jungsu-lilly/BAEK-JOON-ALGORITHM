#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

void DFS(int start,vector <int> a[],bool check[])
{
	check[start] = true;
	cout << start << " ";

	for (int i = 0; i < a[start].size(); i++) {
		int next = a[start][i];
		if (check[next] == false)
			DFS(next, a, check);
	}
}


void BFS(int start,vector <int>a[],bool check[])
{
	queue<int> q;
	q.push(start);
	check[start] = true;

	while (!q.empty())
	{
		int t = q.front();
		cout << t << " ";
		q.pop();
		for (int i = 0; i < a[t].size(); i++) 
		{
			int next = a[t][i];
			if (check[next] != true) { // 방문하지 않았다면
				q.push(next);
				check[next] = true;
			}
		}
	}
}


int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m, v;
	bool check[1001] = { false, };

	cin >> n >> m >> v;
	vector<int>*a = new vector<int>[n+1];

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 0; i <= n; i++) {
		sort(a[i].begin(), a[i].end());
	}
	DFS(v,a,check);
	for (int i = 0; i < n + 1; i++) {
		check[i] = false;
	}
	cout << endl;
	BFS(v,a,check);
	return 0;
}