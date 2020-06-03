#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue <int > q;
 
int **map;
int *visited;

void init(int N) {
	map = new int*[N + 1];
	visited = new int[N + 1];
	for (int i = 0; i <= N; i++) {
		map[i] = new int[N + 1];
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			map[i][j] = 0;
		}
	}
}

void init_visited(int N) {
	for (int i = 0; i <= N; i++) {
		visited[i] = 0;
	}
}

void dfs(int N, int start) {
	visited[start] = 1;

	cout << start << " ";
	for (int i = 1; i <= N; i++) {
		if (map[start][i] == 1 && visited[i] == 0) {
			dfs(N, i);
		}
	}
}

void bfs(int N, int start) {
	visited[start] = 1;
	cout << start << " ";
	while (true) {
		if (!q.empty()) {
			start = q.front();
			q.pop();
		}
		for (int i = 1; i <= N; i++) {
			if (map[start][i] == 1 && visited[i] == 0) {
				cout << i << " ";
				q.push(i);
				visited[i] = 1;
			}
		}
		if (q.empty()) {
			break;
		}
	}
	
}

int main() {
	int N, M , V;
	cin >> N >> M >> V;
	init(N);
	init_visited(N);
	int start = N;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs(N, V);
	init_visited(N);
	cout << "\n";
	bfs(N, V);
}