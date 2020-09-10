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
		if (M > sum) { // �� ���� �߶�����, ���̸� ����� ��
			high = mid - 1;
		}
		else if (M <= sum) { //�� ���� �ڸ��ų�, �� ���� �߶��� ��
			if (result < mid) //�� ���̰� ���� ������� ������ ��
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