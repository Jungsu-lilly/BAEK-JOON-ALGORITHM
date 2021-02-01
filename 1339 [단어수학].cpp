#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
vector<string> s;
vector<int> v[26];
int Sum[26];
int result[26];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if (n < 1 || n>10) return 0;
	int NUM = 9;
	for (int i = 0; i < 26; i++) {
		v[i].push_back(i);
	}
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		s.push_back(str);
	}

	for (unsigned int i = 0; i < s.size(); i++) {
		for (unsigned int j = 0; j < s[i].size(); j++) {
			int x = s[i].size() - j - 1;
			int c = s[i][j] - 'A';
			Sum[c] += pow(10, x);
		}
	}
	for (int i = 0; i < 26; i++) {
		v[i].push_back(Sum[i]);
	}

	for (int i = 0; i < 25; i++) {
		int Max = v[i][1];
		int idx = i;
		for (int j = i + 1; j < 26; j++) {
			if (Max < v[j][1]) {
				idx = j;
				Max = v[j][1];
			}
		}
		if (idx != i) {
			int itemp = Sum[i];
			Sum[i] = Sum[idx];
			Sum[idx] = itemp;
			int temp = v[i][1];
			int idx1 = v[i][0];
			int temp2 = v[idx][1];
			int idx2 = v[idx][0];
			v[i].clear();
			v[i].push_back(idx2);
			v[i].push_back(temp2);
			v[idx].clear();
			v[idx].push_back(idx1);
			v[idx].push_back(temp);
		}
	}
//	cout << v[0][0] << ": " << v[0][1] << endl;
	int total = 0;
	for (int i = 0; i < 26; i++) {
		result[v[i][0]] = NUM--;
		total += result[v[i][0]] * v[i][1];
	}
	cout << total << endl;

	return 0;
}