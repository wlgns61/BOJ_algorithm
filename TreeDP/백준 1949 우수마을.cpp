#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#define MAX 10000

using namespace std;

vector <int> adj[MAX + 1];
vector <int> tree[MAX + 1];
int dp[MAX + 1][2];
int cost[MAX + 1];

void dfs(int now, int parent) {
	for (int i = 0; i < adj[now].size(); i++) {
		int there = adj[now][i];
		if (parent != there) {
			tree[now].push_back(there);
			dfs(there, now);
		}
	}
}

int solve(int now, int include) {
	int &res = dp[now][include];
	if (res != -1) 
		return res;
	if (include) { //우수 마을이라면
		int ans = 0;
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			ans += solve(next, 0);
		}
		return res = ans + cost[now];
	}
	else {
		int ans = 0;
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			int t1 = solve(next, 1);
			int t2 = solve(next, 0);
			ans += max(t1, t2);
		}
		return res = ans;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &cost[i]);
		dp[i][0] = dp[i][1] = -1;
	}
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1, 1);
	int result = max(solve(1, 1), solve(1, 0));
	cout << result;
}