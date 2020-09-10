#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
int n, m;
int map[501][501];
int dp[501][501];
pair<int, int> direction[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };

int solve(int x, int y) {
	int &ret = dp[x][y];
	cout << map[x][y] << " ";
	if (ret != -1)
		return ret;
	if (x == n && y == m)
		return ret = 1;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int next_x = x + direction[i].first;
		int next_y = y + direction[i].second;
		if (1 <= next_x && next_x <= n && 1 <= next_y && next_y <= m) {
			if (map[next_x][next_y] < map[x][y]) {
				ret += solve(next_x, next_y);
			}
		}
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	memset(dp, -1, sizeof(dp));
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	cout << solve(1, 1);
}