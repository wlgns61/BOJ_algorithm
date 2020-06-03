#include <iostream>

using namespace std;

int main() {
	int i = 1, j = 1, k = 1;
	int num = 1;
	int range = 1;
	cin >> num;

	while (true) {
		if (range <= num && num <= range + k - 1) {
			break;
		}
		range = range + k;
		k++;
	}
	if (k % 2 == 0) {
		j = k;
		while (range < num) {
			j--;
			i++;
			range++;
		}
	}
	else {
		i = k;
		while (range < num) {
			i--;
			j++;
			range++;
		}
	}
	cout << i << "/" << j << endl;
}