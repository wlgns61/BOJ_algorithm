#include <iostream>
#include <algorithm>

using namespace std;
int n, k;
int arr[100];
int dp[10001];
int tmp[10001];

void solve() {
	for (int i = 0; i < n; i++) 
		for (int j = 1; j <= k; j++) {
			if (j >= arr[i]) {
				int left = j - arr[i];
				if (left == 0)
					dp[j] = 1;
				else if (tmp[left] != 0) {
					if (tmp[j] == 0) dp[j] = tmp[left] + 1;
					else dp[j] = min(tmp[left] + 1, tmp[j]);
				}
			}
			tmp[j] = dp[j];
		}
}

int main() {
	
	ios_base::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	solve();
	if (dp[k] == 0)
		cout << -1 << "\n";
	else
		cout << dp[k] << "\n";
}