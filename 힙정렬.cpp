#include <iostream>
using namespace std;

int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void)
{
	// ���� ��ü Ʈ�� ������ �ִ� �� ������ �ٲ�. (��Ʈ�� �ִ� ���� ���� ŭ
	for (int i = 1; i < number; i++) 
	{
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c])
			{
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}

	// ũ�⸦ �ٿ����� �ݺ������� ���� ����
	for (int i = number - 1; i >= 0; i--)
	{
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;	// ���� ù��° ���ҿ� �� ������ ���Ҹ� �ٲ�.
		int root = 0;
		int c;
		do {
			c = 2 * root + 1;
			// �ڽ� �߿� �� ū �� ã��
			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;
			}
			if (heap[c] > heap[root] && c < i) {
				int temp = heap[c];
				heap[c] = heap[root];
				heap[root] = temp;
			}
			root = c;
		} while (c < i);
	}

	for (int i = 0; i < number; i++)
		cout << heap[i] << " ";
	cout << endl;

	return 0;
}