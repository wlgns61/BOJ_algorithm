#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int longest_path(vector <pair<int, int>> v[1002], int start) {
	vector <int> distance(1002, -1);
	priority_queue <pair<int, int>> pq; //cost, now
	distance[0] = 0;
	pq.push({ 0, start });
	while (!pq.empty()) {

		int cost = pq.top().first;
		int now = pq.top().second;
		pq.pop();

		if (distance[now] > cost)
			continue;

		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextcost = v[now][i].second + cost;
			if (distance[next] < nextcost) {
				distance[next] = nextcost;
				pq.push({ nextcost, next });
			}
		}
	}
	return distance[1001];
}

int main() {
	int t;
	scanf("%d", &t);
	while (--t >= 0) {
		int N, K;
		scanf("%d %d", &N, &K);

		vector <pair<int, int>> from_to[1002];
		int building[1002] = { 0 };
		int indegree[1002] = { 0 };

		for (int i = 1; i <= N; i++) 
			scanf("%d", &building[i]);
		for (int i = 1; i <= K; i++) {
			int from, to;
			scanf("%d %d", &from, &to);
			from_to[from].push_back({ to, building[from]});
			indegree[to]++;
		}
		int last;
		scanf("%d", &last);
		from_to[last].push_back({ 1001, building[last] });
		//루프의 입력 완료
		queue <int> q;
		for (int i = 1; i <= N; i++) {
			if (indegree[i] == 0)
				q.push(i);
		}
		
		while (!q.empty()) {
			int to = q.front();
			from_to[0].push_back({ to,0 });
			q.pop();
		}
		printf("%d\n", longest_path(from_to, 0));
	}
}