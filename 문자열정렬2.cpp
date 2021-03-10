#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a[1000];

bool compare(string a, string b)
{
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() > b.length())
		return 0;

	else{	// ���ڿ� ���̰� ���� ���
		int length = a.length();
		int aDigit = 0;
		int bDigit = 0;
		for (int i = 0; i < length; i++){
			if (a[i] - '0' <=9 && a[i]-'0'>=0) {	// ������ ���
				aDigit += a[i] - '0';
			}
			if (b[i] - '0' <= 9 && b[i] - '0' >= 0) {
				bDigit += b[i] - '0';
			}
		}

		if (aDigit < bDigit)	// ������ ���� ������찡 �켱!
			return 1;
		else if (aDigit > bDigit)
			return 0;
		else {	// ������ ���� ���� ���
			return a < b;
			// string ���� ��� �񱳿����� ���ָ� �ڵ����� ���������� �������ش�.
		}
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
		cout << a[i] << endl;
	}
	return 0;
}