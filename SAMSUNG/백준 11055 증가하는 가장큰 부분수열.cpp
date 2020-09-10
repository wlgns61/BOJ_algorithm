#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[1001];
int dp[1001];
int n;
int result = 0;

void LIS() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + arr[i]);
				result = max(dp[i], result);
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		dp[i] = arr[i];
	}
	result = dp[0];
	LIS();
	cout << result;
}