#include <iostream>
#include <algorithm>

using namespace std;

long long *arr;

void solve(int K, int N, long long high) {
	long long low = 1;
	long long mid;
	while (true) {
		long long sum = 0;
		mid = (low + high) / 2;
		for (int i = 0; i < K; i++) {
			sum += (arr[i] / mid);
		}
		if (sum >= N) {
			low = mid + 1;
			if (high - low < 0) {
				cout << mid;
				return;
			}
		}
		else if (sum < N) {
			high = mid - 1;
		}
	}
}

int main() {
	int K, N;
	long long high = 0;
	cin >> K >> N;
	arr = new long long[K];
	for (int i = 0; i < K; i++) {
		cin >> arr[i];
		high = max(high, arr[i]);
	}
	solve(K, N, high);
}