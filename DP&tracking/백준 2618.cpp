#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

int choose[1010][1010];
int dp[1010][1010];
vector <pair<int, int>> pos;
int n, w;

int dist(pair<int, int> x, pair<int, int> y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

int solve(int x, int y) {
	int here = max(x, y) + 1;
	if (here == w + 2) return 0; //모든 사건 해결, 남은거리=0

	if (dp[x][y] != -1) return dp[x][y]; // 방문 여부

	int x_solve = solve(here, y) + dist(pos[x], pos[here]);
	int y_solve = solve(x, here) + dist(pos[y], pos[here]);
	if (x_solve > y_solve) { // y해결
		choose[x][y] = 1;
		dp[x][y] = y_solve;
	}
	else {
		dp[x][y] = x_solve;
	}
	return dp[x][y];
}


int main() {
	cin >> n >> w; // 도로, 사건
	memset(dp, -1, sizeof(dp));
	pos.push_back({ 1, 1 });
	pos.push_back({ n, n });
	for (int i = 0; i < w; i++){
		int x, y;
		cin >> x >> y;
		pos.push_back({ x,y });
	}
	printf("%d\n", solve(0, 1));
	for (int x = 0, y = 1; max(x, y) + 1 < w + 2;) {
		if (choose[x][y] == 1)
			printf("2\n");
		else
			printf("1\n");
		if (choose[x][y] == 1) y = max(x, y) + 1; //y가 해결한 경우 
		else x = max(x, y) + 1; //x가 해결한 경우
	}

}