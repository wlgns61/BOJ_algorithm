#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int buildtime[1001];
int dp[1001];
int indegree[1001];
vector<int> map[1001];
int t, n, k, dest;

void init() {

	memset(buildtime, 0, sizeof(buildtime));
	memset(dp, 0, sizeof(dp));
	memset(indegree, 0, sizeof(indegree));
	for (int i = 0; i <= n; i++) {
		map[i].clear();
	}

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> buildtime[i];
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		map[a].push_back(b);
		indegree[b]++;
	}
	cin >> dest;
}

int solve(int dest) {

	int result = 0;

	queue <int> q;
	for (int i = 1; i <= n; i++) 
		if (indegree[i] == 0) {
			q.push(i);
			dp[i] = buildtime[i];
		}

	while (!q.empty()) {
		
		int now = q.front();
		q.pop();

		if (now == dest) {
			result = dp[now];
			break;
		}

		for (int i = 0; i < map[now].size(); i++) {
			int next = map[now][i];
			if (--indegree[next] == 0) {
				q.push(next);
			}
			dp[next] = max(dp[next], dp[now] + buildtime[next]);
		}
	}

	return result;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> t;

	while (--t >= 0) {
		init();
		cout << solve(dest) << "\n";
	}
}