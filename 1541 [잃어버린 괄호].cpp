#include <iostream>
#include <string>
using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	string a;
	cin >> a;
	string temp;
	int result = 0;
	bool minus = false;
	for (int i = 0; i < a.length(); i++) {
		char b = a[i];
		if (b >= '0' && b <= '9') {  // digit인 경우
			temp += b;
		}
		if (b == '+' || b == '-' || i == a.length()-1) { // '+', '-', 마지막인 경우
			if (b == '+' ||( b >= '0' && b <= '9')) {
				if (!minus)
					result += stoi(temp);
				else if (minus)
					result -= stoi(temp);
			}
			if (b == '-') {
				if (!minus) {
					result += stoi(temp);
					minus = true;
				}
				else if (minus)
					result -= stoi(temp);
			}
			temp = "";
		}
	}
	cout << result << endl;

	return 0;
}