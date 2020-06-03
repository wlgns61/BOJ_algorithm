#include <iostream>
using namespace std;
int main() {
	int i = 1;
	int n = 1;
	int bound_limit = 1;
	cin >> n;
	while (bound_limit < n) {
		bound_limit = bound_limit + (6 * i);
		i++;
	}
	cout << i;
}