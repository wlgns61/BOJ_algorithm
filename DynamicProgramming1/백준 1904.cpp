#include <iostream>

using namespace std;

int n;
unsigned long long *fib_arr;

int find_fib() {
	fib_arr[0] = 1;
	fib_arr[1] = 2;
	for (int i = 2; i < n; i++) {
		fib_arr[i] = (fib_arr[i - 1] + fib_arr[i - 2]) % 15746;
	}
	return fib_arr[n - 1];
}


int main() {

	cin >> n;
	fib_arr = new unsigned long long[n];
	cout << find_fib();

}