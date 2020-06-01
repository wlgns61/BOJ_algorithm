#include <iostream>
#include <algorithm>

using namespace std;

int *arr;
int *dp;

int LIS(int N) {
	int result = 1;
	if (N == 1) return 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				dp[i] = max(dp[i], dp[j]+1);
				if (dp[i] > result) result = dp[i];
			}
		}
	}
	return result;
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
		dp[i] = 1;
	}
	cout << LIS(N);
}