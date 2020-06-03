#include <iostream>

using namespace std;

int main() {
	int i = 0, j = 0, k = 0;
	int test = 0;
	int n = 0;
	int count = 0;
	while (true) {
		count = 0;
		bool arr[123456*2+1] = { false };
		arr[0] = true;
		arr[1] = true;
		cin >> n;
		if (n == 0) break;
		for (j = 2; j*j <= 2*n; j++) {
			for (k = 2; j*k <= 2*n; k++) {
				if (arr[j*k] == false) {
					arr[j*k] = true;
				}
			}
		}
		for (j = n+1; j <= 2 * n; j++) {
			if (arr[j] == false) count++;
		}
		cout << count << "\n";
	}
}