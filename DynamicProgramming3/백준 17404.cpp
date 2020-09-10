#include <iostream>
#include <stdio.h>
#include <algorithm>
#define INF 0xFFFFFFF
using namespace std;
int RGB[1001][3] = { 0, };

void RGB_solve(int N) {

	int result = INF;
	for (int rgb = 0; rgb < 3; rgb++) { //R����, G����, B���ۿ� ���� ����  
		int dp[1001][3] = { 0, };
		dp[0][rgb] = INF; //��������� ����ġ�� �������� �θ� �ش� ����������� �������� ����
		dp[0][(rgb + 1) % 3] = RGB[0][(rgb + 1) % 3];  
		dp[0][(rgb + 2) % 3] = RGB[0][(rgb + 2) % 3];

		for (int i = 1; i < N; i++) {
			dp[i][0] = RGB[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
			dp[i][1] = RGB[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
			dp[i][2] = RGB[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}
		result = min(result, dp[N - 1][rgb]);
	}
	cout << result;
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> RGB[i][j];
		}
	}
	RGB_solve(N);
}