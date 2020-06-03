#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <tuple>

using namespace std;

queue <tuple<int, int, int>> q;
int map[1001][1001] = { 0, };
int cnt[1001][1001][2];
int N, M;

int bfs() {

	int s_x[4] = { 0,1,0,-1 };
	int s_y[4] = { 1,0,-1,0 };
	int x = 0, y = 0, w_cnt;
	cnt[0][0][1] = 1;
	while (!q.empty()) {
		x = get<0>(q.front());
		y = get<1>(q.front());
		w_cnt = get<2>(q.front());
		q.pop();
		
		if (x == N - 1 && y == M - 1)
			return cnt[x][y][w_cnt]; 

		for (int i = 0; i < 4; i++) {
			int n_x = x + s_x[i];
			int n_y = y + s_y[i];
			if (0 <= n_x && n_x < N && 0 <= n_y && n_y < M) {
				if (map[n_x][n_y] == 1 && w_cnt) {
					q.push(make_tuple(n_x, n_y, w_cnt - 1));
					cnt[n_x][n_y][w_cnt - 1] = cnt[x][y][w_cnt] + 1;
				}
				else if (map[n_x][n_y] == 0 && cnt[n_x][n_y][w_cnt] == 0) {
					q.push(make_tuple(n_x, n_y, w_cnt));
					cnt[n_x][n_y][w_cnt] = cnt[x][y][w_cnt] + 1;
				}
			}
		}
	}
	return -1;
}



int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	q.push(make_tuple(0,0,1));
	cout << bfs();
	
}