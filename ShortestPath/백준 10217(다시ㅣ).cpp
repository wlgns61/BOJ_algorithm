#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 0xFFFFFFF

using namespace std;

struct info {
	int dest;
	int cost;
	int time;
};
typedef struct info info;

struct compare {
	bool operator()(info &a, info &b) {
		return a.cost > b.cost;
	}
};

vector <info> graph[101];
int timedelay[101][10001];

void shortest_path(const int& N, const int& MAX_COST) {
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= MAX_COST; j++) {
			timedelay[i][j] = INF;
		}
	}
	priority_queue <info, vector<info>, compare> pq;
	pq.push({ 1,0,0 }); //dest, cost, time
	timedelay[1][0] = 0;
	while (!pq.empty()) {
		int current = pq.top().dest;
		int money = pq.top().cost;
		int time = pq.top().time;
		pq.pop();
		if (time > timedelay[current][money])
			continue;
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].dest;
			int nexttime = time + graph[current][i].time;
			int nextcost = money + graph[current][i].cost;
			if (nextcost > MAX_COST)
				continue;
			if (timedelay[next][nextcost] > nexttime) {
				for (int j = nextcost; j <= MAX_COST; j++) {
					if (timedelay[next][j] > nexttime) {
						timedelay[next][j] = nexttime;
					}
				}
				pq.push({ next, nextcost, nexttime });
			}
		}
	}
	int ret = INF;
	for (int i = 1; i <= MAX_COST; i++) {
		ret = min(ret, timedelay[N][i]);
	}
	if (ret == INF) {
		cout << "Poor KCM\n";
	}
	else {
		cout << ret << "\n";
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
		//graph_clear();
		cin >> N >> M >> K;
		for (int j = 1; j <= N; j++) {
			while (!graph[j].empty()) {
				graph[j].pop_back();
			}
		}
		for (int j = 0; j < K; j++) {
			int x, y, cost, time;
			cin >> x >> y >> cost >> time;
			graph[x].push_back({ y, cost, time} ); //x에서 y로 요금 시간
		}
		shortest_path(N,M);
	}
}