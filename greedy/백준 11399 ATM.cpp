#include <iostream>
#include <algorithm>

using namespace std;

int *arr;

int main() {
	int N;
	cin >> N;
	arr = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			sum += arr[j];
		}
	}
	cout << sum;
}