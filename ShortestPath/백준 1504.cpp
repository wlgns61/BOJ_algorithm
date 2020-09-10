#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#define INF 0xFFFFFFF

using namespace std;

vector <pair<int, int>> graph[801];

int shortest_path(int start, int end, int V) {
	vector <int> distance(V + 1, INF);
	distance[start] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start }); // cost, neighbor;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int currentV = pq.top().second;
		pq.pop();
		if (cost > distance[currentV])
			continue;
		for (int i = 0; i < graph[currentV].size(); i++) {
			int neighbor = graph[currentV][i].first;
			int neighborCost = cost + graph[currentV][i].second;
			if (neighborCost < distance[neighbor]) {
				distance[neighbor] = neighborCost;
				pq.push({ neighborCost, neighbor });
			}
		}
	}
	return distance[end];
}

int main() {
	int V, E;
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int sour, dest, w;
		cin >> sour >> dest >> w;
		graph[sour].push_back({ dest,w });
		graph[dest].push_back({ sour,w });
	}
	int stop1, stop2;
	cin >> stop1 >> stop2;

	int path1 = shortest_path(1, stop1, V);
	int path2 = shortest_path(stop1, stop2, V);
	int path3 = shortest_path(stop2, V, V);

	int path4 = shortest_path(1, stop2, V);
	int path5 = shortest_path(stop2, stop1, V);
	int path6 = shortest_path(stop1, V, V);

	if ((path1 == INF || path2 == INF || path3 == INF) && (path4 == INF || path5 == INF || path6 == INF)) {
		cout << -1;
	}
	else {
		cout << min(path1 + path2 + path3, path4 + path5 + path6);
	}
}