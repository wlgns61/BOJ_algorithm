#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int *memory;
int	*cost;
int **dp;
int cost_sum = 0;

void init() {
	memory = new int[N];
	cost = new int[N];

	for (int i = 0; i < N; i++) {
		cin >> memory[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> cost[i];
		cost_sum += cost[i];
	}
	dp = new int*[N];
	for (int i = 0; i < N; i++) {
		dp[i] = new int[cost_sum + 1];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= cost_sum; j++) {
			dp[i][j] = 0;
		}
	}
}

int min_cost() {
	int _min = cost_sum + 1;
	for (int j = 0; j <= cost_sum; j++) {
		if (j >= cost[0])
			dp[0][j] = memory[0];
		if (dp[0][j] >= M) {
			_min = min(_min, j);
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j <= cost_sum; j++) {
			if (j - cost[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], memory[i] + dp[i - 1][j - cost[i]]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			if (dp[i][j] >= M) {
				_min = min(_min, j);
			}
		}
	}
	return _min;
}

int main() {
	cin >> N >> M;
	init();
	cout << min_cost();
}