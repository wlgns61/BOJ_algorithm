#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> v;

int **map;
int cnt = 0;

void init(int N) {
	map = new int*[N];
	for (int i = 0; i < N; i++) {
		map[i] = new int[N];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			char inp;
			cin >> inp;
			map[i][j] = int(inp) - int('0');
		}
	}
}

void solve(int N, int x, int y) {
	
	int shift_x[4] = { 1,0,-1,0 };
	int shift_y[4] = { 0,1,0,-1 };

	map[x][y] = 0;
	cnt++;

	for (int i = 0; i < 4; i++) {
		int next_x = shift_x[i] + x;
		int next_y = shift_y[i] + y;
		if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N) {
			if (map[next_x][next_y] == 1) {
				solve(N, next_x, next_y);
			}
		}
	}

}

int main() {
	int N;
	cin >> N;
	init(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				cnt = 0;
				solve(N, i, j);
				v.push_back(cnt);
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int j = 0; j < v.size(); j++) {
		cout << v[j] << "\n";
	}
}