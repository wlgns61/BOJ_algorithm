#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

long long *arr;

void solve(int N, int M, long long high) {
	long long low = 1;
	long long mid;
	long long result = 0;
	while (high >= low) {
		long long sum = 0;
		mid = (low + high) / 2;
		for (int i = 0; i < N; i++) {
			if (arr[i] > mid) {
				sum += (arr[i] - mid);
			}
		}
		if (M > sum) { // 더 조금 잘랐을때, 높이를 낮춰야 함
			high = mid - 1;
		}
		else if (M <= sum) { //더 많이 자르거나, 딱 맞춰 잘랐을 때
			if (result < mid) //더 높이가 높은 결과값이 들어왔을 때
				result = mid; 
			low = mid + 1;
		}
	}
	cout << result;
}

int main() {
	int N, M;
	long long high = 0;
	scanf("%d", &N);
	scanf("%d", &M);
	arr = new long long[N];
	for (int i = 0; i < N; i++) {
		scanf("%lli", &arr[i]);
		high = max(high, arr[i]);
	}
	solve(N, M , high);
}