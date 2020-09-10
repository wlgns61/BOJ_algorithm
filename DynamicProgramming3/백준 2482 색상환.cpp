#include <iostream>
#define MAX 1001
#define MOD 1000000003

using namespace std;

long long dp[MAX][MAX] = {0};

long long solve(int N, int K) {
	
	for (int i = 1; i <= 3; i++) {
		dp[i][1] = i;
	}
	
	for (int now = 4; now <= N; now++) {
		int max_cnt = now / 2;
		for (int cnt = 1; cnt <= max_cnt; cnt++) {
			if (cnt == 1) {
				dp[now][cnt] = now;
			}
			else
				dp[now][cnt] = (dp[now - 2][cnt - 1] + dp[now - 1][cnt]) % MOD;
		}
	}
	return dp[N][K];
}

int main() {
	int N, K;
	//cin >> N >> K;
	//cout << solve(N, K);
}