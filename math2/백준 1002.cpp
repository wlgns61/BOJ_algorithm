#include <iostream>
#include <cmath>

using namespace std;

int main() {
	float dist = 0;
	int x1, y1, x2, y2, r1, r2;
	int test = 0;
	cin >> test;
	//int result = 0;
	int i = 0;
	for (i = 0; i < test; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		dist = pow((pow(x1 - x2, 2) + pow(y1 - y2, 2)), 0.5);
		if (dist == 0 && r1 == r2) cout << "-1\n";
		else if (dist == r1 + r2 || dist == abs(r1 - r2))
			cout << "1\n";
		else if (dist < r1 + r2 && dist > abs(r1 - r2))
			cout << "2\n";
		else cout << "0\n";
	}
}