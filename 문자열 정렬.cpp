#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string a[20000];

bool compare(string a, string b) {
	// 길이가 짧은게 우선순위가 더 높음
	if (a.length() < b.length()) {
		return 1;
	}
	else if (a.length() > b.length()) {
		return 0;
	}
	else {// 길이가 같은 경우
		return a < b; // string같은 경우는 비교연산을 하면 자동으로 사전순으로 정렬해줌
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