#include <iostream>
#include <vector>
using namespace std;
#define MAX 1001
int d[MAX];
vector<int> v;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	d[1] = 1;
	
	for (int i = 2; i <= 1000; i++) {
		for (int j = 2 * i; j <= 1000; j += i) {
			if (d[j] == 1) // 이미 방문한 경우
				continue;
			if (d[j] == 0) // 아직 방문x
				d[j] = 1;
		}
	}
	int n,m; // 수의 갯수
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> m;
		v.push_back(m);
	}
	int count = 0;
	for (int i = 0; i < v.size(); i++) {
		int x = v.at(i);
		if (d[x] == 0)
			count++;
	}
	cout << count << endl;
	return 0;
}