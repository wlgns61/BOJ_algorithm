#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector <int> adj[100002];
int dp[100002][21];
int depth[100002];

void dfs(int now, int parent, int dep) {
	depth[now] = dep;
	for (int i = 0; i < adj[now].size(); i++) {
		int next = adj[now][i];
		if (next == parent)
			continue;
		dp[next][0] = now;
		dfs(next, now, dep + 1);
	}
}

void init_dp(int n) {
	for (int j = 1; j < 21; j++) {
		for (int i = 1; i <= n; i++) {
			int ancestor = dp[i][j - 1];
			dp[i][j] = dp[ancestor][j - 1];
		}
	}
}

int LCS(int a, int b) {
	if (depth[a] != depth[b]) {
		if (depth[a] < depth[b]) {
			swap(a, b);
		}
		for (int i = 20; i >= 0; i--) {
			if (depth[a] - depth[b] >= (1 << i)) {
				a = dp[a][i]; //³·ÀºÂÊÀ» ¿Ã·ÁÁÜ
			}
		}
	}
	if (a == b)
		return a;
	
	if (a != b) {
		for (int i = 20; i >= 0; i--) {
			if (dp[a][i] != dp[b][i]) {
				a = dp[a][i];
				b = dp[b][i];
			}
		}
	}
	return dp[a][0];
}

int main() {
	int N, M;
	scanf("%d", &N);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 0, 0);
	init_dp(N);
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", LCS(a, b));
	}

}