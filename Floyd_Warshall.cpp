#include <iostream>
using namespace std;
int INF = 100000000; // 1��
int a[4][4] = { {0,5,INF,8},
{7,0,9,INF},
{2,INF,0,4},
{INF,INF,3,0} };
int num = 4;


// ��� �������� ��� ���������� �ִܰ��
void FloydWarshall() {
	// �����ϴ� ���� : i
	for (int i = 0; i < num; i++) {
		// j -> k
		for (int j = 0; j < num; j++) {
			if (j == i) continue;
			for (int k = 0; k < num; k++) {
				if (k == i) continue;
				if (j == k) continue;

				if (a[j][k] > a[j][i] + a[i][k]) {
					a[j][k] = a[j][i] + a[i][k]; // ����
				}
			}
		}
	}
}

int main(void)
{
	FloydWarshall();
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	return 0;
}