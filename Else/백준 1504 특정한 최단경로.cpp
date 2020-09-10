#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0xFFFFFFF

using namespace std;
int n, e;

vector<pair<int, int>> map[801];

struct comp {
	bool operator() (pair<int, int> a, pair<int, int> b){
		if (a.second > b.second)
			return true;
		return false;
	}
};

int shortestPath(int start, int end) {

	priority_queue <pair<int, int>, vector<pair<int, int>>, comp> pq;
	vector<int> distance(n+1, INF);

	pq.push({ start, 0 });
	distance[start] = 0;

	while (!pq.empty()) {

		int now = pq.top().first;
		pq.pop();

		for (int i = 0; i < map[now].size(); i++) {
			int next_node = map[now][i].first;
			int next_cost = map[now][i].second;
			if (distance[next_node] > distance[now] + next_cost) {
				distance[next_node] = distance[now] + next_cost;
				pq.push({ next_node, distance[next_node] });
			}
		}
	}
	return distance[end];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int start, end;

	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		map[from].push_back({ to, cost });
		map[to].push_back({ from, cost });
	}

	cin >> start >> end;
	
	int ret1 = shortestPath(1, start) + shortestPath(start, end) + shortestPath(end, n);
	int ret2 = shortestPath(1, end) + shortestPath(end, start) + shortestPath(start, n);

	int result = min(ret1, ret2);

	if (result >= INF)
		cout << "-1";
	else
		cout << result;
	
}