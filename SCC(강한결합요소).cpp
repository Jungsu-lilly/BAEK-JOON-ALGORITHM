#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 1001 // 가능한 총 노드의 갯수

int d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>>SCC;
stack<int> s;

int dfs(int x)
{
	d[x] = x; // 노드에 번호부여
	s.push(x); // 스택에 자기자신을 넣음

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i]; // 이웃 노드
		if (!d[y]) // 방문하지 않은 경우
			parent = min(parent, dfs(y));
		else if (!finished[y]) //진행 중인 경우
			parent = min(parent, d[y]);
	}

	if (parent == d[x]) { // 부모 노드가 자기 자신인 경우
		vector<int> scc;
		while (true) 
		{
			int k = s.top();
			s.pop();
			scc.push_back(k);
			finished[k] = true;
			if (k == x) // 자기 자신과 만나면
				break;
		}
		SCC.push_back(scc);
	}

	return parent;
}

int main(void)
{
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);

	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);

	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);

	for (int i = 1; i <= 11; i++) {
		if (d[i] == 0) dfs(i);
	}

	cout << "SCC 갯수: " << SCC.size() << endl;
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}