#include <iostream>
#include <string>
using namespace std;
int d[10001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cout.tie(0); cin.tie(0);
	int num = 0; // ¼¿ÇÁ³Ñ¹ö °¹¼ö

	for (int i = 1; i <= 10000; i++) {
		if (d[i] == 0)
			num++;
		string s = to_string(i);
		int sum = i;
		for (int j = 0; j < s.size(); j++)
			sum += s[j] - '0';
		if (sum <= 10000)
			d[sum] = 1;
	}

	for (int i = 1; i <= 10000; i++) {
		if (d[i] == 0)
			cout << i << '\n';
	}

	return 0;
}