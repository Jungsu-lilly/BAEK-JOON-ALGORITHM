#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> v[10];
int inDegree[10];
int MAX = 10;
int num; // ��尹��

void TopologySort()	// �������� �˰���
{
	queue<int> q;
	for (int i = 0; i < 7; i++) {
		if (inDegree[i] == 0) // 0������
		{
			q.push(i);
			inDegree[i] = -1;
			break;
		}
	}
	for(int i=0;i<num;i++) {
		if (q.empty()) {	// �������� ������ ���: ��Ȯ�� ��� ����(num)��ŭ �湮.
			cout << "����Ŭ�� �����Ǿ����ϴ�." << endl;
			return;
		}
		int x = q.front();
		q.pop();
		cout << x << " ";
		for (int i = 0; i < v[x].size(); i++) {
			inDegree[v[x][i]] -= 1; // ���� �ϳ��� ����
		}
		for (int i = 0; i< MAX; i++) {	// ������ ���� ��带 ť�� ����
			if (inDegree[i] == 0)
			{
				q.push(i);
				inDegree[i] = -1;
			}
		}
	}
	cout << endl;
}
int main(void)
{
	num = 7; // 7���� ��尡 ����
	for (int i = 0; i < MAX; i++)
		inDegree[i] = -1;

	v[1].push_back(2);
	v[1].push_back(5);
	v[2].push_back(3);
	v[3].push_back(4);
	v[4].push_back(6);
	v[5].push_back(6);
	v[6].push_back(5);
	v[6].push_back(7);

	inDegree[1] = 0;
	inDegree[2] = 1;
	inDegree[3] = 1;
	inDegree[4] = 1;
	inDegree[5] = 2;
	inDegree[6] = 2;
	inDegree[7] = 1;

	TopologySort();
	return 0;
}