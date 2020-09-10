//트리의 지름
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector <pair<int, int>> tree[100001];
int visited[100001];
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
	for (int i = 0; i < V; i++) {
		int start, end, cost;
		cin >> start;
		while (true) {
			cin >> end;
			if (end == -1) break;
			cin >> cost;
			tree[start].push_back({ end, cost });
		}
	}
	
	memset(visited, -1, sizeof(visited));
	DFS(1, 0); //문제에서 루트를 안알려주었기 때문에 꼭 1이 아니어도 됨
	_max = -1;
	memset(visited, -1, sizeof(visited));
	DFS(farnode, 0);
	cout << _max;
}