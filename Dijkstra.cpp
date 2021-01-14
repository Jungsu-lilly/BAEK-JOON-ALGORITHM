#include <iostream>
using namespace std;

int number = 6;
int INF = 100000000; // 1억

//전체 그래프 초기화
int a[6][6] = {
	{0,2,5,1,INF,INF},
	{2,0,3,2,INF,INF},
	{5,3,0,3,1,5},
	{1,2,3,0,1,INF},
	{INF,INF,1,1,0,2},
	{INF,INF,5,INF,2,0}
};

bool v[6]; // 방문 노드
int d[6]; // 최단 거리


// 가장 최소 거리를 가지는 정점 반환.
int getSmallIndex()
{
	int min = INF;
	int index = 0;
	for (int i = 0; i < number; i++) {
		if (d[i] < min && !v[i]) {
			min = d[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start)
{
	v[start] = true;
	for (int i = 0; i < number; i++) {
		d[i] = a[start][i];
	}
	
	for (int i = 0; i < number - 2; i++){
		int current = getSmallIndex(); // 방문 X, 가장 가까운 노드 탐색
		v[current] = true; // 해당 노드 방문처리

		for (int j = 0; j < 6; j++)
		{
			if (!v[j]){
				// 노드를 거쳐서 갔을 때 거리가 더 가까운 경우
				if (d[current]+a[current][j] < d[j]) {
					d[j] = d[current] + a[current][j]; // 최단거리 갱신
				}
			}
		}
	}
}


int main(void)
{
	dijkstra(0);

	for (int i = 0; i < number; i++)
		cout << d[i] << " ";
	cout << endl;
	return 0;
}