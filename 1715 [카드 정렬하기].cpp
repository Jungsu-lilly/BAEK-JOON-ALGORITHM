#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100000
using namespace std;
priority_queue <int,vector<int>,greater<int>> pq;	// �켱���� ť. ������������ ����.

int main(void) {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int n = 0, total = 0;
	cin >> n;
	if (n<1 || n>MAX) return 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x <= 0 || x>1000) return 0;
		pq.push(x);
	}
	
	if (n == 1) { // ī�尡 1���� ���
		total = 1;
	}
	else if(n>=2) { // ī�尡 2�� �̻��� ���
		int Size = pq.size();
		for (int i = 0; i < Size - 1; i++) { // size - 1�� ����
			int x = pq.top(); pq.pop(); // ���� ���� ��
			int y = pq.top(); pq.pop(); // �״��� ���� ��
			total += x + y;
			pq.push(x + y);
		}
	}
	cout << total << endl;
	return 0;
}