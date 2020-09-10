#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long dp[100][2];

long long solve(int cnt, int now) {

	long long &ref = dp[cnt][now];

	if (ref != 0)  //방문한적 있다면
		return ref;
	if (cnt == n)  //마지막까지 도달
		return ref = 1;
	if (now) 
		ref += solve(cnt + 1, !now);
	else 
		ref += (solve(cnt + 1, now) + solve(cnt + 1, !now));
	return ref;
}

int main() {
	cin >> n;
	cout  << solve(1, 1) << endl;
}