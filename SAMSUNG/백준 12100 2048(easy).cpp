#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, result;

vector<vector<int>> move(int dir, vector<vector<int>> map) { //0 ºÏ 1 ¼­ 2 µ¿ 3 ³²
	if (dir == 0) {
		for (int j = 0; j < n; j++) {
			int zerocnt = 0;
			for (int i = 0; i < n; i++) {
				if (map[i][j] == 0) {
					zerocnt++;
				}
				else {
					if (zerocnt != 0) {
						map[i - zerocnt][j] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
			for (int i = 0; i < n - 1; i++) {
				if (map[i][j] == map[i + 1][j]) {
					map[i][j] += map[i + 1][j];
					map[i + 1][j] = 0;
				}
			}
			zerocnt = 0;
			for (int i = 0; i < n; i++) {
				if (map[i][j] == 0) {
					zerocnt++;
				}
				else {
					if (zerocnt != 0) {
						map[i - zerocnt][j] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
		}
	}
	if (dir == 1) {
		for (int i = 0; i < n; i++) {
			int zerocnt = 0;
			for (int j = n - 1; j >= 0; j--) {
				if (map[i][j] == 0) {
					zerocnt++;
				}
				else {
					if (zerocnt != 0) {
						map[i][j + zerocnt] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
			for (int j = n - 1; j > 0; j--) {
				if (map[i][j - 1] == map[i][j]) {
					map[i][j] *= 2;
					map[i][j - 1] = 0;
				}
			}
			zerocnt = 0;
			for (int j = n - 1; j >= 0; j--) {
				if (map[i][j] == 0) {
					zerocnt++;
				}
				else {
					if (zerocnt != 0) {
						map[i][j + zerocnt] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
		}
	}
	if (dir == 2) {
		for (int j = 0; j < n; j++) {
			int zerocnt = 0;
			for (int i = n - 1; i >= 0; i--) {
				if (map[i][j] == 0) {
					zerocnt++;
				}
				else {
					if (zerocnt != 0) {
						map[i + zerocnt][j] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
			for (int i = n - 1; i > 0; i--) {
				if (map[i][j] == map[i - 1][j]) {
					map[i][j] *= 2;
					map[i - 1][j] = 0;
				}
			}
			zerocnt = 0;
			for (int i = n - 1; i >= 0; i--) {
				if (map[i][j] == 0) {
					zerocnt++;
				}
				else {
					if (zerocnt != 0) {
						map[i + zerocnt][j] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
		}
	}
	if (dir == 3) {
		for (int i = 0; i < n; i++) {
			int zerocnt = 0;
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) {
					zerocnt++;
				}
				else {
					if (zerocnt != 0) {
						map[i][j - zerocnt] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
			for (int j = 0; j < n - 1; j++) {
				if (map[i][j] == map[i][j + 1]) {
					map[i][j] *= 2;
					map[i][j + 1] = 0;
				}
			}
			zerocnt = 0;
			for (int j = 0; j < n; j++) {
				if (map[i][j] == 0) {
					zerocnt++;
				}
				else {
					if (zerocnt != 0) {
						map[i][j - zerocnt] = map[i][j];
						map[i][j] = 0;
					}
				}
			}
		}
	}
	return map;
}


int find_max(vector<vector<int>> map) {
	int maximum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			maximum = max(maximum, map[i][j]);
		}
	}
	return maximum;
}

void solve(int cnt, vector<vector<int>> &map) {
	if (cnt == 5) {
		result = max(find_max(map), result);
		return;
	}
	for (int i = 0; i < 4; i++) {
		vector<vector<int>> tmp = map;
		map = move(i, map);
		solve(cnt + 1, map);
		map = tmp;
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	vector<vector<int>> map;
	vector<vector<int>> tmp;

	cin >> n;

	map.resize(n);
	tmp.resize(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num;
			cin >> num;
			map[i].push_back(num);
		}
	}
	solve(0, map);
	cout << result;
}