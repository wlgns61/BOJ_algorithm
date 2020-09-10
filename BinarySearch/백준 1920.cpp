#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int *arr;

int search(int num, int n) {
	int start = 0;
	int index = 0;
	int end = n - 1;
	while (end - start >= 0) {
		index = (start + end) / 2;
		if (arr[index] == num) {
			return 1;
		}
		else if (arr[index] < num) {
			start = index + 1;
		}
		else if (arr[index] > num) {
			end = index - 1;
		}
	}
	return 0;
}

int main() {
	int N;
	scanf("%d", &N);
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	int M = N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int num;
		scanf("%d", &num);
		printf("%d\n", search(num, M));
	}
}