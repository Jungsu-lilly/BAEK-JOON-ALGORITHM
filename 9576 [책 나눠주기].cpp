#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int d[1001];

bool manage(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) // �������� ���ٸ� �������� �� ū ������
		return a.first > b.first;
	return a.second < b.second; // �������� ���� ������ ����
}	

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T; // �׽�Ʈ ���̽�
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
				if (d[j] == 0) { // �湮���� ���� ���
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