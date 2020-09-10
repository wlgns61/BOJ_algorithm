#include <iostream>

using namespace std;

int **dp;
int **map;

void init(int N, int M) {
	dp = new int*[N];
	map = new int*[N];
	for (int i = 0; i < N; i++) {
		dp[i] = new int[M];
		map[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			dp[i][j] = -1;
		}
	}
}

int dfs(int N, int M, int I, int J){

	if (dp[I][J] != -1) return dp[I][J];
	if (I < 0 || I >= N || J < 0 || J >= M) return 0;
	if (I == N - 1 && J == M - 1) return 1;

	dp[I][J] = 0;
	
	int shift_I[4] = { 1,0,-1,0 };
	int shift_J[4] = { 0,1,0,-1 };
	for (int i = 0; i < 4; i++) {
		int next_I = I + shift_I[i];
		int next_J = J + shift_J[i];
		if (next_I < 0 || next_I >= N || next_J < 0 || next_J >= M) {
			continue;
		}
		if (map[I][J] > map[next_I][next_J]) {
			dp[I][J] += dfs(N, M, next_I, next_J);
		}
	}
	return dp[I][J];
}

void print(int N, int M) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	init(N, M);
	cout << dfs(N, M, 0, 0) <<"\n";
	//print(N, M);
}