#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a, b;

bool desc(int a, int b) {
	return a > b;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, temp = 0, ans = 0;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> temp;
		a.push_back(temp);
		b.push_back(temp);
	}
	sort(b.begin(), b.end(), desc);
	int top = b[0];
	if (b[0] <= 0) {
		cout << b[0] << endl;
		return 0;
	}
	temp = 0;
	ans = a[0];
	for (unsigned int i = 0; i < a.size(); i++) {
		if (temp + a[i] < 0) { // 음수라면
			temp = 0; // 초기화해줌
			continue;
		}
		temp += a[i];
		if (ans < temp)
			ans = temp;
	}
	cout << ans << endl;
	return 0;
}