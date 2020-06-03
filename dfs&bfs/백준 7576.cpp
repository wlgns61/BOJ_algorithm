#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue <pair<int, int>> q;
int map[1001][1001] = { 0, };
int cnt[1001][1001] = { 0, };
int N, M;
int result = 0;

void bfs() {

	int s_x[4] = { 0,1,0,-1 };
	int s_y[4] = { 1,0,-1,0 };
	int x = 0, y = 0;

	while (true) {
		if (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
		}
		for (int i = 0; i < 4; i++) {
			int n_x = x + s_x[i];
			int n_y = y + s_y[i];
			if (0 <= n_x && n_x < N && 0 <= n_y && n_y < M) {
				if (cnt[n_x][n_y] == 0 && map[n_x][n_y] == 0) {
					map[n_x][n_y] = 1;
					q.push({ n_x, n_y });
					cnt[n_x][n_y] = cnt[x][y] + 1;
					result = max(cnt[n_x][n_y], result);
					map[n_x][n_y] = 1;
				}
			}
		}
		if (q.empty()) {
			return;
		}
	}
}


int main() {

	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	bfs();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				result = -1;
			}
		}
	}
	cout << result;
}