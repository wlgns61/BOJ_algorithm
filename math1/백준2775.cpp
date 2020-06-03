#include <iostream>

using namespace std;

int main() {
	int k = 0, n = 0; //kÃþ nÈ£
	int i = 0, j = 0; //jÃþ iÈ£
	int test = 0, count = 0;
	cin >> test;
	for (count = 0; count < test; count++) {
		cin >> k;
		cin >> n;
		int *arr = new int[n];
		for (i = 0; i < n; i++) {
			arr[i] = i + 1;
		}
		for (j = 1; j <= k; j++) {
			for (i = 1; i < n; i++) {
				arr[i] += arr[i - 1];
			}
		}
		cout << arr[i - 1] << endl;
	}
}