#include <iostream>
using namespace std;
int main(void)
{
	int n; // �ݾ�
	cin >> n;
	if (n >= 1 && n < 1000) {
		int s = 1000 - n; // �ܵ�
		int num = 0; // �ܵ� ����
		num += s / 500;
		s %= 500;
		num += s / 100;
		s %= 100;
		num += s / 50;
		s %= 50;
		num += s / 10;
		s %= 10;
		num += s / 5;
		s %= 5;
		num += s;
		cout << num << endl;
	}
	return 0;
}