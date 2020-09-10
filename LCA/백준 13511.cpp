#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define SIZE 100000
#define MILL 1000001

using namespace std;

typedef struct info {
	int ancestor;
	long long cost;
};

vector <pair<int, int>> v[SIZE + 2];
int depth[SIZE + 2];
info dp[SIZE + 2][18];

void dfs(int now, int parent, int dep) {

	depth[now] = dep;
	for (int i = 0; i < v[now].size(); i++) {
		int next = v[now][i].first;
		long long cost = v[now][i].second;
		if (next == parent)
			continue;
		dp[next][0].ancestor = now;
		dp[next][0].cost = cost;
		dfs(next, now, dep + 1);
	}
}

void make_dp(int n) {

	for (int j = 1; j <= 17; j++) {
		for (int i = 1; i <= n; i++) {
			info a = dp[i][j - 1];
			dp[i][j].ancestor = dp[a.ancestor][j - 1].ancestor;
			dp[i][j].cost = dp[i][j - 1].cost + dp[a.ancestor][j - 1].cost;
		}
	}
}

int LCA(int a, int b, bool flag) {

	long long a_sum = 0;
	long long b_sum = 0;

	if (depth[a] != depth[b]) {
		if (depth[a] < depth[b]) {
			swap(a, b);
		}
		for (int i = 17; i >= 0; i--) {
			if (depth[a] - depth[b] >= (1 << i)) {
				a_sum = dp[a][i].cost;
				a = dp[a][i].ancestor;
			}
		}
	}

	if (a == b) {
		if(flag)
			printf("%d\n", a_sum);
		return a;
	}

	if (a != b) {
		for (int i = 17; i >= 0; i--) {
			if (dp[a][i].ancestor != dp[b][i].ancestor) {
				a_sum = dp[a][i].cost;
				b_sum = dp[b][i].cost;
				a = dp[a][i].ancestor;
				b = dp[b][i].ancestor;
			}
		}
	}
	if(flag)
		printf("%d\n", a_sum + b_sum);
	return dp[a][0].ancestor;
}

void find_vertex(int a, int b, int k) {
	int lca = LCA(a, b, 0);
	int da = depth[a]; int db = depth[b]; int dl = depth[lca];
	if (da - dl + 1 >= k) {
		k--;
		for (int i = 17; i >= 0; i--) {
			if ((1LL << i) <= k) {
				k -= (1 << i);
				a = dp[a][i].ancestor;
			}
		}
		printf("%d\n", a);
	}
	else {
		k = db - dl + 1 + da - dl - k;
		for (int i = 17; i >= 0; i--) {
			if ((1LL << i) <= k) {
				k -= (1 << i);
				b = dp[b][i].ancestor;
			}
		}
		printf("%d\n", b);
	}
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
	dfs(1, 0, 0);
	make_dp(N);
	scanf("%d", &K);
	for (int i = 0; i < K; i++) {
		int q, a, b, c;
		scanf("%d", &q);
		if (q == 1) {
			scanf("%d %d", &a, &b);
			LCA(a, b, 1);
		}
		else if(q == 2){
			scanf("%d %d %d", &a, &b, &c);
			find_vertex(a, b, c);
		}
	}
}