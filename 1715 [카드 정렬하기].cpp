#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100000
using namespace std;
priority_queue <int,vector<int>,greater<int>> pq;	// 우선순위 큐. 오름차순으로 정렬.

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
	
	if (n == 1) { // 카드가 1장인 경우
		total = 1;
	}
	else if(n>=2) { // 카드가 2장 이상인 경우
		int Size = pq.size();
		for (int i = 0; i < Size - 1; i++) { // size - 1번 수행
			int x = pq.top(); pq.pop(); // 제일 작은 값
			int y = pq.top(); pq.pop(); // 그다음 작은 값
			total += x + y;
			pq.push(x + y);
		}
	}
	cout << total << endl;
	return 0;
}