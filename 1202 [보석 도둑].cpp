#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector <pair<int, int>> jewl; // �μ�
multiset <int> bag; // ���� ���� ��� ����

bool desc(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) // ������ ���ٸ� ������ -> ���ſ� ��
		return a.first < b.first;
	else
		return a.second > b.second; // ���� �������� ����
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; // ����, ���� ����
	int total = 0;
	cin >> n >> k;
	int bagNum = k;
	for(int i=0;i<n;i++){
		int m, v;
		cin >> m >> v;
		jewl.push_back(make_pair(m, v)); // ����, ����
	}
	sort(jewl.begin(), jewl.end(), desc); // ���� ��������

	for (int i = 0; i < k; i++) {
		int temp; cin >> temp;
		bag.insert(temp);
	}

	for (int i = 0; i < n; i++) {
		int m = jewl[i].first; // ������ ����
		multiset<int>::iterator it = bag.lower_bound(m);
		if (it != bag.end()) { // ��Ҹ� ã�� ���
			total += jewl[i].second;
			bag.erase(it);
			bagNum--; // ���� ���氹�� 1����
		}
		if (bagNum == 0) break;
	}
	cout << total << endl;
	return 0;
}