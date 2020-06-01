#include <iostream>
#include <vector>
#include <algorithm>
/*
담은 경우는 D[i-1][j-w[i]] + v[i]이다.  ( w[i]는 i의 무게, v[i]는 i의 가치)

담지 않은 경우는 D[i-1][j]
*/

using namespace std;

int **dp;
vector<pair<int, int>> inp;

void init(int N, int K) {

	dp = new int*[N+1];
	inp.push_back(make_pair(0, 0));
	for (int i = 0; i < N; i++) {
		int w, v;
		cin >> w >> v;
		inp.push_back(make_pair(w, v));
		dp[i] = new int[K+1];
	}
	dp[N] = new int[K + 1];
	for (int i = 0; i < N+1; i++) {
		for (int j = 0; j < K+1; j++) {
			dp[i][j] = 0;
		}
	}
	sort(inp.begin(), inp.end());
	
}

void find_max(int N, int K) {
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			dp[i][j] = dp[i - 1][j]; //현재 항목을 담지 않았음
			if (j - inp[i].first >= 0) { // 현재 항목을 담을 수 있을 때
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - inp[i].first] + inp[i].second);
			}
		}
	}
}

int main() {

	int N, K;
	cin >> N >> K;
	init(N, K);
	find_max(N, K);
	cout << dp[N][K];
}