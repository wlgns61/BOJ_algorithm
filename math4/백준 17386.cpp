#include <iostream>

using namespace std;

typedef long long ll;

int main() {
	ll x1, x2, x3, x4, y1, y2, y3, y4;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	ll t1 = (x1 * y2) + (x2 * y3) + (x3 * y1) - (x2 * y1) - (x3 * y2) - (x1 * y3);
	ll t2 = (x1 * y2) + (x2 * y4) + (x4 * y1) - (x2 * y1) - (x4 * y2) - (x1 * y4);
	ll t3 = (x3 * y4) + (x4 * y1) + (x1 * y3) - (x4 * y3) - (x1 * y4) - (x3 * y1);
	ll t4 = (x3 * y4) + (x4 * y2) + (x2 * y3) - (x4 * y3) - (x2 * y4) - (x3 * y2);
	int f1 = 1, f2 = 1, f3 = 1, f4 = 1;
	if (t1 < 0)
		f1 = -1;
	if (t2 < 0)
		f2 = -1;
	if (t3 < 0)
		f3 = -1;
	if (t4 < 0)
		f4 = -1;
	//cout << f1 << " " << f2 << " " << f3 << " " << f4 << endl
	if (f1*f2 == -1 && f3*f4 == -1)
		cout << 1;
	else
		cout << 0;
	
}