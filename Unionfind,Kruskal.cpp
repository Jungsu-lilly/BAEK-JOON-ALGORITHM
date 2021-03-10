#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//부모 노드를 찾는 함수
int getParent(int parent[], int x)
{
	if (parent[x] == x) // 연결된 노드가 없는 경우
		return x;
	else {
		parent[x] = getParent(parent,parent[x]);
		return parent[x];
	}
}


// 두 부모노드를 합치는 함수
void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);

	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}


// 같은 부모를 가지는지 확인(같은 그래프에 속하는지를 확인)
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
		return 1;

	else return 0;
}

// 간선
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int d) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = d;
	}
	// 정렬 기준: 거리가 작은게 우선 출력되도록
	bool operator < (Edge &edge) {
		return this->distance < edge.distance;
	}
};


int main(void)
{
/*	int parent[11] = { 0, };

	for (int i = 1; i <= 10; i++)
		parent[i] = i;	// 개별적인 노드들을 생성
	
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);

	cout << "1과 5는 연결되어 있나요?" << endl;
	for (int i = 1; i <= 10; i++)
		cout << getParent(parent,i) << " ";
	cout << endl << findParent(parent, 1, 5) << endl;

	unionParent(parent, 2, 8);
	cout << "1과 6는 연결되어 있나요?" << endl;
	for (int i = 1; i <= 10; i++)
		cout << getParent(parent,i) << " ";
	cout << endl<< findParent(parent, 1, 6) << endl;*/

	const int n = 7;
	int m = 11;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	// 간선의 비용을 기준으로 오름차순 정렬
	sort(v.begin(), v.end());

	int parent[n];
	for(int i = 0;i<n;i++){
		parent[i] = i;
	}

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		// 사이클이 발생하지 않는 경우 그래프에 포함시킴
		if (!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}
	cout << sum << endl;

	return 0;
}