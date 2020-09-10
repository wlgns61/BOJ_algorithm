#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct info{
	int x;
	int y;
};

int n, m;
int dir;
int map[50][50];
info direction[4] = { {-1,0}, {0,1}, {1,0}, {0,-1} }; // 현재 dir에서 진행
info now;
//북 동 남 서
//0  1  2  3
//북->서 서->남 남->동 동->북
//0->3  3->2  2->1  1->0
//후진 
int solve() {
	int cnt = 0;
	while (true) {
		if (map[now.x][now.y] == 0) {
			map[now.x][now.y] = 2;
			cnt++;
		}
		//int nextdir = dir;
		info next;
		bool flag = false;
		for (int i = 0; i < 4; i++) {
			dir = dir - 1;
			if (dir < 0) dir = 3;
			next.x = now.x + direction[dir].x;
			next.y = now.y + direction[dir].y;
			if (map[next.x][next.y] == 0) {
				now = next;
				flag = true;
				break;
			}
		}
		if (flag) continue;
		else {
			int back = (dir + 2) % 4;
			next.x = now.x + direction[back].x;
			next.y = now.y + direction[back].y;
			if (map[next.x][next.y] == 0 || map[next.x][next.y] == 2) {
				now = next;
				continue;
			}
			else {
				break;
			}
		}
	}
	return cnt;
}

int main() {
	
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cin >> now.x >> now.y >> dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	cout << solve();
}