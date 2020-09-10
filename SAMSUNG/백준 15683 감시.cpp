#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct info {
	int x;
	int y;
	int type;
	int dir;  //0 up 1 down 2 left 3 right
};

int map[8][8];
int tmp[8][8];
vector <info> cctv;
vector <info> stk;
int N, M;
int result = 0xFFFFFFF;

void draw_up(int x, int y) {
	for (int i = x; i >= 0; i--) {
		if (tmp[i][y] == 6)
			break;
		tmp[i][y] = 9;
	}
}
void draw_down(int x, int y) {
	for (int i = x; i < N; i++) {
		if (tmp[i][y] == 6)
			break;
		tmp[i][y] = 9;
	}
		
}
void draw_left(int x, int y) {
	for (int i = y; i >= 0; i--) {
		if (tmp[x][i] == 6)
			break;
		tmp[x][i] = 9;
	}
}
void draw_right(int x, int y) {
	for (int i = y; i < M; i++) {
		if (tmp[x][i] == 6)
			break;
		tmp[x][i] = 9;
	}
}

void draw(info now) {
	if (now.type == 1) {
		if (now.dir == 0) draw_up(now.x, now.y);
		else if (now.dir == 1) draw_down(now.x, now.y);
		else if (now.dir == 2) draw_left(now.x, now.y);
		else if (now.dir == 3) draw_right(now.x, now.y);
	}
	else if (now.type == 2) {
		if (now.dir == 0 || now.dir == 1) {
			draw_up(now.x, now.y);
			draw_down(now.x, now.y);
		}
		else if (now.dir == 2 || now.dir == 3) {
			draw_right(now.x, now.y);
			draw_left(now.x, now.y);
		}
	}
	else if (now.type == 3) {
		if (now.dir == 0) {
			draw_up(now.x, now.y);
			draw_right(now.x, now.y);
		} 
		else if (now.dir == 1) {
			draw_right(now.x, now.y);
			draw_down(now.x, now.y);
		}
		else if (now.dir == 2) {
			draw_down(now.x, now.y);
			draw_left(now.x, now.y);
		}
		else if (now.dir == 3) {
			draw_left(now.x, now.y);
			draw_up(now.x, now.y);
		}
	}
	else if (now.type == 4) {
		if (now.dir == 0) {
			draw_left(now.x, now.y);
			draw_up(now.x, now.y);
			draw_right(now.x, now.y);
		}
		else if (now.dir == 1) {
			draw_up(now.x, now.y);
			draw_right(now.x, now.y);
			draw_down(now.x, now.y);
		}
		else if (now.dir == 2) {
			draw_right(now.x, now.y);
			draw_down(now.x, now.y);
			draw_left(now.x, now.y);
		}
		else if (now.dir == 3) {
			draw_down(now.x, now.y);
			draw_left(now.x, now.y);
			draw_up(now.x, now.y);
		}
	}
	else if (now.type == 5) {
		draw_up(now.x, now.y);
		draw_right(now.x, now.y);
		draw_down(now.x, now.y);
		draw_left(now.x, now.y);
	}
}

void copymap() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			tmp[i][j] = map[i][j];
}

void solve(int cnt) {
	if (cctv.size() == cnt) {
		int ret = 0;
		copymap();
		for (int i = 0; i < cnt; i++) 
			draw(stk[i]);
		
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++) 
				if (tmp[i][j] == 0)
					ret++;
		result = min(result, ret);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		stk.push_back({ cctv[cnt].x,cctv[cnt].y,cctv[cnt].type,(cctv[cnt].dir+i)%4 });
		solve(cnt+1);
		stk.pop_back();
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (1 <= map[i][j] && map[i][j] <= 5) {
				cctv.push_back({ i,j, map[i][j], 1 });
			}
		}
	}
	solve(0);
	cout << result << "\n";
}