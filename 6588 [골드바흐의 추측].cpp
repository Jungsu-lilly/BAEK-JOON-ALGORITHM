#include <iostream>
#define MAX 1000000 // 백만
using namespace std;

int d[MAX+1];
int oddNumber[MAX + 1];
int main(void) {

	d[1] = 1; // 1은 소수가 아님.
	for (int i = 2; i <= MAX; i++) {
		if (d[i] == 1)
			continue;
		else if (i != 2) { // d[i] == 0인 상태
			oddNumber[i] = i;
		}
		for (int j = i + i; j <= MAX; j += i) {
			if (d[j] == 1) continue;
			else
				d[j] = 1;
		}
	}


	int n = 0, count = 0;
	while (count <= 100000) {
		cin >> n;
		if (n == 0) break;
		if (n<6 || n>MAX || n % 2 != 0)
			return 0;
		
		for (int i = 3; i <= n/2; i += 2) {
			if (oddNumber[i] != 0 && oddNumber[n - i] != 0) {
				cout << n << " = " << i << " + " << n - i << '\n';
				break;
			}
		}
		count++;
	}
	return 0;
}