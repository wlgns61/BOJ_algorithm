#include <iostream>
#include <algorithm>

using namespace std;

int *arr;
int *i_dp;
int *d_dp;

void push_dp(int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i]) {
				i_dp[i] = max(i_dp[i], i_dp[j] + 1);
			}
		}
		for (int j = N - 1; j >= N - 1 - i; j--) {
			if (arr[j] < arr[N - 1 - i]) {
				d_dp[N - 1 - i] = max(d_dp[N - 1 - i], d_dp[j] + 1);
			}
		}
	}
}

int find_max(int N) {
	push_dp(N);
	int _max = 1;
	for (int i = 0; i < N; i++) {
		_max = max((i_dp[i] + d_dp[i]), _max);
	}
	return _max - 1;
}

int main() {
	int N;
	cin >> N;
	arr = new int[N];
	i_dp = new int[N];
	d_dp = new int[N];
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr[i] = num;
		i_dp[i] = 1;
		d_dp[i] = 1;
	}
	cout << find_max(N);

}