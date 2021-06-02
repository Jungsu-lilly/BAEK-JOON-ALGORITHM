#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> adj;
int cnt = 0;
int N;

void dfs(int x, int y, int dir) {
	if (x >= 0 && y >= 0 && x < N && y < N) {

		if (dir == 2) { // �밢��
			if (adj[x][y] == 1 || adj[x - 1][y] == 1 || adj[x][y - 1] == 1) {
				return;
			}
		}
		else if (dir == 1 || dir == 0) { // ������, �Ʒ�
			if (adj[x][y] == 1) {
				return;
			}
		}

		if (x == N - 1 && y == N - 1) {
			cnt++;
			return;
		}

		if (dir == 0) { // ������
			dfs(x, y + 1, 0);
			dfs(x + 1, y + 1, 2);
		}
		else if (dir == 1) { // �Ʒ�
			dfs(x + 1, y, 1);
			dfs(x + 1, y + 1, 2);
		}
		else { // ������ �밢�� �Ʒ�
			dfs(x, y + 1, 0);
			dfs(x + 1, y, 1);
			dfs(x + 1, y + 1, 2);
		}
	}
}

int main() {

	cin >> N;
	adj = vector<vector<int>>(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int block;
			cin >> block;
			if (block == 1)
				adj[i][j] = block;
		}
	}

	if (adj[0][0] != 1 && adj[N - 1][N - 1] != 1) {
		dfs(0, 1, 0);
	}
	cout << cnt;
}