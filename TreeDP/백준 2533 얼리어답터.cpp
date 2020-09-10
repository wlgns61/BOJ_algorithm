#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#define MIL 1000000

using namespace std;

vector <int> adj[MIL + 1];
vector <int> tree[MIL + 1];
int dp[MIL + 1][2];

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
	if (res != -1) return res; //중복되는 경우 
	if (!include) { //내가 얼리어답터가 아니라면
		int ans = 0;
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			ans += solve(next, 1);
		}
		return res = ans;
	} 
	else { //내가 얼리어답터라면
		int ans = 1;
		for (int i = 0; i < tree[now].size(); i++) {
			int next = tree[now][i];
			ans += min(solve(next, 1), solve(next, 0));
		}
		return res = ans;
	}

}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
		dp[i][0] = dp[i][1] = -1;
	}
	dp[n][0] = dp[n][1] = -1;

	dfs(1, 1);
	int result = min(solve(1, 1), solve(1, 0));
	cout << result;
}