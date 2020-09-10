#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct info {
	int x;
	int y;
};

vector <info> stk;
info next_dir[4] = { {1,0}, {-1,0}, {0,-1}, {0,1} };
int map[500][500];
bool visited[500][500];
int N, M;
int result = -1;

void solve(int cnt, int x, int y) {
	if (cnt == 4) {
		int sum = 0;
		for (int i = 0; i < 4; i++) {
			sum += map[stk[i].x][stk[i].y];
			result = max(result, sum);
		}
		return;
	}
	if (cnt == 3) {
		if (stk[0].x == stk[1].x && stk[1].x == stk[2].x) {
			info fuck[2] = { {1, 0} ,{-1, 0} };
			for (int i = 0; i < 2; i++) {
				int next_x = stk[1].x + fuck[i].x;
				int next_y = stk[1].y + fuck[i].y;
				if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M && !visited[next_x][next_y]) {
					visited[next_x][next_y] = true;
					stk.push_back({ next_x, next_y });
					solve(cnt + 1, next_x, next_y);
					stk.pop_back();
					visited[next_x][next_y] = false;
				}
			}
		}
		else if (stk[0].y == stk[1].y && stk[1].y == stk[2].y){
			info fuck[2] = { {0, 1} ,{0, -1} };
			for (int i = 0; i < 2; i++) {
				int next_x = stk[1].x + fuck[i].x;
				int next_y = stk[1].y + fuck[i].y;
				if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M && !visited[next_x][next_y]) {
					visited[next_x][next_y] = true;
					stk.push_back({ next_x, next_y });
					solve(cnt + 1, next_x, next_y);
					stk.pop_back();
					visited[next_x][next_y] = false;
				}
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		int next_x = x + next_dir[i].x;
		int next_y = y + next_dir[i].y;
		if (0 <= next_x && next_x < N && 0 <= next_y && next_y < M && !visited[next_x][next_y]) {
			visited[next_x][next_y] = true;
			stk.push_back({ next_x, next_y });
			solve(cnt + 1, next_x, next_y);
			stk.pop_back();
			visited[next_x][next_y] = false;
		}
	}

}

int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = true;
			stk.push_back({ i,j });
			solve(1, i, j);
			stk.pop_back();
			visited[i][j] = false;
		}
	}
	cout << result << "\n";
}