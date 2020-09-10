#include <iostream>
#include <algorithm>

using namespace std;

long long n, k;

long long countNum(long long mid) {
	
	long long cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += min( mid/i, n);
	}
	return cnt;
}

long long search() {
	
	long long end = k;
	long long start = 1;
	long long result = 0;

	while (start <= end) {
		
		long long mid = (start + end) / 2;
		long long cnt = countNum(mid); //mid보다 작거나 같은 갯수

		if (cnt < k) {  
			start = mid + 1;
		}	
		else {
			result = mid;
			end = mid - 1;
		}
	}
	return result;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	cout << search();
}