#include <iostream>
using namespace std;

class node {
public:
	int data;
	node* leftchild;
	node* rightchild;
};

void preeOrder(node* ptr) // 전위 순회
{
	if (ptr != nullptr)
	{
		cout << ptr->data << " ";
		preeOrder(ptr->leftchild);
		preeOrder(ptr->rightchild);
	}
}

void inOrder(node* ptr) // 중위순회
{
	if (ptr)
	{
		inOrder(ptr->leftchild);
		cout << ptr->data << " ";
		inOrder(ptr->rightchild);
	}
}

void postOrder(node* ptr)
{
	if (ptr) {
		postOrder(ptr->leftchild);
		postOrder(ptr->rightchild);
		cout << ptr->data << " ";
	}
}

int main(void)
{
	node* tree = new node[16]; // 노드 1 ~ 15

	for (int i = 1; i <= 15; i++)
	{
		tree[i].data = i;
		tree[i].leftchild = nullptr;
		tree[i].rightchild = nullptr;
	}

	for (int i = 1; i <= 15; i++) {
		if (i % 2 == 0) {
			tree[i / 2].leftchild = &tree[i];
		}
		else {
			tree[i / 2].rightchild = &tree[i];
		}
	}

	preeOrder(&tree[1]);
	cout << endl;
	inOrder(&tree[1]);
	cout << endl;
	postOrder(&tree[1]);
	return 0;
}