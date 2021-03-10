#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#define MAX 10000
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);

	int t;
	cin >> t; // 테스트 케이스 갯수
	while (t--) {
		vector<int> a;
		priority_queue<int, vector<int>, less<int>> pq; // 내림차순
		int N; // 통나무 갯수
		cin >> N;
		a.resize(N);
		for (int i = 0; i < N; i++) {
			int L; cin >> L; // 각 통나무의 높이
			pq.push(L);
		}
		int t = N / 2;
		a[t] = pq.top(); pq.pop();
		int Size = pq.size();
		for (unsigned int i = 0; i < Size; i++) {
			if (i % 2 == 0) {
				a[t - i / 2 - 1] = pq.top();
				pq.pop();
			}
			else {
				a[t + i / 2 + 1] = pq.top();
				pq.pop();
			}
		}
	/*	for (int i = 0; i < a.size(); i++)
			cout << a[i] << " ";
		cout << endl;*/
		int sub = a[0]-a[N-1];
		for (unsigned int i = 0; i < a.size()-1; i++) {
			if (sub < abs(a[i + 1] - a[i]))
				sub = abs(a[i + 1] - a[i]);
		}
		cout << sub << endl;
	}
	return 0;
}