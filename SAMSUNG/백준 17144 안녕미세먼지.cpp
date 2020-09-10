#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct info {
	int x;
	int y;
	int cost;
};

vector <info> v; // 먼지들의 양과 좌표
vector <info> cleaner;
int map[50][50];
int R, C, sec;

void spread() {
	int tmp[50][50];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			tmp[i][j] = map[i][j];
		}
	}
	pair <int, int> dir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (tmp[i][j] > 0) {
				int nextcost = tmp[i][j] / 5;
				int nextcnt = 0;
				for (int k = 0; k < 4; k++) {
					int next_x = i + dir[k].first;
					int next_y = j + dir[k].second;
					if (0 <= next_x && next_x < R && 0 <= next_y && next_y < C) {
						if (cleaner[0].x == next_x && cleaner[0].y == next_y)
							continue;
						if (cleaner[1].x == next_x && cleaner[1].y == next_y)
							continue;
						map[next_x][next_y] += nextcost;
						nextcnt++;
					}
				}
				map[i][j] -= (nextcost*nextcnt);
			}
		}
	}
}

void wind() {
	
	int up_x = cleaner[0].x;
	int dn_x = cleaner[1].x;

	for (int i = up_x - 2; i >= 0; i--) {
		map[i + 1][0] = map[i][0];
	}
	for (int i = 0; i < C - 1; i++) {
		map[0][i] = map[0][i + 1];
	}
	for (int i = 1; i <= up_x; i++) {
		map[i - 1][C - 1] = map[i][C - 1];
	}
	for (int i = C - 1; i >= 2; i--) {
		map[up_x][i] = map[up_x][i - 1];
	}
	map[up_x][1] = 0;

	for (int i = dn_x + 1; i < R; i++) {
		map[i][0] = map[i + 1][0];
	}
	for (int i = 0; i < C - 1; i++) {
		map[R - 1][i] = map[R - 1][i + 1];
	}
	for (int i = R - 1; i > dn_x; i--) {
		map[i][C - 1] = map[i - 1][C - 1];
	}
	for (int i = C - 1; i >= 1; i--) {
		map[dn_x][i] = map[dn_x][i - 1];
	}
	map[dn_x][1] = 0;
}

void print() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

void solve() {
	while (--sec>=0) {
		spread();
		//cout << endl;
		wind();
		//print();
		//cout << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	cin >> R >> C >> sec;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0) {
				v.push_back({ i,j,map[i][j] });
			}
			if (map[i][j] < 0) {
				cleaner.push_back({ i,j,-1 });
			}
		}
	}
	solve();
	int result = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (i == cleaner[0].x && j == cleaner[0].y)
				continue;
			if (i == cleaner[1].x && j == cleaner[1].y)
				continue;
			result += map[i][j];
		}
	}
	cout << result;
	
}