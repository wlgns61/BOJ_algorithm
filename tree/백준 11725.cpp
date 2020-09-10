//트리의 부모 찾기
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector <int> tree[100001];
int visited[100001];

void DFS(int now) {
	
	if(now==1)
		visited[now] = now;
	for (int i = 0; i < tree[now].size(); i++) {
		int next = tree[now][i];
		if (visited[next] == 0) {
			visited[next] = now;
			DFS(next);
		}
	}
}

int main() {
	int n;
	int x, y;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		tree[x].push_back(y);
		tree[y].push_back(x);
	}
	DFS(1);
	for (int i = 2; i <= n; i++) {
		cout << visited[i] << "\n";
	}
	
}