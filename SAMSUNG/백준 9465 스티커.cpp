#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int arr[2][100000];
int dp[2][100000];

void find_max(int n) {
	dp[0][0] = arr[0][0];
	dp[1][0] = arr[1][0];
	dp[0][1] = dp[1][0] + arr[0][1];
	dp[1][1] = dp[0][0] + arr[1][1];
	for (int i = 2; i < n; i++) {
		dp[0][i] = max(arr[0][i] + dp[1][i - 2], max(dp[0][i], arr[0][i] + dp[1][i - 1]));
		dp[1][i] = max(arr[1][i] + dp[0][i - 2], max(dp[1][i], arr[1][i] + dp[0][i - 1]));
	}
	cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
}

void solve() {
	int n;
	cin >> n;
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	find_max(n);
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (--t >= 0) {
		solve();
	}
}