#include <iostream>
#include <queue>

using namespace std;

queue <pair<int, int>> q;

int **map;
int **cnt;
//int cnt = 0;
int N, M;

void init() {
	map = new int*[N];
	cnt = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
		cnt[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			char inp;
			cin >> inp;
			map[i][j] = int(inp) - int('0');
			cnt[i][j] = 0;
		}
	}
}

int solve() {
	int shift_x[4] = { 0,1,0,-1 };
	int shift_y[4] = { 1,0,-1,0 };
	int x = 0;
	int y = 0;
	q.push({ 0,0 });
	map[0][0] = 0;
	while (true) {
		if (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
		}
		for (int i = 0; i < 4; i++) {
			int next_x = shift_x[i] + x;
			int next_y = shift_y[i] + y;
			if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M) {
				if (map[next_x][next_y] == 1 && cnt[next_x][next_y] == 0) { //cnt==0일때만 접근 가능하므로 가장 먼저 찾아온 녀석이 cnt값을 바꿔놓으므로 
					q.push({next_x, next_y});                               // 그 이후에 누군가가 찾아오면 접근이 불가능하다
					cnt[next_x][next_y] = cnt[x][y] + 1;
				}
			}
		}
		if (q.empty()) {
			return cnt[N-1][M-1] + 1;
		}
	}

}

int main() {

	cin >> N >> M;
	init();
	cout << solve();
}