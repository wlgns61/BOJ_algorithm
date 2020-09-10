#include <iostream>
#include <cmath>
#define MAX 505050

using namespace std;

long long dp[MAX][22];

long long solve(int loop, int start) {
	int n = loop;
	for (int i = 0; i <= ((int)log2(MAX)); i++) {
		if (loop & (1 << i)) {
			start = dp[start][i];
		}
	}
	return start;
}

int main() {
	int m, q, n, x;
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d", &dp[i][0]);
	}
	for (int j = 1; j < 22; j++) {
		for (int i = 1; i <= m; i++) {
			long long result = dp[i][j - 1];
			dp[i][j] = dp[result][j - 1];
		}
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		int loop, start;
		scanf("%d %d", &loop, &start);
		printf("%d\n", solve(loop, start));
	}
}