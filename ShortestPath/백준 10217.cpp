#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 0xFFFFFFF

using namespace std;

vector <pair<int, pair<int, int>>> graph[101];
int timedelay[101][10001]; //[도착지, 돈] = 시간

void shortest_path(const int& V, const int &M) {

	for (int i = 0; i <= V; i++) {
		for (int j = 0; j <= M; j++) {
			timedelay[i][j] = INF;
		}
	}

	timedelay[1][0] = 0;
	priority_queue <pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	pq.push({ 0, {0,1} }); // 비용, 시간, neighbor;
	while (!pq.empty()) {
		int money = pq.top().first; // 돈
		int currentV = pq.top().second.second; //현위치
		int time = pq.top().second.first; //시간
		pq.pop();
		if (time > timedelay[currentV][money])
			continue;
		for (int i = 0; i < graph[currentV].size(); i++) {
			int neighbor = graph[currentV][i].first;
			int neighborTime = time + graph[currentV][i].second.second;
			int neighborMoney = money + graph[currentV][i].second.first;
			if (neighborMoney > M)
				continue;
			if (timedelay[neighbor][neighborMoney] > neighborTime) {
				for (int k = neighborMoney; k <= M; k++) {
					if (timedelay[neighbor][k] > neighborTime ) {
						timedelay[neighbor][k] = neighborTime;
					}
				}
				pq.push({ neighborMoney, {neighborTime, neighbor} });
			}
		}
	}
	int result = INF;
	for (int i = 1; i <= M; i++) {
		result = min(timedelay[V][i], result);
	}
	if (result == INF) {
		cout << "poor KCM\n";
	}
	else {
		cout << result << "\n";
	}
}

void graph_clear() {
	for (int i = 0; i < 101; i++) {
		graph[i].clear();
	}
}

int main() {
	int T, N, M, K; //공항, 돈, 경로
	cin >> T;
	for (int i = 0; i < T; i++) {
		graph_clear();
		cin >> N >> M >> K;
		for (int j = 0; j < K; j++) {
			int x, y, cost, time;
			cin >> x >> y >> cost >> time;
			graph[x].push_back({ y,{cost, time} }); //x에서 y로 요금 시간
		}
		shortest_path(N, M);
	}
}