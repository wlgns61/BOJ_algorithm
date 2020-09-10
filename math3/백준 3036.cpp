#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (a%b == 0) {
		return b;
	}
	return gcd(b, a%b);
}

int main() {
	int *arr;
	int N;
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < N; i++) {
		int GCD = gcd(arr[0], arr[i]);
		cout << arr[0] / GCD << "/" << arr[i] / GCD << "\n";
	}
}