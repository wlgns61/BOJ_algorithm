#include <iostream>
#include <algorithm>

using namespace std;
int map[1001][1001];
int dp[1001][1001];

int main() {
	
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = max(dp[i][j], max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i][j - 1])) + map[i][j]);
		}
	}
	cout << dp[n][m];
}