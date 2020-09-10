#include <iostream>
#include <vector>
#define white 0
#define red 1
#define blue 2

using namespace std;

typedef struct horse{
	int x, y, dir;
};
pair <int, int> direction[4] = { {0,1}, {0,-1}, {-1,0}, {1,0} };
horse horses[10];
int map[14][14];
vector <int> location[14][14];
int n, k;
int cnt = 0;

vector <int> when_white(horse now, int me, int next_x, int next_y) { 
	int h = 0;
	vector <int> move;
	int size = location[now.x][now.y].size();
	for (h = 0; h < size; h++) {
		if (location[now.x][now.y][h] == me)
			break;
	}
	for (int i = h; i < size; i++) {
		int elem = location[now.x][now.y][i];
		location[next_x][next_y].push_back(elem);
		move.push_back(elem);
	}
	for (int i = h; i < size; i++)
		location[now.x][now.y].pop_back();
	return move;
}
vector <int> when_red(horse now, int me, int next_x, int next_y) {
	
	int h = 0;
	vector <int> move;
	int size = location[now.x][now.y].size();
	for (h = 0; h < size; h++)
		if (location[now.x][now.y][h] == me)
			break;
	for (int i = size - 1; i >= h; i--) {
		int elem = location[now.x][now.y][i];
		location[next_x][next_y].push_back(elem);
		move.push_back(elem);
	}
	for (int i = h; i < size; i++)
		location[now.x][now.y].pop_back();
	return move;
}

void sync(vector <int> move, int next_x, int next_y){
	for (int i = 0; i < move.size(); i++) {
		horses[move[i]].x = next_x;
		horses[move[i]].y = next_y;
	}
}

int solve() {
	while (true) {
		cnt++;
		for (int i = 0; i < k; i++) {
			horse now = horses[i];
			int next_x = now.x + direction[now.dir].first;
			int next_y = now.y + direction[now.dir].second;

			vector <int> move;
			if (map[next_x][next_y] == white) 
				move = when_white(now, i, next_x, next_y);
			else if (map[next_x][next_y] == red) 
				move = when_red(now, i, next_x, next_y);
			else {
				int next_dir = 0;
				if (now.dir <= 1)   //방향 전환
					next_dir = 1 - now.dir;
				else 
					next_dir = 5 - now.dir;
				horses[i].dir = next_dir;
				next_x = now.x + direction[next_dir].first;
				next_y = now.y + direction[next_dir].second;
				if (map[next_x][next_y] == blue)
					continue;
				else if(map[next_x][next_y] == white)
					move = when_white(now, i, next_x, next_y);
				else 
					move = when_red(now, i, next_x, next_y);
			}
			sync(move, next_x, next_y);
			if (cnt > 1000)
				return -1;
			if (location[next_x][next_y].size() >= 4)
				return cnt;
		}
	}
	return cnt;
}

int main() {

	ios_base::sync_with_stdio(NULL); cin.tie(0); cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i <= n + 1; i++) 
		for (int j = 0; j <= n + 1; j++) {
			if (i == 0 || i == n + 1 || j == 0 || j == n + 1)
				map[i][j] = 2;
			else
				cin >> map[i][j];
		}
	for (int i = 0; i < k; i++) {
		int x, y, dir;
		cin >> x >> y >> dir;
		horses[i] = { x,y,dir-1 };
		location[x][y].push_back(i);
	}
	cout << solve();
}
