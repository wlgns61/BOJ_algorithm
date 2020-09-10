#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

vector <vector<int>> v(100001);
int dp[100001];
int visited[100001];

int dfs(int start) {
	visited[start] = 1;
	for (int i = 0; i < v[start].size(); i++) {
		int now = v[start][i];
		if (visited[now] == 0) 
			dp[start] += dfs(now);
	}
	return dp[start] += 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, R, Q;
	cin >> N >> R >> Q;
	for (int i = 1; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(R);
	for (int i = 0; i < Q; i++) {
		int root;
		cin >> root;
		cout << dp[root] <<"\n";
	}
}