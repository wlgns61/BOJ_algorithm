#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int n, int from, int to, int aux) {
	if (n == 1) {
		cout << from << " " << to << "\n";
		return;
	}
	hanoi(n - 1, from, aux, to);
	cout << from << " " << to << "\n";
	hanoi(n - 1, aux, to, from);
}

void count(int n) {
	int sum = 0;
	while (n > 0) {
		sum += pow(2,--n);
	}
	cout << sum << "\n";
}

int main() {
	int n;
	cin >> n;
	count(n);
	hanoi(n, 1, 3, 2);
}