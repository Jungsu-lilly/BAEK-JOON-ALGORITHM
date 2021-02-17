#include <iostream>
using namespace std;
int main(void) {
	int n, count = 0; // 거스름돈 액수
	cin >> n;
	if (n % 5 == 0) {
		count += n / 5;
	}
	else { // 5의 배수가 아닌 경우
		while (true) {
			if (n < 0) {
				cout << -1 << endl;
				return 0;
			}
			if (n == 0) {
				count++;
				break;
			}
			if (n % 5 == 0) {
				count += n / 5;
				break;
			}
			n -= 2;
			count++; // 2원짜리 동전 1개 증가
		}
	}
	cout << count << endl;
	return 0;
}