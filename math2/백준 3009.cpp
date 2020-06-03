#include <iostream>

using namespace std;

int main() {
	int x_1 = 0, x_2 = 0, x_3 = 0, x_4 = 0;
	int y_1 = 0, y_2 = 0, y_3 = 0, y_4 = 0;
	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;
	if (x_1 == x_2) x_4 = x_3;
	else if (x_1 == x_3) x_4 = x_2;
	else if (x_2 == x_3) x_4 = x_1;

	if (y_1 == y_2) y_4 = y_3;
	else if (y_1 == y_3) y_4 = y_2;
	else if (y_2 == y_3) y_4 = y_1;
	cout << x_4 << " " << y_4;
}