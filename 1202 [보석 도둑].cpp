#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
vector <pair<int, int>> jewl; // 부석
multiset <int> bag; // 보석 가방 허용 무게

bool desc(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) // 가격이 같다면 가벼운 -> 무거운 순
		return a.first < b.first;
	else
		return a.second > b.second; // 가격 내림차순 정렬
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; // 보석, 가방 개수
	int total = 0;
	cin >> n >> k;
	int bagNum = k;
	for(int i=0;i<n;i++){
		int m, v;
		cin >> m >> v;
		jewl.push_back(make_pair(m, v)); // 무게, 가격
	}
	sort(jewl.begin(), jewl.end(), desc); // 가격 내림차순

	for (int i = 0; i < k; i++) {
		int temp; cin >> temp;
		bag.insert(temp);
	}

	for (int i = 0; i < n; i++) {
		int m = jewl[i].first; // 보석의 무게
		multiset<int>::iterator it = bag.lower_bound(m);
		if (it != bag.end()) { // 요소를 찾은 경우
			total += jewl[i].second;
			bag.erase(it);
			bagNum--; // 남은 가방갯수 1감소
		}
		if (bagNum == 0) break;
	}
	cout << total << endl;
	return 0;
}