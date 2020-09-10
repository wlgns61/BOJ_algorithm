#include <iostream>
#include <algorithm>

using namespace std;

struct info {
	int cnt;
	int track;
};
typedef info info;

info arr[1000002] = {0};

void backtracking(int n) {
	arr[2].cnt = 1;
	arr[2].track = 1;
	arr[3].cnt = 1;
	arr[3].track = 1;
	for (int i = 4; i <= n; i++) {
		if (i % 6 == 0) {
			int min_ = min(arr[i - 1].cnt, min(arr[i / 3].cnt, arr[i / 2].cnt));
			if (min_ == arr[i / 3].cnt) {
				arr[i].cnt = arr[i / 3].cnt + 1;
				arr[i].track = i / 3;
			}
			else if (min_ == arr[i / 2].cnt) {
				arr[i].cnt = arr[i / 2].cnt + 1;
				arr[i].track = i / 2;
			}
			else {
				arr[i].cnt = arr[i - 1].cnt + 1;
				arr[i].track = i - 1;
			}
		}
		else if (i % 2 == 0) {
			if (arr[i - 1].cnt >= arr[i / 2].cnt) {
				arr[i].cnt = arr[i / 2].cnt + 1;
				arr[i].track = i / 2;
			}
			else {
				arr[i].cnt = arr[i - 1].cnt + 1;
				arr[i].track = i - 1;
			}
		}
		else if (i % 3 == 0) {
			if (arr[i - 1].cnt >= arr[i / 3].cnt) {
				arr[i].cnt = arr[i / 3].cnt + 1;
				arr[i].track = i / 3;
			}
			else {
				arr[i].cnt = arr[i - 1].cnt + 1;
				arr[i].track = i - 1;
			}
		}
		else {
			arr[i].cnt = arr[i - 1].cnt + 1;
			arr[i].track = i - 1;
		}
	}
	cout << arr[n].cnt << endl;
	int i = n;
	cout << i << " ";
	while (arr[i].track!=0) {
		cout << arr[i].track << " ";
		i = arr[i].track;
	}
}

int main() {
	int n;
	cin >> n;
	backtracking(n);
}
