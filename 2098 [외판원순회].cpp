#include <iostream>
#include <algorithm>
#include <string>
#define endl 'n'
#define INF 999999999
using namespace std;
int N, map[16][16], cost[16][1 << 16];
int answer_Bit = 0;

int dfs(int cur_Node, int cur_Bit) {

	if (cur_Bit == answer_Bit) { // 모든 노드 방문
		if (map[cur_Node][0] == 0)
			return INF;
		else {
			return map[cur_Node][0];
		}
	}
	if (cost[cur_Node][cur_Bit] != -1)
		return cost[cur_Node][cur_Bit];
	
	cost[cur_Node][cur_Bit] = INF;

	for (int i = 0; i < N; i++) {
		if ((cur_Bit & (1 << i)) == (1 << i)) // 이미 방문한 경우
			continue;
		if (map[cur_Node][i] == 0) // 길이 없는 경우
			continue;
		
		cost[cur_Node][cur_Bit] = min(cost[cur_Node][cur_Bit], map[cur_Node][i] + dfs(i,cur_Bit | 1 << i));
	}
	return cost[cur_Node][cur_Bit];
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}
	answer_Bit = (1 << N) - 1;
	memset(cost, -1, sizeof(cost));
	cout << dfs(0, 1);
	return 0;
}