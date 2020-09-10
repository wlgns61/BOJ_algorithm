#include <iostream>

using namespace std;

int main() {
	int N, K;
	int cnt = 0;
	cin >> N >> K;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = N - 1; i >= 0; i--) {
		int tmp = K;
		cnt = 0;
		if (arr[i] <= tmp) {
			for (int j = i; j >= 0; j--) {
				cnt += tmp / arr[j];
				tmp = tmp % arr[j];
				if (tmp == 0) break;
			}
		}
		if (tmp == 0) break;
	}
	cout << cnt;

}