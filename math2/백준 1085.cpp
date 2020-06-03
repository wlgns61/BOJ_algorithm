#include <iostream>

using namespace std;

int main() {
	int x, y, w, h;
	int x_dist = 0; int y_dist = 0;
	cin >> x >> y >> w >> h;
	if (2 * x <= w) x_dist = x;
	else x_dist = w - x;
	if (2 * y <= h) y_dist = y;
	else y_dist = h - y;
	if (y_dist <= x_dist) cout << y_dist;
	else cout << x_dist;
}