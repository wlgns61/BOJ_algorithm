#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int N, k;
long long dp[1 << 15][101];
string arr_str[15];
pair<long long, int> arr[15];

long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}


long long solve(int visited, int R) {
	
	if (dp[visited][R] != -1) { // 방문 한적이 있는 dp
		return dp[visited][R];
	}

	if (visited == ((1 << N) - 1)) { //dp를 전부 다 방문 하였을때,
		if (R == 0) 
			return dp[visited][R] = 1;
		else 
			return dp[visited][R] = 0;
	}
	dp[visited][R] = 0;
	for (int i = 0; i < N; i++) {
		if ((visited & (1 << i)) == 0) {
			int num = ((R * int(pow(10, arr[i].second))) % k + (arr[i].first % k)) % k;
			dp[visited][R] += solve((visited | (1 << i)), num);
		}
	}
	return dp[visited][R];
}

void init() {
	for (int i = 0; i < (1 << 15); i++) {
		for (int j = 0; j < 101; j++) {
			dp[i][j] = -1;
		}
	}
}

void transformation(int k) {
	int result = 0;
	int radix = 10;
	for (int i = 0; i < N; i++) {
		result = int(arr_str[i][0]);
		int j = 0;
		while (j < arr_str[i].size) {
			if (result >= k) {
				result %= k;
			}
			else {
				result = (radix*result) + int(arr_str[i][j]);
				j++;
			}
		}
	}
}

int main() {

	cin >> N;
	init();
	for (int i = 0; i < N; i++) {
		string num;
		cin >> num;
		arr_str[i] = num;
		arr[i].second = num.size();
	}
	cin >> k;
	long long son = solve(0, 0), mom = 1;
	if (son == 0) {
		cout << "0/1"; return 0;
	}
	for (int i = 1; i <= N; i++) mom *= i;
	long long g = gcd(son, mom);
	son /= g; mom /= g;
	cout << son << "/" << mom;
	
}