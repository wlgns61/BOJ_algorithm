#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> line;
int *dp;

int cut_line(int N) {
	int _max = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (line[j].second < line[i].second) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		_max = max(_max, dp[i]);
	}
	return N - _max;
}

int main() {
	int N;
	cin >> N;
	dp = new int[N];
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		line.push_back(make_pair(x, y));
		dp[i] = 1;
	}
	sort(line.begin(), line.end());
	cout << cut_line(N);
}