#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct ball {
	int x;
	int y;
};

typedef struct balls {
	ball Red;
	ball Blue;
};

pair <int, int>direction[4] = { {0,1},{1,0},{0,-1},{-1,0} };
ball R, B;
char map[12][12]; 
int visited[12][12][12][12]; //[»¡x][»¡y] [ÆÄx][ÆÄy]
int N, M;

bool move(ball &obj, ball &other, int dir) {
	int x = obj.x;
	int y = obj.y;
	while (true) {
		x += direction[dir].first;
		y += direction[dir].second;
		if (map[x][y] == '#' || (x == other.x && y == other.y))
			break;
		if (map[x][y] == 'O') {
			obj.x = 0;
			obj.y = 0;
			return true;
		}
		obj = { x, y };
	}
	return false;
}

int isEscape(bool rflag, bool bflag) {
	if (rflag && bflag) //µÑ´ÙÅ»Ãâ
		return -1;
	else if (rflag && !bflag) //»¡°£°ø¸¸ Å»Ãâ
		return 1;
	else if (bflag && !rflag) //ÆÄ¶û Å»Ãâ
		return -1;
	else                      // µÑ´Ù Å»Ãâx
		return 0;

}

int tilt(ball &red, ball &blue, int dir) {

	bool rEscape = false;
	bool bEscape = false;

	if (dir == 0) { //µ¿
		if (red.y > blue.y) {
			rEscape = move(red, blue, dir);
			bEscape = move(blue, red, dir);
		}
		else {
			bEscape = move(blue, red, dir);
			rEscape = move(red, blue, dir);
		}
	}
	else if (dir == 1) { // ³²
		if (red.x > blue.x) {
			rEscape = move(red, blue, dir);
			bEscape = move(blue, red, dir);
		}
		else {
			bEscape = move(blue, red, dir);
			rEscape = move(red, blue, dir);
		}
	}
	else if (dir == 2) { //¼­
		if (red.y < blue.y) {
			rEscape = move(red, blue, dir);
			bEscape = move(blue, red, dir);
		}
		else {
			bEscape = move(blue, red, dir);
			rEscape = move(red, blue, dir);
		}
	}
	else if (dir == 3) { //ºÏ
		if (red.x < blue.x) {
			rEscape = move(red, blue, dir);
			bEscape = move(blue, red, dir);
		}
		else {
			bEscape = move(blue, red, dir);
			rEscape = move(red, blue, dir);
		}
	}
	return isEscape(rEscape, bEscape);
}

int bfs() {

	int cnt = 1;
	int flag = 0;
	int ret = 9999999;
	queue <balls> q;
	q.push({ R,B });
	visited[R.x][R.y][B.x][B.y] = true;

	while (!q.empty()) {
		int qsize = q.size();
		while (--qsize >= 0) {

			ball red = q.front().Red;
			ball blue = q.front().Blue;
			q.pop();

			for (int i = 0; i < 4; i++) {
				
				ball next_r = red;
				ball next_b = blue;
				flag = tilt(next_r, next_b, i);

				if (next_r.x == 0 && next_r.y == 0) {
					if (next_b.x != 0 && next_b.y != 0) {
						ret = min(ret, cnt);
					}
				}
				
				if (next_r.x != 0 && next_b.x != 0 && visited[next_r.x][next_r.y][next_b.x][next_b.y] == false) {
					q.push({ next_r, next_b });
					visited[next_r.x][next_r.y][next_b.x][next_b.y] = true;
				}
			}
		}
		cnt++;
	}
	if (ret == 9999999)
		return -1;
	else {
		if (ret > 10)
			return -1;
		return ret;
	}
}

int main() {
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j= 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				R = { i,j };
			}
			if (map[i][j] == 'B')
				B = { i,j };
		}
	}
	cout << bfs();
}