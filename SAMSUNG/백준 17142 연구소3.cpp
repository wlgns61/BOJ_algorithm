#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int map[51][51];
int tmp[51][51];
pair<int, int> next_dir[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
vector<pair<int, int>> virus;
vector<int> visited;
int n, m;
int result = 9999;

void copy_map(vector<int> choose) {

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			tmp[i][j] = map[i][j];
			if (tmp[i][j] == 2)
				tmp[i][j] = -1;
 		}
	
	for (int i = 0; i < choose.size(); i++) 
		tmp[virus[choose[i]].first][virus[choose[i]].second] = 2;
}

bool check() {
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			if (tmp[i][j] == 0)
				return false;

	return true;
}

int bfs(vector<int> choose) {
	queue <pair<int, int>> q;
	int time = 0;
	for (int i = 0; i < choose.size(); i++) 
		q.push({ virus[choose[i]].first, virus[choose[i]].second});
	
	while (!q.empty()) {
		int now_x = q.front().first;
		int now_y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = now_x + next_dir[i].first;
			int next_y = now_y + next_dir[i].second;
			if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n) {
				if (tmp[next_x][next_y] == 0) {
					tmp[next_x][next_y] = tmp[now_x][now_y] + 1;
					time = max(time, tmp[next_x][next_y]);
					q.push({ next_x, next_y});
				}
				else if (tmp[next_x][next_y] == -1) {
					if (check())
						return time - 2;
					else {
						tmp[next_x][next_y] = tmp[now_x][now_y] + 1;
						time = max(time, tmp[next_x][next_y]);
						q.push({ next_x, next_y });
					}
				}
			}
		}
	}
	if (check())
		return time - 2;
	else
		return 9999;
}

void pick_m(int cnt, vector<int> &choose, int idx) {
	if (cnt == m) {
		copy_map(choose);
		result = min(bfs(choose), result);
		return;
	}
	for (int i = idx; i < virus.size(); i++) {
		if (visited[i] == false) {
			visited[i] = true;
			choose.push_back(i);
			pick_m(cnt + 1, choose, i);
			visited[i] = false;
			choose.pop_back();
		}
	}
}

int solve() {
	visited.resize(virus.size(), 0);
	vector<int> choose;
	pick_m(0, choose, 0);
	if (result == 9999)
		return -1;
	else if (result == -2)
		return 0;
	else
		return result;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if(map[i][j] == 2)
				virus.push_back({ i,j });
		}
	
	cout << solve();
}