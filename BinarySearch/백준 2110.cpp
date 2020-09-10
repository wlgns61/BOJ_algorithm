#include <iostream>
#include <algorithm>

using namespace std;

int *arr;
int N, C;

void solve() {
	int end = arr[N - 1];
	int start = 1;
	int distance;
	int result = 0;
	while (end >= start) {
		int cnt = 1;
		distance = (start + end) / 2;
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i] - arr[tmp] >= distance) {
				cnt++;
				tmp = i;
			}
		}
		if (cnt >= C) { //더 많이 설치 했을 때, 간격을 넓혀야 함 
						//딱 맞는 갯수로 설치가 되었어도 간격을 넓혀서 볼 수 있음
			result = max(result, distance);
			start = distance + 1;
		}
		else { //더 적게 설치했을때, 간격을 줄여야함
			end = distance - 1;
		}
	}
	cout << result;

}

int main() {
	
	cin >> N >> C;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	solve();

}