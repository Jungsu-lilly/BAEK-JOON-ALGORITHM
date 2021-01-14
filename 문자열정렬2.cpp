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

	else{	// 문자열 길이가 같은 경우
		int length = a.length();
		int aDigit = 0;
		int bDigit = 0;
		for (int i = 0; i < length; i++){
			if (a[i] - '0' <=9 && a[i]-'0'>=0) {	// 숫자인 경우
				aDigit += a[i] - '0';
			}
			if (b[i] - '0' <= 9 && b[i] - '0' >= 0) {
				bDigit += b[i] - '0';
			}
		}

		if (aDigit < bDigit)	// 숫자의 합이 작은경우가 우선!
			return 1;
		else if (aDigit > bDigit)
			return 0;
		else {	// 숫자의 합이 같은 경우
			return a < b;
			// string 같은 경우 비교연산을 해주면 자동으로 사전순으로 정렬해준다.
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