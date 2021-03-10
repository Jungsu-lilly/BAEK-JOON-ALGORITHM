#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<pair<int, int>> a;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		a.clear();
		int n;
		int min = 100001, result = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			a.push_back(make_pair(x, y));
		}
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			if (min > a[i].second) {
				min = a[i].second;
				result++;
			}
		}
		cout << result << endl;
	}
	return 0;
}