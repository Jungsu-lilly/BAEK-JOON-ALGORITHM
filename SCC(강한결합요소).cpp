#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
#define MAX 1001 // ������ �� ����� ����

int d[MAX];
bool finished[MAX];
vector<int> a[MAX];
vector<vector<int>>SCC;
stack<int> s;

int dfs(int x)
{
	d[x] = x; // ��忡 ��ȣ�ο�
	s.push(x); // ���ÿ� �ڱ��ڽ��� ����

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i]; // �̿� ���
		if (!d[y]) // �湮���� ���� ���
			parent = min(parent, dfs(y));
		else if (!finished[y]) //���� ���� ���
			parent = min(parent, d[y]);
	}

	if (parent == d[x]) { // �θ� ��尡 �ڱ� �ڽ��� ���
		vector<int> scc;
		while (true) 
		{
			int k = s.top();
			s.pop();
			scc.push_back(k);
			finished[k] = true;
			if (k == x) // �ڱ� �ڽŰ� ������
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

	cout << "SCC ����: " << SCC.size() << endl;
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}