#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int **dp;
vector <pair<int, int>> v;

void init(int N) {
	v.clear();
	dp = new int*[N];
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
		dp[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = 0x3f3f3f3f;
		}
	}
}

int solve(int tx, int ty) {
	if (dp[tx][ty] != 0x3f3f3f3f) {
		return dp[tx][ty];
	}
	if (tx + 1 == ty) {
		dp[tx][ty] = v[tx].first * v[tx].second * v[ty].second;
		return dp[tx][ty];
	}
	if (tx == ty) {
		dp[tx][ty] = 0;
		return dp[tx][ty];
	}
	for (int i = tx; i < ty; i++) {
		int left = solve(tx, i);
		int right = solve(i + 1, ty);
		dp[tx][ty] = min(dp[tx][ty], left + right + (v[tx].first * v[i].second * v[ty].second));
	}
	return dp[tx][ty];
}

void print(int K) {
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < K; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int N;
	cin >> N;
	init(N);
	cout << solve(0, N - 1) << "\n";
	//print(N);
}
