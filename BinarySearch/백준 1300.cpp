#include <iostream>
#include <algorithm>

using namespace std;


int solve(int N, int K) {
	int end = K;
	int start = 1;
	int mid;
	int result = 0;
	while (end>=start) {
		long long cnt = 0;
		mid = (end + start) / 2;
		for (int i = 1; i <= N; i++) {
			cnt += min(mid / i, N); //mid보다 작거나 같은 수가 몇 개 있는지 
		}
		if (cnt < K) { // mid보다 더 큰수가 정답임 
			start = mid + 1;
		}
		else if(cnt >= K){ //mid보다 더 작은 수가 정답임, count가 많이 되어도 정답일 수 있음
			result = mid;
			end = mid - 1;
		}
	}
	return result;
}

int main() {
	int N,K;
	cin >> N >> K;

	cout << solve(N, K);
}