#include <iostream>
#include <algorithm>

using namespace std;

int *total;
int *stair;

int find_max(int N) {
	int num;
	total = new int[N];
	stair = new int[N];
	for (int i = 0; i < N; i++) {
		total[i] = 0;
		stair[i] = 0;
	}
	if (N == 1) {
		cin >> num;
		return num;
	}
	else if (N == 2) {
		int num2;
		cin >> num >> num2;
		return num + num2;
	}
	else {
		cin >> num; stair[0] = num;
		cin >> num; stair[1] = num;
		cin >> num; stair[2] = num;
		total[0] = stair[0];
		total[1] = max(stair[0] + stair[1], stair[1]);
		total[2] = max((stair[0] + stair[2]), (stair[1] + stair[2]));
		for (int i = 3; i < N; i++) {
			cin >> num;
			stair[i] = num;
			total[i] = max((total[i - 2] + stair[i]), (total[i - 3] + stair[i] + stair[i - 1]));

		}
		return total[N - 1];
	}
}

int main() {
	int N;
	cin >> N;
	cout << find_max(N);
}