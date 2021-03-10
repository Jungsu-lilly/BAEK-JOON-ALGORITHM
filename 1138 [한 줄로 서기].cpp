#include <iostream>
using namespace std;
int main(void)
{
	int d[11] = { 0 , };
	int n; // »ç¶÷¼ö
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		int count = 0;
		for (int j = 1; j <= n;j++) {
			if (d[j] == 0 && count == x) {
				d[j] = i;
				break;
			}
			if (d[j] == 0) count++;
		}
	}

	for (int i = 1; i <= n; i++)
		cout << d[i] << " ";
	cout << endl;
	return 0;
}