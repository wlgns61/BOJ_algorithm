#include <iostream>
#include <algorithm>

using namespace std;


int **map;
int *visited;
int cnt = 0;

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
	for (int i = 1; i <= N; i++) {
		if (map[start][i] == 1 && visited[i] == 0) {
			dfs(N, i);
		}
	}
}


int main() {
	int N, M;
	cin >> N >> M;
	init(N);
	init_visited(N);
	int start = N;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	dfs(N, 1);
	for (int i = 2; i <= N; i++) {
		if (visited[i]) {
			cnt++;
		}
	}
	cout << cnt;
}