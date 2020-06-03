#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int A;
	int B;
	int C;
	int x;
	//int y;
	cin >> A >> B >> C;
	if (C - B > 0) {
		x = A/(C - B);
		x++;
	}
	else x = -1;	
	cout << x << endl;
}