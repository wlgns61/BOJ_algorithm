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
			cnt += min(mid / i, N); //mid���� �۰ų� ���� ���� �� �� �ִ��� 
		}
		if (cnt < K) { // mid���� �� ū���� ������ 
			start = mid + 1;
		}
		else if(cnt >= K){ //mid���� �� ���� ���� ������, count�� ���� �Ǿ ������ �� ����
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