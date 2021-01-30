#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 100001
int a[MAX];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	if (n<1 || n>MAX-1)
		return 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int maxWeight = 0;
	for (int i = 0; i < n; i++) {
		maxWeight = max(maxWeight, a[i] * (n - i));
	}
	cout << maxWeight << endl;
	return 0;
}