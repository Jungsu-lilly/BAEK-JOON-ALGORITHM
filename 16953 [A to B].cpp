#include <iostream>
#define MAX 1000000000
using namespace std;

int main(void) {
	int a, b, count = 0;
	cin >> a >> b;

	if (a<1 || a >= b || b>MAX) return 0;

	while (1) {
		if (b % 2 == 0) { // b�� ¦�����
			b = b / 2;
			count++;
		}
		else if (b % 2 != 0) { // b�� Ȧ�����
			if ((b - 1) % 10 != 0) {
				cout << -1 << endl;
				break;
			}
			b = (b - 1) / 10;

			count++;
		}
		if (b == a) {
			cout << count + 1 << endl;
			break;
		}
		if (b < a) {
			cout << -1 << endl;
			break;
		}
	}
	return 0;
}