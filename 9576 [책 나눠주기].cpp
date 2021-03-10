#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int d[1001];

bool manage(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) // 끝지점이 같다면 시작점이 더 큰 순으로
		return a.first > b.first;
	return a.second < b.second; // 끝지점이 작은 순으로 정렬
}	

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; // 테스트 케이스
	cin >> T;
	while (T--) {
		memset(d, 0, sizeof(d));
		int N, M, count = 0;
		cin >> N >> M;

		vector <pair <int, int>> vec;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			vec.push_back(make_pair(a, b));
		}

		sort(vec.begin(), vec.end(), manage);
		for (int i = 0; i < M; i++) {
			int start = vec[i].first;
			int end = vec[i].second;
			for (int j = start; j <= end; j++) {
				if (d[j] == 0) { // 방문하지 않은 경우
					d[j] = 1;
					count++;
					break;
				}
			}
		}
		cout << count << endl;
	}
	
	return 0;
}