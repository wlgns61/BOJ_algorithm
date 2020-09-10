#include <stdio.h>
#include <iostream>
#include <limits.h>
#include <algorithm>
#define INF 0xFFFFFFF
using namespace std;

int n, all;
int cost[16][16];
int dp[16][1 << 16];

int func(int cur, int visited) {

	if (visited == all) {
		if (cost[cur][0] != 0)
			return cost[cur][0];
		else
			return INF;
	}
	if (dp[cur][visited] != 0) { //�ݺ� ���� �ʰ���
		return dp[cur][visited];
	}

	int m = INF;
	for (int i = 1; i < n; i++) {
		if (((visited & (1 << i)) == 0) && (cost[cur][i] != 0)) {
			m = min(m, func(i, (visited|(1 << i))) + cost[cur][i]);
		}
	}
	dp[cur][visited] = m;
	return m;
}

int main() {

	scanf("%d", &n);
	all = (1 << n) - 1;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", &cost[i][j]);

	printf("%d", func(0, 1));
	return 0;
}
