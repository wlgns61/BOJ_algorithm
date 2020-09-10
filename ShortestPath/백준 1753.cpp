#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>
#define INF 0xFFFFFFF

using namespace std;

vector <pair<int, int>> graph[20001];

vector <int> shortest_path(int start, int V) {
	vector <int> distance(V + 1, INF); // V의 크기, value는 INF로 초기와
	distance[start] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	//priority_queue <pair<int, int>> pq;
	pq.push(make_pair(0, start)); // cost, vertex
	while (!pq.empty()) {

		int cost = pq.top().first;
		int currentV = pq.top().second;
		pq.pop();
		//cout << currentV << " " << cost << "\n";
		if (distance[currentV] < cost)
			continue;
		for (int i = 0; i < graph[currentV].size(); i++) {

			int neighbor = graph[currentV][i].first;
			int neighborCost = cost + graph[currentV][i].second;
			if (neighborCost < distance[neighbor]) {
				distance[neighbor] = neighborCost;
				pq.push({ neighborCost , neighbor });
			}
		}
	}
	return distance;
}

int main() {
	int V, E, s;
	cin >> V >> E >> s;
	for (int i = 0; i < E; i++) {
		int start, end, w;
		cin >> start >> end >> w;
		graph[start].push_back({ end, w });
	}
	vector <int> result = shortest_path(s, V);
	for (int i = 1; i < result.size(); i++) {
		if (result[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << result[i] << "\n";
		}
	}
}

