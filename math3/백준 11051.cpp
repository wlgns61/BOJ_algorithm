#include <iostream>

using namespace std;

int **arr;

int main() {
	int n, k;
	int div = 10007;
	cin >> n >> k;
	arr = new int*[n+1];
	for (int i = 0; i <= n; i++) {
		arr[i] = new int[k+1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			arr[i][j] = 0;
		}
	}

	if (n == 0 || k == 0) {
		cout << 1;
	}
	else if (0 <= k && k <= n) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= k; j++) {
				if (j == 1) {
					arr[i][j] = i % div;
				}
				else if (i == j) {
					arr[i][j] = 1 % div;
				}
				else {
					arr[i][j] = (arr[i - 1][j - 1] + arr[i - 1][j]) % div;
				}
			}
		}
		cout << arr[n][k] % div;
	}
	else {
		cout << 0;
	}
	

}