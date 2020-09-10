#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <vector>
#include <stack>
#define INF 0xFFFFFFF

using namespace std;

vector <pair<int, int>> v[1001];
int N, K;

void shortest_path(int start, int V, int end){

	vector <pair<int, int>> backtrack(V + 1); //cost, past
	for (int i = 0; i <= V; i++) {
		backtrack[i].first = INF;
		backtrack[i].second = 0;
	}
	backtrack[start].first = 0;
	backtrack[start].second = start;
	priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //next, cost
	pq.push({ start, 0 });

	while (!pq.empty()) {
		int now = pq.top().first;
		int cost = pq.top().second;
		pq.pop();
		if (backtrack[now].first < cost)
			continue;
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i].first;
			int nextCost = cost + v[now][i].second;
			if (backtrack[next].first > nextCost) {
				backtrack[next].first = nextCost;
				backtrack[next].second = now;
				pq.push({ next, nextCost });
			}
		}
	}
	
	cout << backtrack[end].first << "\n";
	stack <int> st;
	int past = end;
	st.push(past);
	while (past != start) {
		past = backtrack[past].second;
		st.push(past);
	}
	cout << st.size() << "\n";
	while (!st.empty()) {
		cout << st.top() << " ";
		st.pop();
	}
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back({ y, w });
	}
	int start, end;
	cin >> start >> end;
	shortest_path(start, N, end);
	
}