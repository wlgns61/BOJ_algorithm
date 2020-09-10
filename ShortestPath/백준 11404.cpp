#include <iostream>
#include <vector>
#include <algorithm>
#define INF 0xFFFFFFF

using namespace std;

int dist[101][101];
//vector <pair<int, int>> graph[101];

void init_graph() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (i == j) {
				dist[i][j] = 0;
			}
			else {
				dist[i][j] = INF;
			}
		}
	}
}

void shortest_path(int N) {
	for (int via = 1; via <= N; via++) {
		for (int from = 1; from <= N; from++) {
			for (int to = 1; to <= N; to++) {
				if (dist[from][to] > dist[from][via] + dist[via][to]) {
					dist[from][to] = dist[from][via] + dist[via][to];
				}
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	init_graph();
	for (int i = 0; i < M; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		dist[x][y] = min(dist[x][y], w);
	}
	shortest_path(N);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] == INF) {
				cout << 0 << " ";
			}
			else
				cout << dist[i][j] << " ";
		}
		cout << "\n";
	}
}