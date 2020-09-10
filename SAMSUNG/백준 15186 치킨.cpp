#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef struct info{
	int x;
	int y;
};
vector <info> house;
vector <info> chick;
bool visited[14];
int choose[14];
int result = 999999999;
int n;
int m;

int distance(info a, info b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int min_dist() {
	int ret = 0;
	for (auto &home : house) {
		int min_ = 999999999;
		for (int i = 0; i < m; i++) {
			min_ = min(min_, distance(home, chick[choose[i]]));
		}
		ret += min_; //골라진 치킨집에 대한 최소거리
	}
	return ret;
}

void tracking(int cnt, int idx) {
	if (cnt == m) {
		result = min(result, min_dist());
		return;
	}
	for (int i = idx + 1; i <= chick.size(); i++) {
		if (visited[i] == false) {
			visited[i] = true;
			choose[cnt] = i - 1;
			tracking(cnt + 1, i);
			visited[i] = false;
		}
	}
}

void solve() {
	tracking(0, 0);
	cout << result;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			if (num == 1)
				house.push_back({ i,j });
			else if (num == 2)
				chick.push_back({ i,j });
		}
	}
	solve();
}