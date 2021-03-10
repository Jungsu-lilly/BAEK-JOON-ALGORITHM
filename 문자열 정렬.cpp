#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a[20000];

bool compare(string a, string b) {
	// ���̰� ª���� �켱������ �� ����
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() > b.length()) {
		return 0;
	}
	else {// ���̰� ���� ���
		return a < b; // string���� ���� �񱳿����� �ϸ� �ڵ����� ���������� ��������
	}
}

int main(void)
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	sort(a, a + n, compare);
	for (int i = 0; i < n; i++) {
		if (a[i] == a[i + 1]) {
			continue;
		}
		else {
			cout << a[i] << endl;
		}
	}
	return 0;
}