#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int num = 0;

void DFS(int start, int check[],vector<int>* vec)
{
	check[start] = 1;
	num++;

	for (int i = 0; i < vec[start].size(); i++) {
		if (!check[vec[start][i]]) {
			DFS(vec[start][i], check, vec);
		}
	}
}

int main(void)
{
	int check[101] = { 0, };
	int n, v;
	cin >> n >> v;
	if (n > 100)
		return -1;

	vector<int>* vec = new vector<int>[n + 1];
	for (int i = 0; i < v; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}

	for (int i = 0; i <= n; i++) {
		sort(vec[i].begin(), vec[i].end());

	}

	DFS(1, check, vec);
	cout << num-1 << endl;
	return 0;
}