#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int i = 0, j = 0;
	int m = 0, n = 0;
	int count = 0;
	cin >> m >> n;
	bool arr[1000001] = {false};
	arr[0] = true;
	arr[1] = true;
	for (i = 2; i*i <= 1000000; i++) {
		j = 1;
		if (arr[i] == false) {
			while (i*(j + 1) <= n) {
				arr[i*(j + 1)] = true;
				j++;
			}
		}
	}
	for (i = m; i <= n; i++) {
		if (arr[i] == false) cout << i << "\n"; //endl보다 \n이 더 빠르다.
	}
} 