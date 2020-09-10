#include <iostream>

using namespace std;

int main() {
	int x[4];
	int y[4];
	for (int i = 0; i < 3; i++) {
		cin >> x[i] >> y[i];
	}
	x[3] = x[0];
	y[3] = y[0];
	int result = 0;
	for (int i = 0; i < 3; i++) {
		result += (x[i] * y[i + 1]) - (y[i] * x[i + 1]);
	}
	if (result > 0)
		cout << 1;
	else if (result < 0)
		cout << -1;
	else
		cout << 0;
}