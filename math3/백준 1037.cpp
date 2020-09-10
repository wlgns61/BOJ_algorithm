#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int N;
	int _max = 0;
	int _min = 1000001;
	cin >> N;
	int *arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		_max = max(_max, arr[i]);
		_min = min(_min, arr[i]);
	}
	long long num = 1;
	while (true) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			if (num % arr[i] == 0) cnt++;
			else break;
		}
		if (cnt == N) {
			if (_max == num) num = num * _min;
			cout << num;
			break;
		}
		num++;
	}
}