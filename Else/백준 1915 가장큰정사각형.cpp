#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int map[1002][1002];
pair<int, int> checkdir[3] = { {-1,0}, {0,-1}, {-1,-1} };
int n, m;

int solve() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j= 1; j <= m; j++) {
			if (map[i][j] != 0) {
				map[i][j] = min(map[i][j - 1], min(map[i - 1][j], map[i - 1][j - 1])) + 1;
				ans = max(ans, map[i][j]);
			}
		}
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++) {
			int inp;
			scanf("%1d", &inp);
			map[i][j] = inp;
		}
	}		

	int ans = solve();
	cout << ans * ans;
}