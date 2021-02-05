#include <iostream>
using namespace std;
#define MAX 100000
int d[MAX]; // ���ð� �Ÿ�
int price[MAX]; // ������ ���ʹ� ����
int main(void)
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int n;
	long long int total = 0;
	cin >> n;
	if (n<2 || n>MAX) return 0;

	for (int i = 0; i < n - 1; i++)
		cin >> d[i];
	for (int i = 0; i < n; i++)
		cin >> price[i];

	total += 1LL * d[0] * price[0];
	int temp = price[0];
	for (int i = 1; i < n - 1; i++) {
		if (price[i] < temp) { // ���� �� ũ�ٸ�
			total += 1LL * price[i] * d[i];
			temp = price[i];
		}
		else { // �̹��� �� ũ�ٸ�
			total += 1LL * temp * d[i];
		}
	}
	cout << total << endl;
	return 0;
}