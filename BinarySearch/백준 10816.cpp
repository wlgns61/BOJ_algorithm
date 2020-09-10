#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

int *arr;
vector <pair<int, int>> v;

int solve(int num, int N) {
	int cnt = 0;
	int start = 0;
	int end = N - 1;
	int mid;
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (num > v[mid].first) {
			start = mid + 1;
		}
		else if (num < v[mid].first) {
			end = mid - 1;
		}
		else if (num == v[mid].first) {
			cnt+=v[mid].second;
			return cnt;
		}
	}
	return cnt;
}

int main() {
	int N;
	scanf("%d", &N);
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + N);
	int j = 0;
	v.push_back({ arr[0],1 });
	for (int i = 1; i < N; i++) {
		if (arr[i] == v[j].first) {
			v[j].second++;
		}
		else {
			v.push_back({arr[i],1});
			j++;
		}
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		int num;
		scanf("%d", &num);
		printf("%d ", solve(num, v.size()));
	}
	
}