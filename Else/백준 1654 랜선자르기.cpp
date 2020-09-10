#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector <long long> arr;
int k, n;
long long high = 0;

int countLine(long long mid) {
	int cnt = 0;
	for (int i = 0; i < arr.size(); i++) {
		cnt += (arr[i] / mid);
	}
	return cnt;
}

long long solve() {

	long long start = 1;
	long long result = 0;

	while (start <= high) {

		long long mid = (high + start) / 2;
		int cnt = countLine(mid);

		if (cnt < n) {
			high = mid - 1;
		}
		else {
			result = max(result, mid);
			start = mid + 1;
		}
	}
	return result;

}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k >> n;

	for (int i = 0; i < k; i++) {
		long long num;
		cin >> num;
		high = max(high, num);
		arr.push_back(num);
	}

	cout << solve();
}