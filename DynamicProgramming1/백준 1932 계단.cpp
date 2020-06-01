#include <iostream>
#include <algorithm>

using namespace std;

int find_max(int n) {

	int *stair = new int[n+1]; //현재계단값 
	int *stair_temp = new int[n+1]; //임시 누적 계단값
	int *stair_total = new int[n+1]; //누적 계단값
	int num;

	for (int i = 0; i < n + 1; i++) {
		stair[i] = 0;
		stair_temp[i] = 0;
		stair_total[i] = 0;
	}
	
	cin >> num; stair[1] = num;
	stair_temp[1] = stair[1];
	stair_total[1] = stair[1];

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			stair_temp[j] = stair_total[j];
			cin >> num; 
			stair[j] = num;
		}
		for (int i = 1; i <= n; i++) {
			stair_total[i] = stair[i] + max(stair_temp[i], stair_temp[i - 1]);
		}
	}
	int max_ = stair_total[0];
	for (int i = 1; i < n + 1; i++) {
		if (max_ < stair_total[i]) max_ = stair_total[i];
	}
	return max_;
}

int main() {
	int N;
	cin >> N;
	cout << find_max(N);

}