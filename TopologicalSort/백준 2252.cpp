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
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		indegree[b]++;
		v[a].push_back(b); //a -> b
	}

	queue <int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front(); 
		q.pop();
		printf("%d ", now);
		for (int i = 0; i < v[now].size(); i++) {
			if (--indegree[v[now][i]] == 0) {
				q.push(v[now][i]);
			}
		}
	}
}