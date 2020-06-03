#include <iostream>

using namespace std;

int main() {
	int n = 0, i = 0, j = 0;
	int count = 0;
	int count2 = 0;
	int number = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		count2 = 0;
		cin >> number;
		for (j = 1; j <= number; j++) {
			if (number%j == 0) count2++;
		}
		if (count2 == 2) count++;
	}
	cout << count;
}