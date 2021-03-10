#include <iostream>
#include <string>
using namespace std;
int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, numofCup = 0;
	cin >> n;
	if (n < 1 || n>50) return 0;

	string s;
	cin >> s;
	unsigned int i = 0;
	if (s[0] == 'S') {
		numofCup += 2;
		i++;
	}
	else if (s[0] == 'L') {
		numofCup += 2;
		i += 2;
	}
	while (i < s.size()) {
		char c = s[i];
		if (c == 'S') {
			numofCup += 1; 
			i++;
		}
		else if (c == 'L') {
			numofCup += 1;
			i += 2;
		}
	}
	cout << numofCup << endl;
	return 0;
}