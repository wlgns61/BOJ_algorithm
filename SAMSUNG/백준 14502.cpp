#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>

using namespace std;

int room[8][8];
vector <pair<int, int>> zeros;
vector <pair<int, int>> virus;
int max_ = 0;

int bfs(int x, int y) {

	int cnt = 0;
	queue < pair<int, int>> q;
	q.push({ x,y });
	while (!q.empty()) {
		auto elem = q.front();
		int i = elem.first;
		int j = elem.second;
		q.pop();
		if (i + 1 <= 7) {
			if (room[i + 1][j] == 0) {
				q.push({ i + 1, j });
				room[i + 1][j] = 2;
				cnt++;
			}
		}
		if (i - 1 >= 0) {
			if (room[i - 1][j] == 0) {
				q.push({ i - 1, j });
				room[i - 1][j] = 2;
				cnt++;
			}
		}
		if (j + 1 <= 7) {
			if (room[i][j + 1] == 0) {
				q.push({ i, j + 1 });
				room[i][j + 1] = 2;
				cnt++;
			}
		}
		if (j - 1 >= 0) {
			if (room[i][j - 1] == 0) {
				q.push({ i, j - 1 });
				room[i][j - 1] = 2;
				cnt++;
			}
		}
	}
	return cnt;
}

void build_wall(int n, int m) {

	for (int i = 0; i < zeros.size();i++) {
		for (int j = i+1; j < zeros.size(); j++) {
			for (int k = j+1; k < zeros.size(); k++) {
				int cnt = 0;
				auto first = zeros[i];
				auto second = zeros[j];
				auto third = zeros[k];
				room[first.first][first.second] = 1;
				room[second.first][second.second] = 1;
				room[third.first][third.second] = 1;
				for (auto &elem : virus) {
					cnt += bfs(elem.first, elem.second); //바이러스가 퍼진 영역의 수
				}
				int safe = zeros.size() - 3 - cnt;
				max_ = max(max_, safe);
				for (auto &elem : zeros) {
					room[elem.first][elem.second] = 0;
				}
				room[first.first][first.second] = 0;
				room[second.first][second.second] = 0;
				room[third.first][third.second] = 0;
			}
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(room, -1, sizeof(room));

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			if (room[i][j] == 0)
				zeros.push_back({ i,j });
			else if (room[i][j] == 2)
				virus.push_back({ i,j });
		}
	}
	build_wall(n, m);
	cout << max_;

}