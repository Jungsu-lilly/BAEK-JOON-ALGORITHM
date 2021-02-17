#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;

struct asc { // 오름차순으로 정렬
	bool operator()(long long a, long long b) {
		return a > b;
	}
};

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int n, m;
	long long sum = 0;
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		long long temp;
		cin >> temp;
		pq.push(temp);
	}
	
	for (int i = 0; i < m; i++) {
		long long p = 0;
		p += pq.top(); pq.pop();
		p += pq.top(); pq.pop();
		pq.push(p); pq.push(p);
	}

	while (!pq.empty()) {
		sum += pq.top();
		pq.pop();
	}
	cout << sum << endl;

	return 0;
}