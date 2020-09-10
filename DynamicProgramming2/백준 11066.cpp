#include <iostream>
#include <algorithm>

using namespace std;

int **dp;
int *arr;
int *sum;

void init(int K) {
	arr = new int[K + 1];
	sum = new int[K + 1];
	dp = new int*[K + 1];

	arr[0] = 0;
	sum[0] = 0;
	dp[0] = new int[K + 1];

	for (int i = 1; i <= K; i++) {
		cin >> arr[i];
		dp[i] = new int[K+1];
		sum[i] = sum[i - 1] + arr[i];
	}
	for (int i = 0; i <= K; i++) {
		for (int j = 0; j <= K; j++) {
			dp[i][j] = 2000000000;
		}
	}
	
}

int solve(int start, int end) {
	if (dp[start][end] != 2000000000) {
		return dp[start][end];
	}
	if (start == end) {
		dp[start][end] = 0;
		return dp[start][end];
	}
	if (end == start + 1) {
		dp[start][end] = arr[start] + arr[end];
		return dp[start][end];
	}
	for (int i = start; i < end; i++) {
		int left = solve(start, i);
		int right = solve(i + 1, end);
		dp[start][end] = min(dp[start][end], left + right);
	}
	return dp[start][end] += (sum[end] - sum[start - 1]);
}

void print(int K) {
	for (int i = 1; i <= K; i++) {
		for (int j = 1; j <= K; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int T, K;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> K;
		init(K);
		cout << solve(1, K) << "\n";
		//print(K);
	}
}