#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> s;
vector<int> a[8];
int check[8] = { 0, };

void DFS(int start)
{
	s.push(start);
	check[start] = 1;
	cout << start << " ";

	while (!s.empty())
	{
		int t = s.top();

		int k = 0;
		for (int i = 0; i < a[t].size(); i++) 
		{
			int x = a[t][i];
			if (check[x] != 1) { // 방문하지 않았다면
				s.push(x); // 스택에 넣고
				check[x] = 1; // 방문처리 한다.
				cout << x << " ";
				break;
			}
			else { // 인접노드가 이미 방문된 경우
				k++;
			}

			if (k == a[t].size()) { // 인접노드 다 방문
				s.pop();
			}
		}
	}
}

int main(void)
{
	a[1].push_back(2);
	a[2].push_back(1);

	a[1].push_back(3);
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);
	DFS(1);
	cout << endl;
	return 0;
}