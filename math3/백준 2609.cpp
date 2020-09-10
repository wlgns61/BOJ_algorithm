#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int bigger = max(a, b);
	while (true) {
		if (bigger%a == 0 && bigger%b == 0) {
			break;
		}
		bigger++;
	}
	cout << (a * b) / bigger << "\n" << bigger;
}