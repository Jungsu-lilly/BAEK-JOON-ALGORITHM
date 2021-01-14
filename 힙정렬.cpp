#include <iostream>
using namespace std;

int number = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main(void)
{
	// 먼저 전체 트리 구조를 최대 힙 구조로 바꿈. (루트에 있는 값이 제일 큼
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

	// 크기를 줄여가며 반복적으로 힙을 구성
	for (int i = number - 1; i >= 0; i--)
	{
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;	// 힙의 첫번째 원소와 맨 마지막 원소를 바꿈.
		int root = 0;
		int c;
		do {
			c = 2 * root + 1;
			// 자식 중에 더 큰 값 찾기
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