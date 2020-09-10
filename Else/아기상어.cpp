#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef struct shark{
	int x;
	int y;
	int size;
	int exp;
};

typedef struct q_info {
	int x;
	int y;
	int dist;
};

shark babyshark;
pair<int, int> direction[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int map[21][21];
int visited[21][21];
int n;

q_info compare(q_info origin, q_info newone) {
	if (origin.dist == newone.dist) {
		if (origin.x == newone.x) 
			return origin.y < newone.y ? origin : newone;
		else
			return origin.x < newone.x ? origin : newone;
	}
	else
		return origin.dist < newone.dist ? origin : newone;
}

int BFS(int x, int y) {
	
	queue<q_info> q; //x,y,level
	q.push({ x,y,0 });
	q_info next = { 1000,1000,1000 };

	while (!q.empty()) {

		int now_x = q.front().x;
		int now_y = q.front().y;
		int dist = q.front().dist;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_x = now_x + direction[i].first;
			int next_y = now_y + direction[i].second;
			if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n ) {
				if (!visited[next_x][next_y] && map[next_x][next_y] <= babyshark.size) { //이동할 수 있는 모든 경우
					q.push({ next_x, next_y, dist + 1 });
					visited[next_x][next_y] = true;
					if (0 < map[next_x][next_y] && map[next_x][next_y] < babyshark.size) { // 이동할 곳에 먹이가 있다면
						next = compare(next, { next_x, next_y, dist + 1 });
					}
				}
			}
		}
	}
	if (next.x == 1000) {
		return 0;
	}
	else {
		map[next.x][next.y] = 0;
		if (babyshark.exp + 1 == babyshark.size) { //레벨업 조건
			babyshark = { next.x, next.y, babyshark.size+1, 0 };
		}
		else {
			babyshark = { next.x, next.y, babyshark.size, babyshark.exp+1 };
		}
		return next.dist;
	}

}

void printmap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int solve() {

	int result = 0;
	while (1) {
		memset(visited, 0, sizeof(visited));
		int dist = BFS(babyshark.x, babyshark.y);
		if (dist == 0)
			break;
		result += dist;
	}
	return result;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				map[i][j] = 0;
				babyshark = { i,j,2,0 };
			}
		}
	}
	cout << solve();
}