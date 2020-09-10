#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0xFFFFFFF

using namespace std;

vector <pair<int, int>> graph[502];
int dist[502] = { INF, };

int main() {
	int N, M;
	cin >> N >> M;
	bool updated = false;
	for (int i = 0; i < 502; i++) {
		dist[i] = INF;
	}
	for (int i = 0; i < M; i++) {
		int s, e, w;
		cin >> s >> e >> w;
		graph[s].push_back({ e,w });
	}
	dist[1] = 0;
	for (int i = 1; i <= N; i++) { //N-1번 탐색
		updated = false;
		for (int from = 1; from <= N; from++) {
			if (dist[from] == INF) {
				continue;
			}
			for (int j = 0; j < graph[from].size(); j++) {
				int to = graph[from][j].first; //i와 연결된 지점
				int cost = graph[from][j].second;
				if (dist[to] > dist[from] + cost) {
					dist[to] = dist[from] + cost;
					updated = true;
				}
			}
		}
		if (i == N) {
			if (updated == true) {
				cout << -1 << "\n";
				return 0;
			}
		}
	}
	for (int j = 2; j <= N; j++) {
		if (dist[j] == INF)
			cout << -1 << "\n";
		else {
			cout << dist[j] << "\n";
		}
	}
	
}