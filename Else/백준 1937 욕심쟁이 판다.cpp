#include <iostream>
#include <algorithm>

using namespace std;

int map[500][500];
int dp[500][500];
pair<int, int> nextdir[4] = { {1,0}, {0,1}, {-1,0}, {0,-1} };
int result = 0;
int n;

int solve(int nowx, int nowy) {

	int &ref = dp[nowx][nowy];
	int ret = 0;

	if (ref != 0)  //방문한 적이 있다면
		return ref;
	else  // 방문한적이 없다면
		ref = 1;

	for (int i = 0; i < 4; i++) {
		int next_x = nowx + nextdir[i].first;
		int next_y = nowy + nextdir[i].second;
		if (0 <= next_x && next_x < n && 0 <= next_y && next_y < n) {
			if (map[nowx][nowy] < map[next_x][next_y]) {
				ret = max(ret, solve(next_x, next_y));
			}
		}
	}
	ref += ret;
	return ref;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (dp[i][j] == 0) //방문 한적 없다면
				result = max(result, solve(i, j));
			else //방문한 적 있다면
				result = max(result, dp[i][j]);
		}

	cout << result << endl;
}