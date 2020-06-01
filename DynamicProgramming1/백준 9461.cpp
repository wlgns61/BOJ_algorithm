#include <iostream>

using namespace std;

int n;
unsigned long long fib_arr[101] = {1,1,1,1,2,2,};

unsigned long long find_fib() {
	for (int i = 6; i <= n; i++) {
		fib_arr[i] = fib_arr[i - 1] + fib_arr[i - 5];
	}
	return fib_arr[n];
}


int main() {

	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << find_fib() << "\n";
	}

}