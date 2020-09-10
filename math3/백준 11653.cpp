#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;
	int i = 2;
	if (N == 1) return 0;
	else {
		for (i = 2; i*i <= N; i++) {
			if (N%i == 0) {
				N = N / i;
				cout << i << "\n";
				--i;
			}
		}
	}
	if (N > 1) cout << N;
}