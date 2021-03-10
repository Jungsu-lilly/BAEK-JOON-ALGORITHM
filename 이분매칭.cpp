#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

vector<int> a[MAX];
int d[MAX]; // 특정한 정점을 선택하고 있는 노드 정보
bool c[MAX]; // 특정 정점 처리여부
int  n = 3, m;

//매칭에 성공한 경우 true, 실패한 경우 false 반환
bool dfs(int x)
{
	for(int i =0;i<a[x].size();i++){
		int t = a[x][i];
		//이미 처리한 노드는 볼 필요 x
		if (c[t]) continue;
		c[t] = true;
		// 비어있거나 점유노드에 더 들어갈 공간이 있는 경우
		if(d[t] ==0||dfs(d[t])){
			d[t] = x;
			return true;
		}
	}
	return false;
}

int main(void)
{
	a[1].push_back(1);
	a[1].push_back(2);
	a[1].push_back(3);
	a[2].push_back(1);
	a[3].push_back(2);
	int count = 0;
	for (int i = 1; i <= n; i++)	{
		fill(c, c + MAX, false);
		if (dfs(i)) count++;
	}
	cout << count << "개의 매칭이 이루어졌습니다." << endl;
	for (int i = 1; i <= MAX; i++) {
		if (d[i] != 0)
			cout << d[i] << " -> " << i << endl;
	}
	return 0;
}