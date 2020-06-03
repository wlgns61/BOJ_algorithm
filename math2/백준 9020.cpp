#include <iostream>

using namespace std;

int main() {
	int test = 0;
	cin >> test;
	int i = 0, j = 0, k = 0;
	int num1=0, num2=0;
	bool arr[10001] = { true,true,false, };

	for (i = 2; i*i <= 10000; i++) {
		for (j = 2; i*j <= 10000; j++) {
			if (arr[i*j] == false) arr[i*j] = true;
		}
	}

	for (i = 0; i < test; i++) {
		int n = 0;
		bool flag = false;
		cin >> n;
		for (j = n/2; j <= n; j++) {
			if (arr[j] == false) {
				for (k = n/2; k > 0; k--) {
					if (j + k == n && arr[k] == false) {
						//cout << k << " " << j << "\n";
						num1 = k;
						num2 = j;
						flag = true;
						break;
					}
				}
			}
			if (flag == true) break;
		}
		cout << num1 << " " << num2 << "\n";
	}
}