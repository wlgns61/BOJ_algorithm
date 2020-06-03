#include <iostream>
#define M_PI 3.14159265358979323846

using namespace std;

int main() {
	int r=0;
	cin >> r;
	cout.precision(6);
	cout<<fixed;
	cout << r * r * M_PI << "\n" << 2.0 * r * r;
}