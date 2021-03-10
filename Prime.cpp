#include <iostream>
#include <math.h>
using namespace std;

bool isPrime(int x) {
	for (int i = 2; i < x; i++) {
		if (x%i == 0) return false;
	}
	return true;
}

bool isPrime2(int x) {
	int end = (int)sqrt(x);
	for (int i = 2; i <= end; i++) {
		if (x%i == 0)return false;
	}
}

int number = 100000;
int a[100001];

void primeNumberSieve()
{
	for (int i = 2; i <= number; i++) {
		a[i] = i;
	}
	for (int i = 2; i <= number; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j <= number; j += i) {
			a[j] = 0;
		}
	}
	for (int i = 2; i <= number; i++) {
		if (a[i] != 0) {
			cout << a[i] << " ";
		}
	}
}
int main(void)
{
	//cout << isPrime(97) << endl;
	primeNumberSieve();
	return 0;
}