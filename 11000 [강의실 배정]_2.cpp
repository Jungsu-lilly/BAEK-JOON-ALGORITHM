#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

bool ascbyStartTime(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}

struct ascbyEndTime{
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first > b.first;
		return a.second > b.second;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<pair<int, int>> a;
	priority_queue<pair<int, int>, vector<pair<int, int>>, ascbyEndTime> pq;

	int n, s, t, cnt = 1;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> s >> t;
		a[i] = { s,t };
	}
	sort(a.begin(), a.end(), ascbyStartTime);
	pq.push(a[0]);
	for (int i = 1; i < n; i++) {
		if (pq.top().second > a[i].first) {
			pq.push(a[i]);
			cnt++;
		}
		else {
			pq.pop();
			pq.push(a[i]);
		}
	}
	cout << cnt << endl;
	return 0;
}