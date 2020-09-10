#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, H;
int map[32][12]; //height, line
int result = 4;	

bool go() {
	
	for (int i = 1; i <= N; i++) {
		int nowl = i; 
		for (int nowh = 0; nowh <= H; nowh++){
			if (map[nowh][nowl] == 1) 
				nowl++;
			else if (map[nowh][nowl - 1] == 1) 
				nowl--;
		}
		if (nowl != i)
			return false;
	}
	return true;
}

void solve(int cnt, int now_h, int now_l) {
	if (go()) {
		result = min(cnt, result);
		return;
	}
	if (cnt == 3) 
		return;

	for (int h = now_h; h <= H; h++) {
		for (int l = now_l; l < N; l++) {
			if (map[h][l] == 0 && map[h][l - 1] == 0 && map[h][l + 1] == 0) {
				map[h][l] = 1;
				solve(cnt + 1, h, l);
				map[h][l] = 0;
			}
		}
		now_l = 1;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> H;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b; //a높이 b라인
		map[a][b] = 1;
	}
	solve(0, 1, 1);
	
	if (result >= 4)
		cout << -1 << "\n";
	else
		cout << result << "\n";
}