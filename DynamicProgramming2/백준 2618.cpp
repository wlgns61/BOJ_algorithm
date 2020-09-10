#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;

pair <int, int> *pos;
int **choose;
int N, W;
int dp[1123][1123];

int dist(pair<int, int> x, pair<int, int> y) {
	return abs(x.first - y.first) + abs(x.second - y.second);
}

int solve(int x, int y) {
	int here = max(x, y) + 1;
	if (here == W + 2) return 0; // ����� ��� �ذ��� ���

	int &x_solve = dp[x][y];
	if (x_solve != -1) return x_solve;

	//x�� �ذ��� ���, y�� �ذ��� ���
	x_solve = solve(here, y) + dist(pos[x], pos[here]);
	int y_solve = solve(x, here) + dist(pos[y], pos[here]);
	
	//y�� �ذ��� ���
	if (x_solve > y_solve) {
		choose[x][y] = 1;
		x_solve = y_solve;
	}
	return x_solve;
}


int main() {
	scanf("%d %d", &N, &W);
	pos = new pair<int, int> [W + 1];
	choose = new int*[W + 3];
	memset(dp, -1, sizeof(dp));
	pos[0] = { 1,1 };
	pos[1] = { N,N };
	choose[0] = new int[W + 3];
	choose[1] = new int[W + 3];
	for (int i = 2; i <= W + 2; i++) {
		choose[i] = new int[W + 3];
		scanf("%d %d", &pos[i].first, &pos[i].second);
	}
	for (int i = 0; i < W+3; i++) {
		for (int j = 0; j < W+3; j++) {
			choose[i][j] = 0;
		}
	}
	printf("%d\n", solve(0, 1));
	for (int x = 0, y = 1; max(x, y) + 1 < W + 2;) {
		if (choose[x][y] == 1)
			printf("2\n");
		else
			printf("1\n");
		if (choose[x][y] == 1) y = max(x, y) + 1; //y�� �ذ��� ��� 
		else x = max(x, y) + 1; //x�� �ذ��� ���
	}
}