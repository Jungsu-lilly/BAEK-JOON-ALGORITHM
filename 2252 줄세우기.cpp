#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v[32001];
int inDegree[32001];
queue<int> q;

int main(void)
{
	int n, m;
	scanf("%d %d", &n, &m);

	if ((1 <= n && n <= 32000) && (1 <= m && m <= 100000)) {
		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			inDegree[b]++; // ��� a�� �������� 1����
		}
	}

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			inDegree[i] = -1;
			break;
		}
	}

	while (!q.empty()) {
		int x = q.front(); // ť ���� �տ� ��
		printf("%d ", x);
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			inDegree[y] -= 1; // ���� ��� ���� ������.
		}
		for (int i = 1; i <= n; i++) {
			if (inDegree[i] == 0) {
				q.push(i);
				inDegree[i] = -1;
			}
		}
	}
	printf("\n");
	return 0;
}