#include <iostream>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n = 1;
	while (1) {
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 & p == 0 && v == 0)
			return 0;
		int total = 0, remain = 0;
		remain = v % p;
		total += (v / p)*l;

		if (remain < l) {
			total += remain;
		}
		else {
			total += l;
		}
		cout << "Case " << n << ": " << total << endl;
		n++;
	}
	return 0;
}