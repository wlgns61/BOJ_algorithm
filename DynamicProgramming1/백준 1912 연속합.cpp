#include <iostream>
#include <algorithm>

using namespace std;

int *arr;
int *dp;

int continuous_sum(int N) {
	int _max = dp[0] = arr[0];
	for (int i = 1; i < N; i++) {
		if (dp[i - 1] < 0) {
			dp[i] = arr[i];
		}
		else {
			dp[i] = dp[i - 1] + arr[i];
		}
		_max = max(_max, dp[i]);
	}
	return _max;
}

int main() {
	int N;
	cin >> N;
	arr = new int[N];
	dp = new int[N];
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[i] = num;
		dp[i] = 0;
	}
	cout << continuous_sum(N);

}