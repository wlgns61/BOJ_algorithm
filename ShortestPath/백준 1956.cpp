#include <iostream>
#include <algorithm>
#define INF 0xFFFFFFF

using namespace std;

int graph[401][401];

void init_graph(int N) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			graph[i][j] = INF;
		}
	}
}

int Floyd(int N) {
	int result = INF;
	for (int via = 1; via <= N; via++) {
		for (int from = 1; from <= N; from++) {
			for (int to = 1; to <= N; to++) {
				if (graph[from][to] > graph[from][via] + graph[via][to]) {
					graph[from][to] = graph[from][via] + graph[via][to];
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		result = min(result, graph[i][i]);
	}
	if (result == INF) return -1;
	return result;
}

int main() {
	int V, E;
	cin >> V >> E;
	init_graph(V);
	for (int i = 0; i < E; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		graph[x][y] = w;
	}
	cout << Floyd(V);

	
}