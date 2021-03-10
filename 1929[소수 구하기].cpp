#include <iostream>
#define MAX 1000000
using namespace std;
int d[MAX+1];

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int m, n, count = 0;
	cin >> m >> n;
	d[1] = 1; // 1은 소수가 아님.
	
	for (int i = 2; i <= MAX;i++) {
		if (d[i] == 1)
			continue;
		for (int j = i+i; j <= MAX; j+=i) {
			if (d[j] == 1) continue;
			else { // d[j] == 0
				d[j] = 1;
			}
		}
	}
	for (int i = m; i <= n; i++) {
		if (d[i] == 0){
			cout << i;
			printf("\n");
		}
	}
	return 0;
}