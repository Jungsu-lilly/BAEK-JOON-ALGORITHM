#include <iostream>
using namespace std;
int main(void) {
	int n, count = 0; // �Ž����� �׼�
	cin >> n;
	if (n % 5 == 0) {
		count += n / 5;
	}
	else { // 5�� ����� �ƴ� ���
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
			count++; // 2��¥�� ���� 1�� ����
		}
	}
	cout << count << endl;
	return 0;
}