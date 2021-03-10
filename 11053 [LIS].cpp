#include <iostream>
#include <algorithm>
using namespace std;
int L[1001], len;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int N; cin >> N;

	for (int i = 1; i <= N; i++) {
		int temp; 
		cin >> temp;
		auto pos = lower_bound(L , L + len , temp);

		cout << pos << endl;
		*pos = temp;
		if (pos == L + len )
			len++;
	}
	cout << len << endl;
	return 0;
}