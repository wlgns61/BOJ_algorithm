#include <iostream>

using namespace std;

int total_multiply(int start, int end) {
	int result = 1;
	for (int i = start; i <= end; i++) {
		result *= i;
	}
	return result;
}

int main() {
	int n, k;
	cin >> n >> k;
	int  mother, son;
	if (0 <= k && k <= n) {
		son = total_multiply(k + 1, n);
		mother = total_multiply(1, n - k);
		cout << son / mother;
	}
	else {
		cout << 0;
	}
}