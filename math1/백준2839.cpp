#include <iostream>

using namespace std;

int main() {
	int total = 0; int temp = 0;
	int kg5 = 0;
	int kg3 = 0;
	int i = 0, j = 0;
	cin >> total;

	for (i = total / 5; i >= -1; i--) {
		temp = total - (i * 5);
		if (temp == 0) break;
		else {
			if (temp % 3 == 0) {
				j = temp / 3;
				break;
			}
		}
	}
	if (i == -1) cout << i << endl;
	else {
		cout << i + j << endl;
	}
}