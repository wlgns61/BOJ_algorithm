#include <iostream>
#include <cmath>
using namespace std;

int findRadix(int n) {
	int radix = 1;
	int i = 0;
	while (radix < n) {
		radix = radix * 10;
		i++;
	}
	return i;
}

int divideSum(int n) {
	int i = 0, j=0;
	int radix = 0;
	int result = 0;
	int positionValue = 0;
	int positionValueSum = 0;
	radix = findRadix(n);
	for (i = n - (radix * 9); i < n ; i++) {
		positionValueSum = 0;
		for (j = 1; j <= radix; j++) {
			positionValue = i % int(pow(10, j));
			positionValue = positionValue / (pow(10, j-1));
			positionValueSum += positionValue;
		}
		result = i + positionValueSum;
		if (result == n) return i;
	}
	return 0;
}

int main() {
	int n = 0;
	cin >> n;
	cout << divideSum(n);
}