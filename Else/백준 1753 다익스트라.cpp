#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0xFFFFFFF

using namespace std;

vector <pair<int, int>> map[20001];
int v, e, start;


struct comp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second > b.second)
			return true;
		return false;
	}
};

void shortestPath() {
	
	priority_queue < pair<int, int>, vector<pair<int, int>>, comp> pq; //가장 작은 수가 top -> 큰 수의 갱신은 잦은 갱신이 요구됨

	vector<int> distance(20001, INF);

	pq.push({start, 0});
	distance[start] = 0;

	while (!pq.empty()) {
		
		int now = pq.top().first;
		int cost = pq.top().second;
		pq.pop();

		for (int i = 0; i < map[now].size(); i++) {
			int next_node = map[now][i].first;
			int next_cost = map[now][i].second;
			if (distance[next_node] > cost + next_cost) { //if (distance[next_node] > distance[now] + next_cost) 와 동일함
				distance[next_node] = cost + next_cost;
				pq.push({ next_node, distance[next_node]});
			}
		}
	}

	for (int i = 1; i <= v; i++) {
		if (distance[i] == INF) 
			cout << "INF\n";
		else
			cout << distance[i] << "\n";
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> e >> start;

	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		map[from].push_back({ to, cost });
	}
	shortestPath();
}