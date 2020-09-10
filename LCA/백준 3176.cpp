#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define SIZE 100000
#define MILL 1000001

using namespace std;

typedef struct info {
	int ancestor;
	int _max;
	int _min;
};

vector <pair<int, int>> v[SIZE + 2];
int depth[SIZE + 2];
info dp[SIZE + 2][18];

void dfs(int now, int parent, int dep) {

	depth[now] = dep;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i].first;
		int cost = v[now][i].second;
		if (next == parent) 
			continue;
		dp[next][0].ancestor = now;
		dp[next][0]._min = min(dp[next][0]._min, cost);
		dp[next][0]._max = max(dp[next][0]._max, cost);
		dfs(next, now, dep + 1);
	}
}

void make_dp(int n) {

	for (int j = 1; j <= 17; j++) {
		for (int i = 1; i <= n; i++) {
			info a = dp[i][j - 1];
			dp[i][j].ancestor = dp[a.ancestor][j - 1].ancestor;
			dp[i][j]._max = max(dp[a.ancestor][j - 1]._max, dp[i][j - 1]._max);
			dp[i][j]._min = min(dp[a.ancestor][j - 1]._min, dp[i][j - 1]._min);
		}
	}
}

void init_dp(int n) {

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 18; j++) {
			dp[i][j]._min = MILL;
		}
	}
}

void LCA(int a, int b) {

	int _max = 0; 
	if (depth[a] > depth[b]) {
		_max = dp[a][0]._max;
	}
	else {
		_max = dp[b][0]._max;
	}
	int _min = MILL;

	if (depth[a] != depth[b]) {
		if (depth[a] < depth[b]) {
			swap(a, b);
		}
		for (int i = 17; i >= 0; i--) {
			if (depth[a] - depth[b] >= (1 << i)) {
				_max = max(_max, dp[a][i]._max);
				_min = min(_min, dp[a][i]._min);
				a = dp[a][i].ancestor;
			}
		}
	}

	if (a == b) {
		printf("%d %d\n", _min, _max);
		return;
	}

	if (a != b) {
		for (int i = 17; i >= 0; i--) {
			if (dp[a][i].ancestor != dp[b][i].ancestor) {
				_max = max(_max, max(dp[a][i]._max, dp[b][i]._max));
				_min = min(_min, min(dp[a][i]._min, dp[b][i]._min));
				a = dp[a][i].ancestor;
				b = dp[b][i].ancestor;
			}
		}
	}
	_max = max(_max, max(dp[a][0]._max, dp[b][0]._max));
	_min = min(_min, min(dp[a][0]._min, dp[b][0]._min));
	printf("%d %d\n", _min, _max);
	return;
}

int main() {
	int N, K;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		scanf("%d %d %d", &a, &b, &cost);
		v[a].push_back({ b,cost });
		v[b].push_back({ a,cost });
	}
	init_dp(N);
	dfs(1, 0, 0);
	make_dp(N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		LCA(a, b);
	}
}