#include <iostream>

using namespace std;

int *coins;
int *dp;

void init(int n, int k) {
	coins = new int[n + 1];
	dp = new int[k + 1];
	coins[0] = 0;
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> coins[i];
	}
	for (int i = 1; i <= k; i++) {
		dp[i] = 0;
	}
}

int main() {
	int n, k;
	cin >> n >> k;
	init(n, k);
	for (int i = 1; i <= n; i++) { //coin
		for (int j = 1; j <= k; j++) { //dp
			if (j - coins[i] >= 0) {
				dp[j] = dp[j] + dp[j - coins[i]];
			}
		}
	}
	cout << dp[k];
}