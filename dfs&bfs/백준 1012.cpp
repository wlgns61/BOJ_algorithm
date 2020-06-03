#include <iostream>

using namespace std;

int **map;
int cnt = 0;
int N, M, worms;

void init() {
	map = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[M];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			map[i][j] = 0;
		}
	}
	for (int i = 0; i < worms; i++) {
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}

}

void solve(int x, int y) {

	int shift_x[4] = { 1,0,-1,0 };
	int shift_y[4] = { 0,1,0,-1 };

	map[x][y] = 0;

	for (int i = 0; i < 4; i++) {
		int next_x = shift_x[i] + x;
		int next_y = shift_y[i] + y;
		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
			if (map[next_x][next_y] == 1) {
				solve(next_x, next_y);
			}
		}
	}

}

int main() {
	int T;
	cin >> T;
	for(int i=0;i<T;i++){
		cin >> N >> M >> worms;
		init();
		cnt = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				if (map[j][k] == 1) {
					solve(j, k);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
}