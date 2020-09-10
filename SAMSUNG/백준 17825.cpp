#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

vector <int> map[33];
int dp[10];
int dice[10];
int tmp[4];
int score[33] = { 
0,2,4,6,8,10,12,14,16,18,
20,22,24,26,28,30,32,34,36,38,
13,16,19,22,24,28,27,26,25,30,
35,40,0 };

void init() {
	for (int i = 0; i <= 18; i++) //0~18
		map[i].push_back(i + 1);  
	for (int i = 20; i <= 21; i++)  // 20 ~ 21
		map[i].push_back(i + 1);
	for (int i = 25; i <= 31; i++) // 25 ~ 31
		map[i].push_back(i + 1);
	
	map[5].push_back(20); //blue
	map[10].push_back(23); //blue
	map[15].push_back(25); //blue
	map[19].push_back(31); //坷->付瘤阜
	map[22].push_back(28); //哭->啊款单
	map[23].push_back(24); // 啊厘关-> 关
	map[24].push_back(28); //关 -> 啊款单
}

int go(int now, int jump) {
	if (now == 5 || now == 10 || now == 15) {
		now = map[now][1];
		jump--;
	} 
	for (int i = 0; i < jump; i++) {
		if (now == 32) break;
		now = map[now][0];
	}
	return now;
}

bool is_movable(int next, int a, int b, int c, int d) {
	if (next < 33) {
		if (next == 32) return true;
		if (next != a && next != b && next != c && next != d)
			return true;
	}
	return false;
}

int solve(int now1, int now2, int now3, int now4, int cnt) {
	
	int &ret = dp[cnt];
	if (cnt == 10) return 0;
	ret = 0;

	int next1 = go(now1, dice[cnt]);
	int next2 = go(now2, dice[cnt]);
	int next3 = go(now3, dice[cnt]);
	int next4 = go(now4, dice[cnt]);

	if (is_movable(next1,now1,now2,now3,now4) && now1 < 32) 
		ret = max(ret, solve(next1, now2, now3, now4, cnt + 1) + score[next1]);
	if (is_movable(next2, now1,now2, now3, now4) && now2 < 32) 
		ret = max(ret, solve(now1, next2, now3, now4, cnt + 1) + score[next2]);
	if (is_movable(next3, now1, now2,now3, now4) && now3 < 32) 
		ret = max(ret, solve(now1, now2, next3, now4, cnt + 1) + score[next3]);
	if (is_movable(next4, now1, now2, now3, now4) && now4 < 32) 
		ret = max(ret, solve(now1, now2, now3, next4, cnt + 1) + score[next4]);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	init();
	for (int i = 0; i < 10; i++) 
		cin >> dice[i];
	memset(dp, -1, sizeof(dp));
	cout << solve(0, 0, 0, 0, 0);
}