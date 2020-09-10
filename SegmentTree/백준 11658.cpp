#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;
ll dp[1025][1025];
int arr[1025][1025];

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			arr[i][j] = num;
			dp[i][j] = num + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
		}
	}
	int q;
	for (int i = 1; i <= m; i++) {
		cin >> q;
		if (q == 0) {
			int x, y, num;
			cin >> x >> y >> num;
			int diff = num - arr[x][y];
			for (int i = x; i <= n; i++) {
				for (int j = y; j <= n; j++) {
					dp[i][j] += diff;
				}
			}
		}
		else if (q == 1) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << "\n";
		}
	}
}