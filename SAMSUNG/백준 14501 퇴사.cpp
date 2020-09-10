#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair <int, int>> v(20, {0,0});
int dp[17];
int n;

int solve(int cur) { //1

	if (cur > n + 1) 
		return -1;
	if (cur == n + 1) 
		return dp[cur] = v[cur].second; //딱 마지막 날이면 그값을 반환

	else { //만약 next로 진입이 가능하다면 
		for (int i = cur + v[cur].first; i <= n + 1; i++) { //미팅이 시작 가능한 경우의 한에서
			int ret = solve(i);
			if (ret != -1) 
				dp[cur] = max(ret + v[cur].second, dp[cur]);
		}
		return dp[cur];
	}
}

int main() {

	cin >> n;
	v[0] = {1,0};
	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> t >> p;
		v[i] = { t,p };
	}
	cout << solve(0) << endl;
}