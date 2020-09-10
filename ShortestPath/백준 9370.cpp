#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define INF 0xFFFFFFF

using namespace std;

vector <pair<int, int>> graph[2001];
vector <int> candidate;

vector <int> shortest_path(int start, int V) {

	vector <int> distance(V+1, INF);
	distance[start] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({ 0, start }); // cost, vertex

	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (cost > distance[cur]) 
			continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			int neighbor = graph[cur][i].first;
			int neighborCost = cost + graph[cur][i].second;
			if (neighborCost < distance[neighbor]) {
				distance[neighbor] = neighborCost;
				pq.push({ neighborCost , neighbor });
			}
		}
		
	}
	return distance;
}

void graph_clear() {
	for (int i = 0; i < 2001; i++) {
		graph[i].clear();
	}
}

int main() {
	int T, n, m, t, s, g, h, a, b, d;
	cin >> T;
	for (int i = 0; i < T; i++) {
		candidate.clear();
		graph_clear();

		cin >> n >> m >> t; // vertex, edge, candidate count
		cin >> s >> g >> h; // start, stop1, stop2

		for (int j = 0; j < m; j++) {
			cin >> a >> b >> d; 
			if ((a == g && b == h) || (a == h && b == g)) {
				graph[a].push_back({ b, d * 2 - 1 });
				graph[b].push_back({ a, d * 2 - 1 });
			}
			else {
				graph[a].push_back({ b,d * 2 });
				graph[b].push_back({ a,d * 2 });
			}
		}

		for (int j = 0; j < t; j++) {
			int cndi;
			cin >> cndi;
			candidate.push_back(cndi);
		}
		sort(candidate.begin(), candidate.end());
		vector <int> result = shortest_path(s, n);
		for (int j = 0; j < candidate.size(); j++) {
			if (result[candidate[j]] == INF)
				continue;
			else if (result[candidate[j]] % 2 == 1) {
				cout << candidate[j] << " ";
			}
		}
		cout << "\n";
	}
}