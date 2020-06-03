#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

queue <tuple<int, int ,int>> q;
int map[101][101][101] = { 0, };
int cnt[101][101][101] = { 0, };
int N, M, K;
int result = 0;

void bfs() {

	int s_x[6] = { 0,1,0,-1,0,0 };
	int s_y[6] = { 1,0,-1,0,0,0 };
	int s_z[6] = { 0,0,0,0,1,-1 };
	int x = 0, y = 0, z = 0;

	while (true) {
		if (!q.empty()) {
			x = get<0>(q.front());
			y = get<1>(q.front());
			z = get<2>(q.front());
			q.pop();
		}
		for (int i = 0; i < 6; i++) {
			int n_x = x + s_x[i];
			int n_y = y + s_y[i];
			int n_z = z + s_z[i];
			if (0 <= n_x && n_x < N && 0 <= n_y && n_y < M && 0 <= n_z && n_z < K) {
				if (cnt[n_x][n_y][n_z] == 0 && map[n_x][n_y][n_z] == 0) {
					map[n_x][n_y][n_z] = 1;
					q.push(make_tuple(n_x, n_y ,n_z));
					cnt[n_x][n_y][n_z] = cnt[x][y][z] + 1;
					result = max(cnt[n_x][n_y][n_z], result);
					map[n_x][n_y][n_z] = 1;
				}
			}
		}
		if (q.empty()) {
			return;
		}
	}
}

void print() {
	for (int k = 0; k < K; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cout << cnt[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
}


int main() {

	cin >> M >> N >> K;
	for (int k = 0; k < K; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
				}
			}
		}
	}
	
	bfs();
	for (int k = 0; k < K; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j][k] == 0) {
					result = -1;
				}
			}
		}
	}
	
	cout << result;
}