#include <iostream>

using namespace std;

typedef long long ll;
ll dp[1001][10]; //n자리수, 가장앞자리수의숫자
int n;

void solve() {
	for (int first = 0; first <= 9; first++)
		dp[1][first] = 10 - first;
	for (int n = 2; n <= 1000; n++) {
		dp[n][9] = 1;
		for (int first = 9; first >= 1; first--) 
			dp[n][first - 1] = (dp[n][first] + dp[n - 1][first - 1]) % 10007;
	}
}

int main() {
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	solve();
	cin >> n;
	cout << dp[n][0] << "\n";
}