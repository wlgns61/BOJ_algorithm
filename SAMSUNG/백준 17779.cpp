#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int map[21][21];
int visited[21][21];
int n;

int area1(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = 1; i < x + d1; i++)
		for (int j = 1; j <= y; j++) {
			if (i + j < x + y) {
				visited[i][j] = 1;
				sum += map[i][j];
			}
		}
	return sum;
}
int area2(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = 1; i <= x + d2; i++) 
		for (int j = y+1; j <= n; j++) {
			if (y - x < j - i) {
				visited[i][j] = 2;
				sum += map[i][j];
			}
		}
	return sum;
}
int area3(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = x + d1; i <= n; i++) 
		for (int j = 1; j < y - d1 + d2; j++) 
			if (x - y + 2 * d1 < i - j) {
				visited[i][j] = 3;
				sum += map[i][j];
			}
	return sum;
}
int area4(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = x + d2 + 1; i <= n; i++) 
		for (int j = y - d1 + d2; j <= n; j++) 
			if (i + j > x + y + 2 * d2) {
				visited[i][j] = 4;
				sum += map[i][j];
			}
	return sum;
}
int area5(int x, int y, int d1, int d2) {
	int sum = 0;
	for (int i = 1; i <= n; i++) 
		for (int j = 1; j <= n; j++) 
			if (visited[i][j] == 0) {
				visited[i][j] = 5;
				sum += map[i][j];
			}
	return sum;
}

int make_area(int x, int y, int d1, int d2) {

	int cnt1 = area1(x, y, d1, d2);
	int cnt2 = area2(x, y, d1, d2);
	int cnt3 = area3(x, y, d1, d2);
	int cnt4 = area4(x, y, d1, d2);
	int cnt5 = area5(x, y, d1, d2);

	int maxi = max(cnt1, max(cnt2, max(cnt3, max(cnt4, cnt5))));
	int mini = min(cnt1, min(cnt2, min(cnt3, min(cnt4, cnt5))));
	return maxi - mini;
}

int solve(){
	int result = 0xFFFFFFF;
	for (int x = 1; x <= n; x++) 
		for (int y = 1; y <= n; y++) 
			for (int d1 = 1; d1 <= n; d1++) 
				for (int d2 = 1; d2 <= n; d2++) 
					if (1 <= x && x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n) {
						memset(visited, 0, sizeof(visited));
						result = min(result, make_area(x, y, d1, d2));
					}
	return result;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	cout << solve() << endl;
}