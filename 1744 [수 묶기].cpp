#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 10000
using namespace std;
vector<int> a;
stack<int> s;

bool desc(int a, int b) {
	return a > b;
}

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	int result = 0, minus = 0, zero = 0;
	cin >> n;
	if (n >= MAX || n<1) return 0;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (temp<-MAX || temp>MAX) return 0;
		if (temp < 0) minus++;
		if (temp == 0) zero++;
		a.push_back(temp);
	}
	sort(a.begin(),a.end(), desc); // 내림차순으로 정렬
	if(minus%2==0){ // 음수가 짝수개
		int len = a.size();
		int temp = 0;
		for (int i = len-1; i > len-minus-1; i-=2) {
			int t = a[i]; a.pop_back();
			int k = a[i - 1]; a.pop_back();
			temp += t*k;
		}
		result += temp;
	}
	else if (minus % 2 != 0) { // 음수가 홀수개
		int len = a.size();
		int temp = 0;
		for (int i = len - 1; i > len - minus; i-=2) {
			int t = a[i]; a.pop_back();
			int k = a[i - 1]; a.pop_back();
			temp += t * k;
		}
		if (zero >= 1) { // 수열에 0이 하나 이상 존재할 경우
			a[len - minus] = 0;
		}
		result += temp;
	}

	vector<int> b;
	for (unsigned int i = 0; i < a.size(); i++) {
		if (a[i] > 1) {
			b.push_back(a[i]);
			a[i] = 0;
		}
	}
	for (unsigned int i = 0; i < b.size(); i += 2) {
		if (i + 1 >= b.size()) break;
		int x = b[i];
		int y = b[i + 1];
		b[i] = 0; b[i + 1] = 0;
		result += x * y;
	}
	for (unsigned int i = 0; i < b.size(); i++) {
		if (b[i] != 0)
			result += b[i];
	}
	for (unsigned int i = 0; i < a.size(); i++) {
		result += a[i];
	}
	cout << result << endl;
	return 0;
}