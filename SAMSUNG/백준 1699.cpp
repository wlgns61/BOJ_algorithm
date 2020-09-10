#include <iostream>
#include <algorithm>

using namespace std;

int dp[100001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		dp[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		int x = 0;
		while (true) {
			x++;
			if (x*x > i)
				break;
			dp[i] = min(dp[i], dp[i - x * x] + 1);
		}
	}
	cout << dp[n];
}