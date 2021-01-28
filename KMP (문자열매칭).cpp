#include <iostream>
#include <string>
#include <vector>
using namespace std;

int findString(string parent, string target) {
	int p = parent.size();
	int t = target.size();
	
	for (int i = 0; i <= p - t; i++) {
		bool check = true;
		for (int j = 0; j < t; j++) {
			if (target[j] != parent[i + j]) {
				check = false;
				break;
			}
		}
		if (check == true) {
			return i + 1;
		}
	}
	return -1;
}


vector<int> makeTable(string pattern) {
	int patternsize = pattern.size();
	vector<int> table(patternsize, 0); // patternsize��ŭ 0���� �ʱ�ȭ��
	int j = 0;
	for (int i = 1; i < patternsize; i++) {
		while (j > 0 && pattern[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j]) {
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(string parent, string pattern) {
	vector<int> table = makeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < parentSize; i++) {
		while (j > 0 && parent[i] != pattern[j]) {
			j = table[j - 1];
		}
		if (parent[i] == pattern[j]) {
			if (j == patternSize - 1) {
				cout << i - patternSize + 2 << "��°���� ã�ҽ��ϴ�." << endl;
				j = table[j];
			}
			else
				j++;
		}
	}
}

int main(void) {
/*	string parent = "Hello World!";
	string target = "ld!";
	int result = findString(parent, target);
	if (result == -1)
		cout << "ã�� �� �����ϴ�." << endl;
	else
		cout << "���ڿ��� " << result << "��°�Դϴ�." << endl;*/
	
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	vector<int> v = makeTable(pattern);
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	KMP(parent, pattern);
	return 0;
}