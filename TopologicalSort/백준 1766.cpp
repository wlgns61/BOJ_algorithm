#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int indegree[32001];
vector <int> v[32001];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	while (--m >= 0) {
		int from, to;
		scanf("%d %d", &from, &to);
		v[from].push_back(to);
		indegree[to]++;
	}
	priority_queue <int, vector<int>, greater<int>> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int now = q.top();
		printf("%d ", now);
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			if (--indegree[next] == 0)
				q.push(next);
		}
	}

}