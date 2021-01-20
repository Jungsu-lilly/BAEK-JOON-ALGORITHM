#include <iostream>
#include <vector>
#include <queue>
#define MAX 10001
using namespace std;

class Edge {
public:
	int node; // 도착노드
	int time; // 소요 시간
	Edge(int node, int time) {
		this->node = node;
		this->time = time;
	}
};

int inDegree[MAX];
vector<Edge> a[MAX];
vector<Edge> b[MAX];
int n, m;
int start, finish;
int result[MAX], c[MAX];

void topologySort()
{
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i].node;
			if (result[y] < a[x][i].time + result[x])
				result[y] = a[x][i].time + result[x];
			inDegree[y]--;
			if (inDegree[y] == 0)
				q.push(y);
		}
	}

	int count = 0;
	q.push(finish);
	while (!q.empty()) {
		int y = q.front();
		q.pop();
		for (int i = 0; i < b[y].size(); i++) {
			Edge x = b[y][i];
			if (result[y] - x.time == result[x.node]) {
				count++;
				if (c[x.node] == 0) {
					c[x.node] = 1;
					q.push(x.node);
				}
			}
		}
	}
	cout << result[finish] << endl;
	cout << count << endl;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		a[x].push_back(Edge(y, t));
		b[y].push_back(Edge(x, t));
		inDegree[y]++;
	}

	// 출발점, 도착점.
	cin >> start >> finish;
	topologySort();

	return 0;
}