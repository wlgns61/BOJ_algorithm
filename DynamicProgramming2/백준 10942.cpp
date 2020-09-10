#include <iostream>
#include <stdio.h>

using namespace std;

bool **dp;
int *arr;

void init(int N) {
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}
	dp = new bool*[N];
	for (int i = 0; i < N; i++) {
		dp[i] = new bool[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = false;
		}
	}
}

void make_dp(int N) {

	for (int i = 0; i < N; i++) {
		dp[i][i] = true;
		if (i >= 1) {
			if (arr[i - 1] == arr[i]) 
				dp[i - 1][i] = true;
		}
	}

	for (int i = 2; i < N; i++) { //i는 길이를 나타냄 즉 길이 2부터 N까지
		for (int j = 0; j <= N - i; j++) { //j는 시작 지점, j + i는 끝 지점.
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1] == true) {
				//cout << "S: " << arr[j] << " E: " << arr[j + i] << "\n\n\n";
				dp[j][j + i] = true;
			}
		}
	}
}

int main() {
	int N, M;
	cin >> N;
	init(N);
	make_dp(N);
	cin >> M;
	for (int i = 0; i < M; i++) {
		int S, E;
		scanf("%d %d", &S, &E);
		printf("%d\n", dp[S - 1][E - 1]);
	}
}