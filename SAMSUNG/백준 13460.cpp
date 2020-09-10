#include <iostream>
#include <queue>
#define INF 0xfffffff

using namespace std;

typedef struct ball {
	int x;
	int y;
	char type;
};

typedef struct balls {
	ball R;
	ball B;
};

int N, M;
int visited[11][11][11][11];
char map[11][11];
ball R, B;
const pair<int, int> direction[4] = { {0,1}, {1,0}, {0,-1}, {-1,0} };

bool move(ball &obj, ball &other, int direct) {

	bool isEscape = false;
	int x = obj.x;
	int y = obj.y;

	while (true) {

		x += direction[direct].first;
		y += direction[direct].second;
		if (map[x][y] == '#' || (x == other.x && y == other.y)) 
			break;
		else if (map[x][y] == 'O') {
			obj.y = 0;
			obj.x = 0;
			isEscape = true;
			break;
		}
		obj.x = x;
		obj.y = y;
	}
	return isEscape;
}

int isEscape(bool rEscape, bool bEscape) {

	if (rEscape && bEscape)
		return -1;
	else if (bEscape) 
		return -1;
	else if (rEscape)
		return 1;
	else
		return 0;
}

int tilt(ball &red, ball &blue, int direct) {

	bool rEscape = false;
	bool bEscape = false;

	if (direct == 0) {
		if (red.y > blue.y) {
			rEscape = move(red, blue, direct);
			bEscape = move(blue, red, direct);
		}
		else {
			bEscape = move(blue, red, direct);
			rEscape = move(red, blue, direct);
		}
	}
	else if (direct == 1) {
		if (red.x > blue.x) {
			rEscape = move(red, blue, direct);
			bEscape = move(blue, red, direct);
		}
		else {
			bEscape = move(blue, red, direct);
			rEscape = move(red, blue, direct);
		}
	}
	else if (direct == 2) {
		if (red.y <= blue.y) {
			rEscape = move(red, blue, direct);
			bEscape = move(blue, red, direct);
		}
		else {
			bEscape = move(blue, red, direct);
			rEscape = move(red, blue, direct);
		}
	}
	else if (direct == 3) {
		if (red.x < blue.x) {
			rEscape = move(red, blue, direct);
			bEscape = move(blue, red, direct);
		}
		else {
			bEscape = move(blue, red, direct);
			rEscape = move(red, blue, direct);
		}
	}
	return isEscape(rEscape, bEscape);
}

int BFS() {

	queue <balls> q;
	q.push({ R,B });
	visited[R.x][R.y][B.x][B.y] = 1;
	
	int cnt = 1;
	int ret;
	int ans = INF;
	ball cur_R, cur_B;
	ball next_R, next_B;

	while (!q.empty()) {
		int cur_level = q.size();
		while (cur_level--) {
			cur_R = q.front().R;
			cur_B = q.front().B;
			q.pop();

			for (int direct = 0; direct < 4; direct++) {
				next_R = cur_R;
				next_B = cur_B;

				ret = tilt(next_R, next_B, direct);
				// cout << next_R.x << "," << next_R.y << "=>";
				if (next_R.x == 0 && next_R.y == 0) {
					if (next_B.x == 0 && next_B.y == 0)
						continue;
					else {
						ans = min(ans, cnt);
						continue;
					}
				}
				if (!visited[next_R.x][next_R.y][next_B.x][next_B.y]) {
					q.push({ next_R, next_B });
					visited[next_R.x][next_R.y][next_B.x][next_B.y] = 1;
				}
			}
		}
		++cnt;
	}
	if (ans != INF) {
		if (ans > 10) {
			return -1;
		}
		return ans;
	}
	return -1;
}

int main() {

	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				R = { i,j, 'R' };
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				B = { i,j, 'B' };
				map[i][j] = '.';
			}
		}
	}
	cout << BFS();

}