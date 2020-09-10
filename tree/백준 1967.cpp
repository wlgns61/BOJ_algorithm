//트리의 지름
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector <pair<int, int>> tree[10001];
int visited[10001];
int _max = -1;
int farnode;

void DFS(int now, int sum) {
	visited[now] = sum;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i].first;
		int cost = sum + tree[now][i].second;
		if (visited[next] == -1) {
			DFS(next, cost);
		}
	}
	if (_max <= sum) {
		_max = sum;
		farnode = now;
	}
}

int main() {
	int V;
	cin >> V;
	for (int i = 1; i < V; i++) {
		int start, end, cost;
		cin >> start >> end >> cost;
		tree[start].push_back({ end, cost });
		tree[end].push_back({ start, cost });
	}
	memset(visited, -1, sizeof(visited));
	DFS(1, 0); //1에서 가장 멀리 떨어진 곳이 한쪽 지름의 끝이 된다. 하지만 반대쪽 끝이 1임은 보장 못한다.
	_max = -1;
	memset(visited, -1, sizeof(visited));
	DFS(farnode, 0);
	cout << _max;
}