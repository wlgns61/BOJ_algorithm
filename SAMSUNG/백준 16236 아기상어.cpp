#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

typedef struct Shark {
	int x;
	int y;
	int size;
};
Shark shark;

int map[21][21];
bool visited[21][21];
int result = 0;
int sizeup = 0;
int n;

bool compare(Shark a, Shark b) {
	//1 °Å¸®°¡ Âª, 2 À§ÀÏ ¼ö·Ï, 3¿ÞÂÊ
	if (a.size == b.size) {
		if (a.x == b.x) {
			return a.y > b.y;
		}
		return a.x > b.x;
	}
	return a.size > b.size;
}


int solve() {
	
	queue <Shark> q;
	q.push({ shark.x,shark.y,0});
	visited[shark.x][shark.y] = true;
	Shark next = { 1000, 1000, 1000 };
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().size;
		q.pop();
		pair <int, int> move[4] = { {1,0}, {-1,0}, {0,1}, {0, -1} };
		vector <Shark> v;
		for (int i = 0; i < 4; i++) {
			int next_x = x + move[i].first;
			int next_y = y + move[i].second;
			if (!(next_x < 0 || n <= next_x || next_y < 0 || n <= next_y)) {
				if (map[next_x][next_y] <= shark.size && visited[next_x][next_y] == false) {
					q.push({ next_x, next_y, cnt+1});
					if (0 < map[next_x][next_y] && map[next_x][next_y] < shark.size) {
						if (compare(next, { next_x, next_y, cnt+1 }))
							next = { next_x, next_y, cnt + 1 };
					}
					visited[next_x][next_y] = true;
				}
			}
		}
	}
	if (next.size < 1000) {
		map[shark.x][shark.y] = 0;
		shark.x = next.x;
		shark.y = next.y;
		map[shark.x][shark.y] = 9;
		sizeup++;
		if (shark.size == sizeup) {
			shark.size++;
			sizeup = 0;
		}
		return next.size;
	}
	return 0;
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) 
				shark = { i,j,2 };
		}
	
	while (true) {
		memset(visited, false, sizeof(visited));
		int ret = solve();
		if (ret == 0)
			break;
		result += ret;
	}
	cout << result;
}